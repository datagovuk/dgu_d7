<?php
/**
 * @file
 * dgu_search.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function dgu_search_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'solr';
  $environment->name = 'localhost server';
  $environment->url = 'http://localhost:8983/solr4/drupal';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_index_last' => array(),
    'apachesolr_read_only' => '0',
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'article',
      1 => 'book',
      2 => 'page',
      3 => 'panel',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
