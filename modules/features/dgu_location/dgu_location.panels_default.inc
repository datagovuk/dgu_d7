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
  $display->uuid = '97b46b4e-d69b-4b18-9294-3895a7db4f18';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4d6926ec-0e5b-48b1-a518-483666526046';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>The UK Location infrastructure enables you to find, share and reuse, location data, including data published under the INSPIRE Directive.</p><ul><li><strong>Find data...</strong><ul><li><a href="/data/search?UKLP=True">Search the location data catalogue</a></li><li><a href="/location/map-based-search">Find out more about map based search</a></li><li><a href="/location/preview-on-map">Find out more about preview on map</a></li></ul></li><li><strong>Find out about INSPIRE</strong><ul><li><a href="/library/factsheet-inspire-directive">INSPIRE factsheet</a></li><li><a href="/location/inspire">INSPIRE</a></li></ul></li><li><strong>Find out about publishing metadata</strong><ul><li><a href="/location/uk-location-infrastructure#metadataexplained">Discovery metadata service explained</a></li><li><a href="/library/uk-location-getting-started-guide-4-publishing-discovery-and-view-services">Getting started guide for discovery metadata</a></li><li><a href="/library/uk-location-discovery-metadata-service-operational-guide">Operational guide for metadata</a></li></ul></li><li><strong>Find out about view and download services</strong><ul><li><a href="/library/uk-location-getting-started-guide-4-publishing-discovery-and-view-services">Getting started guide for view services</a></li><li><a href="/library/uk-location-view-service-operational-guide">Operational guide for view services</a></li><li><a href="/library/uklp-download-services-operational-guidance">Operational guide for download services</a></li></ul></li></ul><p><a class="btn-default btn btn-primary" href="/location/guidance_and_tools" title="">See UK Location/INSPIRE Guidance now</a></p><div>To find out who to contact if you need to need advice or support please see the <a href="/location/contact_points" title="">location contacts</a> page.</div>',
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
    $pane->uuid = '4d6926ec-0e5b-48b1-a518-483666526046';
    $display->content['new-4d6926ec-0e5b-48b1-a518-483666526046'] = $pane;
    $display->panels['middle'][0] = 'new-4d6926ec-0e5b-48b1-a518-483666526046';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4d6926ec-0e5b-48b1-a518-483666526046';
  $mini->display = $display;
  $export['uk_location_infrastructure'] = $mini;

  return $export;
}
