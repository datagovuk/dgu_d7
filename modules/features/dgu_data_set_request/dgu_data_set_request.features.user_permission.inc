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

  // Exported permission: 'create field_data_set_link'.
  $permissions['create field_data_set_link'] = array(
    'name' => 'create field_data_set_link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_review_notes'.
  $permissions['create field_review_notes'] = array(
    'name' => 'create field_review_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_review_outcome'.
  $permissions['create field_review_outcome'] = array(
    'name' => 'create field_review_outcome',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_review_status'.
  $permissions['create field_review_status'] = array(
    'name' => 'create field_review_status',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'delete any dataset_request content'.
  $permissions['delete any dataset_request content'] = array(
    'name' => 'delete any dataset_request content',
    'roles' => array(),
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

  // Exported permission: 'edit any dataset_request content'.
  $permissions['edit any dataset_request content'] = array(
    'name' => 'edit any dataset_request content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_data_set_link'.
  $permissions['edit field_data_set_link'] = array(
    'name' => 'edit field_data_set_link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_review_notes'.
  $permissions['edit field_review_notes'] = array(
    'name' => 'edit field_review_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_review_outcome'.
  $permissions['edit field_review_outcome'] = array(
    'name' => 'edit field_review_outcome',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_review_status'.
  $permissions['edit field_review_status'] = array(
    'name' => 'edit field_review_status',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own dataset_request content'.
  $permissions['edit own dataset_request content'] = array(
    'name' => 'edit own dataset_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_data_set_link'.
  $permissions['edit own field_data_set_link'] = array(
    'name' => 'edit own field_data_set_link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_review_notes'.
  $permissions['edit own field_review_notes'] = array(
    'name' => 'edit own field_review_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_review_outcome'.
  $permissions['edit own field_review_outcome'] = array(
    'name' => 'edit own field_review_outcome',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_review_status'.
  $permissions['edit own field_review_status'] = array(
    'name' => 'edit own field_review_status',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_data_set_link'.
  $permissions['view field_data_set_link'] = array(
    'name' => 'view field_data_set_link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_review_notes'.
  $permissions['view field_review_notes'] = array(
    'name' => 'view field_review_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_review_outcome'.
  $permissions['view field_review_outcome'] = array(
    'name' => 'view field_review_outcome',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_review_status'.
  $permissions['view field_review_status'] = array(
    'name' => 'view field_review_status',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_data_set_link'.
  $permissions['view own field_data_set_link'] = array(
    'name' => 'view own field_data_set_link',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_review_notes'.
  $permissions['view own field_review_notes'] = array(
    'name' => 'view own field_review_notes',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_review_outcome'.
  $permissions['view own field_review_outcome'] = array(
    'name' => 'view own field_review_outcome',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_review_status'.
  $permissions['view own field_review_status'] = array(
    'name' => 'view own field_review_status',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
