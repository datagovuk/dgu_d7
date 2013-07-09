<?php
/**
 * @file
 * dgu_glossary.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function dgu_glossary_filter_default_formats() {
  $formats = array();

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 0,
    'status' => 1,
    'weight' => 10,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_lexicon' => array(
        'weight' => 50,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
