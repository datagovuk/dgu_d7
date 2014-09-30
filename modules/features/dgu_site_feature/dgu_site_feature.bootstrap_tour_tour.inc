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
      'selector' => 'a[href="/admin/workbench"]',
      'path' => 'user',
      'placement' => 'bottom',
      'title' => 'Manage my content',
      'content' => '<p>Next please click &#39;Manage my content&#39; tab.</p>
',
      'format' => 'filtered_html',
    ),
    2 => array(
      'selector' => '.view-my-content',
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
      'selector' => '.view-user-replies',
      'path' => '',
      'placement' => 'top',
      'title' => 'My comments',
      'content' => '<p>Here you can find your latest comments, number of items on this list is limited to 5.</p>
',
      'format' => 'filtered_html',
    ),
    5 => array(
      'selector' => 'a[href="/admin/workbench/comments/my"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'My comments',
      'content' => '<p>Here you can find all comments created by you.</p>
',
      'format' => 'filtered_html',
    ),
    6 => array(
      'selector' => 'a[href="/admin/workbench/content/edited"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'My Edits',
      'content' => '<p>Here you can find your or other users content which you have edited.</p>
',
      'format' => 'filtered_html',
    ),
    7 => array(
      'selector' => 'a[href="/admin/workbench/content/drafts"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'My Drafts',
      'content' => '<p>Here you can find your draft content.</p>
',
      'format' => 'filtered_html',
    ),
  );
  $export['how_to_navigate_your_content'] = $bootstrap_tour;

  return $export;
}
