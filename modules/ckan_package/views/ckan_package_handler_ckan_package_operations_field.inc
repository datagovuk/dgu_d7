<?php

/**
 * This field handler aggregates operations that can be done on a CKAN Package
 * under a single field providing a more flexible way to present them in a view
 */
class ckan_package_handler_ckan_package_operations_field extends views_handler_field {
  function construct() {
    parent::construct();

    $this->additional_fields['ckan_id'] = 'ckan_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {

    $links = menu_contextual_links('ckan_package', 'admin/content/ckan_package', array($this->get_value($values, 'ckan_id')));
    
    if (!empty($links)) {
      return theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
    }
  }
}
