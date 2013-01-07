<?php
/**
 * @file
 * dgu_idea.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_idea_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function dgu_idea_node_info() {
  $items = array(
    'idea' => array(
      'name' => t('Idea'),
      'base' => 'node_content',
      'description' => t('This content type supports listing, display, and submission of \'Ideas\' - publicly-submitted ideas for government web applications that do not yet exist but should.'),
      'has_title' => '1',
      'title_label' => t('What is your idea'),
      'help' => '',
    ),
  );
  return $items;
}
