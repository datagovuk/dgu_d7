<?php
/**
 * @file
 * dgu_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dgu_blog_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dgu_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog entry'),
      'base' => 'node_content',
      'description' => t('Use for multi-user blogs. Every user gets a personal blog.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
