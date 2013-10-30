<?php
/**
 * @file
 * dgu_site_feature.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dgu_site_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-apps.
  $menus['menu-apps'] = array(
    'menu_name' => 'menu-apps',
    'title' => 'Apps',
    'description' => 'Sub navigation for \'Apps\' main navigation link',
  );
  // Exported menu: menu-interact.
  $menus['menu-interact'] = array(
    'menu_name' => 'menu-interact',
    'title' => 'Interact',
    'description' => 'Sub navigation for \'Interact\' main navigation link',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Apps');
  t('Interact');
  t('Main menu');
  t('Sub navigation for \'Apps\' main navigation link');
  t('Sub navigation for \'Interact\' main navigation link');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
