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

  // Exported role: Glossary moderator.
  $roles['Glossary moderator'] = array(
    'name' => 'Glossary moderator',
    'weight' => '3',
  );

  return $roles;
}
