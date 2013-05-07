<?php
/**
 * @file
 * dgu_glossary.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgu_glossary_user_default_permissions() {
  $permissions = array();

  // Exported permission: access lexicon.
  $permissions['access lexicon'] = array(
    'name' => 'access lexicon',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'lexicon',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: create suggested_definition content.
  $permissions['create suggested_definition content'] = array(
    'name' => 'create suggested_definition content',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: create suggested_term content.
  $permissions['create suggested_term content'] = array(
    'name' => 'create suggested_term content',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any suggested_definition content.
  $permissions['delete any suggested_definition content'] = array(
    'name' => 'delete any suggested_definition content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete any suggested_term content.
  $permissions['delete any suggested_term content'] = array(
    'name' => 'delete any suggested_term content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'Glossary moderator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit any suggested_definition content.
  $permissions['edit any suggested_definition content'] = array(
    'name' => 'edit any suggested_definition content',
    'roles' => array(
      0 => 'Glossary moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any suggested_term content.
  $permissions['edit any suggested_term content'] = array(
    'name' => 'edit any suggested_term content',
    'roles' => array(
      0 => 'Glossary moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'Glossary moderator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: moderate content from needs_review to published.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: moderate glossary.
  $permissions['moderate glossary'] = array(
    'name' => 'moderate glossary',
    'roles' => array(
      0 => 'Glossary moderator',
    ),
    'module' => 'dgu_glossary',
  );

  // Exported permission: suggest new definitions.
  $permissions['suggest new definitions'] = array(
    'name' => 'suggest new definitions',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'authenticated user',
    ),
    'module' => 'dgu_glossary',
  );

  // Exported permission: suggest new terms.
  $permissions['suggest new terms'] = array(
    'name' => 'suggest new terms',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'dgu_glossary',
  );

  // Exported permission: use vote up/down.
  $permissions['use vote up/down'] = array(
    'name' => 'use vote up/down',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
    ),
    'module' => 'vud',
  );

  // Exported permission: use workbench_moderation needs review tab.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view all unpublished content.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view moderation history.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view moderation messages.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'Glossary moderator',
      1 => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
