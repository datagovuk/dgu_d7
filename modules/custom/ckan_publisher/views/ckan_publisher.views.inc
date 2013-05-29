<?php

/**
 * @file
 * Providing extra functionality for the CKAN Publisher UI via views.
 */

/**
 * Implements hook_views_data()
 */
function ckan_publisher_views_data_alter(&$data) {
  $data['ckan_publisher']['link_ckan_publisher'] = array(
      'field' => array(
          'title' => t('Link'),
          'help' => t('Provide a link to the CKAN Publisher.'),
          'handler' => 'ckan_publisher_handler_link_field',
      ),
  );
  $data['ckan_publisher']['created']['field']['handler'] = 'ckan_publisher_handler_timestamp_field';

}

/**
 * Implements hook_views_default_views().
 */
function ckan_publisher_views_default_views() {

  $views = array();

  $view = new view();
  $view->name = 'ckan_publishers';
  $view->description = 'A list of all CKAN Publishers';
  $view->tag = 'ckan_publisher';
  $view->base_table = 'ckan_publisher';
  $view->human_name = 'CKAN Publishers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Publishers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any CKAN Publisher type';
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
    'created' => 'created',
    'link_ckan_publisher' => 'link_ckan_publisher',
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_ckan_publisher' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No Publishers have been created yet';
  /* Field: Publisher: Publisher ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'ckan_publisher';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['separator'] = '.';
  /* Field: Publisher: Ckan_id */
  $handler->display->display_options['fields']['ckan_id']['id'] = 'ckan_id';
  $handler->display->display_options['fields']['ckan_id']['table'] = 'ckan_publisher';
  $handler->display->display_options['fields']['ckan_id']['field'] = 'ckan_id';
  /* Field: Publisher: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ckan_publisher';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Publisher: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'ckan_publisher';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  /* Field: Publisher: Link */
  $handler->display->display_options['fields']['link_ckan_publisher']['id'] = 'link_ckan_publisher';
  $handler->display->display_options['fields']['link_ckan_publisher']['table'] = 'ckan_publisher';
  $handler->display->display_options['fields']['link_ckan_publisher']['field'] = 'link_ckan_publisher';
  $handler->display->display_options['fields']['link_ckan_publisher']['label'] = 'View';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'ckan_publisher_admin_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/ckan_publishers/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Publishers';
  $handler->display->display_options['tab_options']['description'] = 'Manage Publishers';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  $views[$view->name] = $view;
  return $views;
}
