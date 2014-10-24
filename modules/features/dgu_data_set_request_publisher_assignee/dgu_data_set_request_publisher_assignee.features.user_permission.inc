<?php
/**
 * @file
 * dgu_data_set_request_publisher_assignee.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgu_data_set_request_publisher_assignee_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_publisher_assignee'.
  $permissions['create field_publisher_assignee'] = array(
    'name' => 'create field_publisher_assignee',
    'roles' => array(
      'administrator' => 'administrator',
      'data request administrator' => 'data request administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_publisher_assignee'.
  $permissions['edit field_publisher_assignee'] = array(
    'name' => 'edit field_publisher_assignee',
    'roles' => array(
      'administrator' => 'administrator',
      'data request administrator' => 'data request administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_publisher_assignee'.
  $permissions['edit own field_publisher_assignee'] = array(
    'name' => 'edit own field_publisher_assignee',
    'roles' => array(
      'administrator' => 'administrator',
      'data request administrator' => 'data request administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_publisher_assignee'.
  $permissions['view field_publisher_assignee'] = array(
    'name' => 'view field_publisher_assignee',
    'roles' => array(
      'administrator' => 'administrator',
      'data publisher' => 'data publisher',
      'data request administrator' => 'data request administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_publisher_assignee'.
  $permissions['view own field_publisher_assignee'] = array(
    'name' => 'view own field_publisher_assignee',
    'roles' => array(
      'administrator' => 'administrator',
      'data request administrator' => 'data request administrator',
      'editor' => 'editor',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
