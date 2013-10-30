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
    'weight' => 3,
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
    'weight' => 3,
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
    'weight' => 1,
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
    'weight' => 4,
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
    'weight' => 0,
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
    'weight' => 5,
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
    'weight' => 7,
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
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'parent_path' => 'interact',
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
    'weight' => 2,
    'parent_path' => 'interact',
  );
  // Exported menu link: menu-apps:apps
  $menu_links['menu-apps:apps'] = array(
    'menu_name' => 'menu-apps',
    'link_path' => 'apps',
    'router_path' => 'apps',
    'link_title' => 'Browse Apps',
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
  // Exported menu link: menu-apps:search/everything/
  $menu_links['menu-apps:search/everything/'] = array(
    'menu_name' => 'menu-apps',
    'link_path' => 'search/everything/',
    'router_path' => 'search/everything',
    'link_title' => 'Search apps',
    'options' => array(
      'query' => array(
        'f[0]' => 'bundle:app',
      ),
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
  // Exported menu link: menu-interact:blog
  $menu_links['menu-interact:blog'] = array(
    'menu_name' => 'menu-interact',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'All Blogs',
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
    'weight' => -48,
  );
  // Exported menu link: menu-interact:forum
  $menu_links['menu-interact:forum'] = array(
    'menu_name' => 'menu-interact',
    'link_path' => 'forum',
    'router_path' => 'forum',
    'link_title' => 'All Forums',
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
    'weight' => -47,
  );
  // Exported menu link: menu-interact:library
  $menu_links['menu-interact:library'] = array(
    'menu_name' => 'menu-interact',
    'link_path' => 'library',
    'router_path' => 'library',
    'link_title' => 'Library',
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
    'weight' => -46,
  );
  // Exported menu link: menu-interact:linked-data
  $menu_links['menu-interact:linked-data'] = array(
    'menu_name' => 'menu-interact',
    'link_path' => 'linked-data',
    'router_path' => 'linked-data',
    'link_title' => 'Linked Data',
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
    'weight' => -49,
  );
  // Exported menu link: menu-interact:location
  $menu_links['menu-interact:location'] = array(
    'menu_name' => 'menu-interact',
    'link_path' => 'location',
    'router_path' => 'location',
    'link_title' => 'Location',
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
    'weight' => -50,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('All Blogs');
  t('All Forums');
  t('Apps');
  t('Blogs');
  t('Browse Apps');
  t('Data');
  t('Data requests');
  t('Forum');
  t('Home');
  t('Interact');
  t('Library');
  t('Linked Data');
  t('Location');
  t('Search apps');


  return $menu_links;
}
