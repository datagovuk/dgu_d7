<?php
/**
 * @file
 * dgu_data_set.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dgu_data_set_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'ckan_dataset-ckan_dataset-field_comment'
  $field_instances['ckan_dataset-ckan_dataset-field_comment'] = array(
    'bundle' => 'ckan_dataset',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'reply',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'reply_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'ckan_dataset',
    'field_name' => 'field_comment',
    'label' => 'Comments',
    'required' => 0,
    'settings' => array(
      'access' => -1,
      'allow_reply' => -1,
      'display' => -1,
      'form' => -1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'reply',
      'settings' => array(),
      'type' => 'reply',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Comments');

  return $field_instances;
}
