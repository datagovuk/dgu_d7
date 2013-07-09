<?php
/**
 * @file
 * dgu_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dgu_user_user_default_roles() {
  $roles = array();

  // Exported role: data publisher.
  $roles['data publisher'] = array(
    'name' => 'data publisher',
    'weight' => 4,
  );

  // Exported role: moderator.
  $roles['moderator'] = array(
    'name' => 'moderator',
    'weight' => 3,
  );

  // Exported role: unverified user.
  $roles['unverified user'] = array(
    'name' => 'unverified user',
    'weight' => 3,
  );

  return $roles;
}
