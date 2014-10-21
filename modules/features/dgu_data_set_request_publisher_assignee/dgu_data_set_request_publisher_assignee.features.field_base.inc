<?php
/**
 * @file
 * dgu_data_set_request_publisher_assignee.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dgu_data_set_request_publisher_assignee_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_publisher_assignee'
  $field_bases['field_publisher_assignee'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_publisher_assignee',
    'field_permissions' => array(
      'type' => '2',
    ),
    'foreign keys' => array(
      'uid' => array(
        'columns' => array(
          'uid' => 'uid',
        ),
        'table' => 'users',
      ),
    ),
    'indexes' => array(
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'locked' => '0',
    'module' => 'dgu_assignee',
    'settings' => array(),
    'translatable' => '0',
    'type' => 'assignee',
  );

  return $field_bases;
}
