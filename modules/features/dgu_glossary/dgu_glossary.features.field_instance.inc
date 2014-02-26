<?php
/**
 * @file
 * dgu_glossary.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dgu_glossary_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-suggested_definition-field_comment'
  $field_instances['node-suggested_definition-field_comment'] = array(
    'bundle' => 'suggested_definition',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'reply',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'reply_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_comment',
    'label' => 'Comments',
    'required' => 0,
    'settings' => array(
      'access' => -1,
      'allow_reply' => -1,
      'display' => -1,
      'form' => -1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'reply',
      'settings' => array(),
      'type' => 'reply',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-suggested_definition-field_reason_for_change'
  $field_instances['node-suggested_definition-field_reason_for_change'] = array(
    'bundle' => 'suggested_definition',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Briefly describe why you have suggested this change.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_reason_for_change',
    'label' => 'Reason for change',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-suggested_definition-field_suggested_definition'
  $field_instances['node-suggested_definition-field_suggested_definition'] = array(
    'bundle' => 'suggested_definition',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_comments' => '',
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suggested_definition',
    'label' => 'suggested definition',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-suggested_definition-field_term'
  $field_instances['node-suggested_definition-field_term'] = array(
    'bundle' => 'suggested_definition',
    'default_value' => array(
      0 => array(
        'tid' => 8,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'field_comments' => '',
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term',
    'label' => 'Term',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-suggested_term-field_reason_for_change'
  $field_instances['node-suggested_term-field_reason_for_change'] = array(
    'bundle' => 'suggested_term',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Briefly describe why you have suggested this change. If this term comes from an accredited glossary, you should cite it here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_reason_for_change',
    'label' => 'Reason for change',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-suggested_term-field_suggested_definition'
  $field_instances['node-suggested_term-field_suggested_definition'] = array(
    'bundle' => 'suggested_term',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_comments' => '',
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suggested_definition',
    'label' => 'suggested definition',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-suggested_term-field_term_name'
  $field_instances['node-suggested_term-field_term_name'] = array(
    'bundle' => 'suggested_term',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_comments' => '',
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term_name',
    'label' => 'Term name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'taxonomy_term-glossary-field_comment'
  $field_instances['taxonomy_term-glossary-field_comment'] = array(
    'bundle' => 'glossary',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'reply',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'reply_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_comment',
    'label' => 'Comments',
    'required' => 0,
    'settings' => array(
      'access' => -1,
      'allow_reply' => -1,
      'display' => -1,
      'form' => -1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'reply',
      'settings' => array(),
      'type' => 'reply',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'taxonomy_term-glossary-field_endorse'
  $field_instances['taxonomy_term-glossary-field_endorse'] = array(
    'bundle' => 'glossary',
    'default_value' => array(
      0 => array(
        'vud_widget' => 'updown',
        'votingapi_tag' => 'vote',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'vud_field',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_endorse',
    'label' => 'endorse',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'votingapi_tag' => 'vote',
      'vud_widget' => 'endorse',
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'vud_field',
      'settings' => array(),
      'type' => 'vud_field_default_widget',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'taxonomy_term-glossary-field_is_new'
  $field_instances['taxonomy_term-glossary-field_is_new'] = array(
    'bundle' => 'glossary',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_is_new',
    'label' => 'is_new',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'taxonomy_term-glossary-field_quality'
  $field_instances['taxonomy_term-glossary-field_quality'] = array(
    'bundle' => 'glossary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'fivestar',
        'settings' => array(
          'expose' => TRUE,
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
          'style' => 'average',
          'text' => 'average',
          'widget' => array(
            'fivestar_widget' => NULL,
          ),
        ),
        'type' => 'fivestar_formatter_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_quality',
    'label' => 'Quality',
    'required' => 0,
    'settings' => array(
      'allow_clear' => 0,
      'stars' => 5,
      'target' => 'none',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'fivestar',
      'settings' => array(
        'widget' => array(
          'fivestar_widget' => 'default',
        ),
      ),
      'type' => 'stars',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'taxonomy_term-glossary-field_related_terms'
  $field_instances['taxonomy_term-glossary-field_related_terms'] = array(
    'bundle' => 'glossary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_related_terms',
    'label' => 'related terms',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'taxonomy_term-glossary-field_source'
  $field_instances['taxonomy_term-glossary-field_source'] = array(
    'bundle' => 'glossary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_source',
    'label' => 'source',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'taxonomy_term-glossary-field_source_url'
  $field_instances['taxonomy_term-glossary-field_source_url'] = array(
    'bundle' => 'glossary',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'link_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_source_url',
    'label' => 'source_url',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Briefly describe why you have suggested this change.');
  t('Briefly describe why you have suggested this change. If this term comes from an accredited glossary, you should cite it here.');
  t('Comments');
  t('Quality');
  t('Reason for change');
  t('Term');
  t('Term name');
  t('endorse');
  t('is_new');
  t('related terms');
  t('source');
  t('source_url');
  t('suggested definition');

  return $field_instances;
}
