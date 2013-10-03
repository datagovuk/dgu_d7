<?php
/**
 * @file
 * dgu_forum.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dgu_forum_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'forum_active_menu';
  $context->description = 'Sets active menu to \'Forum\' for forum node types';
  $context->tag = 'Active menu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'forum' => 'forum',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'forum/*' => 'forum/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'forum',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active menu');
  t('Sets active menu to \'Forum\' for forum node types');
  $export['forum_active_menu'] = $context;

  return $export;
}
