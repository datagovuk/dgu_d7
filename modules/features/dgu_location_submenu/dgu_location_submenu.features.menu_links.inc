<?php
/**
 * @file
 * dgu_location_submenu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgu_location_submenu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:node/3996
  $menu_links['main-menu:data/map-based-search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'data/map-based-search',
    'router_path' => 'node/%',
    'link_title' => 'Map based search',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'location',
  );
  // Exported menu link: main-menu:node/4026
  $menu_links['main-menu:location/guidance_and_tools'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'location/guidance_and_tools',
    'router_path' => 'node/%',
    'link_title' => 'Guidance and Tools',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'location',
  );
  // Exported menu link: main-menu:node/4030
  $menu_links['main-menu:location/contact_points'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'location/contact_points',
    'router_path' => 'node/%',
    'link_title' => 'Contact Points',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'location',
  );
  // Exported menu link: main-menu:node/4031
  $menu_links['main-menu:location/inspire'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'location/inspire',
    'router_path' => 'node/%',
    'link_title' => 'INSPIRE',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'location',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact Points');
  t('Guidance and Tools');
  t('INSPIRE');
  t('Map based search');


  return $menu_links;
}
