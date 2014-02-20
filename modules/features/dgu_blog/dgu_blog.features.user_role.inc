<?php
/**
 * @file
 * dgu_blog.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dgu_blog_user_default_roles() {
  $roles = array();

  // Exported role: blog moderator.
  $roles['blog moderator'] = array(
    'name' => 'blog moderator',
    'weight' => 9,
  );

  return $roles;
}
