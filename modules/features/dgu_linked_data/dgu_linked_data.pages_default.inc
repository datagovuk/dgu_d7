<?php
/**
 * @file
 * dgu_linked_data.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgu_linked_data_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Linked data pages',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'linked-data/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
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
  $display->title = 'Linked data';
  $display->uuid = '2d29cffc-fe6c-4e67-93ce-d8fa816dc765';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b3045944-1a06-418d-9b20-f136fc6d663f';
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
      'leave_node_title' => 0,
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
    $pane->uuid = 'b3045944-1a06-418d-9b20-f136fc6d663f';
    $display->content['new-b3045944-1a06-418d-9b20-f136fc6d663f'] = $pane;
    $display->panels['left'][0] = 'new-b3045944-1a06-418d-9b20-f136fc6d663f';
    $pane = new stdClass();
    $pane->pid = 'new-13176ee0-00a3-4ae9-a0e7-1370d5a56b7a';
    $pane->panel = 'right';
    $pane->type = 'panels_mini';
    $pane->subtype = '10_seconds_tour';
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
    $pane->uuid = '13176ee0-00a3-4ae9-a0e7-1370d5a56b7a';
    $display->content['new-13176ee0-00a3-4ae9-a0e7-1370d5a56b7a'] = $pane;
    $display->panels['right'][0] = 'new-13176ee0-00a3-4ae9-a0e7-1370d5a56b7a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b3045944-1a06-418d-9b20-f136fc6d663f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_linked_data_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'linked_data';
  $page->task = 'page';
  $page->admin_title = 'Linked data';
  $page->admin_description = 'Linked data landing page';
  $page->path = 'linked-data';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Linked Data',
    'name' => 'main-menu',
    'weight' => '7',
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
  $handler->name = 'page_linked_data_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'linked_data';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'linked-data',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '50fe26e8-7fd4-4929-832a-9d3232440216';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fc76e9a7-a126-4d16-957d-d7c0c4f7fb76';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'What is linked data?',
      'title' => 'What is linked data?',
      'body' => '<div class="fluidVideo"><iframe width="736" height="414" src="//www.youtube.com/embed/OM6XIICm_qo?HD=1;rel=0;showinfo=0" frameborder="0" allowfullscreen></iframe></div>
<br /><p>Sir Tim Berners-Lee\'s talk from TED2009 on TED.com</p>',
      'format' => 'full_html',
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
    $pane->uuid = 'fc76e9a7-a126-4d16-957d-d7c0c4f7fb76';
    $display->content['new-fc76e9a7-a126-4d16-957d-d7c0c4f7fb76'] = $pane;
    $display->panels['left'][0] = 'new-fc76e9a7-a126-4d16-957d-d7c0c4f7fb76';
    $pane = new stdClass();
    $pane->pid = 'new-10d352bc-b28a-4d4d-810b-87c45209b5df';
    $pane->panel = 'right';
    $pane->type = 'panels_mini';
    $pane->subtype = '10_seconds_tour';
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
    $pane->uuid = '10d352bc-b28a-4d4d-810b-87c45209b5df';
    $display->content['new-10d352bc-b28a-4d4d-810b-87c45209b5df'] = $pane;
    $display->panels['right'][0] = 'new-10d352bc-b28a-4d4d-810b-87c45209b5df';
    $pane = new stdClass();
    $pane->pid = 'new-36a12d5e-050a-48fd-913a-e7fa75fc1144';
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
      'display' => 'blogs_linked_data',
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
    $pane->uuid = '36a12d5e-050a-48fd-913a-e7fa75fc1144';
    $display->content['new-36a12d5e-050a-48fd-913a-e7fa75fc1144'] = $pane;
    $display->panels['right'][1] = 'new-36a12d5e-050a-48fd-913a-e7fa75fc1144';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['linked_data'] = $page;

  return $pages;

}
