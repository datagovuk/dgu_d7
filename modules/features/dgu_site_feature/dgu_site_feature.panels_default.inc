<?php
/**
 * @file
 * dgu_site_feature.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function dgu_site_feature_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'what_s_data_gov_uk_all_about_';
  $mini->category = 'Mini Panels';
  $mini->admin_title = 'What\'s data.gov.uk all about?';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->title = 'What\'s data.gov.uk all about?';
  $display->uuid = '4a4a5a66-148d-41ad-a329-d16101aefe25';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-75223d05-8e09-44a5-81ae-d079cc9cf933';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Hear more about the Government\'s Transparency agenda from the Prime Minister.</p><div class="fluidVideo"><iframe allowfullscreen="" frameborder="0" height="240" src="https://www.youtube.com/embed/0stXV_fWWtU?wmode=transparent&amp;rel=0" width="220"></iframe></div>',
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
    $pane->uuid = '75223d05-8e09-44a5-81ae-d079cc9cf933';
    $display->content['new-75223d05-8e09-44a5-81ae-d079cc9cf933'] = $pane;
    $display->panels['middle'][0] = 'new-75223d05-8e09-44a5-81ae-d079cc9cf933';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-75223d05-8e09-44a5-81ae-d079cc9cf933';
  $mini->display = $display;
  $export['what_s_data_gov_uk_all_about_'] = $mini;

  return $export;
}
