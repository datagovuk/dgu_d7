<?php
/**
 * @file
 * dgu_data_set_request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_data_set_request_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
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
function dgu_data_set_request_views_api($module = NULL, $api = NULL) {
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
      'description' => t('You can create a data request for any data that you believe should be released as open Data but you have had difficulty obtaining.  You will be asked questions about how you plan to use the data and what benefits you can see to releasing this data.  You may choose to keep your data request confidential.  Before creating a new data request please look through any published data requests to make sure that someone else has not already started this process.'),
      'has_title' => '1',
      'title_label' => t('Data request title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
