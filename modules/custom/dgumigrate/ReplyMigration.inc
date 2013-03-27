<?php



class CommentReplyMigration extends DrupalMigration {
	/**
	 * Contains the content type name for the legacy content type which comments were attached to. Used by
	 * query() to limit the source data to only the content type we are interested in.
	 *
	 * @var String
	 */
	protected $source_type;

	/**
	 * Constructor for CommentMigration
	 * $arguments should contain the following elements:
	 *  - node_migration: The machine name of the migration to use as the source for node id's.
	 *  - user_migration: The machine name of the migration to use as the source for user id's.
	 *  - source_type: The content type name for the legacy content type which the comment was attached to.
	 *  - destination_field: The name of the field which will reference the reply
	 *  - destination_type: The name of the content type with which the imported reply should be linked.
	 *  - reply_bundle: The bundle name to create reply enties with. This defalts to 'comments'
	 *  - default_uid: user id to use if not specified.
	 *
	 * @param array $arguments
	 * @throws MigrateException
	 */
	function __construct($arguments){

		$this->highwaterField = array(
				'name' => 'timestamp',
				'alias' => 'c',
				'type' => 'int',
		);


		if (!empty($arguments['node_migration'])) {
			$nodeMigration = $arguments['node_migration'];
			$this->dependencies[] = $nodeMigration;
		}

		if (!empty($arguments['user_migration'])) {
			$user_migration = $arguments['user_migration'];
			$this->dependencies[] = $user_migration;
		}
		if (!empty($arguments['source_type'])) {
			$this->source_type = $arguments['source_type'];
		}
		if (!array_key_exists('description', $arguments)){
			$arguments['description'] = '';
		}
		if (!array_key_exists('reply_bundle', $arguments)){
			$arguments['reply_bundle'] = 'comment';
		}
		parent::__construct($arguments);
		$instance = field_info_instance('node', $arguments['destination_field'], $arguments['destination_type']);
		if (!$instance){
			throw new MigrateException(t('Could not find !dest in the type: !type. You need to add this field to import comments for this type.',
					array('!dest' => $arguments['destination_field'], '!type' => $arguments['destination_type'])));
		}
		$this->source = new MigrateSourceSQL($this->query(),  $this->sourceFields, NULL, $this->sourceOptions);
		$this->destination = new MigrateDestinationReply($arguments['reply_bundle']);
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
		$this->addSimpleMappings(array('hostname'));
		$this->addFieldMapping('status')->defaultValue(1);
		$this->addFieldMapping('language')->defaultValue('en');
		$this->addFieldMapping('entity_id', 'nid')->sourceMigration($nodeMigration)->defaultValue(0);
		$this->addFieldMapping('instance_id')->defaultValue($instance['id']);
		$this->addFieldMapping('parent', 'pid')->sourceMigration($arguments['machine_name'])->defaultValue(0);
		$this->addFieldMapping('entity_type')->defaultValue('node');

		if (!empty($nodeMigration)) {
			$this->addFieldMapping('nid', 'nid')
				->sourceMigration($nodeMigration);
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
		$query->fields('n', array('vid'));

		if ($this->source_type){
			$query->condition('type', $this->source_type, '=');
		}
		$query->join('node', 'n', 'c.nid = n.nid');
		$query->orderBy('timestamp');
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

    if($reply->parent) {
      $parent = reply_load($reply->parent);
      $reply->depth = $parent->depth;
      $reply->depth++;
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

	public function bulkRollback(array $ids){

	}


}