<?php
/**
 * @file
 * dgu_library.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgu_library_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 7;
  $handler->conf = array(
    'title' => 'Library',
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
              'resource' => 'resource',
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
  $display->title = 'Library';
  $display->uuid = '76b93220-0af9-4dee-9991-ab858a8c7bf0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c65b08fd-5744-4eae-88cf-ba4f85d432b0';
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
    $pane->uuid = 'c65b08fd-5744-4eae-88cf-ba4f85d432b0';
    $display->content['new-c65b08fd-5744-4eae-88cf-ba4f85d432b0'] = $pane;
    $display->panels['left'][0] = 'new-c65b08fd-5744-4eae-88cf-ba4f85d432b0';
    $pane = new stdClass();
    $pane->pid = 'new-80e3fa46-5a4f-4858-b532-5fc02f0d3d79';
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
    $pane->uuid = '80e3fa46-5a4f-4858-b532-5fc02f0d3d79';
    $display->content['new-80e3fa46-5a4f-4858-b532-5fc02f0d3d79'] = $pane;
    $display->panels['right'][0] = 'new-80e3fa46-5a4f-4858-b532-5fc02f0d3d79';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c65b08fd-5744-4eae-88cf-ba4f85d432b0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_library_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'library';
  $page->task = 'page';
  $page->admin_title = 'Library';
  $page->admin_description = '';
  $page->path = 'library/!query';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Library',
    'name' => 'main-menu',
    'weight' => '5',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'query' => array(
      'id' => 1,
      'identifier' => 'Search Query',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 1,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_search';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'top-left' => NULL,
      'top-right' => NULL,
      'left_top' => NULL,
      'left_bottom' => NULL,
    ),
    'left' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Library';
  $display->uuid = 'fa153cf3-53ef-41de-b7fe-b9101d8f8e1a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-40e79334-582e-4b08-a7bd-830ef4689f16';
    $pane->panel = 'left_bottom';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-rdivo01SKN5F1E4FueqZJl3JRX19bxQ4';
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
    $pane->uuid = '40e79334-582e-4b08-a7bd-830ef4689f16';
    $display->content['new-40e79334-582e-4b08-a7bd-830ef4689f16'] = $pane;
    $display->panels['left_bottom'][0] = 'new-40e79334-582e-4b08-a7bd-830ef4689f16';
    $pane = new stdClass();
    $pane->pid = 'new-3aceeca7-21e9-471d-aa22-9e992e233be9';
    $pane->panel = 'left_bottom';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-4Zh0ggJMBgeeYbrLPJCe8EML3A6PLE0J';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3aceeca7-21e9-471d-aa22-9e992e233be9';
    $display->content['new-3aceeca7-21e9-471d-aa22-9e992e233be9'] = $pane;
    $display->panels['left_bottom'][1] = 'new-3aceeca7-21e9-471d-aa22-9e992e233be9';
    $pane = new stdClass();
    $pane->pid = 'new-51a44292-2427-4dbf-ac00-218df8fb0585';
    $pane->panel = 'left_bottom';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-DlKt6k0NxuIZ3UKJlQnnoHsJVwxoJMbY';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '51a44292-2427-4dbf-ac00-218df8fb0585';
    $display->content['new-51a44292-2427-4dbf-ac00-218df8fb0585'] = $pane;
    $display->panels['left_bottom'][2] = 'new-51a44292-2427-4dbf-ac00-218df8fb0585';
    $pane = new stdClass();
    $pane->pid = 'new-5ec47a26-97fd-48d2-b888-acc1b0444a07';
    $pane->panel = 'left_top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'all',
      'override_title' => 0,
      'override_title_text' => '',
      'show_counter' => NULL,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5ec47a26-97fd-48d2-b888-acc1b0444a07';
    $display->content['new-5ec47a26-97fd-48d2-b888-acc1b0444a07'] = $pane;
    $display->panels['left_top'][0] = 'new-5ec47a26-97fd-48d2-b888-acc1b0444a07';
    $pane = new stdClass();
    $pane->pid = 'new-2fb4e8a1-bbeb-419c-afd9-d84318361b3c';
    $pane->panel = 'right';
    $pane->type = 'dgu_search_info';
    $pane->subtype = 'dgu_search_info';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2fb4e8a1-bbeb-419c-afd9-d84318361b3c';
    $display->content['new-2fb4e8a1-bbeb-419c-afd9-d84318361b3c'] = $pane;
    $display->panels['right'][0] = 'new-2fb4e8a1-bbeb-419c-afd9-d84318361b3c';
    $pane = new stdClass();
    $pane->pid = 'new-c8d8de2d-53b8-47e7-a3a7-de03ad8b822d';
    $pane->panel = 'right';
    $pane->type = 'apachesolr_result';
    $pane->subtype = 'apachesolr_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'keys_action' => 'none',
      'keys' => '',
      'keys_required' => 0,
      'filters_action' => 'append',
      'filters' => 'bundle:resource',
      'rows' => '10',
      'env_id' => '',
      'sort_action' => 'fallback',
      'sort' => 'ds_changed desc',
      'breadcrumb' => 1,
      'title_override' => 0,
      'title_override_text' => '',
      'empty_override' => 0,
      'empty_override_title' => '',
      'empty_override_text' => array(
        'value' => '',
        'format' => 'plain_text',
      ),
      'empty_override_format' => 'plain_text',
      'log' => 0,
      'substitute' => 0,
      'context' => 'argument_string_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c8d8de2d-53b8-47e7-a3a7-de03ad8b822d';
    $display->content['new-c8d8de2d-53b8-47e7-a3a7-de03ad8b822d'] = $pane;
    $display->panels['right'][1] = 'new-c8d8de2d-53b8-47e7-a3a7-de03ad8b822d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['library'] = $page;

  return $pages;

}
