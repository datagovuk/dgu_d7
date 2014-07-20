<?php
/**
 * @file
 * dgu_moderation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_moderation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
