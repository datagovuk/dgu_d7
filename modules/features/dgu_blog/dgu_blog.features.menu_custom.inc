<?php
/**
 * @file
 * dgu_blog.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dgu_blog_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-blog-tabs.
  $menus['menu-blog-tabs'] = array(
    'menu_name' => 'menu-blog-tabs',
    'title' => 'Blog tabs',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog tabs');


  return $menus;
}
