<?php
/**
 * @file
 * dgu_library.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_library_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dgu_library_node_info() {
  $items = array(
    'resource' => array(
      'name' => t('Library resource'),
      'base' => 'node_content',
      'description' => t('Library resource'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
