<?php
/**
 * @file
 * dgu_footer.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dgu_footer_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer.
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer',
    'description' => 'Footer menu',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer');
  t('Footer menu');


  return $menus;
}
