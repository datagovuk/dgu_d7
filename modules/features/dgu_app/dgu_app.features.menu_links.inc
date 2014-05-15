<?php
/**
 * @file
 * dgu_app.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgu_app_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-apps-tabs:apps
  $menu_links['menu-apps-tabs:apps'] = array(
    'menu_name' => 'menu-apps-tabs',
    'link_path' => 'apps',
    'router_path' => 'apps',
    'link_title' => 'Latest apps',
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
    'weight' => 0,
  );
  // Exported menu link: menu-apps-tabs:apps/top
  $menu_links['menu-apps-tabs:apps/top'] = array(
    'menu_name' => 'menu-apps-tabs',
    'link_path' => 'apps/top',
    'router_path' => 'apps',
    'link_title' => 'Top rated apps',
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
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Latest apps');
  t('Top rated apps');


  return $menu_links;
}
