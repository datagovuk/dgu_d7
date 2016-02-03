<?php
/**
 * @file
 * dgu_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_search_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_results';
  $page->task = 'page';
  $page->admin_title = 'Search Results';
  $page->admin_description = 'This is the default search results page.';
  $page->path = 'search/everything/!query';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'query' => array(
      'id' => 1,
      'identifier' => 'Search Query',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
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
  $handler->name = 'page_search_results_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search_results';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Search',
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
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'top-left' => NULL,
      'top-right' => NULL,
      'left_top' => NULL,
      'left_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '15cdbd52-bd67-4308-892e-4826af1eb5fa';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-df9164c3-0be7-43b7-b955-fa07bcfa9cf0';
    $pane->panel = 'left_bottom';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu';
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
    $pane->uuid = 'df9164c3-0be7-43b7-b955-fa07bcfa9cf0';
    $display->content['new-df9164c3-0be7-43b7-b955-fa07bcfa9cf0'] = $pane;
    $display->panels['left_bottom'][0] = 'new-df9164c3-0be7-43b7-b955-fa07bcfa9cf0';
    $pane = new stdClass();
    $pane->pid = 'new-5d8f12d0-c6fa-42cb-a5ee-9d267e6a3566';
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
    $pane->uuid = '5d8f12d0-c6fa-42cb-a5ee-9d267e6a3566';
    $display->content['new-5d8f12d0-c6fa-42cb-a5ee-9d267e6a3566'] = $pane;
    $display->panels['left_bottom'][1] = 'new-5d8f12d0-c6fa-42cb-a5ee-9d267e6a3566';
    $pane = new stdClass();
    $pane->pid = 'new-4884e508-85dc-42ab-a803-25665b6f8514';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4884e508-85dc-42ab-a803-25665b6f8514';
    $display->content['new-4884e508-85dc-42ab-a803-25665b6f8514'] = $pane;
    $display->panels['left_bottom'][2] = 'new-4884e508-85dc-42ab-a803-25665b6f8514';
    $pane = new stdClass();
    $pane->pid = 'new-dbb39072-9d76-49ca-8cb7-49159cd08d74';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'dbb39072-9d76-49ca-8cb7-49159cd08d74';
    $display->content['new-dbb39072-9d76-49ca-8cb7-49159cd08d74'] = $pane;
    $display->panels['left_bottom'][3] = 'new-dbb39072-9d76-49ca-8cb7-49159cd08d74';
    $pane = new stdClass();
    $pane->pid = 'new-e2ce9cb9-ca4b-44f4-a043-362dd227dd37';
    $pane->panel = 'left_bottom';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-EkFIUzN6EE00EWS2gBWyGz9V0YUXSMXP';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e2ce9cb9-ca4b-44f4-a043-362dd227dd37';
    $display->content['new-e2ce9cb9-ca4b-44f4-a043-362dd227dd37'] = $pane;
    $display->panels['left_bottom'][4] = 'new-e2ce9cb9-ca4b-44f4-a043-362dd227dd37';
    $pane = new stdClass();
    $pane->pid = 'new-df752782-7934-4659-8aca-e4920b312bc8';
    $pane->panel = 'left_bottom';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-nNIok1zEcTDdArOSMLOe8qvM7lVhDjlG';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'df752782-7934-4659-8aca-e4920b312bc8';
    $display->content['new-df752782-7934-4659-8aca-e4920b312bc8'] = $pane;
    $display->panels['left_bottom'][5] = 'new-df752782-7934-4659-8aca-e4920b312bc8';
    $pane = new stdClass();
    $pane->pid = 'new-2ee7f629-e0e9-4b86-9e27-a96100acf1c2';
    $pane->panel = 'left_bottom';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-OMYIDTb0E4wA80mSSDf2mOJcq4aCjhX8';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '2ee7f629-e0e9-4b86-9e27-a96100acf1c2';
    $display->content['new-2ee7f629-e0e9-4b86-9e27-a96100acf1c2'] = $pane;
    $display->panels['left_bottom'][6] = 'new-2ee7f629-e0e9-4b86-9e27-a96100acf1c2';
    $pane = new stdClass();
    $pane->pid = 'new-c658204d-4bd3-4801-93f5-573ca048c124';
    $pane->panel = 'left_bottom';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-AGN1CtKA94JO5jVTLR1SN7DieSsqMDbx';
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'c658204d-4bd3-4801-93f5-573ca048c124';
    $display->content['new-c658204d-4bd3-4801-93f5-573ca048c124'] = $pane;
    $display->panels['left_bottom'][7] = 'new-c658204d-4bd3-4801-93f5-573ca048c124';
    $pane = new stdClass();
    $pane->pid = 'new-de056639-2af1-44f2-bc88-7de21001e967';
    $pane->panel = 'left_bottom';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-QzRqS0QDg8NoxrEl29HCuN0PLk60EtBa';
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'de056639-2af1-44f2-bc88-7de21001e967';
    $display->content['new-de056639-2af1-44f2-bc88-7de21001e967'] = $pane;
    $display->panels['left_bottom'][8] = 'new-de056639-2af1-44f2-bc88-7de21001e967';
    $pane = new stdClass();
    $pane->pid = 'new-44dce5b7-3b6f-4bf4-97b4-6f6560d4a663';
    $pane->panel = 'left_top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'all',
      'show_counter' => NULL,
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
    $pane->uuid = '44dce5b7-3b6f-4bf4-97b4-6f6560d4a663';
    $display->content['new-44dce5b7-3b6f-4bf4-97b4-6f6560d4a663'] = $pane;
    $display->panels['left_top'][0] = 'new-44dce5b7-3b6f-4bf4-97b4-6f6560d4a663';
    $pane = new stdClass();
    $pane->pid = 'new-e50ffdd4-7cca-4610-ae20-50ef42ed235a';
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
    $pane->uuid = 'e50ffdd4-7cca-4610-ae20-50ef42ed235a';
    $display->content['new-e50ffdd4-7cca-4610-ae20-50ef42ed235a'] = $pane;
    $display->panels['right'][0] = 'new-e50ffdd4-7cca-4610-ae20-50ef42ed235a';
    $pane = new stdClass();
    $pane->pid = 'new-7fc43c16-d67e-447b-9fd2-d046154aeaef';
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
      'filters' => 'entity_type:"node"',
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
    $pane->uuid = '7fc43c16-d67e-447b-9fd2-d046154aeaef';
    $display->content['new-7fc43c16-d67e-447b-9fd2-d046154aeaef'] = $pane;
    $display->panels['right'][1] = 'new-7fc43c16-d67e-447b-9fd2-d046154aeaef';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_results'] = $page;

  return $pages;

}
