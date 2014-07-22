<?php
/**
 * @file
 * dgu_reply.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dgu_reply_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_comment'
  $field_bases['field_comment'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_comment',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'reply',
    'settings' => array(
      'access' => '-1',
      'allow_reply' => '-1',
      'bundle' => 'comment',
      'display' => '-1',
      'form' => '-1',
    ),
    'translatable' => '0',
    'type' => 'reply',
  );

  // Exported field_base: 'field_reply_comment'
  $field_bases['field_reply_comment'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_reply_comment',
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

  // Exported field_base: 'field_reply_subject'
  $field_bases['field_reply_subject'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_reply_subject',
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
      'max_length' => 60,
    ),
    'translatable' => '0',
    'type' => 'text',
  );

  // Exported field_base: 'field_review_comment'
  $field_bases['field_review_comment'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_review_comment',
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

  return $field_bases;
}
