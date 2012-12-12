<?php

/**
 * @file
 * Providing extra functionality for the CKAN Package UI via views.
 */


/**
 * Implements hook_views_data()
 */
function ckan_package_views_data_alter(&$data) { 
  $data['ckan_package']['link_ckan_package'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the CKAN Package.'),
      'handler' => 'ckan_package_handler_link_field',
    ),
  );
  $data['ckan_package']['edit_ckan_package'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the CKAN Package.'),
      'handler' => 'ckan_package_handler_edit_link_field',
    ),
  );
  $data['ckan_package']['delete_ckan_package'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the CKAN Package.'),
      'handler' => 'ckan_package_handler_delete_link_field',
    ),
  );
  $data['ckan_package']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this CKAN Package.'),
      'handler' => 'ckan_package_handler_ckan_package_operations_field',
    ),
  );
}


/**
 * Implements hook_views_default_views().
 */
function ckan_package_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'ckan_package';
  $view->description = 'A list of all CKAN Packages';
  $view->tag = 'ckan_package';
  $view->base_table = 'ckan_package';
  $view->human_name = 'CKAN Packages';
  $view->core = 7;
  $view->api_version = '3';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CKAN Packages';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any CKAN Package type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'ckan_id' => 'ckan_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'ckan_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No CKAN Packages have been created yet';
  /* Field: CKAN Package: CKAN ID */
  $handler->display->display_options['fields']['ckan_id']['id'] = 'ckan_id';
  $handler->display->display_options['fields']['ckan_id']['table'] = 'ckan_package';
  $handler->display->display_options['fields']['ckan_id']['field'] = 'ckan_id';
  $handler->display->display_options['fields']['ckan_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ckan_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ckan_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ckan_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ckan_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ckan_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ckan_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ckan_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ckan_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ckan_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ckan_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ckan_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['ckan_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ckan_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ckan_id']['empty_zero'] = 0;
  /* Field: CKAN Package: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'ckan_package';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  /* Field: CKAN Package: Link */
  $handler->display->display_options['fields']['link_ckan_package']['id'] = 'link_ckan_package';
  $handler->display->display_options['fields']['link_ckan_package']['table'] = 'ckan_package';
  $handler->display->display_options['fields']['link_ckan_package']['field'] = 'link_ckan_package';
  $handler->display->display_options['fields']['link_ckan_package']['label'] = 'View';
  $handler->display->display_options['fields']['link_ckan_package']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_ckan_package']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_ckan_package']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_ckan_package']['empty_zero'] = 0;
  /* Field: CKAN Package: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'ckan_package';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'ckan_package_admin_page');
  $handler->display->display_options['path'] = 'admin/content/ckan_packages/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'CKAN Package';
  $handler->display->display_options['tab_options']['description'] = 'Manage CKAN Package';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['ckan_package'] = array(
    t('Master'),
    t('CKAN Package'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Empty '),
    t('No CKAN Packages have been created yet'),
    t('CKAN ID'),
    t('.'),
    t(','),
    t('Name'),
    t('View'),
    t('Operations links'),
    t('Page'),
  );
  $views[] = $view;
  return $views;

}
