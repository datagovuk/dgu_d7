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
    $this->addFieldMapping('field_audio', 'field_audio');
    $this->addFieldMapping('field_video', 'field_video')
     ->callbacks(array($this, 'mapVideo'));
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
