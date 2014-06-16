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

  // Exported role: data request account manager.
  $roles['data request account manager'] = array(
    'name' => 'data request account manager',
    'weight' => 11,
  );

  // Exported role: data request administrator.
  $roles['data request administrator'] = array(
    'name' => 'data request administrator',
    'weight' => 9,
  );

  // Exported role: data request dispatcher.
  $roles['data request dispatcher'] = array(
    'name' => 'data request dispatcher',
    'weight' => 10,
  );

  return $roles;
}
