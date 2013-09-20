<?php
/**
 * @file
 * dgu_location.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dgu_location_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'location_active_menu';
  $context->description = 'Sets active menu to \'Location\' for all pages with location/* path';
  $context->tag = 'Active menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'location/*' => 'location/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'location',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active menu');
  t('Sets active menu to \'Location\' for all pages with location/* path');
  $export['location_active_menu'] = $context;

  return $export;
}
