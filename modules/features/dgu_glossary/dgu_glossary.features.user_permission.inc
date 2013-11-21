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

  // Exported permission: 'access lexicon'.
  $permissions['access lexicon'] = array(
    'name' => 'access lexicon',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'lexicon',
  );

  // Exported permission: 'create suggested_definition content'.
  $permissions['create suggested_definition content'] = array(
    'name' => 'create suggested_definition content',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create suggested_term content'.
  $permissions['create suggested_term content'] = array(
    'name' => 'create suggested_term content',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any suggested_definition content'.
  $permissions['delete any suggested_definition content'] = array(
    'name' => 'delete any suggested_definition content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any suggested_term content'.
  $permissions['delete any suggested_term content'] = array(
    'name' => 'delete any suggested_term content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in document_type'.
  $permissions['delete terms in document_type'] = array(
    'name' => 'delete terms in document_type',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any suggested_definition content'.
  $permissions['edit any suggested_definition content'] = array(
    'name' => 'edit any suggested_definition content',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any suggested_term content'.
  $permissions['edit any suggested_term content'] = array(
    'name' => 'edit any suggested_term content',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in document_type'.
  $permissions['edit terms in document_type'] = array(
    'name' => 'edit terms in document_type',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'moderate glossary'.
  $permissions['moderate glossary'] = array(
    'name' => 'moderate glossary',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
    ),
    'module' => 'dgu_glossary',
  );

  // Exported permission: 'reset vote up/down votes'.
  $permissions['reset vote up/down votes'] = array(
    'name' => 'reset vote up/down votes',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'unverified user' => 'unverified user',
    ),
    'module' => 'vud',
  );

  // Exported permission: 'suggest new definitions'.
  $permissions['suggest new definitions'] = array(
    'name' => 'suggest new definitions',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'dgu_glossary',
  );

  // Exported permission: 'suggest new terms'.
  $permissions['suggest new terms'] = array(
    'name' => 'suggest new terms',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'dgu_glossary',
  );

  // Exported permission: 'use vote up/down'.
  $permissions['use vote up/down'] = array(
    'name' => 'use vote up/down',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'unverified user' => 'unverified user',
    ),
    'module' => 'vud',
  );

  return $permissions;
}
