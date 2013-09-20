<?php
/**
 * @file
 * dgu_data_set_request.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dgu_data_set_request_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'data_requests_active_menu';
  $context->description = 'Sets active menu to \'Data requests\' for data request node types, and /odug path';
  $context->tag = 'Active menu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'dataset_request' => 'dataset_request',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        'odug/*' => 'odug/*',
        'odug-roadmap' => 'odug-roadmap',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'odug',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active menu');
  t('Sets active menu to \'Data requests\' for data request node types, and /odug path');
  $export['data_requests_active_menu'] = $context;

  return $export;
}
