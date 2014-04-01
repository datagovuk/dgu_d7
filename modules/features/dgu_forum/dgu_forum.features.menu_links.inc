<?php
/**
 * @file
 * dgu_forum.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgu_forum_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-forum-tabs:forum
  $menu_links['menu-forum-tabs:forum'] = array(
    'menu_name' => 'menu-forum-tabs',
    'link_path' => 'forum',
    'router_path' => 'forum',
    'link_title' => 'Latest forum topics',
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
  // Exported menu link: menu-forum-tabs:forum/categories
  $menu_links['menu-forum-tabs:forum/categories'] = array(
    'menu_name' => 'menu-forum-tabs',
    'link_path' => 'forum/categories',
    'router_path' => 'forum/categories',
    'link_title' => 'Forum categories',
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
  // Exported menu link: menu-forum-tabs:forum/popular
  $menu_links['menu-forum-tabs:forum/popular'] = array(
    'menu_name' => 'menu-forum-tabs',
    'link_path' => 'forum/popular',
    'router_path' => 'forum/popular',
    'link_title' => 'Most popular topics',
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
  // Translatables
  // Included for use with string extractors like potx.
  t('Forum categories');
  t('Latest forum topics');
  t('Most popular topics');


  return $menu_links;
}
