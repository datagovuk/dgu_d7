<?php
/**
 * @file
 * dgu_site_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dgu_site_feature_taxonomy_default_vocabularies() {
  return array(
    'category' => array(
      'name' => 'Categories',
      'machine_name' => 'category',
      'description' => NULL,
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'document_type' => array(
      'name' => 'Document Types',
      'machine_name' => 'document_type',
      'description' => NULL,
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'nation' => array(
      'name' => 'Nation',
      'machine_name' => 'nation',
      'description' => NULL,
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'public_body' => array(
      'name' => 'Public Body',
      'machine_name' => 'public_body',
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
