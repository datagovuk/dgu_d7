<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying edit links
 * as fields
 */


class ckan_package_handler_edit_link_field extends ckan_package_handler_link_field {
  function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }


  function render($values) {
    $type = $values->{$this->aliases['type']};
    
    //Creating a dummy ckan_package to check access against
    $dummy_ckan = (object) array('type' => $type);
    if (!ckan_package_access('edit', $dummy_ckan)) {
      return;
    }
    
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $ckan_package_id = $values->{$this->aliases['ckan_id']};
    
    return l($text, 'admin/content/ckan_packages/ckan_package/' . $ckan_id . '/edit');
  }
}
