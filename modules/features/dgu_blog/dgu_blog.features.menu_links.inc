<?php
/**
 * @file
 * dgu_blog.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgu_blog_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-blog-tabs:blog
  $menu_links['menu-blog-tabs:blog'] = array(
    'menu_name' => 'menu-blog-tabs',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Latest Blogs',
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
  // Exported menu link: menu-blog-tabs:blog/popular
  $menu_links['menu-blog-tabs:blog/popular'] = array(
    'menu_name' => 'menu-blog-tabs',
    'link_path' => 'blog/popular',
    'router_path' => 'blog',
    'link_title' => 'Most popular Blogs',
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
  t('Latest blog posts');
  t('Most popular blog posts');


  return $menu_links;
}
