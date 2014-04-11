<?php
/**
 * @file
 * dgu_glossary.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dgu_glossary_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'glossary_active_menu';
  $context->description = '';
  $context->tag = 'Active menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'glossary/*' => 'glossary/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'glossary',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active menu');
  $export['glossary_active_menu'] = $context;

  return $export;
}
