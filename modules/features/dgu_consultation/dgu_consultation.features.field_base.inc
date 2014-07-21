<?php
/**
 * @file
 * dgu_consultation.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dgu_consultation_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_field_comments'
  $field_bases['field_field_comments'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_field_comments',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'reply',
    'settings' => array(
      'access' => -1,
      'allow_reply' => -1,
      'bundle' => 'field_comment',
      'display' => -1,
      'form' => -1,
    ),
    'translatable' => '0',
    'type' => 'reply',
  );

  // Exported field_base: 'field_paragraph'
  $field_bases['field_paragraph'] = array(
    'active' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_paragraph',
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
