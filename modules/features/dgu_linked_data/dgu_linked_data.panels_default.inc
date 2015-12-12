<?php
/**
 * @file
 * dgu_linked_data.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function dgu_linked_data_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = '10_seconds_tour';
  $mini->category = 'Mini Panels';
  $mini->admin_title = '10_seconds_tour';
  $mini->admin_description = '\'10 second tour\' block on linked data pages';
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
  $display->title = '10 second tour';
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
      'body' => '<div class="item-list">
	<ul>
		<li><a href="/linked-data/overview-of-linked-data"><strong>Overview of Linked Data</strong></a>
			<p>Across government over the last ten years there has been a growing realisation to the power of linked data for exposing, sharing, and connecting pieces of data and information using uniform resource identifiers (URIs).</p>
		</li>
		<li><a href="/linked-data/what-is-linked-data"><strong>What is Linked Data?</strong></a>
			<p>Linked Data is data in which real-world things are given addresses on the web (URIs), and data is published about them in machine-readable formats.</p>
		</li>
		<li><a href="/linked-data/list-linked-datasets-vocabularies"><strong>List of Linked Datasets &amp; Vocabularies</strong></a>
			<p>Linked data to explore, use and build other data on.</p>
		</li>
	</ul>
</div>
',
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
  $export['10_seconds_tour'] = $mini;

  return $export;
}
