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

  // Exported permission: 'flag dataset'.
  $permissions['flag dataset'] = array(
    'name' => 'flag dataset',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag spam_node'.
  $permissions['flag spam_node'] = array(
    'name' => 'flag spam_node',
    'roles' => array(
      'CKAN sysadmin' => 'CKAN sysadmin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'data publisher' => 'data publisher',
      'glossary moderator' => 'glossary moderator',
      'moderator' => 'moderator',
      'unverified user' => 'unverified user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag spam_reply'.
  $permissions['flag spam_reply'] = array(
    'name' => 'flag spam_reply',
    'roles' => array(
      'CKAN sysadmin' => 'CKAN sysadmin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'data publisher' => 'data publisher',
      'glossary moderator' => 'glossary moderator',
      'moderator' => 'moderator',
      'unverified user' => 'unverified user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag subscribe_node'.
  $permissions['flag subscribe_node'] = array(
    'name' => 'flag subscribe_node',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'data publisher' => 'data publisher',
      'data request administrator' => 'data request administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag dataset'.
  $permissions['unflag dataset'] = array(
    'name' => 'unflag dataset',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag spam_node'.
  $permissions['unflag spam_node'] = array(
    'name' => 'unflag spam_node',
    'roles' => array(
      'CKAN sysadmin' => 'CKAN sysadmin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'data publisher' => 'data publisher',
      'glossary moderator' => 'glossary moderator',
      'moderator' => 'moderator',
      'unverified user' => 'unverified user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag spam_reply'.
  $permissions['unflag spam_reply'] = array(
    'name' => 'unflag spam_reply',
    'roles' => array(
      'CKAN sysadmin' => 'CKAN sysadmin',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'data publisher' => 'data publisher',
      'glossary moderator' => 'glossary moderator',
      'moderator' => 'moderator',
      'unverified user' => 'unverified user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag subscribe_node'.
  $permissions['unflag subscribe_node'] = array(
    'name' => 'unflag subscribe_node',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'data publisher' => 'data publisher',
      'data request administrator' => 'data request administrator',
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
