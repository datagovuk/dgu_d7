<?php
/**
 * @file
 * dgu_forum.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dgu_forum_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'forum_categories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Forum categories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Forum categories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'nid' => 'nid',
    'id' => 'id',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'forum/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'forums' => 'forums',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Content using Forums */
  $handler->display->display_options['relationships']['reverse_taxonomy_forums_node']['id'] = 'reverse_taxonomy_forums_node';
  $handler->display->display_options['relationships']['reverse_taxonomy_forums_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_taxonomy_forums_node']['field'] = 'reverse_taxonomy_forums_node';
  /* Relationship: Content: Reply */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['relationship'] = 'reverse_taxonomy_forums_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<img src="/assets/img/forum-folder.png" />';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'forum/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_taxonomy_forums_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Topics';
  /* Field: Reply: Reply ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'reply';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['relationship'] = 'nid';
  $handler->display->display_options['fields']['id']['group_type'] = 'count';
  $handler->display->display_options['fields']['id']['label'] = 'Replies';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'forums' => 'forums',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_taxonomy_forums_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Reply: Status */
  $handler->display->display_options['filters']['status_2']['id'] = 'status_2';
  $handler->display->display_options['filters']['status_2']['table'] = 'reply';
  $handler->display->display_options['filters']['status_2']['field'] = 'status';
  $handler->display->display_options['filters']['status_2']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_2']['value']['value'] = '1';
  $handler->display->display_options['filters']['status_2']['group'] = 2;
  /* Filter criterion: Reply: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'reply';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['status_1']['group'] = 2;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Content using Forums */
  $handler->display->display_options['relationships']['reverse_taxonomy_forums_node']['id'] = 'reverse_taxonomy_forums_node';
  $handler->display->display_options['relationships']['reverse_taxonomy_forums_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_taxonomy_forums_node']['field'] = 'reverse_taxonomy_forums_node';
  $handler->display->display_options['relationships']['reverse_taxonomy_forums_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'forum/[name]';
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_taxonomy_forums_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['nid']['format_plural_singular'] = '1 post';
  $handler->display->display_options['fields']['nid']['format_plural_plural'] = '@count posts';
  $handler->display->display_options['fields']['nid']['prefix'] = '(';
  $handler->display->display_options['fields']['nid']['suffix'] = ')';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'forums' => 'forums',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_taxonomy_forums_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $export['forum_categories'] = $view;

  $view = new view();
  $view->name = 'forum_topics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Forum topics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Forum topics';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Reply */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Forums (taxonomy_forums) */
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['id'] = 'taxonomy_forums_tid';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['table'] = 'field_data_taxonomy_forums';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['field'] = 'taxonomy_forums_tid';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['validate_options']['vocabularies'] = array(
    'forums' => 'forums',
  );
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['validate_options']['transform'] = TRUE;
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
    'forum' => 'forum',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'id' => 'id',
    'name' => 'name',
    'created' => 'created',
    'created_1' => 'created_1',
  );
  $handler->display->display_options['style_options']['default'] = 'created_1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
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
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Reply */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Topic';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Reply: Reply ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'reply';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['relationship'] = 'nid';
  $handler->display->display_options['fields']['id']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['id']['label'] = 'Replies';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Created by';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Reply: Created */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'reply';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['relationship'] = 'nid';
  $handler->display->display_options['fields']['created_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['created_1']['label'] = 'Last reply';
  $handler->display->display_options['fields']['created_1']['empty'] = 'N/A';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Forums (taxonomy_forums) */
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['id'] = 'taxonomy_forums_tid';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['table'] = 'field_data_taxonomy_forums';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['field'] = 'taxonomy_forums_tid';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['validate_options']['vocabularies'] = array(
    'forums' => 'forums',
  );
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['taxonomy_forums_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
    3 => 'OR',
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
    'forum' => 'forum',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Reply: Entity_type */
  $handler->display->display_options['filters']['entity_type']['id'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['table'] = 'reply';
  $handler->display->display_options['filters']['entity_type']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['entity_type']['value'] = 'node';
  $handler->display->display_options['filters']['entity_type']['group'] = 2;
  /* Filter criterion: Reply: Entity_type */
  $handler->display->display_options['filters']['entity_type_1']['id'] = 'entity_type_1';
  $handler->display->display_options['filters']['entity_type_1']['table'] = 'reply';
  $handler->display->display_options['filters']['entity_type_1']['field'] = 'entity_type';
  $handler->display->display_options['filters']['entity_type_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['entity_type_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['entity_type_1']['group'] = 2;
  /* Filter criterion: Reply: Status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'reply';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_1']['value']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 3;
  /* Filter criterion: Reply: Status */
  $handler->display->display_options['filters']['status_2']['id'] = 'status_2';
  $handler->display->display_options['filters']['status_2']['table'] = 'reply';
  $handler->display->display_options['filters']['status_2']['field'] = 'status';
  $handler->display->display_options['filters']['status_2']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['status_2']['group'] = 3;
  $handler->display->display_options['argument_input'] = array(
    'taxonomy_forums_tid' => array(
      'type' => 'panel',
      'context' => 'terms.name_dashed',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Forums (taxonomy_forums)',
    ),
  );
  $export['forum_topics'] = $view;

  return $export;
}
