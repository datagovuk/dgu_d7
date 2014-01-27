<?php
/**
 * @file
 * dgu_services.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dgu_services_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dataset_referrers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dataset referrers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uses_dataset_target_id']['id'] = 'field_uses_dataset_target_id';
  $handler->display->display_options['relationships']['field_uses_dataset_target_id']['table'] = 'field_data_field_uses_dataset';
  $handler->display->display_options['relationships']['field_uses_dataset_target_id']['field'] = 'field_uses_dataset_target_id';
  $handler->display->display_options['relationships']['field_uses_dataset_target_id']['required'] = TRUE;
  /* Relationship: Content: Screen shots (field_screen_shots:fid) */
  $handler->display->display_options['relationships']['field_screen_shots_fid']['id'] = 'field_screen_shots_fid';
  $handler->display->display_options['relationships']['field_screen_shots_fid']['table'] = 'field_data_field_screen_shots';
  $handler->display->display_options['relationships']['field_screen_shots_fid']['field'] = 'field_screen_shots_fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Dataset: Ckan_id */
  $handler->display->display_options['fields']['ckan_id']['id'] = 'ckan_id';
  $handler->display->display_options['fields']['ckan_id']['table'] = 'ckan_dataset';
  $handler->display->display_options['fields']['ckan_id']['field'] = 'ckan_id';
  $handler->display->display_options['fields']['ckan_id']['relationship'] = 'field_uses_dataset_target_id';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_screen_shots_fid';
  $handler->display->display_options['fields']['uri']['label'] = 'Thumbnail';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Dataset: Ckan_id */
  $handler->display->display_options['filters']['ckan_id']['id'] = 'ckan_id';
  $handler->display->display_options['filters']['ckan_id']['table'] = 'ckan_dataset';
  $handler->display->display_options['filters']['ckan_id']['field'] = 'ckan_id';
  $handler->display->display_options['filters']['ckan_id']['relationship'] = 'field_uses_dataset_target_id';
  $handler->display->display_options['filters']['ckan_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['ckan_id']['expose']['operator_id'] = 'ckan_id_op';
  $handler->display->display_options['filters']['ckan_id']['expose']['label'] = 'Ckan_id';
  $handler->display->display_options['filters']['ckan_id']['expose']['operator'] = 'ckan_id_op';
  $handler->display->display_options['filters']['ckan_id']['expose']['identifier'] = 'ckan_id';
  $handler->display->display_options['filters']['ckan_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    7 => 0,
    5 => 0,
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'dataset_referrers';
  $export['dataset_referrers'] = $view;

  return $export;
}
