<?php


abstract class DGUNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    //$this->addFieldMapping('field_legacy_nid', 'nid')
    //  ->description('We have a common field to save the D6 nid');
  }

  protected function mapVideo($video){
    if (! empty($video[0])){

      error_log(print_r($this->getSource()->current(), true));
      error_log(print_r($this->getDestination(), true));
      error_log(print_r($video, true));

    }
  }
}

class DGUAppMigration extends DGUNodeMigration {

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
