<?php
/**
 * @file
 * dgu_site_feature.bootstrap_tour_tour.inc
 */

/**
 * Implements hook_default_bootstrap_tour().
 */
function dgu_site_feature_default_bootstrap_tour() {
  $export = array();

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'how_to_navigate_your_content';
  $bootstrap_tour->title = 'How to navigate your content';
  $bootstrap_tour->roles = '2';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.nav-user',
      'path' => 'help',
      'placement' => 'left',
      'title' => 'User account',
      'content' => '<p>To navigate your content please go to user account page.</p>
',
      'format' => 'filtered_html',
    ),
    1 => array(
      'selector' => '#menu-tabs a[href="/admin/workbench"]',
      'path' => 'user',
      'placement' => 'bottom',
      'title' => 'Manage my content',
      'content' => '<p>Next please click &#39;Manage my content&#39; tab.</p>
',
      'format' => 'filtered_html',
    ),
    2 => array(
      'selector' => '.my-content',
      'path' => 'admin/workbench',
      'placement' => 'top',
      'title' => 'My content',
      'content' => '<p>Here you can find your latest content, number of items on this list is limited to 5.</p>
',
      'format' => 'filtered_html',
    ),
    3 => array(
      'selector' => 'a[href="/admin/workbench/content/my"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'My content',
      'content' => '<p>Here you can find all content created by you.</p>
',
      'format' => 'filtered_html',
    ),
    4 => array(
      'selector' => '.my-comments',
      'path' => '',
      'placement' => 'top',
      'title' => 'My comments',
      'content' => '<p>Here you can find your latest comments, number of items on this list is limited to 5.</p>
',
      'format' => 'filtered_html',
    ),
    5 => array(
      'selector' => 'a[href="/admin/workbench/content/comments/my"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'My comments',
      'content' => '<p>Here you can find all comments created by you.</p>
',
      'format' => 'filtered_html',
    ),
    6 => array(
      'selector' => 'a[href="/admin/workbench/content/edited"]',
      'path' => 'admin/workbench',
      'placement' => 'bottom',
      'title' => 'My Edits',
      'content' => '<p>Here you can find your or other users content which you have edited.</p>
',
      'format' => 'filtered_html',
    ),
    7 => array(
      'selector' => 'a[href="/admin/workbench/content/drafts"]',
      'path' => 'admin/workbench',
      'placement' => 'bottom',
      'title' => 'My Drafts',
      'content' => '<p>Here you can find your draft content.</p>
',
      'format' => 'filtered_html',
    ),
    8 => array(
      'selector' => '#edit-title',
      'path' => 'admin/workbench/content/my',
      'placement' => 'bottom',
      'title' => 'Title filter',
      'content' => '<p>You can search through the titles, enter any string contained in the title to perform search.</p>
',
      'format' => 'filtered_html',
    ),
    9 => array(
      'selector' => '#edit-type',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Content type',
      'content' => '<p>You can flter content by type, please select content type from the drop down list.</p>
',
      'format' => 'filtered_html',
    ),
    10 => array(
      'selector' => '#edit-items-per-page',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Items per page',
      'content' => '<p>Here you can choose number items displayed on the list.</p>
',
      'format' => 'filtered_html',
    ),
    11 => array(
      'selector' => '#edit-submit-my-content',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Apply button',
      'content' => '<p>Please don&#39;t forget to press &#39;Apply&#39; button to apply filters.<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    12 => array(
      'selector' => 'ul.tabs--secondary li.active a',
      'path' => 'admin/workbench/content/edited',
      'placement' => 'bottom',
      'title' => 'My Edits',
      'content' => '<p>Filters on My Edits page are identical.</p>
',
      'format' => 'filtered_html',
    ),
    13 => array(
      'selector' => 'ul.tabs--secondary li.active a',
      'path' => 'admin/workbench/content/comments/my',
      'placement' => 'bottom',
      'title' => 'My comments',
      'content' => '<p>The same on My Comments page.</p>
',
      'format' => 'filtered_html',
    ),
    14 => array(
      'selector' => '.views-widget-filter-state',
      'path' => 'admin/workbench/content/drafts',
      'placement' => 'bottom',
      'title' => 'Moderation state filter',
      'content' => '<p>On &#39;My Drafts&#39; page you have the same filters and also new State filter which lets you filter by moderation state.</p>
',
      'format' => 'filtered_html',
    ),
  );
  $export['how_to_navigate_your_content'] = $bootstrap_tour;

  return $export;
}
