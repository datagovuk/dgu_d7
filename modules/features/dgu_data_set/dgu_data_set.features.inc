<?php
/**
 * @file
 * dgu_data_set.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_data_set_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
