<?php
/**
 * @file
 * dgu_site_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_site_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dgu_site_feature_node_info() {
  $items = array(
    'app' => array(
      'name' => t('App'),
      'base' => 'node_content',
      'description' => t('This content type supports listing, display, and submission of \'Apps\' - production or prototype applications that make use of publicly-available government data feeds.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('Please submit examples of Internet-based applications that make use of publicly-available government data sources.'),
    ),
  );
  return $items;
}
