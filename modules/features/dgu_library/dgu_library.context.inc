<?php
/**
 * @file
 * dgu_library.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dgu_library_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'library_active_menu';
  $context->description = 'Sets active menu to \'Library\' for resource node types';
  $context->tag = 'Active menu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'resource' => 'resource',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'library',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active menu');
  t('Sets active menu to \'Library\' for resource node types');
  $export['library_active_menu'] = $context;

  return $export;
}
