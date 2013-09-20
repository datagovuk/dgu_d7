<?php
/**
 * @file
 * dgu_site_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dgu_site_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'about_active_menu';
  $context->description = 'Sets active menu to \'About\' for all pages with about/* path';
  $context->tag = 'Active menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about/*' => 'about/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'about',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active menu');
  t('Sets active menu to \'About\' for all pages with about/* path');
  $export['about_active_menu'] = $context;

  return $export;
}
