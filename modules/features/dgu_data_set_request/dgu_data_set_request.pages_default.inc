<?php
/**
 * @file
 * dgu_data_set_request.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgu_data_set_request_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Data request',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'dataset_request' => 'dataset_request',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'odug/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
              1 => 10,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Data requests';
  $display->uuid = '3ebcaae7-940e-4944-af23-98b0a936ac90';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cfc42002-6239-4658-a0c8-c9f996fd7911';
    $pane->panel = 'left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 1,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cfc42002-6239-4658-a0c8-c9f996fd7911';
    $display->content['new-cfc42002-6239-4658-a0c8-c9f996fd7911'] = $pane;
    $display->panels['left'][0] = 'new-cfc42002-6239-4658-a0c8-c9f996fd7911';
    $pane = new stdClass();
    $pane->pid = 'new-6f96d36b-827f-4055-a3de-b9d86190dfbc';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'apachesolr_search-mlt-001';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6f96d36b-827f-4055-a3de-b9d86190dfbc';
    $display->content['new-6f96d36b-827f-4055-a3de-b9d86190dfbc'] = $pane;
    $display->panels['right'][0] = 'new-6f96d36b-827f-4055-a3de-b9d86190dfbc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cfc42002-6239-4658-a0c8-c9f996fd7911';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_data_set_request_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'data_requests';
  $page->task = 'page';
  $page->admin_title = 'Data requests';
  $page->admin_description = 'Open Data User Group - dataset requests landing page';
  $page->path = 'data-request';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Data requests',
    'name' => 'main-menu',
    'weight' => '2',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_data_requests_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'data_requests';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'odug',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Data requests';
  $display->uuid = 'f5b823dc-03d3-4b54-9705-fb429885525d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-16f62a09-dc69-4695-8a99-efa43985b3ab';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'dataset_requests';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'latest_dataset_requests',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '16f62a09-dc69-4695-8a99-efa43985b3ab';
    $display->content['new-16f62a09-dc69-4695-8a99-efa43985b3ab'] = $pane;
    $display->panels['left'][0] = 'new-16f62a09-dc69-4695-8a99-efa43985b3ab';
    $pane = new stdClass();
    $pane->pid = 'new-b67fde18-9b0c-4ef2-963a-5c0fd056b84d';
    $pane->panel = 'left';
    $pane->type = 'dgu_data_request_summary';
    $pane->subtype = 'dgu_data_request_summary';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => FALSE,
      'title_override_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b67fde18-9b0c-4ef2-963a-5c0fd056b84d';
    $display->content['new-b67fde18-9b0c-4ef2-963a-5c0fd056b84d'] = $pane;
    $display->panels['left'][1] = 'new-b67fde18-9b0c-4ef2-963a-5c0fd056b84d';
    $pane = new stdClass();
    $pane->pid = 'new-090b036a-30d3-4d88-b725-95eaffc4dcfa';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Open Data User Group',
      'body' => '<p>The Open Data User Group (ODUG) exists to help government understand the requirements of people who are using, or could use, the datasets it collects.</p> <div class="item-list"><ul> <li><a href="/odug/overview"><strong>What Are Datasets?</strong><p>A dataset is a collection of information of the same type. Examples of datasets are...</p></a></li> <li><a href="/odug/overview"><strong>How You Can Help?</strong><p>We need to know which datasets, held by government to release entire datasets...</p></a></li> <li><a href="/odug/overview"><strong>What Happens to Data Requests?</strong><p>Alongside the Cabinet Office and members of the community we will, on a routine basis, categorise...</p></a></li>
<li><a href="/library/?f[0]=im_field_document_type%3A90"><strong>ODUG minutes</strong></a></li>
<li><a href="/odug/roadmap"><strong>ODUG business reporting on data requests</strong></a></li>
</ul></div>
',
      'format' => 'unfiltered',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '090b036a-30d3-4d88-b725-95eaffc4dcfa';
    $display->content['new-090b036a-30d3-4d88-b725-95eaffc4dcfa'] = $pane;
    $display->panels['left'][2] = 'new-090b036a-30d3-4d88-b725-95eaffc4dcfa';
    $pane = new stdClass();
    $pane->pid = 'new-799d4527-733f-4cd7-920c-a408788d840c';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create dataset_request content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Request new data (for authenticated users)',
      'title' => '',
      'body' => '<p class="center-contents"><a class="btn-default btn btn-primary" href="/node/add/dataset-request">Request new data</a></p><p>This form will allow you to submit a data request.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '799d4527-733f-4cd7-920c-a408788d840c';
    $display->content['new-799d4527-733f-4cd7-920c-a408788d840c'] = $pane;
    $display->panels['right'][0] = 'new-799d4527-733f-4cd7-920c-a408788d840c';
    $pane = new stdClass();
    $pane->pid = 'new-2dce2da0-7d3a-4d55-b64d-f220075c768e';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Request new data (for anonymous users)',
      'title' => '',
      'body' => '<p class="center-contents"><a class="btn-default btn btn-primary" href="/user/login?destination=/node/add/dataset-request">Login to request new data</a></p><p>This form will allow you to submit a data request.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2dce2da0-7d3a-4d55-b64d-f220075c768e';
    $display->content['new-2dce2da0-7d3a-4d55-b64d-f220075c768e'] = $pane;
    $display->panels['right'][1] = 'new-2dce2da0-7d3a-4d55-b64d-f220075c768e';
    $pane = new stdClass();
    $pane->pid = 'new-030fe4f5-4ddb-4b6b-b2f2-1d6f3d74a70f';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Progress on requests',
      'body' => '<p><a href="/odug/roadmap"><img alt="" src="/profiles/dgu/modules/features/dgu_data_set_request/odug-roadmap.png"> </a></p><p><a class="btn-default btn btn-primary" href="/odug/roadmap">See Dashboard</a></p><p><a href="/odug/status">Find out more about data request status</a></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '030fe4f5-4ddb-4b6b-b2f2-1d6f3d74a70f';
    $display->content['new-030fe4f5-4ddb-4b6b-b2f2-1d6f3d74a70f'] = $pane;
    $display->panels['right'][2] = 'new-030fe4f5-4ddb-4b6b-b2f2-1d6f3d74a70f';
    $pane = new stdClass();
    $pane->pid = 'new-0d0b9820-07bf-4e79-bd10-07104518a892';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'blogs';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '3',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'override_title' => 1,
      'override_title_text' => 'ODUG Blogs',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0d0b9820-07bf-4e79-bd10-07104518a892';
    $display->content['new-0d0b9820-07bf-4e79-bd10-07104518a892'] = $pane;
    $display->panels['right'][3] = 'new-0d0b9820-07bf-4e79-bd10-07104518a892';
    $pane = new stdClass();
    $pane->pid = 'new-50aa88b3-e168-4006-ab75-5b32a5c98039';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'ODUG Members',
      'body' => '<a href="/users/hsavory">Heather Savory</a><br/>
<a href="/users/robert_barr">Robert Barr</a><br/>
<a href="/users/jacqui-taylor">Jacqui Taylor</a><br/>
<a href="/users/charlieboundy">Charlie Boundy</a><br/>
<a href="/users/puntofisso">Giuseppe Sollazzo</a><br/>
<a href="/users/pmalyon">Paul Malyon</a><br/>
<a href="/users/jenit">Jeni Tennison</a><br/>
Simon Briscoe<br/>
Stuart Chalmers<br/>
Hendrick Grothius<br/>
Paul Hodgson<br/>
Nick Halliday<br/>
David Kane<br/>
Ian Makgill<br/>
Johanna Walker<br/>
',
      'format' => 'unfiltered',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '50aa88b3-e168-4006-ab75-5b32a5c98039';
    $display->content['new-50aa88b3-e168-4006-ab75-5b32a5c98039'] = $pane;
    $display->panels['right'][4] = 'new-50aa88b3-e168-4006-ab75-5b32a5c98039';
    $pane = new stdClass();
    $pane->pid = 'new-b9d5327f-91af-4f22-9c96-b1278f2a61bc';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Useful links',
      'body' => '<a href="http://www.theodi.org ">The Open Data Institute</a>
<br/>
<a href="http://www.bis.gov.uk/transparency/data-strategy-board ">The Data Strategy board</a>
<br/>
<a href="https://www.gov.uk/government/groups/public-data-group">Public Data Group</a>
',
      'format' => 'unfiltered',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'b9d5327f-91af-4f22-9c96-b1278f2a61bc';
    $display->content['new-b9d5327f-91af-4f22-9c96-b1278f2a61bc'] = $pane;
    $display->panels['right'][5] = 'new-b9d5327f-91af-4f22-9c96-b1278f2a61bc';
    $pane = new stdClass();
    $pane->pid = 'new-a43d9b7d-680b-43d9-8c3d-29db151f6e15';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
              1 => 10,
              2 => 11,
              3 => 12,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Data request administration',
      'body' => '<a href="/admin/all_data_requests/csv">Download data requests</a>',
      'format' => 'unfiltered',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'a43d9b7d-680b-43d9-8c3d-29db151f6e15';
    $display->content['new-a43d9b7d-680b-43d9-8c3d-29db151f6e15'] = $pane;
    $display->panels['right'][6] = 'new-a43d9b7d-680b-43d9-8c3d-29db151f6e15';
    $pane = new stdClass();
    $pane->pid = 'new-54509efc-0a55-40f3-9663-2c05d3c954f4';
    $pane->panel = 'top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'override_title' => 0,
      'override_title_text' => '',
      'content_type' => 'dataset_request',
      'show_counter' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '54509efc-0a55-40f3-9663-2c05d3c954f4';
    $display->content['new-54509efc-0a55-40f3-9663-2c05d3c954f4'] = $pane;
    $display->panels['top'][0] = 'new-54509efc-0a55-40f3-9663-2c05d3c954f4';
    $pane = new stdClass();
    $pane->pid = 'new-a0574e4e-8311-40cf-9a04-279b8e240d91';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-data-requests-tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'menu-tabs',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a0574e4e-8311-40cf-9a04-279b8e240d91';
    $display->content['new-a0574e4e-8311-40cf-9a04-279b8e240d91'] = $pane;
    $display->panels['top'][1] = 'new-a0574e4e-8311-40cf-9a04-279b8e240d91';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-799d4527-733f-4cd7-920c-a408788d840c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['data_requests'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'data_requests_blogs';
  $page->task = 'page';
  $page->admin_title = 'Data requests - blogs';
  $page->admin_description = 'Open Data User Group - dataset requests landing page';
  $page->path = 'data-request/blogs';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Data requests',
    'name' => 'main-menu',
    'weight' => '2',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_data_requests_blogs_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'data_requests_blogs';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'odug',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Data requests';
  $display->uuid = '5aef6ead-8547-4eb8-9e43-b4f48a97f2b7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3c284ff7-6353-45e4-b327-4bd2e1d80250';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'blogs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '6',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'blogs_odug',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3c284ff7-6353-45e4-b327-4bd2e1d80250';
    $display->content['new-3c284ff7-6353-45e4-b327-4bd2e1d80250'] = $pane;
    $display->panels['left'][0] = 'new-3c284ff7-6353-45e4-b327-4bd2e1d80250';
    $pane = new stdClass();
    $pane->pid = 'new-a48ff988-8315-4baf-9070-bfa93ba9da7a';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'ODUG overview',
      'body' => '<p>The Open Data User Group (ODUG) exists to help government understand the requirements of people who are using, or could use, the datasets it collects.</p> <div class="item-list"><ul> <li><a href="/odug/overview"><strong>What Are Datasets?</strong><p>A dataset is a collection of information of the same type. Examples of datasets are...</p></a></li> <li><a href="/odug/overview"><strong>How You Can Help?</strong><p>We need to know which datasets, held by government to release entire datasets...</p></a></li> <li><a href="/odug/overview"><strong>What Happens to Data Requests?</strong><p>Alongside the Cabinet Office and members of the community we will, on a routine basis, categorise...</p></a></li> </ul></div>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a48ff988-8315-4baf-9070-bfa93ba9da7a';
    $display->content['new-a48ff988-8315-4baf-9070-bfa93ba9da7a'] = $pane;
    $display->panels['left'][1] = 'new-a48ff988-8315-4baf-9070-bfa93ba9da7a';
    $pane = new stdClass();
    $pane->pid = 'new-61e10870-617a-4dde-8300-483d8bd05cc0';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create dataset_request content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Request new data (for authenticated users)',
      'title' => '',
      'body' => '<p class="center-contents"><a class="btn-default btn btn-primary" href="/node/add/dataset-request">Request new data</a></p><p>This form will allow you to submit a data request.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '61e10870-617a-4dde-8300-483d8bd05cc0';
    $display->content['new-61e10870-617a-4dde-8300-483d8bd05cc0'] = $pane;
    $display->panels['right'][0] = 'new-61e10870-617a-4dde-8300-483d8bd05cc0';
    $pane = new stdClass();
    $pane->pid = 'new-b257ad8d-2ce6-4de0-8937-e3095d188d77';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'blogs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_2',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b257ad8d-2ce6-4de0-8937-e3095d188d77';
    $display->content['new-b257ad8d-2ce6-4de0-8937-e3095d188d77'] = $pane;
    $display->panels['right'][1] = 'new-b257ad8d-2ce6-4de0-8937-e3095d188d77';
    $pane = new stdClass();
    $pane->pid = 'new-d459f064-037e-4fa5-aff4-e029d0c60d9b';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Request new data (for anonymous users)',
      'title' => '',
      'body' => '<p class="center-contents"><a class="btn-default btn btn-primary" href="/user/login?destination=/node/add/dataset-request">Login to request new data</a></p><p>This form will allow you to submit a data request.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd459f064-037e-4fa5-aff4-e029d0c60d9b';
    $display->content['new-d459f064-037e-4fa5-aff4-e029d0c60d9b'] = $pane;
    $display->panels['right'][2] = 'new-d459f064-037e-4fa5-aff4-e029d0c60d9b';
    $pane = new stdClass();
    $pane->pid = 'new-fec7e521-b309-4568-ab54-775db7be29a8';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Progress on requests',
      'body' => '<p><a href="/odug/roadmap"><img alt="" src="/profiles/dgu/modules/features/dgu_data_set_request/odug-roadmap.png"> </a></p><p><a class="btn-default btn btn-primary" href="/odug/roadmap">See Dashboard</a></p><p><a href="/odug/status">Find out more about data request status</a></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'fec7e521-b309-4568-ab54-775db7be29a8';
    $display->content['new-fec7e521-b309-4568-ab54-775db7be29a8'] = $pane;
    $display->panels['right'][3] = 'new-fec7e521-b309-4568-ab54-775db7be29a8';
    $pane = new stdClass();
    $pane->pid = 'new-1318fcc1-bd67-4e3c-afe8-dfc550778615';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'ODUG Members',
      'body' => '<a href="/users/robert_barr">Robert Barr</a><br/>
<a href="/users/dlazanski">Dominique Lazanski</a><br/>
<a href="/users/gschimd">Gesche Schmid</a><br/>
<a href="/users/jacqui-taylor">Jacqui Taylor</a><br/>
<a href="/users/charlieboundy">Charlie Boundy</a><br/>
<a href="/users/alex-kafetz">Alex Kafetz</a><br/>
<a href="/users/duncan3ross">Duncan Ross</a><br/>
<a href="/users/puntofisso">Giuseppe Sollazzo</a><br/>
<a href="/users/tomsmith">Tom Smith</a><br/>
Carlos Somohano<br/>
Paul Fenton<br/>
<a href="/users/hsavory">Heather Savory</a><br/>
<a href="/users/pmalyon">Paul Malyon</a><br/>
<a href="/users/jenit">Jeni Tennison</a><br/>
<a href="/users/harveylewis">Harvey Lewis</a><br/>',
      'format' => 'unfiltered',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '1318fcc1-bd67-4e3c-afe8-dfc550778615';
    $display->content['new-1318fcc1-bd67-4e3c-afe8-dfc550778615'] = $pane;
    $display->panels['right'][4] = 'new-1318fcc1-bd67-4e3c-afe8-dfc550778615';
    $pane = new stdClass();
    $pane->pid = 'new-ed5cb100-9977-48f2-bddf-70c172666d6c';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Useful links',
      'body' => '<a href="http://www.theodi.org ">The Open Data Institute</a>
<a href="http://www.bis.gov.uk/transparency/data-strategy-board ">The Data Strategy board</a>
<a href="http://www.cabinetoffice.gov.uk/content/open-data-user-group ">Cabinet Office ODUG page</a>
<a href="http://www.bis.gov.uk/policies/shareholderexecutive/structure/portfolio-unit/public-data-group/background">Public Data Group</a>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'ed5cb100-9977-48f2-bddf-70c172666d6c';
    $display->content['new-ed5cb100-9977-48f2-bddf-70c172666d6c'] = $pane;
    $display->panels['right'][5] = 'new-ed5cb100-9977-48f2-bddf-70c172666d6c';
    $pane = new stdClass();
    $pane->pid = 'new-a2db3741-573d-4e81-9823-a7bd44854c70';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any dataset_request content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Data request administration',
      'body' => '<a href="/admin/all_data_requests">Browse data requests</a>
<br />
<a href="/admin/all_data_requests/csv">Download data requests</a>',
      'format' => 'unfiltered',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'a2db3741-573d-4e81-9823-a7bd44854c70';
    $display->content['new-a2db3741-573d-4e81-9823-a7bd44854c70'] = $pane;
    $display->panels['right'][6] = 'new-a2db3741-573d-4e81-9823-a7bd44854c70';
    $pane = new stdClass();
    $pane->pid = 'new-1493d795-9ee8-4453-83fc-8aaeb7e323f1';
    $pane->panel = 'top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'override_title' => 0,
      'override_title_text' => '',
      'content_type' => 'dataset_request',
      'show_counter' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1493d795-9ee8-4453-83fc-8aaeb7e323f1';
    $display->content['new-1493d795-9ee8-4453-83fc-8aaeb7e323f1'] = $pane;
    $display->panels['top'][0] = 'new-1493d795-9ee8-4453-83fc-8aaeb7e323f1';
    $pane = new stdClass();
    $pane->pid = 'new-5ee0fd2f-2304-4804-a7e0-872525937510';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-data-requests-tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'menu-tabs',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5ee0fd2f-2304-4804-a7e0-872525937510';
    $display->content['new-5ee0fd2f-2304-4804-a7e0-872525937510'] = $pane;
    $display->panels['top'][1] = 'new-5ee0fd2f-2304-4804-a7e0-872525937510';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-61e10870-617a-4dde-8300-483d8bd05cc0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['data_requests_blogs'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'data_requests_minutes';
  $page->task = 'page';
  $page->admin_title = 'Data requests - minutes';
  $page->admin_description = 'Open Data User Group - dataset requests landing page';
  $page->path = 'data-request/minutes';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Data requests',
    'name' => 'main-menu',
    'weight' => '2',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_data_requests_minutes_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'data_requests_minutes';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'odug',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Data requests';
  $display->uuid = 'e8e3991e-2afa-4827-a033-37421359b675';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-297f5cbf-b0ff-4fe1-91b4-6e1f395fe702';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'minutes';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'odug_minutes_block',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '297f5cbf-b0ff-4fe1-91b4-6e1f395fe702';
    $display->content['new-297f5cbf-b0ff-4fe1-91b4-6e1f395fe702'] = $pane;
    $display->panels['left'][0] = 'new-297f5cbf-b0ff-4fe1-91b4-6e1f395fe702';
    $pane = new stdClass();
    $pane->pid = 'new-24178036-de89-409b-94be-f5df476034af';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'ODUG overview',
      'body' => '<p>The Open Data User Group (ODUG) exists to help government understand the requirements of people who are using, or could use, the datasets it collects.</p> <div class="item-list"><ul> <li><a href="/odug/overview"><strong>What Are Datasets?</strong><p>A dataset is a collection of information of the same type. Examples of datasets are...</p></a></li> <li><a href="/odug/overview"><strong>How You Can Help?</strong><p>We need to know which datasets, held by government to release entire datasets...</p></a></li> <li><a href="/odug/overview"><strong>What Happens to Data Requests?</strong><p>Alongside the Cabinet Office and members of the community we will, on a routine basis, categorise...</p></a></li> </ul></div>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '24178036-de89-409b-94be-f5df476034af';
    $display->content['new-24178036-de89-409b-94be-f5df476034af'] = $pane;
    $display->panels['left'][1] = 'new-24178036-de89-409b-94be-f5df476034af';
    $pane = new stdClass();
    $pane->pid = 'new-82e4a425-e80e-4fbd-90f6-7474874841ee';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create dataset_request content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Request new data (for authenticated users)',
      'title' => '',
      'body' => '<p class="center-contents"><a class="btn-default btn btn-primary" href="/node/add/dataset-request">Request new data</a></p><p>This form will allow you to submit a data request.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '82e4a425-e80e-4fbd-90f6-7474874841ee';
    $display->content['new-82e4a425-e80e-4fbd-90f6-7474874841ee'] = $pane;
    $display->panels['right'][0] = 'new-82e4a425-e80e-4fbd-90f6-7474874841ee';
    $pane = new stdClass();
    $pane->pid = 'new-b5e2e192-4b19-47d9-b0a5-d1c9eb4edf27';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Request new data (for anonymous users)',
      'title' => '',
      'body' => '<p class="center-contents"><a class="btn-default btn btn-primary" href="/user/login?destination=/node/add/dataset-request">Login to request new data</a></p><p>This form will allow you to submit a data request.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b5e2e192-4b19-47d9-b0a5-d1c9eb4edf27';
    $display->content['new-b5e2e192-4b19-47d9-b0a5-d1c9eb4edf27'] = $pane;
    $display->panels['right'][1] = 'new-b5e2e192-4b19-47d9-b0a5-d1c9eb4edf27';
    $pane = new stdClass();
    $pane->pid = 'new-3a89a8ee-3d18-4840-a133-2ad711775262';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Progress on requests',
      'body' => '<p><a href="/odug/roadmap"><img alt="" src="/profiles/dgu/modules/features/dgu_data_set_request/odug-roadmap.png"> </a></p><p><a class="btn-default btn btn-primary" href="/odug/roadmap">See Dashboard</a></p><p><a href="/odug/status">Find out more about data request status</a></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3a89a8ee-3d18-4840-a133-2ad711775262';
    $display->content['new-3a89a8ee-3d18-4840-a133-2ad711775262'] = $pane;
    $display->panels['right'][2] = 'new-3a89a8ee-3d18-4840-a133-2ad711775262';
    $pane = new stdClass();
    $pane->pid = 'new-f451cb03-f573-44c2-b44a-ac9e612d0a44';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'ODUG Members',
      'body' => '<a href="/users/robert_barr">Robert Barr</a><br/>
<a href="/users/dlazanski">Dominique Lazanski</a><br/>
<a href="/users/gschimd">Gesche Schmid</a><br/>
<a href="/users/jacqui-taylor">Jacqui Taylor</a><br/>
<a href="/users/charlieboundy">Charlie Boundy</a><br/>
<a href="/users/alex-kafetz">Alex Kafetz</a><br/>
<a href="/users/duncan3ross">Duncan Ross</a><br/>
<a href="/users/puntofisso">Giuseppe Sollazzo</a><br/>
<a href="/users/tomsmith">Tom Smith</a><br/>
Carlos Somohano<br/>
Paul Fenton<br/>
<a href="/users/hsavory">Heather Savory</a><br/>
<a href="/users/pmalyon">Paul Malyon</a><br/>
<a href="/users/jenit">Jeni Tennison</a><br/>
<a href="/users/harveylewis">Harvey Lewis</a><br/>',
      'format' => 'unfiltered',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'f451cb03-f573-44c2-b44a-ac9e612d0a44';
    $display->content['new-f451cb03-f573-44c2-b44a-ac9e612d0a44'] = $pane;
    $display->panels['right'][3] = 'new-f451cb03-f573-44c2-b44a-ac9e612d0a44';
    $pane = new stdClass();
    $pane->pid = 'new-39be7df2-e371-4daa-b6e4-9de1c94d1c24';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Useful links',
      'body' => '<a href="http://www.theodi.org ">The Open Data Institute</a>
<a href="http://www.bis.gov.uk/transparency/data-strategy-board ">The Data Strategy board</a>
<a href="http://www.cabinetoffice.gov.uk/content/open-data-user-group ">Cabinet Office ODUG page</a>
<a href="http://www.bis.gov.uk/policies/shareholderexecutive/structure/portfolio-unit/public-data-group/background">Public Data Group</a>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '39be7df2-e371-4daa-b6e4-9de1c94d1c24';
    $display->content['new-39be7df2-e371-4daa-b6e4-9de1c94d1c24'] = $pane;
    $display->panels['right'][4] = 'new-39be7df2-e371-4daa-b6e4-9de1c94d1c24';
    $pane = new stdClass();
    $pane->pid = 'new-70b3a47d-f58b-4464-8d26-dea3be9ac6f6';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'edit any dataset_request content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Data request administration',
      'body' => '<a href="/admin/all_data_requests">Browse data requests</a>
<br />
<a href="/admin/all_data_requests/csv">Download data requests</a>',
      'format' => 'unfiltered',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '70b3a47d-f58b-4464-8d26-dea3be9ac6f6';
    $display->content['new-70b3a47d-f58b-4464-8d26-dea3be9ac6f6'] = $pane;
    $display->panels['right'][5] = 'new-70b3a47d-f58b-4464-8d26-dea3be9ac6f6';
    $pane = new stdClass();
    $pane->pid = 'new-793ded4a-80ec-4cbb-9114-261f1ce99384';
    $pane->panel = 'top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'override_title' => 0,
      'override_title_text' => '',
      'content_type' => 'dataset_request',
      'show_counter' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '793ded4a-80ec-4cbb-9114-261f1ce99384';
    $display->content['new-793ded4a-80ec-4cbb-9114-261f1ce99384'] = $pane;
    $display->panels['top'][0] = 'new-793ded4a-80ec-4cbb-9114-261f1ce99384';
    $pane = new stdClass();
    $pane->pid = 'new-cd51f50b-8e6a-4d82-abaa-ac0b28b3210b';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-data-requests-tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'menu-tabs',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cd51f50b-8e6a-4d82-abaa-ac0b28b3210b';
    $display->content['new-cd51f50b-8e6a-4d82-abaa-ac0b28b3210b'] = $pane;
    $display->panels['top'][1] = 'new-cd51f50b-8e6a-4d82-abaa-ac0b28b3210b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-82e4a425-e80e-4fbd-90f6-7474874841ee';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['data_requests_minutes'] = $page;

  return $pages;

}
