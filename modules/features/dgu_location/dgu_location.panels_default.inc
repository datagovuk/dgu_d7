<?php
/**
 * @file
 * dgu_location.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function dgu_location_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'uk_location_infrastructure';
  $mini->category = 'Mini Panels';
  $mini->admin_title = 'UK Location Infrastructure';
  $mini->admin_description = 'Content of \'UK Location Infrastructure\' block';
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
  $display->title = 'UK Location Infrastructure';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<div class="item-list"><ul><li><strong><a href="/location/uk-location-infrastructure#metadataexplained">Discovery Metadata Service explained</a></strong><ul><li><a href="/library/uk-location-getting-started-guide-4-publishing-discovery-and-view-services">Getting Started Guide for discovery metadata</a></li><li><a href="/library/uk-location-discovery-metadata-service-operational-guide">Operational Guide for metadata</a></li><li><a href="/location/map-based-search">Find out more about Map Based Search</a></li></ul></li><li><strong><a href="/location/uk-location-infrastructure#viewserviceexplained">View Service explained</a></strong><ul><li><a href="/library/uk-location-getting-started-guide-4-publishing-discovery-and-view-services">Getting Started Guide for view services</a></li><li><a href="/library/uk-location-view-service-operational-guide">Operational Guide for view services</a></li><li><a href="/location/preview-on-map">Find out more about Preview on Map</a></li></ul></li><li><a href="/location/uk-location-infrastructure#whatscoming"><strong>What\'s coming up next</strong></a></li></ul></div>',
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
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $mini->display = $display;
  $export['uk_location_infrastructure'] = $mini;

  return $export;
}
