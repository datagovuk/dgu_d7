<?php
/**
 * @file
 * dgu_glossary.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_glossary_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'glossary_thank_you_page';
  $page->task = 'page';
  $page->admin_title = 'Glossary thank you page';
  $page->admin_description = '';
  $page->path = 'glossary/suggest_definition/thanks';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_glossary_thank_you_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'glossary_thank_you_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'glossary-thank-you',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Thank you for your suggestion';
  $display->uuid = '86c3e135-5457-43bf-9444-6624798d216c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-85e5217c-4cc3-42d6-8260-7f8e0ab20f38';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => 'Thank you for your suggestion. We will normally get back to you within 5 working days.',
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
    $pane->uuid = '85e5217c-4cc3-42d6-8260-7f8e0ab20f38';
    $display->content['new-85e5217c-4cc3-42d6-8260-7f8e0ab20f38'] = $pane;
    $display->panels['middle'][0] = 'new-85e5217c-4cc3-42d6-8260-7f8e0ab20f38';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-85e5217c-4cc3-42d6-8260-7f8e0ab20f38';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['glossary_thank_you_page'] = $page;

  return $pages;

}
