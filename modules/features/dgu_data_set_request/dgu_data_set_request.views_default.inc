<?php
/**
 * @file
 * dgu_data_set_request.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dgu_data_set_request_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'data_requests_administration';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Data requests administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Active Data requests';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any dataset_request content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'field_publication_preference' => 'field_publication_preference',
    'field_review_status' => 'field_review_status',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_preference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_review_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Nothing is currently assigned to you.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'raw time ago';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_review_status']['id'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['fields']['field_review_status']['field'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Publication preference */
  $handler->display->display_options['fields']['field_publication_preference']['id'] = 'field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['field'] = 'field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['label'] = 'Preference';
  $handler->display->display_options['fields']['field_publication_preference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_publication_preference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_preference']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Assignee (field_assignee) */
  $handler->display->display_options['arguments']['field_assignee_uid']['id'] = 'field_assignee_uid';
  $handler->display->display_options['arguments']['field_assignee_uid']['table'] = 'field_data_field_assignee';
  $handler->display->display_options['arguments']['field_assignee_uid']['field'] = 'field_assignee_uid';
  $handler->display->display_options['arguments']['field_assignee_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_assignee_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_assignee_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_assignee_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_assignee_uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_request' => 'dataset_request',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Status (field_review_status) */
  $handler->display->display_options['filters']['field_review_status_value']['id'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['filters']['field_review_status_value']['field'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_review_status_value']['expose']['operator_id'] = 'field_review_status_value_op';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['operator'] = 'field_review_status_value_op';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['identifier'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_review_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Publication preference (field_publication_preference) */
  $handler->display->display_options['filters']['field_publication_preference_value']['id'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['field'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['operator_id'] = 'field_publication_preference_value_op';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['label'] = 'Preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['operator'] = 'field_publication_preference_value_op';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['identifier'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Reason (field_barriers_reason) */
  $handler->display->display_options['filters']['field_barriers_reason_value']['id'] = 'field_barriers_reason_value';
  $handler->display->display_options['filters']['field_barriers_reason_value']['table'] = 'field_data_field_barriers_reason';
  $handler->display->display_options['filters']['field_barriers_reason_value']['field'] = 'field_barriers_reason_value';
  $handler->display->display_options['filters']['field_barriers_reason_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['operator_id'] = 'field_barriers_reason_value_op';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['label'] = 'Issue';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['operator'] = 'field_barriers_reason_value_op';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['identifier'] = 'field_barriers_reason_value';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Active Data requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    10 => '10',
    11 => '11',
    12 => '12',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 25, 40, 60';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_request' => 'dataset_request',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Status (field_review_status) */
  $handler->display->display_options['filters']['field_review_status_value']['id'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['filters']['field_review_status_value']['field'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_review_status_value']['expose']['operator_id'] = 'field_review_status_value_op';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['operator'] = 'field_review_status_value_op';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['identifier'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_review_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Publication preference (field_publication_preference) */
  $handler->display->display_options['filters']['field_publication_preference_value']['id'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['field'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['operator_id'] = 'field_publication_preference_value_op';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['label'] = 'Preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['operator'] = 'field_publication_preference_value_op';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['identifier'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  $handler->display->display_options['path'] = 'admin/workbench/content/active';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Active Data requests';
  $handler->display->display_options['menu']['weight'] = '100';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Data requests';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 25, 40, 60';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'changed' => 'changed',
    'field_review_status' => 'field_review_status',
    'field_review_outcome' => 'field_review_outcome',
    'field_publication_preference' => 'field_publication_preference',
    'field_assignee' => 'field_assignee',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_review_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_review_outcome' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_preference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_assignee' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'raw time ago';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_review_status']['id'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['fields']['field_review_status']['field'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Outcome */
  $handler->display->display_options['fields']['field_review_outcome']['id'] = 'field_review_outcome';
  $handler->display->display_options['fields']['field_review_outcome']['table'] = 'field_data_field_review_outcome';
  $handler->display->display_options['fields']['field_review_outcome']['field'] = 'field_review_outcome';
  $handler->display->display_options['fields']['field_review_outcome']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Publication preference */
  $handler->display->display_options['fields']['field_publication_preference']['id'] = 'field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['field'] = 'field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['label'] = 'Preference';
  $handler->display->display_options['fields']['field_publication_preference']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_publication_preference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication_preference']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Assignee */
  $handler->display->display_options['fields']['field_assignee']['id'] = 'field_assignee';
  $handler->display->display_options['fields']['field_assignee']['table'] = 'field_data_field_assignee';
  $handler->display->display_options['fields']['field_assignee']['field'] = 'field_assignee';
  $handler->display->display_options['fields']['field_assignee']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Actions';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Assignee (field_assignee) */
  $handler->display->display_options['arguments']['field_assignee_uid']['id'] = 'field_assignee_uid';
  $handler->display->display_options['arguments']['field_assignee_uid']['table'] = 'field_data_field_assignee';
  $handler->display->display_options['arguments']['field_assignee_uid']['field'] = 'field_assignee_uid';
  $handler->display->display_options['arguments']['field_assignee_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_assignee_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_assignee_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_assignee_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_assignee_uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_assignee_uid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_request' => 'dataset_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Status (field_review_status) */
  $handler->display->display_options['filters']['field_review_status_value']['id'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['filters']['field_review_status_value']['field'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_review_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_review_status_value']['expose']['operator_id'] = 'field_review_status_value_op';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['operator'] = 'field_review_status_value_op';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['identifier'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_review_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Publication preference (field_publication_preference) */
  $handler->display->display_options['filters']['field_publication_preference_value']['id'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['field'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['group'] = 1;
  $handler->display->display_options['filters']['field_publication_preference_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['operator_id'] = 'field_publication_preference_value_op';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['label'] = 'Preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['operator'] = 'field_publication_preference_value_op';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['identifier'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Outcome (field_review_outcome) */
  $handler->display->display_options['filters']['field_review_outcome_value']['id'] = 'field_review_outcome_value';
  $handler->display->display_options['filters']['field_review_outcome_value']['table'] = 'field_data_field_review_outcome';
  $handler->display->display_options['filters']['field_review_outcome_value']['field'] = 'field_review_outcome_value';
  $handler->display->display_options['filters']['field_review_outcome_value']['group'] = 1;
  $handler->display->display_options['filters']['field_review_outcome_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_review_outcome_value']['expose']['operator_id'] = 'field_review_outcome_value_op';
  $handler->display->display_options['filters']['field_review_outcome_value']['expose']['label'] = 'Outcome';
  $handler->display->display_options['filters']['field_review_outcome_value']['expose']['operator'] = 'field_review_outcome_value_op';
  $handler->display->display_options['filters']['field_review_outcome_value']['expose']['identifier'] = 'field_review_outcome_value';
  $handler->display->display_options['filters']['field_review_outcome_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_review_outcome_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Reason (field_barriers_reason) */
  $handler->display->display_options['filters']['field_barriers_reason_value']['id'] = 'field_barriers_reason_value';
  $handler->display->display_options['filters']['field_barriers_reason_value']['table'] = 'field_data_field_barriers_reason';
  $handler->display->display_options['filters']['field_barriers_reason_value']['field'] = 'field_barriers_reason_value';
  $handler->display->display_options['filters']['field_barriers_reason_value']['group'] = 1;
  $handler->display->display_options['filters']['field_barriers_reason_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['operator_id'] = 'field_barriers_reason_value_op';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['label'] = 'Issue';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['operator'] = 'field_barriers_reason_value_op';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['identifier'] = 'field_barriers_reason_value';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
    9 => 0,
    11 => 0,
    12 => 0,
    10 => 0,
  );
  $handler->display->display_options['path'] = 'admin/workbench/content/data-requests';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Data requests';
  $handler->display->display_options['menu']['weight'] = '99';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['data_requests_administration'] = $view;

  $view = new view();
  $view->name = 'dataset_request_extract';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dataset request extract';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dataset request extract';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any dataset_request content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y - H:i';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Data request title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Data request description */
  $handler->display->display_options['fields']['field_data_set_description']['id'] = 'field_data_set_description';
  $handler->display->display_options['fields']['field_data_set_description']['table'] = 'field_data_field_data_set_description';
  $handler->display->display_options['fields']['field_data_set_description']['field'] = 'field_data_set_description';
  $handler->display->display_options['fields']['field_data_set_description']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Do you know who holds this data? */
  $handler->display->display_options['fields']['field_data_holder']['id'] = 'field_data_holder';
  $handler->display->display_options['fields']['field_data_holder']['table'] = 'field_data_field_data_holder';
  $handler->display->display_options['fields']['field_data_holder']['field'] = 'field_data_holder';
  $handler->display->display_options['fields']['field_data_holder']['label'] = 'Data holder';
  $handler->display->display_options['fields']['field_data_holder']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: User: Surname */
  $handler->display->display_options['fields']['field_surname']['id'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['table'] = 'field_data_field_surname';
  $handler->display->display_options['fields']['field_surname']['field'] = 'field_surname';
  $handler->display->display_options['fields']['field_surname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_surname']['label'] = '';
  $handler->display->display_options['fields']['field_surname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_surname']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Submitter name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([field_first_name] [field_surname])';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  $handler->display->display_options['fields']['mail']['label'] = 'Submitter e-mail';
  /* Field: Content: Organisation type */
  $handler->display->display_options['fields']['field_organisation_type']['id'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['table'] = 'field_data_field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['field'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Organisation name */
  $handler->display->display_options['fields']['field_organisation_name']['id'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['table'] = 'field_data_field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['field'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Data themes */
  $handler->display->display_options['fields']['field_data_themes']['id'] = 'field_data_themes';
  $handler->display->display_options['fields']['field_data_themes']['table'] = 'field_data_field_data_themes';
  $handler->display->display_options['fields']['field_data_themes']['field'] = 'field_data_themes';
  $handler->display->display_options['fields']['field_data_themes']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  $handler->display->display_options['fields']['field_data_themes']['delta_offset'] = '0';
  /* Field: Content: Reason */
  $handler->display->display_options['fields']['field_barriers_reason']['id'] = 'field_barriers_reason';
  $handler->display->display_options['fields']['field_barriers_reason']['table'] = 'field_data_field_barriers_reason';
  $handler->display->display_options['fields']['field_barriers_reason']['field'] = 'field_barriers_reason';
  $handler->display->display_options['fields']['field_barriers_reason']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Further detail */
  $handler->display->display_options['fields']['field_barriers_detail']['id'] = 'field_barriers_detail';
  $handler->display->display_options['fields']['field_barriers_detail']['table'] = 'field_data_field_barriers_detail';
  $handler->display->display_options['fields']['field_barriers_detail']['field'] = 'field_barriers_detail';
  $handler->display->display_options['fields']['field_barriers_detail']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Suggested use */
  $handler->display->display_options['fields']['field_data_use']['id'] = 'field_data_use';
  $handler->display->display_options['fields']['field_data_use']['table'] = 'field_data_field_data_use';
  $handler->display->display_options['fields']['field_data_use']['field'] = 'field_data_use';
  $handler->display->display_options['fields']['field_data_use']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  $handler->display->display_options['fields']['field_data_use']['delta_offset'] = '0';
  /* Field: Content: Further detail */
  $handler->display->display_options['fields']['field_data_use_detail']['id'] = 'field_data_use_detail';
  $handler->display->display_options['fields']['field_data_use_detail']['table'] = 'field_data_field_data_use_detail';
  $handler->display->display_options['fields']['field_data_use_detail']['field'] = 'field_data_use_detail';
  $handler->display->display_options['fields']['field_data_use_detail']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Benefits overview */
  $handler->display->display_options['fields']['field_benefits_overview']['id'] = 'field_benefits_overview';
  $handler->display->display_options['fields']['field_benefits_overview']['table'] = 'field_data_field_benefits_overview';
  $handler->display->display_options['fields']['field_benefits_overview']['field'] = 'field_benefits_overview';
  $handler->display->display_options['fields']['field_benefits_overview']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_review_status']['id'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['fields']['field_review_status']['field'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Publication preference */
  $handler->display->display_options['fields']['field_publication_preference']['id'] = 'field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['field'] = 'field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_request' => 'dataset_request',
  );
  /* Filter criterion: Content: Suggested use (field_data_use) */
  $handler->display->display_options['filters']['field_data_use_value']['id'] = 'field_data_use_value';
  $handler->display->display_options['filters']['field_data_use_value']['table'] = 'field_data_field_data_use';
  $handler->display->display_options['filters']['field_data_use_value']['field'] = 'field_data_use_value';
  $handler->display->display_options['filters']['field_data_use_value']['operator'] = 'not empty';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'data_requests_%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'admin/all_data_requests/csv';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'nid' => 'nid',
    'created' => 'created',
    'title' => 'title',
    'field_data_set_description' => 'field_data_set_description',
    'field_data_holder' => 'field_data_holder',
    'field_submitter_name' => 'field_submitter_name',
    'field_submitter_email' => 'field_submitter_email',
    'field_organisation_type' => 'field_organisation_type',
    'field_organisation_name' => 'field_organisation_name',
    'field_data_themes' => 'field_data_themes',
    'field_barriers_reason' => 'field_barriers_reason',
    'field_barriers_detail' => 'field_barriers_detail',
    'field_data_use' => 'field_data_use',
    'field_data_use_detail' => 'field_data_use_detail',
    'field_benefits_overview' => 'field_benefits_overview',
    'field_provide_estimates' => 'field_provide_estimates',
    'field_estimates_detail' => 'field_estimates_detail',
    'field_barriers_attempted' => 'field_barriers_attempted',
    'field_issue_type' => 'field_issue_type',
    'field_review_status' => 'field_review_status',
    'field_publication_preference' => 'field_publication_preference',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_data_set_description' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_data_holder' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_submitter_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_submitter_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organisation_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organisation_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_data_themes' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_barriers_reason' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_barriers_detail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_data_use' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_data_use_detail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_benefits_overview' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_provide_estimates' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_estimates_detail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_barriers_attempted' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_issue_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_review_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_publication_preference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y - H:i';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Data name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Data request description */
  $handler->display->display_options['fields']['field_data_set_description']['id'] = 'field_data_set_description';
  $handler->display->display_options['fields']['field_data_set_description']['table'] = 'field_data_field_data_set_description';
  $handler->display->display_options['fields']['field_data_set_description']['field'] = 'field_data_set_description';
  $handler->display->display_options['fields']['field_data_set_description']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Do you know who holds this data? */
  $handler->display->display_options['fields']['field_data_holder']['id'] = 'field_data_holder';
  $handler->display->display_options['fields']['field_data_holder']['table'] = 'field_data_field_data_holder';
  $handler->display->display_options['fields']['field_data_holder']['field'] = 'field_data_holder';
  /* Field: Content: Organisation type */
  $handler->display->display_options['fields']['field_organisation_type']['id'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['table'] = 'field_data_field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['field'] = 'field_organisation_type';
  $handler->display->display_options['fields']['field_organisation_type']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Organisation name */
  $handler->display->display_options['fields']['field_organisation_name']['id'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['table'] = 'field_data_field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['field'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Data themes */
  $handler->display->display_options['fields']['field_data_themes']['id'] = 'field_data_themes';
  $handler->display->display_options['fields']['field_data_themes']['table'] = 'field_data_field_data_themes';
  $handler->display->display_options['fields']['field_data_themes']['field'] = 'field_data_themes';
  $handler->display->display_options['fields']['field_data_themes']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  $handler->display->display_options['fields']['field_data_themes']['delta_offset'] = '0';
  /* Field: Content: Reason */
  $handler->display->display_options['fields']['field_barriers_reason']['id'] = 'field_barriers_reason';
  $handler->display->display_options['fields']['field_barriers_reason']['table'] = 'field_data_field_barriers_reason';
  $handler->display->display_options['fields']['field_barriers_reason']['field'] = 'field_barriers_reason';
  $handler->display->display_options['fields']['field_barriers_reason']['label'] = 'Challenge_reason';
  $handler->display->display_options['fields']['field_barriers_reason']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Further detail */
  $handler->display->display_options['fields']['field_barriers_detail']['id'] = 'field_barriers_detail';
  $handler->display->display_options['fields']['field_barriers_detail']['table'] = 'field_data_field_barriers_detail';
  $handler->display->display_options['fields']['field_barriers_detail']['field'] = 'field_barriers_detail';
  $handler->display->display_options['fields']['field_barriers_detail']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_barriers_detail']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_barriers_detail']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_barriers_detail']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Suggested use */
  $handler->display->display_options['fields']['field_data_use']['id'] = 'field_data_use';
  $handler->display->display_options['fields']['field_data_use']['table'] = 'field_data_field_data_use';
  $handler->display->display_options['fields']['field_data_use']['field'] = 'field_data_use';
  $handler->display->display_options['fields']['field_data_use']['label'] = 'Suggested_use';
  $handler->display->display_options['fields']['field_data_use']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  $handler->display->display_options['fields']['field_data_use']['delta_offset'] = '0';
  /* Field: Content: Further detail */
  $handler->display->display_options['fields']['field_data_use_detail']['id'] = 'field_data_use_detail';
  $handler->display->display_options['fields']['field_data_use_detail']['table'] = 'field_data_field_data_use_detail';
  $handler->display->display_options['fields']['field_data_use_detail']['field'] = 'field_data_use_detail';
  $handler->display->display_options['fields']['field_data_use_detail']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_data_use_detail']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_data_use_detail']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_data_use_detail']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Benefits overview */
  $handler->display->display_options['fields']['field_benefits_overview']['id'] = 'field_benefits_overview';
  $handler->display->display_options['fields']['field_benefits_overview']['table'] = 'field_data_field_benefits_overview';
  $handler->display->display_options['fields']['field_benefits_overview']['field'] = 'field_benefits_overview';
  $handler->display->display_options['fields']['field_benefits_overview']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_benefits_overview']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_benefits_overview']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_benefits_overview']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Are you able to provide estimates of the economic or financial benefit of data release? */
  $handler->display->display_options['fields']['field_provide_estimates']['id'] = 'field_provide_estimates';
  $handler->display->display_options['fields']['field_provide_estimates']['table'] = 'field_data_field_provide_estimates';
  $handler->display->display_options['fields']['field_provide_estimates']['field'] = 'field_provide_estimates';
  $handler->display->display_options['fields']['field_provide_estimates']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Estimates */
  $handler->display->display_options['fields']['field_estimates_detail']['id'] = 'field_estimates_detail';
  $handler->display->display_options['fields']['field_estimates_detail']['table'] = 'field_data_field_estimates_detail';
  $handler->display->display_options['fields']['field_estimates_detail']['field'] = 'field_estimates_detail';
  $handler->display->display_options['fields']['field_estimates_detail']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_estimates_detail']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['field_estimates_detail']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_estimates_detail']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Have you faced challenges in accessing this data? */
  $handler->display->display_options['fields']['field_barriers_attempted']['id'] = 'field_barriers_attempted';
  $handler->display->display_options['fields']['field_barriers_attempted']['table'] = 'field_data_field_barriers_attempted';
  $handler->display->display_options['fields']['field_barriers_attempted']['field'] = 'field_barriers_attempted';
  $handler->display->display_options['fields']['field_barriers_attempted']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_review_status']['id'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['fields']['field_review_status']['field'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Publication preference */
  $handler->display->display_options['fields']['field_publication_preference']['id'] = 'field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['field'] = 'field_publication_preference';
  $handler->display->display_options['fields']['field_publication_preference']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'Author';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_request' => 'dataset_request',
  );
  /* Filter criterion: Content: Suggested use (field_data_use) */
  $handler->display->display_options['filters']['field_data_use_value']['id'] = 'field_data_use_value';
  $handler->display->display_options['filters']['field_data_use_value']['table'] = 'field_data_field_data_use';
  $handler->display->display_options['filters']['field_data_use_value']['field'] = 'field_data_use_value';
  $handler->display->display_options['filters']['field_data_use_value']['operator'] = 'not empty';
  /* Filter criterion: Content: Are you able to provide estimates of the economic or financial benefit of data release? (field_provide_estimates) */
  $handler->display->display_options['filters']['field_provide_estimates_value']['id'] = 'field_provide_estimates_value';
  $handler->display->display_options['filters']['field_provide_estimates_value']['table'] = 'field_data_field_provide_estimates';
  $handler->display->display_options['filters']['field_provide_estimates_value']['field'] = 'field_provide_estimates_value';
  $handler->display->display_options['filters']['field_provide_estimates_value']['value'] = array(
    'all' => 'all',
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_provide_estimates_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_provide_estimates_value']['expose']['operator_id'] = 'field_provide_estimates_value_op';
  $handler->display->display_options['filters']['field_provide_estimates_value']['expose']['label'] = 'Estimates';
  $handler->display->display_options['filters']['field_provide_estimates_value']['expose']['operator'] = 'field_provide_estimates_value_op';
  $handler->display->display_options['filters']['field_provide_estimates_value']['expose']['identifier'] = 'field_provide_estimates_value';
  $handler->display->display_options['filters']['field_provide_estimates_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_provide_estimates_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Data themes (field_data_themes) */
  $handler->display->display_options['filters']['field_data_themes_tid']['id'] = 'field_data_themes_tid';
  $handler->display->display_options['filters']['field_data_themes_tid']['table'] = 'field_data_field_data_themes';
  $handler->display->display_options['filters']['field_data_themes_tid']['field'] = 'field_data_themes_tid';
  $handler->display->display_options['filters']['field_data_themes_tid']['value'] = array(
    72 => '72',
    73 => '73',
    74 => '74',
    75 => '75',
    76 => '76',
    77 => '77',
    78 => '78',
    79 => '79',
    80 => '80',
    81 => '81',
    82 => '82',
    83 => '83',
    84 => '84',
  );
  $handler->display->display_options['filters']['field_data_themes_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_data_themes_tid']['expose']['operator_id'] = 'field_data_themes_tid_op';
  $handler->display->display_options['filters']['field_data_themes_tid']['expose']['label'] = 'Data theme';
  $handler->display->display_options['filters']['field_data_themes_tid']['expose']['operator'] = 'field_data_themes_tid_op';
  $handler->display->display_options['filters']['field_data_themes_tid']['expose']['identifier'] = 'field_data_themes_tid';
  $handler->display->display_options['filters']['field_data_themes_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_data_themes_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_data_themes_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_data_themes_tid']['vocabulary'] = 'category';
  /* Filter criterion: Content: Have you faced challenges in accessing this data? (field_barriers_attempted) */
  $handler->display->display_options['filters']['field_barriers_attempted_value']['id'] = 'field_barriers_attempted_value';
  $handler->display->display_options['filters']['field_barriers_attempted_value']['table'] = 'field_data_field_barriers_attempted';
  $handler->display->display_options['filters']['field_barriers_attempted_value']['field'] = 'field_barriers_attempted_value';
  $handler->display->display_options['filters']['field_barriers_attempted_value']['value'] = array(
    'all' => 'all',
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_barriers_attempted_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_barriers_attempted_value']['expose']['operator_id'] = 'field_barriers_attempted_value_op';
  $handler->display->display_options['filters']['field_barriers_attempted_value']['expose']['label'] = 'Challenges';
  $handler->display->display_options['filters']['field_barriers_attempted_value']['expose']['operator'] = 'field_barriers_attempted_value_op';
  $handler->display->display_options['filters']['field_barriers_attempted_value']['expose']['identifier'] = 'field_barriers_attempted_value';
  $handler->display->display_options['filters']['field_barriers_attempted_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_barriers_attempted_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_issue_type_value']['id'] = 'field_issue_type_value';
  $handler->display->display_options['filters']['field_issue_type_value']['table'] = 'field_data_field_issue_type';
  $handler->display->display_options['filters']['field_issue_type_value']['field'] = 'field_issue_type_value';
  $handler->display->display_options['filters']['field_issue_type_value']['value'] = array(
    'all' => 'all',
    'Data is not published' => 'Data is not published',
    'Data doesn’t exist in specific format' => 'Data doesn’t exist in specific format',
    'Format' => 'Format',
    'Licence' => 'Licence',
    'Other' => 'Other',
  );
  $handler->display->display_options['filters']['field_issue_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_issue_type_value']['expose']['operator_id'] = 'field_issue_type_value_op';
  $handler->display->display_options['filters']['field_issue_type_value']['expose']['label'] = 'Issue type';
  $handler->display->display_options['filters']['field_issue_type_value']['expose']['operator'] = 'field_issue_type_value_op';
  $handler->display->display_options['filters']['field_issue_type_value']['expose']['identifier'] = 'field_issue_type_value';
  $handler->display->display_options['filters']['field_issue_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Organisation type (field_organisation_type) */
  $handler->display->display_options['filters']['field_organisation_type_value']['id'] = 'field_organisation_type_value';
  $handler->display->display_options['filters']['field_organisation_type_value']['table'] = 'field_data_field_organisation_type';
  $handler->display->display_options['filters']['field_organisation_type_value']['field'] = 'field_organisation_type_value';
  $handler->display->display_options['filters']['field_organisation_type_value']['value'] = array(
    'all' => 'all',
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_organisation_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organisation_type_value']['expose']['operator_id'] = 'field_organisation_type_value_op';
  $handler->display->display_options['filters']['field_organisation_type_value']['expose']['label'] = 'Organisation type';
  $handler->display->display_options['filters']['field_organisation_type_value']['expose']['operator'] = 'field_organisation_type_value_op';
  $handler->display->display_options['filters']['field_organisation_type_value']['expose']['identifier'] = 'field_organisation_type_value';
  $handler->display->display_options['filters']['field_organisation_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_organisation_type_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Publication preference (field_publication_preference) */
  $handler->display->display_options['filters']['field_publication_preference_value']['id'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['field'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['value'] = array(
    'all' => 'all',
    1 => '1',
    0 => '0',
  );
  $handler->display->display_options['filters']['field_publication_preference_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['operator_id'] = 'field_publication_preference_value_op';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['label'] = 'Publication preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['operator'] = 'field_publication_preference_value_op';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['identifier'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_publication_preference_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Reason (field_barriers_reason) */
  $handler->display->display_options['filters']['field_barriers_reason_value']['id'] = 'field_barriers_reason_value';
  $handler->display->display_options['filters']['field_barriers_reason_value']['table'] = 'field_data_field_barriers_reason';
  $handler->display->display_options['filters']['field_barriers_reason_value']['field'] = 'field_barriers_reason_value';
  $handler->display->display_options['filters']['field_barriers_reason_value']['value'] = array(
    'all' => 'all',
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    8 => '8',
    9 => '9',
  );
  $handler->display->display_options['filters']['field_barriers_reason_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['operator_id'] = 'field_barriers_reason_value_op';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['label'] = 'Barriers reason';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['operator'] = 'field_barriers_reason_value_op';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['identifier'] = 'field_barriers_reason_value';
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_barriers_reason_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Status (field_review_status) */
  $handler->display->display_options['filters']['field_review_status_value']['id'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['filters']['field_review_status_value']['field'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['value'] = array(
    'all' => 'all',
    0 => '0',
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_review_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_review_status_value']['expose']['operator_id'] = 'field_review_status_value_op';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['label'] = 'Review status';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['operator'] = 'field_review_status_value_op';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['identifier'] = 'field_review_status_value';
  $handler->display->display_options['filters']['field_review_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_review_status_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Suggested use (field_data_use) */
  $handler->display->display_options['filters']['field_data_use_value_1']['id'] = 'field_data_use_value_1';
  $handler->display->display_options['filters']['field_data_use_value_1']['table'] = 'field_data_field_data_use';
  $handler->display->display_options['filters']['field_data_use_value_1']['field'] = 'field_data_use_value';
  $handler->display->display_options['filters']['field_data_use_value_1']['value'] = array(
    'all' => 'all',
    1 => '1',
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['filters']['field_data_use_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_data_use_value_1']['expose']['operator_id'] = 'field_data_use_value_1_op';
  $handler->display->display_options['filters']['field_data_use_value_1']['expose']['label'] = 'Suggested use';
  $handler->display->display_options['filters']['field_data_use_value_1']['expose']['operator'] = 'field_data_use_value_1_op';
  $handler->display->display_options['filters']['field_data_use_value_1']['expose']['identifier'] = 'field_data_use_value_1';
  $handler->display->display_options['filters']['field_data_use_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_data_use_value_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['path'] = 'admin/all_data_requests';
  $export['dataset_request_extract'] = $view;

  $view = new view();
  $view->name = 'dataset_requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dataset requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dataset requests';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '«';
  $handler->display->display_options['pager']['options']['tags']['next'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Reply */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Submitted by';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_review_status']['id'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['fields']['field_review_status']['field'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_request' => 'dataset_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Reply: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'reply';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_1']['value']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Reply: Status */
  $handler->display->display_options['filters']['status_2']['id'] = 'status_2';
  $handler->display->display_options['filters']['status_2']['table'] = 'reply';
  $handler->display->display_options['filters']['status_2']['field'] = 'status';
  $handler->display->display_options['filters']['status_2']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['status_2']['group'] = 2;

  /* Display: Latest dataset requests */
  $handler = $view->new_display('block', 'Latest dataset requests', 'latest_dataset_requests');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a class="rss-icon" href="/odug/rss.xml"><i class="icon-rss-sign"></i></a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '70';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Submitted by';
  $handler->display->display_options['fields']['name']['element_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = 'span';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_type'] = 'span';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  /* Field: Content: Organisation name */
  $handler->display->display_options['fields']['field_organisation_name']['id'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['table'] = 'field_data_field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['field'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['label'] = 'In behalf of';
  $handler->display->display_options['fields']['field_organisation_name']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_organisation_name']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_organisation_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organisation_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_organisation_name']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_organisation_name']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_review_status']['id'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['table'] = 'field_data_field_review_status';
  $handler->display->display_options['fields']['field_review_status']['field'] = 'field_review_status';
  $handler->display->display_options['fields']['field_review_status']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_review_status']['element_label_type'] = 'span';
  $handler->display->display_options['fields']['field_review_status']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_review_status']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_request' => 'dataset_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Reply: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'reply';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_1']['value']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Reply: Status */
  $handler->display->display_options['filters']['status_2']['id'] = 'status_2';
  $handler->display->display_options['filters']['status_2']['table'] = 'reply';
  $handler->display->display_options['filters']['status_2']['field'] = 'status';
  $handler->display->display_options['filters']['status_2']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['status_2']['group'] = 2;
  /* Filter criterion: Content: Publication preference (field_publication_preference) */
  $handler->display->display_options['filters']['field_publication_preference_value']['id'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['field'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Dataset requests';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Requests made under the old \'unlocking service\'';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['type'] = 'ol';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Do you know who holds this data? */
  $handler->display->display_options['fields']['field_data_holder']['id'] = 'field_data_holder';
  $handler->display->display_options['fields']['field_data_holder']['table'] = 'field_data_field_data_holder';
  $handler->display->display_options['fields']['field_data_holder']['field'] = 'field_data_holder';
  /* Field: Content: Organisation name */
  $handler->display->display_options['fields']['field_organisation_name']['id'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['table'] = 'field_data_field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['field'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_organisation_name']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  /* Field: Content: Submitter Name */
  $handler->display->display_options['fields']['field_submitter_name']['id'] = 'field_submitter_name';
  $handler->display->display_options['fields']['field_submitter_name']['table'] = 'field_data_field_submitter_name';
  $handler->display->display_options['fields']['field_submitter_name']['field'] = 'field_submitter_name';
  $handler->display->display_options['fields']['field_submitter_name']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_request' => 'dataset_request',
  );
  /* Filter criterion: Content: Suggested use (field_data_use) */
  $handler->display->display_options['filters']['field_data_use_value']['id'] = 'field_data_use_value';
  $handler->display->display_options['filters']['field_data_use_value']['table'] = 'field_data_field_data_use';
  $handler->display->display_options['filters']['field_data_use_value']['field'] = 'field_data_use_value';
  $handler->display->display_options['filters']['field_data_use_value']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'odug/old-data-requests';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'rss';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_request' => 'dataset_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Publication preference (field_publication_preference) */
  $handler->display->display_options['filters']['field_publication_preference_value']['id'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['table'] = 'field_data_field_publication_preference';
  $handler->display->display_options['filters']['field_publication_preference_value']['field'] = 'field_publication_preference_value';
  $handler->display->display_options['filters']['field_publication_preference_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'odug/rss.xml';
  $export['dataset_requests'] = $view;

  $view = new view();
  $view->name = 'minutes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Minutes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'ODUG Minutes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '«';
  $handler->display->display_options['pager']['options']['tags']['next'] = '»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Resources */
  $handler->display->display_options['fields']['field_resource_file']['id'] = 'field_resource_file';
  $handler->display->display_options['fields']['field_resource_file']['table'] = 'field_data_field_resource_file';
  $handler->display->display_options['fields']['field_resource_file']['field'] = 'field_resource_file';
  $handler->display->display_options['fields']['field_resource_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_resource_file']['settings'] = array(
    'field_replies' => '',
    'field_replies_settings' => array(
      'field_replies_reply_field_name' => '',
      'field_replies_revision' => '',
    ),
  );
  $handler->display->display_options['fields']['field_resource_file']['delta_offset'] = '0';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource' => 'resource',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '14766',
  );
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'tags';

  /* Display: ODUG minutes  */
  $handler = $view->new_display('block', 'ODUG minutes ', 'odug_minutes_block');
  $handler->display->display_options['display_description'] = 'ODUG minutes block';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '«';
  $handler->display->display_options['pager']['options']['tags']['next'] = '»';
  $handler->display->display_options['block_description'] = 'ODUG minutes block';
  $export['minutes'] = $view;

  return $export;
}
