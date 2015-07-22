<?php
/**
 * @file
 * dgu_data_set_request.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dgu_data_set_request_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_assignee'
  $field_bases['field_assignee'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_assignee',
    'field_permissions' => array(
      'type' => '2',
    ),
    'foreign keys' => array(
      'uid' => array(
        'columns' => array(
          'uid' => 'uid',
        ),
        'table' => 'users',
      ),
    ),
    'indexes' => array(
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'locked' => '0',
    'module' => 'dgu_assignee',
    'settings' => array(
      'example_textfield' => 'some text',
    ),
    'translatable' => '0',
    'type' => 'assignee',
  );

  // Exported field_base: 'field_barriers_attempted'
  $field_bases['field_barriers_attempted'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_barriers_attempted',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_barriers_detail'
  $field_bases['field_barriers_detail'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_barriers_detail',
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

  // Exported field_base: 'field_barriers_reason'
  $field_bases['field_barriers_reason'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_barriers_reason',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'The data is supposed to be published but the download links don’t work',
        2 => 'The data is available but the licensing terms are too restrictive',
        3 => 'There are financial charges for the data',
        4 => 'The data is subject to restrictions because of commercial confidentiality',
        5 => 'The data is subject to restrictions because of personal confidentiality',
        6 => 'The data is published but not in a format I can download and use (e.g. only displayed onscreen or only downloadable as a PDF rather than CVS)',
        7 => 'The data is not up-to-date',
        8 => 'A version of the data is published but I need it in a different version',
        9 => 'Other',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_benefits_overview'
  $field_bases['field_benefits_overview'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_benefits_overview',
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

  // Exported field_base: 'field_data_holder'
  $field_bases['field_data_holder'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_data_holder',
    'field_permissions' => array(
      'type' => 0,
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
      'max_length' => 255,
    ),
    'translatable' => '0',
    'type' => 'text',
  );

  // Exported field_base: 'field_data_request_assignee'
  $field_bases['field_data_request_assignee'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_data_request_assignee',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'users' => array(
        'columns' => array(
          'target_id' => 'uid',
        ),
        'table' => 'users',
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
      'target_type' => 'user',
    ),
    'translatable' => '0',
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_data_request_reference'
  $field_bases['field_data_request_reference'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_data_request_reference',
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
          'dataset_request' => 'dataset_request',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => '0',
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_data_set_description'
  $field_bases['field_data_set_description'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_data_set_description',
    'field_permissions' => array(
      'type' => 0,
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

  // Exported field_base: 'field_data_set_link'
  $field_bases['field_data_set_link'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_data_set_link',
    'field_permissions' => array(
      'type' => '2',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => '1',
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => '0',
    'type' => 'link_field',
  );

  // Exported field_base: 'field_data_themes'
  $field_bases['field_data_themes'] = array(
    'active' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_data_themes',
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

  // Exported field_base: 'field_data_use'
  $field_bases['field_data_use'] = array(
    'active' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_data_use',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Business Use',
        2 => 'Personal Use',
        3 => 'Community Work',
        4 => 'Research',
        5 => 'Other',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_data_use_detail'
  $field_bases['field_data_use_detail'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_data_use_detail',
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

  // Exported field_base: 'field_estimates_detail'
  $field_bases['field_estimates_detail'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_estimates_detail',
    'field_permissions' => array(
      'type' => 0,
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

  // Exported field_base: 'field_organisation_name'
  $field_bases['field_organisation_name'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_organisation_name',
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
      'max_length' => 255,
    ),
    'translatable' => '0',
    'type' => 'text',
  );

  // Exported field_base: 'field_organisation_type'
  $field_bases['field_organisation_type'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_organisation_type',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        2 => 'Start up',
        3 => 'Small to Medium Business',
        4 => 'Large Company (Over 250 employees)',
        5 => 'Voluntary sector or not-for-profit organisation',
        6 => 'Public Sector Organisation',
        7 => 'Academic or Research',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_provide_estimates'
  $field_bases['field_provide_estimates'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_provide_estimates',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_publication_preference'
  $field_bases['field_publication_preference'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_publication_preference',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'Request is public',
        0 => 'I would like my entire request to remain confidential',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_publisher_ref'
  $field_bases['field_publisher_ref'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_publisher_ref',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'id' => array(
        'columns' => array(
          'id' => 'id',
        ),
        'table' => 'ckan_publisher',
      ),
    ),
    'indexes' => array(
      'id' => array(
        0 => 'id',
      ),
    ),
    'locked' => '0',
    'module' => 'ckan_publisher_tree',
    'settings' => array(),
    'translatable' => '0',
    'type' => 'ckan_publisher_reference',
  );

  // Exported field_base: 'field_reply_reference'
  $field_bases['field_reply_reference'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_reply_reference',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(
      'reply' => array(
        'columns' => array(
          'target_id' => 'id',
        ),
        'table' => 'reply',
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
          'comment' => 'comment',
          'review_comment' => 'review_comment',
        ),
      ),
      'target_type' => 'reply',
    ),
    'translatable' => '0',
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_review_comments'
  $field_bases['field_review_comments'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_review_comments',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'reply',
    'settings' => array(
      'access' => '-1',
      'allow_reply' => '-1',
      'bundle' => 'review_comment',
      'display' => '-1',
      'form' => '-1',
    ),
    'translatable' => '0',
    'type' => 'reply',
  );

  // Exported field_base: 'field_review_notes'
  $field_bases['field_review_notes'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_review_notes',
    'field_permissions' => array(
      'type' => 2,
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

  // Exported field_base: 'field_review_outcome'
  $field_bases['field_review_outcome'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_review_outcome',
    'field_permissions' => array(
      'type' => '2',
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'New dataset released',
        1 => 'Data cannot be released',
        2 => 'Data already available',
        3 => 'Not a data request or a data issue',
        4 => 'Technical issue resolved',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_review_status'
  $field_bases['field_review_status'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_review_status',
    'field_permissions' => array(
      'type' => '2',
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'New',
        1 => 'Escalated to data holder',
        2 => 'Queried by data holder',
        3 => 'ODUG developing business case',
        4 => 'Scheduled for release',
        5 => 'Postponed',
        6 => 'Closed',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_integer',
  );

  // Exported field_base: 'field_submitter_type'
  $field_bases['field_submitter_type'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_submitter_type',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        1 => 'As a private individual',
        2 => 'On behalf of an Organisation',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_integer',
  );

  return $field_bases;
}
