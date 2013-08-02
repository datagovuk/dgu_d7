<?php
/**
 * @file
 * dgu_data_set_request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_data_set_request_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dgu_data_set_request_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function dgu_data_set_request_node_info() {
  $items = array(
    'dataset_request' => array(
      'name' => t('Dataset Request'),
      'base' => 'node_content',
      'description' => t('Used to store requests for datasets.'),
      'has_title' => '1',
      'title_label' => t('Dataset name'),
      'help' => t('Please enter the name of the dataset you require.'),
    ),
  );
  return $items;
}
