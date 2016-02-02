<?php
/**
 * @file
 * dgu_location.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgu_location_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Location pages',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'location-subpage',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'location/*',
          ),
          'context' => 'empty',
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
  $display->title = 'Location';
  $display->uuid = 'ebb7f716-678a-4382-b023-183917300575';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7384c993-a4fd-4cfd-916b-6a40054695fe';
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
    $pane->uuid = '7384c993-a4fd-4cfd-916b-6a40054695fe';
    $display->content['new-7384c993-a4fd-4cfd-916b-6a40054695fe'] = $pane;
    $display->panels['left'][0] = 'new-7384c993-a4fd-4cfd-916b-6a40054695fe';
    $pane = new stdClass();
    $pane->pid = 'new-6b42e182-c80e-4af3-87d8-630e67329151';
    $pane->panel = 'right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'uk_location_infrastructure';
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
    $pane->uuid = '6b42e182-c80e-4af3-87d8-630e67329151';
    $display->content['new-6b42e182-c80e-4af3-87d8-630e67329151'] = $pane;
    $display->panels['right'][0] = 'new-6b42e182-c80e-4af3-87d8-630e67329151';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_location_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'location';
  $page->task = 'page';
  $page->admin_title = 'Location';
  $page->admin_description = 'Location landing page';
  $page->path = 'location';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Location',
    'name' => 'main-menu',
    'weight' => '6',
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
  $handler->name = 'page_location_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'location';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'location',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_threecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e8bebc6c-eb80-40b2-b9be-e080383de070';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bc5d4500-2468-4ef4-9403-4544d0067fa6';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'blogs';
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
      'display' => 'blogs_location',
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
    $pane->uuid = 'bc5d4500-2468-4ef4-9403-4544d0067fa6';
    $display->content['new-bc5d4500-2468-4ef4-9403-4544d0067fa6'] = $pane;
    $display->panels['left'][0] = 'new-bc5d4500-2468-4ef4-9403-4544d0067fa6';
    $pane = new stdClass();
    $pane->pid = 'new-94bf8f14-7f55-4a40-87a1-2921bcccf9b2';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'uk_location_infrastructure';
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
    $pane->uuid = '94bf8f14-7f55-4a40-87a1-2921bcccf9b2';
    $display->content['new-94bf8f14-7f55-4a40-87a1-2921bcccf9b2'] = $pane;
    $display->panels['middle'][0] = 'new-94bf8f14-7f55-4a40-87a1-2921bcccf9b2';
    $pane = new stdClass();
    $pane->pid = 'new-08942f24-2cfc-4fda-aa70-8ec6da02afcf';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'List of Location Data',
      'title' => '',
      'body' => '<div class="item-list"><p><a href="/data/search?ext_bbox=-20.48,48.79,3.11,62.66">See the list of location data</a></p></div>',
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
    $pane->uuid = '08942f24-2cfc-4fda-aa70-8ec6da02afcf';
    $display->content['new-08942f24-2cfc-4fda-aa70-8ec6da02afcf'] = $pane;
    $display->panels['right'][0] = 'new-08942f24-2cfc-4fda-aa70-8ec6da02afcf';
    $pane = new stdClass();
    $pane->pid = 'new-c3f55fe4-60ea-4b3d-8077-35b9b51b0cd3';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Map based search',
      'body' => '<a class="btn-default btn btn-primary" href="/data/map-based-search">Conduct Map Based Search</a><p>To find out which location datasets cover a particular location you can use Map Based Search.</p>',
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
    $pane->uuid = 'c3f55fe4-60ea-4b3d-8077-35b9b51b0cd3';
    $display->content['new-c3f55fe4-60ea-4b3d-8077-35b9b51b0cd3'] = $pane;
    $display->panels['right'][1] = 'new-c3f55fe4-60ea-4b3d-8077-35b9b51b0cd3';
    $pane = new stdClass();
    $pane->pid = 'new-1fa2a65d-3c29-42f8-bc3a-cd7acdbcae07';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'UK Location website',
      'body' => '<p>An archive of the UK Location website is available in the <a href="http://webarchive.nationalarchives.gov.uk/*/http:/location.defra.gov.uk">National Archives</a>.</p>',
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
    $pane->uuid = '1fa2a65d-3c29-42f8-bc3a-cd7acdbcae07';
    $display->content['new-1fa2a65d-3c29-42f8-bc3a-cd7acdbcae07'] = $pane;
    $display->panels['right'][2] = 'new-1fa2a65d-3c29-42f8-bc3a-cd7acdbcae07';
    $pane = new stdClass();
    $pane->pid = 'new-6d94348b-ad84-4191-bdb8-d4c508600742';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'List of Apps',
      'title' => '',
      'body' => '<div class="item-list" style="font-size: 13px; line-height: 20px;"><p><a href="/search/everything/?f[0]=bundle%3Aapp">See apps developed with location data</a></p></div>',
      'format' => 'filtered_html',
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
    $pane->uuid = '6d94348b-ad84-4191-bdb8-d4c508600742';
    $display->content['new-6d94348b-ad84-4191-bdb8-d4c508600742'] = $pane;
    $display->panels['right'][3] = 'new-6d94348b-ad84-4191-bdb8-d4c508600742';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['location'] = $page;

  return $pages;

}
