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

  // Exported role: ckan adminstrator.
  $roles['ckan adminstrator'] = array(
    'name' => 'ckan adminstrator',
    'weight' => 7,
  );

  // Exported role: data publisher.
  $roles['data publisher'] = array(
    'name' => 'data publisher',
    'weight' => 6,
  );

  // Exported role: moderator.
  $roles['moderator'] = array(
    'name' => 'moderator',
    'weight' => 4,
  );

  // Exported role: unverified user.
  $roles['unverified user'] = array(
    'name' => 'unverified user',
    'weight' => 5,
  );

  return $roles;
}
