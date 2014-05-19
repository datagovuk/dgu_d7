<?php
/**
 * @file
 * dgu_app.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dgu_app_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-apps-tabs.
  $menus['menu-apps-tabs'] = array(
    'menu_name' => 'menu-apps-tabs',
    'title' => 'Apps tabs',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Apps tabs');


  return $menus;
}
