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
  $environment->url = 'http://localhost:8983/solr';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_index_last' => array(
      'ckan_dataset' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'ckan_publisher' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'node' => array(
        'last_changed' => '1376905767',
        'last_entity_id' => '3372',
      ),
      'reply' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'reply_bundle' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'file' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'taxonomy_term' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'taxonomy_vocabulary' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'user' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'wysiwyg_profile' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'rules_config' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
    ),
    'apachesolr_index_updated' => 1376906795,
    'apachesolr_last_optimize' => 1376822188,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'app',
      1 => 'article',
      2 => 'blog',
      3 => 'book',
      4 => 'dataset_request',
      5 => 'forum',
      6 => 'idea',
      7 => 'organogram',
      8 => 'page',
      9 => 'promo_item',
      10 => 'resource',
      11 => 'suggested_definition',
      12 => 'suggested_term',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
