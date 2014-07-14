<?php
/**
 * @file
 * dgu_data_set_request.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dgu_data_set_request_user_default_roles() {
  $roles = array();

  // Exported role: data request administrator.
  $roles['data request administrator'] = array(
    'name' => 'data request administrator',
    'weight' => 9,
  );

  return $roles;
}
