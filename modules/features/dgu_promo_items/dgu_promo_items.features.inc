<?php
/**
 * @file
 * dgu_promo_items.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_promo_items_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dgu_promo_items_node_info() {
  $items = array(
    'promo_item' => array(
      'name' => t('Promo Item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
