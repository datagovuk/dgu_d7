<?php
/**
 * @file
 * dgu_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dgu_blog_taxonomy_default_vocabularies() {
  return array(
    'blog' => array(
      'name' => 'Blog',
      'machine_name' => 'blog',
      'description' => 'Blog names',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'category' => array(
      'name' => 'Categories',
      'machine_name' => 'category',
      'description' => NULL,
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'sector' => array(
      'name' => 'Sectors',
      'machine_name' => 'sector',
      'description' => NULL,
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => NULL,
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
