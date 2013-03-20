<?php
/**
 * @file
 * dgu_consultation.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function dgu_consultation_field_default_fields() {
  $fields = array();

  // Exported field: 'node-book-body'.
  $fields['node-book-body'] = array(
    'field_config' => array(
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
    ),
    'field_instance' => array(
      'bundle' => 'book',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'field_replies' => '',
            'field_replies_settings' => array(
              'field_replies_instance' => '',
              'field_replies_revision' => '',
            ),
          ),
          'type' => 'text_default',
          'weight' => '0',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(
            'field_replies' => '',
            'field_replies_settings' => array(
              'field_replies_instance' => '',
              'field_replies_revision' => '',
            ),
            'trim_length' => 600,
          ),
          'type' => 'text_summary_or_trimmed',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => FALSE,
      'settings' => array(
        'display_summary' => TRUE,
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => '-4',
      ),
    ),
  );

  // Exported field: 'node-book-field_field_comments'.
  $fields['node-book-field_field_comments'] = array(
    'field_config' => array(
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
        'access' => '-1',
        'allow_reply' => '-1',
        'bundle' => 'field_comment',
        'display' => '-1',
        'form' => '-1',
      ),
      'translatable' => '0',
      'type' => 'reply',
    ),
    'field_instance' => array(
      'bundle' => 'book',
      'deleted' => '0',
      'description' => 'Reply bundle used for comments on paragraphs, not meant to be displayed itself',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'reply',
          'settings' => array(
            'field_replies' => '',
            'field_replies_settings' => array(
              'field_replies_instance' => '',
              'field_replies_revision' => '',
            ),
          ),
          'type' => 'reply_default',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_field_comments',
      'label' => 'Field comments',
      'required' => 0,
      'settings' => array(
        'access' => '-1',
        'allow_reply' => '-1',
        'display' => '-1',
        'form' => '-1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'reply',
        'settings' => array(),
        'type' => 'reply',
        'weight' => '32',
      ),
    ),
  );

  // Exported field: 'node-book-field_paragraph'.
  $fields['node-book-field_paragraph'] = array(
    'field_config' => array(
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
    ),
    'field_instance' => array(
      'bundle' => 'book',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(
            'field_replies' => 1,
            'field_replies_settings' => array(
              'field_replies_instance' => '57',
              'field_replies_revision' => 0,
            ),
          ),
          'type' => 'text_default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_paragraph',
      'label' => 'Paragraph',
      'required' => 0,
      'settings' => array(
        'text_processing' => '1',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '31',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('Field comments');
  t('Paragraph');
  t('Reply bundle used for comments on paragraphs, not meant to be displayed itself');

  return $fields;
}
