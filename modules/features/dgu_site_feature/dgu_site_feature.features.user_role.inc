<?php
/**
 * @file
 * dgu_site_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dgu_site_feature_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => '11',
  );

  return $roles;
}
