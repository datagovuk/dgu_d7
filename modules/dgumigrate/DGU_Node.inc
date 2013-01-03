<?php


abstract class DGUNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

  //  $this->addFieldMapping('field_legacy_nid', 'nid')
    //     ->description('We have a common field to save the D6 nid');
    // map some taxonomy terms
    $this->addFieldMapping('field_category', '4');
    $this->addFieldMapping('field_category:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_category:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_category:ignore_case')->defaultValue(TRUE);

    $this->addFieldMapping('field_tags', '6');
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_tags:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_tags:ignore_case')->defaultValue(TRUE);

    $this->addFieldMapping('field_sector', '13');
    $this->addFieldMapping('field_sector:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_sector:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_sector:ignore_case')->defaultValue(TRUE);

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
    $this->addUnmigratedSources(array('field_audio', 'field_audio:value', 'field_audio:provider', 'field_audio:data', 
          'field_audio:status', 'field_audio:version', 'field_audio:title', 'field_audio:description', 
          'field_video', 'field_video:value', 'field_video:provider', 'field_video:data', 
          'field_video:status', 'field_video:version', 'field_video:title', 'field_video:description', 'field_video:duration'));
    $this->addUnmigratedDestinations(array('field_audio', 'field_audio:file_class', 'field_audio:language', 'field_audio:destination_dir', 
      'field_audio:destination_file', 'field_audio:file_replace', 'field_audio:preserve_files', 'field_audio:source_dir', 'field_audio:title', 'field_audio:data',
      'field_video', 'field_video:file_class', 'field_video:language', 'field_video:destination_dir', 
      'field_video:destination_file', 'field_video:file_replace', 'field_video:preserve_files', 'field_video:source_dir', 'field_video:title', 'field_video:data'));
    $this->addFieldMapping('field_blog', '9');
    $this->addFieldMapping('field_blog:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_blog:create_term')->defaultValue(FALSE);
    $this->addFieldMapping('field_blog:ignore_case')->defaultValue(TRUE);

  }

}

class DGUBookMigration extends DGUNodeMigration {

}

class DGUBusLinkContractMigration extends DGUNodeMigration {

}

class DGUContentPromotionMigration extends DGUNodeMigration {

}

class DGUDataRequestMigration extends DGUNodeMigration {

}

class DGUForumMigration extends DGUNodeMigration {

}

class DGUIdeaMigration extends DGUNodeMigration {

}

class DGUOrganogramMigration extends DGUNodeMigration {

}

class DGUPageMigration extends DGUNodeMigration {

}

class DGUStoryMigration extends DGUNodeMigration {

}
