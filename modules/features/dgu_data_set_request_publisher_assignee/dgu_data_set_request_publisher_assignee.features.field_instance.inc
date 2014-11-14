<?php
/**
 * @file
 * dgu_data_set_request_publisher_assignee.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dgu_data_set_request_publisher_assignee_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-dataset_request-field_publisher_assignee'
  $field_instances['node-dataset_request-field_publisher_assignee'] = array(
    'bundle' => 'dataset_request',
    'default_value' => NULL,
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'dgu_assignee',
        'settings' => array(
          'empty_fields_emptyfieldtext_empty_text' => '- None -',
          'empty_fields_handler' => 'EmptyFieldText',
          'field_replies' => 0,
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'dgu_assignee_default',
        'weight' => '3',
      ),
      'rss' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_publisher_assignee',
    'label' => 'Publisher assignee',
    'required' => 0,
    'settings' => array(
      'user_list_provider' => 'dgu_data_set_request_publisher_assignee',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => '5',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Publisher assignee');

  return $field_instances;
}
