<?php
/**
 * @file
 * dgu_app.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dgu_app_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'app_active_menu';
  $context->description = 'Sets active menu to \'Apps\' for app node types';
  $context->tag = 'Active menu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'app' => 'app',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'apps',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active menu');
  t('Sets active menu to \'Apps\' for app node types');
  $export['app_active_menu'] = $context;

  return $export;
}
