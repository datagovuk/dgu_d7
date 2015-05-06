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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
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

  $view = new view();
  $view->name = 'user_account_operations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'User account operations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Message: Operation */
  $handler->display->display_options['fields']['field_operation']['id'] = 'field_operation';
  $handler->display->display_options['fields']['field_operation']['table'] = 'field_data_field_operation';
  $handler->display->display_options['fields']['field_operation']['field'] = 'field_operation';
  $handler->display->display_options['fields']['field_operation']['label'] = 'operation';
  $handler->display->display_options['fields']['field_operation']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Message: User reference */
  $handler->display->display_options['fields']['field_user_reference']['id'] = 'field_user_reference';
  $handler->display->display_options['fields']['field_user_reference']['table'] = 'field_data_field_user_reference';
  $handler->display->display_options['fields']['field_user_reference']['field'] = 'field_user_reference';
  $handler->display->display_options['fields']['field_user_reference']['label'] = 'uid';
  $handler->display->display_options['fields']['field_user_reference']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_user_reference']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'user_operation' => 'user_operation',
  );
  /* Filter criterion: Message: Timestamp */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'message';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = '>';
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'user_account_operation';
  $export['user_account_operations'] = $view;

  return $export;
}
