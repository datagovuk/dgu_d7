<?php
/**
 * @file
 * dgu_glossary.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dgu_glossary_user_default_roles() {
  $roles = array();

  // Exported role: glossary moderator.
  $roles['glossary moderator'] = array(
    'name' => 'glossary moderator',
    'weight' => 3,
  );

  return $roles;
}
