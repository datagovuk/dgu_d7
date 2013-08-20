<?php
/**
 * @file
 * dgu_data_set.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_data_set_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_reply_bundle().
 */
function dgu_data_set_default_reply_bundle() {
  $items = array();
  $items['dataset_feedback'] = entity_import('reply_bundle', '{
    "bundle" : "dataset_feedback",
    "name" : "Dataset feedback",
    "access" : "2",
    "display" : "1",
    "description" : "",
    "form" : "2",
    "allow_reply" : "1",
    "locked" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
