<?php
/**
 * @file
 * dgu_site_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgu_site_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: main-menu:about
  $menu_links['main-menu:about'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'About',
    'options' => array(),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
  );
  // Exported menu link: main-menu:apps
  $menu_links['main-menu:apps'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'apps',
    'router_path' => 'apps',
    'link_title' => 'Apps',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: main-menu:blog
  $menu_links['main-menu:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blogs',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'interact',
  );
  // Exported menu link: main-menu:data
  $menu_links['main-menu:data'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'data',
    'router_path' => 'data',
    'link_title' => 'Data',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: main-menu:forum
  $menu_links['main-menu:forum'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'forum',
    'router_path' => 'forum',
    'link_title' => 'Forum',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'interact',
  );
  // Exported menu link: main-menu:interact
  $menu_links['main-menu:interact'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'interact',
    'router_path' => 'interact',
    'link_title' => 'Interact',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: main-menu:library
  $menu_links['main-menu:library'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'library',
    'router_path' => 'library',
    'link_title' => 'Library',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'interact',
  );
  // Exported menu link: main-menu:linked-data
  $menu_links['main-menu:linked-data'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'linked-data',
    'router_path' => 'linked-data',
    'link_title' => 'Linked Data',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'parent_path' => 'interact',
  );
  // Exported menu link: main-menu:location
  $menu_links['main-menu:location'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'location',
    'router_path' => 'location',
    'link_title' => 'Location',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
    'parent_path' => 'interact',
  );
  // Exported menu link: main-menu:node/2347
  $menu_links['main-menu:node/2347'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2347',
    'router_path' => 'node/%',
    'link_title' => 'Map based search',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'parent_path' => 'location',
  );
  // Exported menu link: main-menu:node/2379
  $menu_links['main-menu:node/2379'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2379',
    'router_path' => 'node/%',
    'link_title' => 'Contact Points',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'parent_path' => 'location',
  );
  // Exported menu link: main-menu:node/2380
  $menu_links['main-menu:node/2380'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2380',
    'router_path' => 'node/%',
    'link_title' => 'INSPIRE',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'location',
  );
  // Exported menu link: main-menu:node/2381
  $menu_links['main-menu:node/2381'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2381',
    'router_path' => 'node/%',
    'link_title' => 'Guidance and Tools',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'parent_path' => 'location',
  );
  // Exported menu link: main-menu:odug
  $menu_links['main-menu:odug'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'odug',
    'router_path' => 'odug',
    'link_title' => 'Data requests',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'interact',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Apps');
  t('Blogs');
  t('Contact Points');
  t('Data');
  t('Data requests');
  t('Forum');
  t('Guidance and Tools');
  t('Home');
  t('INSPIRE');
  t('Interact');
  t('Library');
  t('Linked Data');
  t('Location');
  t('Map based search');


  return $menu_links;
}
