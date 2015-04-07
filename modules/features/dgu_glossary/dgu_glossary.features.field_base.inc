<?php
/**
 * @file
 * dgu_glossary.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function dgu_glossary_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_endorse'
  $field_bases['field_endorse'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_endorse',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'vud_field',
    'settings' => array(
      'votingapi_tag' => 'vote',
      'vud_widget' => 'updown',
    ),
    'translatable' => '0',
    'type' => 'vud_field',
  );

  // Exported field_base: 'field_is_law'
  $field_bases['field_is_law'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_is_law',
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
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_is_new'
  $field_bases['field_is_new'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_is_new',
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
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_quality'
  $field_bases['field_quality'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_quality',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'fivestar',
    'settings' => array(
      'axis' => 'vote',
    ),
    'translatable' => '0',
    'type' => 'fivestar',
  );

  // Exported field_base: 'field_reason_for_change'
  $field_bases['field_reason_for_change'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_reason_for_change',
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

  // Exported field_base: 'field_related_terms'
  $field_bases['field_related_terms'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_related_terms',
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
          'vocabulary' => 'glossary',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => '0',
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_source'
  $field_bases['field_source'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_source',
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
        'Open Data Handbook' => 'Open Data Handbook',
        'A Consultation on Data Policy for a Public Data Corporation - glossary' => 'A Consultation on Data Policy for a Public Data Corporation - glossary',
        'National Archives Information Management Glossary' => 'National Archives Information Management Glossary',
        'Open Data Manual' => 'Open Data Manual',
        'Opening up government - glossary of key terms' => 'Opening up government - glossary of key terms',
        'Open Data White Paper' => 'Open Data White Paper',
        'APPSI definition from Web searches, dictionaries or member proposal' => 'APPSI definition from Web searches, dictionaries or member proposal',
        'Wikipedia (modified by APPSI)' => 'Wikipedia (modified by APPSI)',
        'Wikipedia' => 'Wikipedia',
        'The Big Data Opportunity, Policy Exchange, ISBN: 978-1-907689-22-2, 2012' => 'The Big Data Opportunity, Policy Exchange, ISBN: 978-1-907689-22-2, 2012',
        'HM Treasury Glossary (Managing Public Money)' => 'HM Treasury Glossary (Managing Public Money)',
        'OECD Glossary of Statistical Terms' => 'OECD Glossary of Statistical Terms',
        'EU PSI Directive' => 'EU PSI Directive',
        'Webopedia' => 'Webopedia',
        'Data Protection Act 1998' => 'Data Protection Act 1998',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_text',
  );

  // Exported field_base: 'field_source_url'
  $field_bases['field_source_url'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_source_url',
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
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => '0',
    'type' => 'link_field',
  );

  // Exported field_base: 'field_suggested_definition'
  $field_bases['field_suggested_definition'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_suggested_definition',
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

  // Exported field_base: 'field_term'
  $field_bases['field_term'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_term',
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
          'vocabulary' => 'glossary',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => '0',
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_term_name'
  $field_bases['field_term_name'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_term_name',
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

  return $field_bases;
}
