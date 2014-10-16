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
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any app content'.
  $permissions['delete any app content'] = array(
    'name' => 'delete any app content',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own app content'.
  $permissions['delete own app content'] = array(
    'name' => 'delete own app content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any app content'.
  $permissions['edit any app content'] = array(
    'name' => 'edit any app content',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own app content'.
  $permissions['edit own app content'] = array(
    'name' => 'edit own app content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fivestar',
  );

  return $permissions;
}
