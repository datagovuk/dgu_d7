<?php
/**
 * @file
 * dgu_services.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_services_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function dgu_services_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
