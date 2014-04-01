<?php
/**
 * @file
 * dgu_forum.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dgu_forum_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-forum-tabs.
  $menus['menu-forum-tabs'] = array(
    'menu_name' => 'menu-forum-tabs',
    'title' => 'Forum tabs',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Forum tabs');


  return $menus;
}
