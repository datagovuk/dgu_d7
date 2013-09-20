<?php
/**
 * @file
 * dgu_forum.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_forum_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function dgu_forum_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dgu_forum_node_info() {
  $items = array(
    'forum' => array(
      'name' => t('Forum topic'),
      'base' => 'node_content',
      'description' => t('A <em>forum topic</em> starts a new discussion thread within a forum.'),
      'has_title' => '1',
      'title_label' => t('Subject'),
      'help' => '',
    ),
  );
  return $items;
}
