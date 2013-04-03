<?php


abstract class DGUNodeMigration extends DrupalNode6Migration {
	public function __construct(array $arguments) {
		parent::__construct($arguments);

		//$this->addFieldMapping('field_legacy_nid', 'nid')
		//  ->description('We have a common field to save the D6 nid');
	}

}

class DGUCommentMigration extends CommentReplyMigration {
	function __construct($arguments){
		parent::__construct($arguments);
		$this->addFieldMapping('field_reply_subject', 'subject');
		$this->addFieldMapping('field_reply_comment', 'comment');
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

		$this->addFieldMapping('field_developed_by', 'field_developed_by');
		$this->addFieldMapping('field_rating', NULL);
		$this->addFieldMapping('field_screen_shots', 'field_screen_shots')->sourceMigration('Files');
		$this->addFieldMapping('field_screen_shots:file_class')->defaultValue('MigrateFileFid');
		//$this->addFieldMapping('field_screen_shots:source_dir')->defaultValue(variable_get("drupal6files"));

		$this->addFieldMapping('field_submitter_email', 'field_submitter_email');
		$this->addFieldMapping('field_submitter_name', 'field_submitter_name');
		$this->addFieldMapping('field_uses_dataset', 'field_package');


		$this->addUnmigratedSources(array('field_app_link:attributes', 'field_other_commissioner',
				'field_feature_availability', 'field_screen_shots:list', 'field_screen_shots:data', 'field_app_link:title'));
		$this->addUnmigratedDestinations(array('field_developed_by:language', 'field_screen_shots:language',
				'field_screen_shots:alt', 'field_screen_shots:title', 'field_submitter_name:language',
				'field_category:source_type', 'field_category:create_term', 'field_category:ignore_case', 
				'field_comment', 'field_sector:source_type', 'field_sector:create_term', 'field_sector:ignore_case',
				'field_tags:source_type', 'field_tags:create_term', 'field_tags:ignore_case'));

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
				'field_video', 'field_video:value', 'field_video:provider', 'field_video:data', '9',
				'field_video:status', 'field_video:version', 'field_video:title', 'field_video:description', 'field_video:duration'));
		$this->addUnmigratedDestinations(array('field_audio', 'field_audio:file_class', 'field_audio:language', 'field_audio:destination_dir',
				'field_audio:destination_file', 'field_audio:file_replace', 'field_audio:preserve_files', 'field_audio:source_dir', 'field_audio:title', 
				'field_audio:data', 'field_category:source_type', 'field_category:create_term', 'field_category:ignore_case', 'field_comment',
				'field_sector:source_type', 'field_sector:create_term', 'field_sector:ignore_case', 'field_tags:source_type', 'field_tags:create_term',
				'field_tags:ignore_case','field_video', 'field_video:file_class', 'field_video:language', 'field_video:destination_dir',
				'field_video:destination_file', 'field_video:file_replace', 'field_video:preserve_files', 'field_video:source_dir', 
				'field_video:title', 'field_video:data'));
	}

}

class DGUBookMigration extends DGUNodeMigration {

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
				'field_comment',
				'field_data_themes:source_type',
				'field_data_themes:create_term',
				'field_data_themes:ignore_case',
		));


		$this->removeFieldMapping('body');
		$this->removeFieldMapping('body:language');
		$this->removeFieldMapping('body:summary');
		$this->removeFieldMapping('body:format');
		$this->removeFieldMapping('field_data_set_name:language');

		$this->addFieldMapping(NULL, 'body', FALSE);
		$this->addFieldMapping(NULL, 'teaser', FALSE);
		$this->addFieldMapping(NULL, 'format', FALSE);


		//unmapped source fields:
		$this->addUnmigratedSources(array(
				'field_dataset_link:title',
				'field_dataset_link:attributes',
				'field_website',
				'field_website:title',
				'field_website:attributes',
		));
	}


}

class DGUForumMigration extends DGUNodeMigration {
	function __construct(array $arguments){
		parent::__construct($arguments);
	
		$this->addFieldMapping('taxonomy_forums', '2')->sourceMigration('forum')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_category', '4')->sourceMigration('category')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_sector', '13')->sourceMigration('sector')->arguments(array('source_type' => 'tid'));

		$this->addUnmigratedDestinations(array(
			'taxonomy_forums:source_type', 'taxonomy_forums:create_term', 'taxonomy_forums:ignore_case',
			'field_category:source_type', 'field_category:create_term', 'field_category:ignore_case',
			'field_sector:source_type', 'field_sector:create_term', 'field_sector:ignore_case',
		));
		
	}

}

class DGUIdeaMigration extends DGUNodeMigration {
	function __construct(array $arguments) {
		parent::__construct($arguments);

		$this->addFieldMapping('field_category', '4')->sourceMigration('category')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_tags', '6')->sourceMigration('tags')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_sector', '13')->sourceMigration('sector')->arguments(array('source_type' => 'tid'));

		$this->addFieldMapping('field_submitter_name', 'field_submitter_name');
		$this->addFieldMapping('field_submitter_email', 'field_submitter_email');

		$this->addUnmigratedDestinations(array(
			'field_tags:source_type', 'field_tags:create_term', 'field_tags:ignore_case',
			'field_category:source_type', 'field_category:create_term', 'field_category:ignore_case',
			'field_sector:source_type', 'field_sector:create_term', 'field_sector:ignore_case',
			'field_submitter_name:language', 'field_comment',
		));

	}
}

class DGUOrganogramMigration extends DGUNodeMigration {
	function __construct(array $arguments) {
		parent::__construct($arguments);
		$this->addFieldMapping('field_endpoint', 'field_endpoint');
		$this->addFieldMapping('field_parent_organogram', 'field_parent_org');
		$this->addFieldMapping('field_endpoint:language')->defaultValue('en');
	}
	
}
 
class DGUResourceMigration extends DGUNodeMigration {

	function __construct(array $arguments) {
		parent::__construct($arguments);

		$this->addFieldMapping('field_category', '4')->sourceMigration('category')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_tags', '6')->sourceMigration('tags')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_sector', '13')->sourceMigration('sector')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_document_type', '21')->sourceMigration('document_type')->arguments(array('source_type' => 'tid'));

		$this->addFieldMapping('field_resource_file', 'field_resource_file')->sourceMigration('Files');
		$this->addFieldMapping('field_resource_file:file_class')->defaultValue('MigrateFileFid');
		$this->addFieldMapping('field_resource_file:source_dir')->defaultValue(variable_get("drupal6files"));

		$this->addUnmigratedDestinations(array(
			'field_tags:source_type', 'field_tags:create_term', 'field_tags:ignore_case',
			'field_category:source_type', 'field_category:create_term', 'field_category:ignore_case',
			'field_sector:source_type', 'field_sector:create_term', 'field_sector:ignore_case',
			'field_resource_file:language', 'field_resource_file:description', 'field_resource_file:display',
			'field_document_type:source_type', 'field_document_type:create_term', 'field_document_type:ignore_case',
		));

		$this->addUnmigratedSources(array(
			'field_resource_file:list', 'field_resource_file:data',
		));

	}

}

class DGUPageMigration extends DGUNodeMigration {
	function __construct(array $arguments) {
		
		$attachment_fields = array(
  			'attachments_filename' => t('field_file_attachments'),
		);
		$this->sourceFields = array_merge($this->sourceFields, $attachment_fields);
		parent::__construct($arguments);
		
		$this->addFieldMapping('field_category', '4')->sourceMigration('category')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_tags', '6')->sourceMigration('tags')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_sector', '13')->sourceMigration('sector')->arguments(array('source_type' => 'tid'));
		$this->addFieldMapping('field_file_attachments', 'field_file_attachments')->sourceMigration('Files');
		$this->addFieldMapping('field_file_attachments:file_class')->defaultValue('MigrateFileFid');


		$this->addUnmigratedDestinations(array(
			'field_tags:source_type', 'field_tags:create_term', 'field_tags:ignore_case',
			'field_category:source_type', 'field_category:create_term', 'field_category:ignore_case',
			'field_sector:source_type', 'field_sector:create_term', 'field_sector:ignore_case',
		));
	}

	protected function query() {
		$query = parent::query();
		return $query;
	}

	public function prepareRow($current_row) {
		parent::prepareRow($current_row);
		$query = Database::getConnection('default', $this->sourceConnection)
			->select('upload', 'up')->condition('up.vid', $current_row->vid, '=')
			->fields('up', array('fid'));
		$result = $query->execute();
		foreach ($result as $row) {
			$current_row->field_file_attachments[] = $row->fid;
		}
	}


}

class DGUStoryMigration extends DGUPageMigration {


}

class DGUFileMigration extends DrupalFile6Migration {
	function __construct($arguments){
		parent::__construct($arguments);
		$this->destination = new MigrateDestinationMedia('image');

		$this->addFieldMapping('value', 'filepath', FALSE)->callbacks(array($this, 'fixUri'));
		$this->addFieldMapping('destination_file', 'filepath', FALSE)->callbacks(array($this, 'fixUri'));
		$this->addFieldMapping('timestamp', 'timestamp', FALSE);
		$this->addFieldMapping('uid', 'uid', FALSE)->sourceMigration('User')->defaultValue(1);
		$this->addFieldMapping('source_dir', NULL, FALSE)->defaultValue($arguments['source_dir']);

		$this->addFieldMapping('destination_dir', NULL, FALSE);
		$this->addFieldMapping('destination_file', NULL, FALSE);
		$this->addFieldMapping('file_replace', NULL, FALSE);
		$this->addFieldMapping('preserve_files', NULL, FALSE);
		$this->addFieldMapping('timestamp', NULL, FALSE);


		$this->addUnmigratedDestinations(array(
			'field_image_description:format', 'field_image_description:language', 
			'field_file_image_alt_text', 'field_file_image_alt_text:language', 
			'field_file_image_title_text', 'field_file_image_title_text:language',
		));
		$this->addUnmigratedSources(array(
			'timestamp', 'origname',
		));

		if (module_exists('path')) {
			$this->addUnmigratedDestinations(array('path'));
		}
	}
}
