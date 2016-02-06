<?php
/**
 * @file
 * dgu_issue.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_issue_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
