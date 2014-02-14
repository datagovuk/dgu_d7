<?php
/**
 * @file
 * dgu_flags.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dgu_flags_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag spam_node'.
  $permissions['flag spam_node'] = array(
    'name' => 'flag spam_node',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'ckan adminstrator' => 'ckan adminstrator',
      'data publisher' => 'data publisher',
      'moderator' => 'moderator',
      'unverified user' => 'unverified user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag spam_reply'.
  $permissions['flag spam_reply'] = array(
    'name' => 'flag spam_reply',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'ckan adminstrator' => 'ckan adminstrator',
      'data publisher' => 'data publisher',
      'moderator' => 'moderator',
      'unverified user' => 'unverified user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag spam_node'.
  $permissions['unflag spam_node'] = array(
    'name' => 'unflag spam_node',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'ckan adminstrator' => 'ckan adminstrator',
      'data publisher' => 'data publisher',
      'moderator' => 'moderator',
      'unverified user' => 'unverified user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag spam_reply'.
  $permissions['unflag spam_reply'] = array(
    'name' => 'unflag spam_reply',
    'roles' => array(
      'Glossary moderator' => 'Glossary moderator',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'ckan adminstrator' => 'ckan adminstrator',
      'data publisher' => 'data publisher',
      'moderator' => 'moderator',
      'unverified user' => 'unverified user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
