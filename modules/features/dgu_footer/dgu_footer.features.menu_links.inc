<?php
/**
 * @file
 * dgu_footer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgu_footer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer:contact
  $menu_links['menu-footer:contact'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');


  return $menu_links;
}
