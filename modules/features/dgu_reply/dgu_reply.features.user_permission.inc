<?php
/**
 * @file
 * dgu_reply.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgu_reply_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer replies'.
  $permissions['administer replies'] = array(
    'name' => 'administer replies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'administer reply bundles'.
  $permissions['administer reply bundles'] = array(
    'name' => 'administer reply bundles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'delete comment reply'.
  $permissions['delete comment reply'] = array(
    'name' => 'delete comment reply',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'delete field_comment reply'.
  $permissions['delete field_comment reply'] = array(
    'name' => 'delete field_comment reply',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'delete own comment reply'.
  $permissions['delete own comment reply'] = array(
    'name' => 'delete own comment reply',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'delete own field_comment reply'.
  $permissions['delete own field_comment reply'] = array(
    'name' => 'delete own field_comment reply',
    'roles' => array(),
    'module' => 'reply',
  );

  // Exported permission: 'delete own review_comment reply'.
  $permissions['delete own review_comment reply'] = array(
    'name' => 'delete own review_comment reply',
    'roles' => array(
      'data request administrator' => 'data request administrator',
      'data request dispatcher' => 'data request dispatcher',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'delete review_comment reply'.
  $permissions['delete review_comment reply'] = array(
    'name' => 'delete review_comment reply',
    'roles' => array(
      'data request administrator' => 'data request administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'edit comment reply'.
  $permissions['edit comment reply'] = array(
    'name' => 'edit comment reply',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'edit field_comment reply'.
  $permissions['edit field_comment reply'] = array(
    'name' => 'edit field_comment reply',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'edit own comment reply'.
  $permissions['edit own comment reply'] = array(
    'name' => 'edit own comment reply',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'edit own field_comment reply'.
  $permissions['edit own field_comment reply'] = array(
    'name' => 'edit own field_comment reply',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'edit own review_comment reply'.
  $permissions['edit own review_comment reply'] = array(
    'name' => 'edit own review_comment reply',
    'roles' => array(
      'data request administrator' => 'data request administrator',
      'data request dispatcher' => 'data request dispatcher',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'edit review_comment reply'.
  $permissions['edit review_comment reply'] = array(
    'name' => 'edit review_comment reply',
    'roles' => array(
      'data request administrator' => 'data request administrator',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'post comment reply'.
  $permissions['post comment reply'] = array(
    'name' => 'post comment reply',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'post field_comment reply'.
  $permissions['post field_comment reply'] = array(
    'name' => 'post field_comment reply',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'post review_comment reply'.
  $permissions['post review_comment reply'] = array(
    'name' => 'post review_comment reply',
    'roles' => array(
      'data request administrator' => 'data request administrator',
      'data request dispatcher' => 'data request dispatcher',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'view comment reply'.
  $permissions['view comment reply'] = array(
    'name' => 'view comment reply',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'unverified user' => 'unverified user',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'view field_comment reply'.
  $permissions['view field_comment reply'] = array(
    'name' => 'view field_comment reply',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'unverified user' => 'unverified user',
    ),
    'module' => 'reply',
  );

  // Exported permission: 'view review_comment reply'.
  $permissions['view review_comment reply'] = array(
    'name' => 'view review_comment reply',
    'roles' => array(
      'data request administrator' => 'data request administrator',
      'data request dispatcher' => 'data request dispatcher',
    ),
    'module' => 'reply',
  );

  return $permissions;
}
