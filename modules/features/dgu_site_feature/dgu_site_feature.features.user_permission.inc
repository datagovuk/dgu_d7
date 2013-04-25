<?php
/**
 * @file
 * dgu_site_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgu_site_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: access comments.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: post comment reply.
  $permissions['post comment reply'] = array(
    'name' => 'post comment reply',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'reply',
  );

  // Exported permission: post comments.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: view comment reply.
  $permissions['view comment reply'] = array(
    'name' => 'view comment reply',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'reply',
  );

  return $permissions;
}
