<?php
/**
 * @file
 * dgu_data_set_request.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgu_data_set_request_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create dataset_request content'.
  $permissions['create dataset_request content'] = array(
    'name' => 'create dataset_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own dataset_request content'.
  $permissions['delete own dataset_request content'] = array(
    'name' => 'delete own dataset_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own dataset_request content'.
  $permissions['edit own dataset_request content'] = array(
    'name' => 'edit own dataset_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
