<?php

/**
 * @file
 * Providing extra functionality for the CKAN Dataset UI via views.
 */

/**
 * Implements hook_views_data()
 */
function ckan_dataset_views_data_alter(&$data) {
  $a=1;
  $data['ckan_dataset']['link_ckan_dataset'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the CKAN Dataset.'),
          'handler' => 'ckan_dataset_handler_link_field',
      ),
  );
  $data['ckan_dataset']['created']['field']['handler'] = 'ckan_dataset_handler_timestamp_field';
  $data['ckan_dataset']['changed']['field']['handler'] = 'ckan_dataset_handler_timestamp_field';

}

/**
 * Implements hook_views_default_views().
 */
function ckan_dataset_views_default_views() {

  $views = array();

  $view = new view();
  $view->name = 'ckan_datasets';
  $view->description = 'A list of all CKAN Datasets';
  $view->tag = 'ckan_dataset';
  $view->base_table = 'ckan_dataset';
  $view->human_name = 'CKAN Datasets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Datasets';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any CKAN Dataset type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'ckan_id' => 'ckan_id',
    'name' => 'name',
    'changed' => 'changed',
    'created' => 'created',
    'link_ckan_dataset' => 'link_ckan_dataset',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ckan_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_ckan_dataset' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['content'] = 'No Datasets have been created yet';
  /* Field: Dataset: Dataset ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'ckan_dataset';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['separator'] = '.';
  /* Field: Dataset: Ckan_id */
  $handler->display->display_options['fields']['ckan_id']['id'] = 'ckan_id';
  $handler->display->display_options['fields']['ckan_id']['table'] = 'ckan_dataset';
  $handler->display->display_options['fields']['ckan_id']['field'] = 'ckan_id';
  /* Field: Dataset: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ckan_dataset';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Dataset: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'ckan_dataset';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  /* Field: Dataset: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ckan_dataset';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  /* Field: Dataset: Link */
  $handler->display->display_options['fields']['link_ckan_dataset']['id'] = 'link_ckan_dataset';
  $handler->display->display_options['fields']['link_ckan_dataset']['table'] = 'ckan_dataset';
  $handler->display->display_options['fields']['link_ckan_dataset']['field'] = 'link_ckan_dataset';
  $handler->display->display_options['fields']['link_ckan_dataset']['label'] = 'View';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'ckan_dataset_admin_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/ckan_datasets/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Datasets';
  $handler->display->display_options['tab_options']['description'] = 'Manage Datasets';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  $views[$view->name] = $view;
  return $views;
}
