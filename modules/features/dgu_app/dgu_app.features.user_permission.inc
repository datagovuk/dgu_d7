<?php
/**
 * @file
 * dgu_app.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgu_app_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create app content'.
  $permissions['create app content'] = array(
    'name' => 'create app content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create dataset_request content'.
  $permissions['create dataset_request content'] = array(
    'name' => 'create dataset_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own app content'.
  $permissions['delete own app content'] = array(
    'name' => 'delete own app content',
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

  // Exported permission: 'edit own app content'.
  $permissions['edit own app content'] = array(
    'name' => 'edit own app content',
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
