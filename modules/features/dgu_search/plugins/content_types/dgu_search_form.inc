<?php

if (module_exists('apachesolr_search')) {
  $plugin = array(
    'single' => TRUE,
    'title' => t('DGU Search form'),
    'description' => t('Sorl search form which includes the number of documents in the index/facet.'),
    'icon' => 'icon_search.png',
    'category' => t('Apache Solr Search'),
    'defaults' => array(
      'title_override' => FALSE,
      'title_override_text' => '',
      'content_type' => '',
    ),
  );
}

/**
 * Delegated implementation of hook_theme().
 */
function dgu_search_form_theme(&$theme) {
  $theme['dgu_search_form'] = array(
    'path' => drupal_get_path('module', 'dgu_search') . '/templates',
    'template' => 'dgu_search_form',
    'arguments' => array('form' => NULL, 'count' => NULL, 'content_type' => NULL),
    'render element' => 'form'
  );
}

/**
 * Execute the search and render results.
 */
function dgu_search_dgu_search_form_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module  = 'apachesolr_panels';
  $block->delta   = 'dgu_search_form';
  $block->title   = '';

  $search_types = array(
    'app' => t('Apps'),
    'blog' => t('Blogs'),
    'forum' => t('Forum Posts'),
    'resource' => t('Library'),
    'dataset_request'  => t('Dataset Requests'),
  );


  $form_state = array();
  //do a solr search
  $solr = apachesolr_get_solr(variable_get('apachesolr_default_environment', 'solr'));

  $params = array(
    'rows' => 0,
    'qt' => 'standard',
    'start' => 0,
  );
  if ($conf['content_type'] == 'all') {
    $form_state['content_type'] = "Documents";
    $form_state['searchtype'] = '';
    $params['q'] = "*:*";
  } else {
    $form_state['content_type'] = $search_types[$conf['content_type']];
    $form_state['searchtype'] = $conf['content_type'];
    $params['q'] = "bundle:".$conf['content_type'];
  }
  try {
    $query = new SolrBaseQuery('apachesolr', $solr, $params, '', '');
    list($final_query, $response) = apachesolr_do_query($query);
    if (isset($response->code) && ($response->code == 200) && isset($response->response->numFound)) {
      $form_state['count'] = $response->response->numFound;
    }
  } catch (Exception $e) {
    error_log("Exception occurred talking to solr: ".$e->getMessage());
  }

  $form = drupal_build_form('dgu_search_form', $form_state);
  $block->content = drupal_render($form);
  return $block;
}



/**
 * Empty form so we can have the default override title.
 */
function dgu_search_dgu_search_form_content_type_edit_form($form, &$form_state) {
  $config = $form_state['conf'];
  $form['content_type'] = array(
    //'#prefix' => '<div class="container-inline">',
    '#type' => 'select',
    '#title' => t('Content Type to search for'),
    '#options' => array(
      'all' => t('All'),
      'app' => t('Apps'),
      'blog' => t('Blogs'),
      'forum' => t('Forum Posts'),
      'resource' => t('Library'),
      'dataset_request'  => t('Dataset Requests'),
    ),
    '#default_value' => $config['content_type'],
  );

  return $form;
}

function dgu_search_dgu_search_form_content_type_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

