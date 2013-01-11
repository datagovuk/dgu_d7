<?php

//testing branch workflow


abstract class DGUNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //$this->addFieldMapping('field_legacy_nid', 'nid')
    //  ->description('We have a common field to save the D6 nid');
  }

}

class DGUCommentMigration extends DrupalMigration {
	function __construct($arguments){
		
		$this->highwaterField = array(
				'name' => 'timestamp',
				'alias' => 'c',
				'type' => 'int',
		);
		

		if (!empty($arguments['node_migration'])) {
			$this->nodeMigration = $arguments['node_migration'];
			$this->dependencies[] = $this->nodeMigration;
		}
		
		if (!empty($arguments['user_migration'])) {
			$user_migration = $arguments['user_migration'];
			$this->dependencies[] = $user_migration;
		}
		if (!array_key_exists('description', $arguments)){
			$arguments['description'] = '';
		}
		parent::__construct($arguments);
		$this->source = new MigrateSourceSQL($this->query(),  $this->sourceFields, NULL, $this->sourceOptions);
		// we can create different destination reply bundle targets as required (e.g. CKAN Package Comment)
		$this->destination = new MigrateDestinationReply('comment');
		$this->map = new MigrateSQLMap($this->machineName,
				array(
						'cid' => array('type' => 'int',
								'unsigned' => TRUE,
								'not null' => TRUE,
								'description' => 'Source comment ID',
								'alias' => 'c',
						),
				),
				MigrateDestinationComment::getKeySchema()
		);
		
		// Setup  mappings.
		$this->addSimpleMappings(array('hostname', 'status', 'language'));
		$this->addFieldMapping('entity_id', 'nid');
		$this->addFieldMapping('instance_id', 'vid');
		$this->addFieldMapping('parent', 'pid')->sourceMigration($arguments['machine_name'])->defaultValue(0);
		$this->addFieldMapping('entity_type')->defaultValue('node');
		$this->addFieldMapping('id')->defaultValue(0);
		$this->addFieldMapping('position')->defaultValue(1);
		
		
		

		if (!empty($this->nodeMigration)) {
			$this->addFieldMapping('nid', 'nid')
			->sourceMigration($this->nodeMigration);
		}
		else {
			$this->addFieldMapping('nid', 'nid');
		}
		
		if (isset($arguments['default_uid'])) {
			$default_uid = $arguments['default_uid'];
		}
		else {
			$default_uid = 1;
		}

		if (isset($user_migration)) {
			$this->addFieldMapping('uid', 'uid')
			->sourceMigration($user_migration)
			->defaultValue($default_uid);
		}
		else {
			$this->addFieldMapping('uid')
			->defaultValue($default_uid);
		}		
	}
	
	/**
	 * Implementation of DrupalCommentMigration::query().
	 *
	 * We join to {node} so that we can use separate comment migration classes
	 * for each associated node type.
	 *
	 * @return SelectQueryInterface
	 */
	protected function query() {
		$query = Database::getConnection('default', $this->sourceConnection)
		->select('comments', 'c')
		->fields('c', array('cid', 'pid', 'nid', 'uid', 'subject',
				'comment', 'hostname', 'timestamp', 'status', 'thread', 'name',
				'mail', 'homepage', 'format'));
		$query->
		fields('n', array('vid'));
		$query->join('node', 'n', 'c.nid = n.nid');
		$query->orderBy('timestamp');
	//error_log(dpq($query));
		return $query;
	}
	
}


class MigrateDestinationReply extends MigrateDestinationEntity{
	/**
	 * Basic initialization
	 *
	 * @param string $bundle
	 *  A.k.a. the content type (page, article, etc.) of the ... comment?.
	 * @param array $options
	 *  Options applied to comments.
	 */
	public function __construct($bundle, array $options = array()) {
		parent::__construct('reply', $bundle, $options);
	}
	
	/**
	 * Returns a list of fields available to be mapped for replies in a particlar bundle
	 *
	 * @param Migration $migration
	 *  Optionally, the migration containing this destination.
	 * @return array
	 *  Keys: machine names of the fields (to be passed to addFieldMapping)
	 *  Values: Human-friendly descriptions of the fields.
	 */
	public function fields($migration = NULL) {
		$fields = array();
		// First the core (reply table) fields
		$fields['id'] = t('Reply Id');
		$fields['bundle'] = t('Bundle that the reply belongs to.');
		$fields['parent'] = t('The parent reply used for threading');
		$fields['entity_id'] = t('The entity to which this reply relates');
		$fields['entity_type'] = t('The entity type to which this reply relates');
		$fields['uid'] = t('User Id who created this reply');
		$fields['created'] = t('The date and time when the comment was created.');
		$fields['changed'] = t('The date and time when the comment was last changed');
		$fields['hostname'] = t('The hostname or IP address from which the reply was posted.');
		$fields['status'] = t('Status of reply.');
		$fields['language'] = t('Language of the reply.');
		$fields['depth'] = t('Depth of reply in threaded replies.');
		$fields['instance_id'] = t('Instance Id of the reply.');
		$fields['position'] = t('Position of the reply in the thread.');
		$fields['deleted'] = t('Deleted status of the reply');
	
		// Then add in anything provided by handlers
		$fields += migrate_handler_invoke_all('Entity', 'fields', $this->entityType, $this->bundle, $migration);
		$fields += migrate_handler_invoke_all('Reply', 'fields', $this->entityType, $this->bundle, $migration);
		
		return $fields;
	}
	
	static public function getKeySchema() {
		return array(
				'id' => array(
						'type' => 'int',
						'unsigned' => TRUE,
						'description' => 'ID of reply entity',
				),
		);
	}
	
	
	/**
	 * Import a single reply.
	 *
	 * @param $reply
	 *  Comment object to build. Prefilled with any fields mapped in the Migration.
	 * @param $row
	 *  Raw source data object - passed through to prepare/complete handlers.
	 * @return array
	 *  Array of key fields (id only in this case) of the comment that was saved if
	 *  successful. FALSE on failure.
	 */
	public function import(stdClass $reply, stdClass $row) {
		$migration = Migration::currentMigration();
		// Updating previously-migrated content?
		if (isset($row->migrate_map_destid1)) {
			if (isset($reply->id)) {
				if ($reply->id != $row->migrate_map_destid1) {
					throw new MigrateException(t("Incoming id !id and map destination nid !destid1 don't match",
							array('!id' => $reply->id, '!destid1' => $row->migrate_map_destid1)));
				}
			}
			else {
				$reply->id = $row->migrate_map_destid1;
			}
		}
		// Fix up timestamps
		if (isset($reply->created)) {
			$reply->created = MigrationBase::timestamp($reply->created);
		}
		if (isset($reply->changed)) {
			$reply->changed = MigrationBase::timestamp($reply->changed);
		}
	
		if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
			if (!isset($comment->id)) {
				throw new MigrateException(t('System-of-record is DESTINATION, but no destination id provided'));
			}
			$rawreply = $reply;
			$old_reply = entity_load('reply', $reply->id);
			if (empty($old_reply)) {
				throw new MigrateException(t('System-of-record is DESTINATION, but reply !id does not exist', array('!id' => $reply->id)));
			}
			if (!isset($reply->nid)) {
				$reply->nid = $old_reply->nid;
			}
			if (!isset($reply->created)) {
				$reply->created = $old_reply->created;
			}
			if (!isset($reply->changed)) {
				$reply->changed = $old_reply->changed;
			}
			$this->prepare($reply, $row);
			foreach ($rawreply as $field => $value) {
				$old_reply->$field = $reply->$field;
			}
			$reply = $old_reply;
		}
		else {
			// Set some default properties.
			$defaults = array(
					'language' => $this->language,
					'bundle' => $this->bundle,
					'status' => REPLY_STATUS_ENABLED,
			);
			foreach ($defaults as $field => $value) {
				if (!isset($reply->$field)) {
					$reply->$field = $value;
				}
			}
	
			$this->prepare($reply, $row);
			// Make sure we have a entity id
			if (!isset($reply->entity_id) || !$reply->entity_id) {
				throw new MigrateException(t('No Entity Id provided for reply'));
			}
		}
	
		if (isset($reply->id) && $reply->id) {
			$updating = TRUE;
		}
		else {
			$updating = FALSE;
		}
		migrate_instrument_start('reply_save');
		reply_save($reply);
		migrate_instrument_stop('reply_save');
		$this->complete($reply, $row);
		if (isset($reply->id) && $reply->id > 0) {
			$return = array($reply->id);
			if ($updating) {
				$this->numUpdated++;
			}
			else {
				$this->numCreated++;
			}
		}
		else {
			$return = FALSE;
		}
		return $return;
	}
	
	
}


class DGUAppMigration extends DGUNodeMigration {
  function __construct(array $arguments){
    parent::__construct($arguments);
    $this->addFieldMapping('field_category', '4')->sourceMigration('category')->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_tags', '6')->sourceMigration('tags')->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_sector', '13')->sourceMigration('sector')->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('field_app_charge', 'field_app_charge');
    $this->addFieldMapping('field_app_link', 'field_app_link');
    $this->addFieldMapping('field_app_link:title', 'field_app_link:title');

    $this->addFieldMapping('field_developed_by', 'field_developed_by');
    $this->addFieldMapping('field_rating', '');
    $this->addFieldMapping('field_screen_shots', 'field_screen_shots')->sourceMigration('Files');
    $this->addFieldMapping('field_screen_shots:file_class')->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_screen_shots:source_dir')->defaultValue(variable_get("drupal6files"));

    $this->addFieldMapping('field_submitter_email', 'field_submitter_email');
    $this->addFieldMapping('field_submitter_name', 'field_submitter_name');
    $this->addFieldMapping('field_uses_dataset', 'field_package');


    $this->addUnmigratedSources(array('field_app_link:attributes', 'field_other_commissioner', 
      'field_feature_availability', 'field_screen_shots:list', 'field_screen_shots:data'));
    $this->addUnmigratedDestinations(array('field_developed_by:language', 'field_screen_shots:language', 
      'field_screen_shots:alt', 'field_screen_shots:title', 'field_submitter_name:language'));

  }

}

class DGUBlogMigration extends DGUNodeMigration {
  function __construct(array $arguments) {
    parent::__construct($arguments);
        // map some taxonomy terms
    $this->addFieldMapping('field_category', '4')->sourceMigration('category')->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_tags', '6')->sourceMigration('tags')->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_sector', '13')->sourceMigration('sector')->arguments(array('source_type' => 'tid'));
    $this->addUnmigratedSources(array('field_audio', 'field_audio:value', 'field_audio:provider', 'field_audio:data', 
          'field_audio:status', 'field_audio:version', 'field_audio:title', 'field_audio:description', 
          'field_video', 'field_video:value', 'field_video:provider', 'field_video:data', 
          'field_video:status', 'field_video:version', 'field_video:title', 'field_video:description', 'field_video:duration'));
    $this->addUnmigratedDestinations(array('field_audio', 'field_audio:file_class', 'field_audio:language', 'field_audio:destination_dir', 
      'field_audio:destination_file', 'field_audio:file_replace', 'field_audio:preserve_files', 'field_audio:source_dir', 'field_audio:title', 'field_audio:data',
      'field_video', 'field_video:file_class', 'field_video:language', 'field_video:destination_dir', 
      'field_video:destination_file', 'field_video:file_replace', 'field_video:preserve_files', 'field_video:source_dir', 'field_video:title', 'field_video:data',
      'field_blog', 'field_blog:source_type', 'field_blog:create_term', 'field_blog:ignore_case' ));
  }

}

class DGUBookMigration extends DGUNodeMigration {

}

class DGUBusLinkContractMigration extends DGUNodeMigration {

}

class DGUContentPromotionMigration extends DGUNodeMigration {

}

class DGUDataRequestMigration extends DGUNodeMigration {
  function __construct( array $arguments){
    parent::__construct($arguments);
    $this->addFieldMapping('field_barriers_attempted', 'field_attempted_to_get');
    $this->addFieldMapping('field_submitter_name', 'field_submitter_name');
    $this->addFieldMapping('field_submitter_email', 'field_submitter_email');
    $this->addFieldMapping('field_organisation_type', 'field_organisation_type');
    $this->addFieldMapping('field_organisation_name', 'field_organisation');
    $this->addFieldMapping('field_issue_type', 'field_datareq_type');
    $this->addFieldMapping('field_barriers_reason', 'field_bariers_list');
    $this->addFieldMapping('field_barriers_detail', 'field_barriers_expl');
    $this->addFieldMapping('field_data_use', 'field_could_do_with');
    $this->addFieldMapping('field_data_holder', 'field_data_holder');
    $this->addFieldMapping('field_data_use_detail', 'field_description_of_use');
    $this->addFieldMapping('field_benefits_overview', 'field_benefit_overview');
    $this->addFieldMapping('field_provide_estimates', 'field_provide_estimates');
    $this->addFieldMapping('field_estimates_detail', 'field_provide_estimates_expl');
    $this->addFieldMapping('field_data_set_link', 'field_dataset_link');
    $this->addFieldMapping('field_publication_preference', 'field_publication_preference');
    $this->addFieldMapping('field_review_status', 'field_review_status');
    $this->addFieldMapping('field_data_set_description', 'field_data_description');

    $this->addFieldMapping('field_data_themes', '4')->sourceMigration('category')->arguments(array('source_type' => 'tid'));


    
    //unmapped dest fields:
    $this->addUnmigratedDestinations(array(
      'field_submitter_name:language',
      'field_organisation_name:language',
      'field_data_set_name:language',
      'field_barriers_detail:language',
      'field_data_holder:language',
      'field_data_use_detail:language',
      'field_benefits_overview:language',
      'field_estimates_detail:language',
      'field_data_set_description:language',
      'body',
      'body:language',
      'body:summary',
      'body:format',
      'field_category',

    ));

    //unmapped source fields:
    $this->addUnmigratedSources(array(
      'field_dataset_link:title',
      'field_dataset_link:attributes',
      'field_website',
      'field_website:title',
      'field_website:attributes',
      'body',
      'body:language',
      'body:summary',
      'body:format',
      'teaser',
      'format',
    ));
  }


}

class DGUForumMigration extends DGUNodeMigration {

}

class DGUIdeaMigration extends DGUNodeMigration {
  function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_category', '4')->sourceMigration('category')->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_tags', '6')->sourceMigration('tags')->arguments(array('source_type' => 'tid'));
    $this->addFieldMapping('field_sector', '13')->sourceMigration('sector')->arguments(array('source_type' => 'tid'));

    $this->addFieldMapping('field_submitter_name', 'field_submitter_name');
    $this->addFieldMapping('field_submitter_email', 'field_submitter_email');
  }
}

class DGUOrganogramMigration extends DGUNodeMigration {

}

class DGUPageMigration extends DGUNodeMigration {

}

class DGUStoryMigration extends DGUNodeMigration {

}



class DGUFileMigration extends DrupalFile6Migration {
  function __construct($arguments){
    parent::__construct($arguments);
    $this->destination = new MigrateDestinationMedia('image');

    $this->addFieldMapping('value', 'filepath')->callbacks(array($this, 'fixUri'));
    $this->addFieldMapping('destination_file', 'filepath')->callbacks(array($this, 'fixUri'));
    $this->addFieldMapping('timestamp', 'timestamp');
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('source_dir')->defaultValue($arguments['source_dir']);

    $this->addUnmigratedDestinations(array('field_image_description:format',
      'field_image_description:language', 'destination_dir', 'destination_file',
      'file_replace', 'preserve_files', 'timestamp'));
    if (module_exists('path')) {
      $this->addUnmigratedDestinations(array('path'));
    }      
  }
}
