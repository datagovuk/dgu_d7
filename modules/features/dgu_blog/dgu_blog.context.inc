<?php
/**
 * @file
 * dgu_blog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function dgu_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog_active_menu';
  $context->description = 'Sets active menu to \'Blogs\' for blog node types';
  $context->tag = 'Active menu';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'blog/*' => 'blog/*',
      ),
    ),
  );
  $context->reactions = array(
    'menu' => 'blog',
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Active menu');
  t('Sets active menu to \'Blogs\' for blog node types');
  $export['blog_active_menu'] = $context;

  return $export;
}
