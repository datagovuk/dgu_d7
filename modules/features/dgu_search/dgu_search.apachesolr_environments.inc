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
  $environment->name = 'solr';
  $environment->url = 'http://localhost:8983/solr/dgu_drupal';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_access_always_add_grants' => 0,
    'apachesolr_index_last' => array(
      'ckan_dataset' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'ckan_publisher' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'fieldable_panels_pane' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'flagging' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
      ),
      'node' => array(
        'last_changed' => '1390383020',
        'last_entity_id' => '2902',
      ),
      'redirect' => array(
        'last_changed' => 0,
        'last_entity_id' => 0,
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
    'apachesolr_index_updated' => 1390827730,
    'apachesolr_last_optimize' => 1390753338,
    'apachesolr_read_only' => '0',
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'app',
      1 => 'article',
      2 => 'blog',
      3 => 'dataset_request',
      4 => 'forum',
      5 => 'page',
      6 => 'resource',
    ),
  );
  $export['solr'] = $environment;

  return $export;
}
