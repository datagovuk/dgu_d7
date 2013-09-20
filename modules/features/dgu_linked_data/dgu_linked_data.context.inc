<?php
/**
 * @file
 * dgu_linked_data.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dgu_linked_data_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'linked_data_active_menu';
  $context->description = 'Sets active menu to \'Linked data\' for all pages with linked-data/* path';
  $context->tag = 'Active menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'linked-data/*' => 'linked-data/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'linked-data',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active menu');
  t('Sets active menu to \'Linked data\' for all pages with linked-data/* path');
  $export['linked_data_active_menu'] = $context;

  return $export;
}
