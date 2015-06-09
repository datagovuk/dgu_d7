<?php
/**
 * @file
 * dgu_flags.features.inc
 */

/**
 * Implements hook_views_api().
 */
function dgu_flags_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function dgu_flags_flag_default_flags() {
  $flags = array();
  // Exported flag: "Spam node".
  $flags['spam_node'] = array(
    'entity_type' => 'node',
    'title' => 'Spam node',
    'global' => '0',
    'types' => array(
      0 => 'app',
      1 => 'dataset_request',
      2 => 'forum',
    ),
    'flag_short' => '<i class="icon-exclamation-sign"></i> &nbsp;Flag as offensive',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => ' <i class="icon-exclamation-sign"></i> &nbsp;Unflag this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'print' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'dgu_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Spam reply".
  $flags['spam_reply'] = array(
    'entity_type' => 'reply',
    'title' => 'Spam reply',
    'global' => '0',
    'types' => array(
      0 => 'comment',
      1 => 'field_comment',
    ),
    'flag_short' => ' <i class="icon-exclamation-sign"></i> &nbsp;Flag as offensive',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => ' <i class="icon-exclamation-sign"></i> &nbsp;Unflag this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'dgu_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Dataset".
  $flags['subscribe_dataset'] = array(
    'entity_type' => 'ckan_dataset',
    'title' => 'Dataset',
    'global' => '0',
    'types' => array(),
    'flag_short' => 'Subscribe',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unsubscribe',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'comments' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'dgu_flags',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
