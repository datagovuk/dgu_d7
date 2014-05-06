<?php
/**
 * @file
 * dgu_data_set_request.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dgu_data_set_request_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__dataset_request';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => TRUE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'flag_spam_node' => array(
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'rss' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__dataset_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_dataset_request';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_dataset_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_dataset_request';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_dataset_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_dataset_request';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_dataset_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_dataset_request';
  $strongarm->value = '1';
  $export['node_preview_dataset_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_dataset_request';
  $strongarm->value = 1;
  $export['node_submitted_dataset_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_dataset_request_pattern';
  $strongarm->value = 'data-request/[node:title]';
  $export['pathauto_node_dataset_request_pattern'] = $strongarm;

  return $export;
}
