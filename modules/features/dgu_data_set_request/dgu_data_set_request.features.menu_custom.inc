<?php
/**
 * @file
 * dgu_data_set_request.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dgu_data_set_request_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-data-requests-tabs.
  $menus['menu-data-requests-tabs'] = array(
    'menu_name' => 'menu-data-requests-tabs',
    'title' => 'Data requests tabs',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Data requests tabs');


  return $menus;
}
