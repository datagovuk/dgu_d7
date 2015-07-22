<?php
/**
 * @file
 * dgu_shared_fields.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dgu_shared_fields_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'
  $field_bases['body'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => '0',
    'module' => 'text',
    'settings' => array(),
    'translatable' => '0',
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_category'
  $field_bases['field_category'] = array(
    'active' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_category',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => '0',
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'category',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => '0',
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_message_rendered_body'
  $field_bases['field_message_rendered_body'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_message_rendered_body',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => '0',
    'module' => 'text',
    'settings' => array(),
    'translatable' => '0',
    'type' => 'text_long',
  );

  // Exported field_base: 'field_message_rendered_subject'
  $field_bases['field_message_rendered_subject'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_message_rendered_subject',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => '0',
    'module' => 'text',
    'settings' => array(
      'max_length' => '255',
    ),
    'translatable' => '0',
    'type' => 'text',
  );

  // Exported field_base: 'field_node_reference'
  $field_bases['field_node_reference'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_node_reference',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => '0',
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'app' => 'app',
          'article' => 'article',
          'blog' => 'blog',
          'book' => 'book',
          'dataset_request' => 'dataset_request',
          'forum' => 'forum',
          'page' => 'page',
          'resource' => 'resource',
          'suggested_definition' => 'suggested_definition',
          'suggested_term' => 'suggested_term',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => '0',
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_sector'
  $field_bases['field_sector'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_sector',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => '0',
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'sector',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => '0',
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_submitter_email'
  $field_bases['field_submitter_email'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_submitter_email',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'email',
    'settings' => array(),
    'translatable' => '0',
    'type' => 'email',
  );

  // Exported field_base: 'field_submitter_name'
  $field_bases['field_submitter_name'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_submitter_name',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => '0',
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => '0',
    'type' => 'text',
  );

  // Exported field_base: 'field_tags'
  $field_bases['field_tags'] = array(
    'active' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_tags',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => '0',
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'tags',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => '0',
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_uses_dataset'
  $field_bases['field_uses_dataset'] = array(
    'active' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_uses_dataset',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(
      'ckan_dataset' => array(
        'columns' => array(
          'target_id' => 'id',
        ),
        'table' => 'ckan_dataset',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => '0',
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(),
      ),
      'target_type' => 'ckan_dataset',
    ),
    'translatable' => '0',
    'type' => 'entityreference',
  );

  return $field_bases;
}
