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

<<<<<<< HEAD
  // Exported role: Glossary moderator.
=======
  // Exported role: glossary moderator.
>>>>>>> af2550bb0204c070d99dc9242ebf0a012bb1cd40
  $roles['glossary moderator'] = array(
    'name' => 'glossary moderator',
    'weight' => 3,
  );

  return $roles;
}
