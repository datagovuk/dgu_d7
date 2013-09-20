<?php
/**
 * @file
 * dgu_linked_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_linked_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
