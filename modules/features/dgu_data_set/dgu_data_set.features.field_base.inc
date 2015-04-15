<?php
/**
 * @file
 * dgu_data_set.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dgu_data_set_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_dataset_reference'
  $field_bases['field_dataset_reference'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_dataset_reference',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(
      'ckan_dataset' => array(
        'columns' => array(
          'target_id' => 'id',
        ),
        'table' => 'ckan_dataset',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => '0',
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(),
      ),
      'target_type' => 'ckan_dataset',
    ),
    'translatable' => '0',
    'type' => 'entityreference',
  );

  return $field_bases;
}
