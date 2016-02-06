<?php
/**
 * @file
 * dgu_app.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgu_app_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'App',
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
              'app' => 'app',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
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
  $display->title = 'Apps';
  $display->uuid = '5f7b65d6-7c4b-40f8-a5e2-360c78bc4961';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-23a84805-c4c5-4f44-a4db-ef6717bcab15';
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
    $pane->uuid = '23a84805-c4c5-4f44-a4db-ef6717bcab15';
    $display->content['new-23a84805-c4c5-4f44-a4db-ef6717bcab15'] = $pane;
    $display->panels['left'][0] = 'new-23a84805-c4c5-4f44-a4db-ef6717bcab15';
    $pane = new stdClass();
    $pane->pid = 'new-15a0fba4-c990-4f57-ad86-8371679069e1';
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
    $pane->uuid = '15a0fba4-c990-4f57-ad86-8371679069e1';
    $display->content['new-15a0fba4-c990-4f57-ad86-8371679069e1'] = $pane;
    $display->panels['right'][0] = 'new-15a0fba4-c990-4f57-ad86-8371679069e1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-23a84805-c4c5-4f44-a4db-ef6717bcab15';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_app_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apps';
  $page->task = 'page';
  $page->admin_title = 'Latest apps';
  $page->admin_description = 'Apps landing page';
  $page->path = 'apps';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Apps',
    'name' => 'menu-apps',
    'weight' => '3',
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
  $handler->name = 'page_apps_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'apps';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'apps',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_threecol_twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'top_left' => NULL,
      'top_middle' => NULL,
      'top_right' => NULL,
      'bottom_left' => NULL,
      'bottom_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '85db1cee-b450-47e1-beea-a3f50a3d7581';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-12d88fbd-f0c9-4703-9f5f-607e49f12ff9';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-apps-tabs';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '12d88fbd-f0c9-4703-9f5f-607e49f12ff9';
    $display->content['new-12d88fbd-f0c9-4703-9f5f-607e49f12ff9'] = $pane;
    $display->panels['bottom'][0] = 'new-12d88fbd-f0c9-4703-9f5f-607e49f12ff9';
    $pane = new stdClass();
    $pane->pid = 'new-8f4ff967-d376-4055-9561-d3648a2377d9';
    $pane->panel = 'bottom';
    $pane->type = 'views';
    $pane->subtype = 'apps';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '8',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'latest_apps',
      'override_title' => 1,
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
    $pane->uuid = '8f4ff967-d376-4055-9561-d3648a2377d9';
    $display->content['new-8f4ff967-d376-4055-9561-d3648a2377d9'] = $pane;
    $display->panels['bottom'][1] = 'new-8f4ff967-d376-4055-9561-d3648a2377d9';
    $pane = new stdClass();
    $pane->pid = 'new-212b0bea-4512-4c1f-a422-448122ce01ab';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Add your app (for authenticated users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/node/add/app">Add your app &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '212b0bea-4512-4c1f-a422-448122ce01ab';
    $display->content['new-212b0bea-4512-4c1f-a422-448122ce01ab'] = $pane;
    $display->panels['bottom'][2] = 'new-212b0bea-4512-4c1f-a422-448122ce01ab';
    $pane = new stdClass();
    $pane->pid = 'new-7d280943-4fea-4786-911a-863b967a6e11';
    $pane->panel = 'bottom';
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
      'admin_title' => 'Add your app (for anonymous users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/user/login?destination=/apps">Login to add your app &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '7d280943-4fea-4786-911a-863b967a6e11';
    $display->content['new-7d280943-4fea-4786-911a-863b967a6e11'] = $pane;
    $display->panels['bottom'][3] = 'new-7d280943-4fea-4786-911a-863b967a6e11';
    $pane = new stdClass();
    $pane->pid = 'new-dcb99dc4-11a3-456c-913f-c38ab91c5d9e';
    $pane->panel = 'top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'app',
      'override_title' => 0,
      'override_title_text' => '',
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
    $pane->uuid = 'dcb99dc4-11a3-456c-913f-c38ab91c5d9e';
    $display->content['new-dcb99dc4-11a3-456c-913f-c38ab91c5d9e'] = $pane;
    $display->panels['top'][0] = 'new-dcb99dc4-11a3-456c-913f-c38ab91c5d9e';
    $pane = new stdClass();
    $pane->pid = 'new-8cfc4981-7d9c-4d78-ac6f-a61fdd67a870';
    $pane->panel = 'top_left';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:19';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8cfc4981-7d9c-4d78-ac6f-a61fdd67a870';
    $display->content['new-8cfc4981-7d9c-4d78-ac6f-a61fdd67a870'] = $pane;
    $display->panels['top_left'][0] = 'new-8cfc4981-7d9c-4d78-ac6f-a61fdd67a870';
    $pane = new stdClass();
    $pane->pid = 'new-f32cb166-f7c7-4c94-9937-800a5cfea55d';
    $pane->panel = 'top_middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:20';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f32cb166-f7c7-4c94-9937-800a5cfea55d';
    $display->content['new-f32cb166-f7c7-4c94-9937-800a5cfea55d'] = $pane;
    $display->panels['top_middle'][0] = 'new-f32cb166-f7c7-4c94-9937-800a5cfea55d';
    $pane = new stdClass();
    $pane->pid = 'new-2cb9c348-3f37-491c-b587-cff4cdd581e0';
    $pane->panel = 'top_right';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:21';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2cb9c348-3f37-491c-b587-cff4cdd581e0';
    $display->content['new-2cb9c348-3f37-491c-b587-cff4cdd581e0'] = $pane;
    $display->panels['top_right'][0] = 'new-2cb9c348-3f37-491c-b587-cff4cdd581e0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apps'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'top_rated_apps';
  $page->task = 'page';
  $page->admin_title = 'Top rated apps';
  $page->admin_description = 'Apps landing page';
  $page->path = 'apps/top';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Apps',
    'name' => 'menu-apps',
    'weight' => '3',
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
  $handler->name = 'page_top_rated_apps_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'top_rated_apps';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'apps',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_threecol_twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'top_left' => NULL,
      'top_middle' => NULL,
      'top_right' => NULL,
      'bottom_left' => NULL,
      'bottom_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '537c72e4-605e-40f1-94c5-f8c5e30e6ec0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cdc7156b-f158-4c18-b6f6-1957e9a3fa8d';
    $pane->panel = 'bottom';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-apps-tabs';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cdc7156b-f158-4c18-b6f6-1957e9a3fa8d';
    $display->content['new-cdc7156b-f158-4c18-b6f6-1957e9a3fa8d'] = $pane;
    $display->panels['bottom'][0] = 'new-cdc7156b-f158-4c18-b6f6-1957e9a3fa8d';
    $pane = new stdClass();
    $pane->pid = 'new-8c7591e4-7c04-4767-a20e-f8bb90b78f0f';
    $pane->panel = 'bottom';
    $pane->type = 'views';
    $pane->subtype = 'apps';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '8',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'top_rated_apps',
      'override_title' => 1,
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
    $pane->uuid = '8c7591e4-7c04-4767-a20e-f8bb90b78f0f';
    $display->content['new-8c7591e4-7c04-4767-a20e-f8bb90b78f0f'] = $pane;
    $display->panels['bottom'][1] = 'new-8c7591e4-7c04-4767-a20e-f8bb90b78f0f';
    $pane = new stdClass();
    $pane->pid = 'new-fd326d69-88e4-478e-926e-09f18701ed74';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Add your app (for authenticated users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/node/add/app">Add your app &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'fd326d69-88e4-478e-926e-09f18701ed74';
    $display->content['new-fd326d69-88e4-478e-926e-09f18701ed74'] = $pane;
    $display->panels['bottom'][2] = 'new-fd326d69-88e4-478e-926e-09f18701ed74';
    $pane = new stdClass();
    $pane->pid = 'new-c6834d17-08b1-485b-82a4-c9b69b8449bb';
    $pane->panel = 'bottom';
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
      'admin_title' => 'Add your app (for anonymous users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/user/login?destination=/apps">Login to add your app &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c6834d17-08b1-485b-82a4-c9b69b8449bb';
    $display->content['new-c6834d17-08b1-485b-82a4-c9b69b8449bb'] = $pane;
    $display->panels['bottom'][3] = 'new-c6834d17-08b1-485b-82a4-c9b69b8449bb';
    $pane = new stdClass();
    $pane->pid = 'new-0a7ecec0-a7d4-4e87-98ef-4cfa6fb764a8';
    $pane->panel = 'top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'app',
      'override_title' => 0,
      'override_title_text' => '',
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
    $pane->uuid = '0a7ecec0-a7d4-4e87-98ef-4cfa6fb764a8';
    $display->content['new-0a7ecec0-a7d4-4e87-98ef-4cfa6fb764a8'] = $pane;
    $display->panels['top'][0] = 'new-0a7ecec0-a7d4-4e87-98ef-4cfa6fb764a8';
    $pane = new stdClass();
    $pane->pid = 'new-04a1e7c0-67b7-42b1-bef3-0a9564934094';
    $pane->panel = 'top_left';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:19';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '04a1e7c0-67b7-42b1-bef3-0a9564934094';
    $display->content['new-04a1e7c0-67b7-42b1-bef3-0a9564934094'] = $pane;
    $display->panels['top_left'][0] = 'new-04a1e7c0-67b7-42b1-bef3-0a9564934094';
    $pane = new stdClass();
    $pane->pid = 'new-6d372943-a141-4977-bea3-c99248492487';
    $pane->panel = 'top_middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:20';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6d372943-a141-4977-bea3-c99248492487';
    $display->content['new-6d372943-a141-4977-bea3-c99248492487'] = $pane;
    $display->panels['top_middle'][0] = 'new-6d372943-a141-4977-bea3-c99248492487';
    $pane = new stdClass();
    $pane->pid = 'new-2bed99c9-4d3d-435a-bd64-24f6299d3c4e';
    $pane->panel = 'top_right';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:21';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2bed99c9-4d3d-435a-bd64-24f6299d3c4e';
    $display->content['new-2bed99c9-4d3d-435a-bd64-24f6299d3c4e'] = $pane;
    $display->panels['top_right'][0] = 'new-2bed99c9-4d3d-435a-bd64-24f6299d3c4e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['top_rated_apps'] = $page;

  return $pages;

}
