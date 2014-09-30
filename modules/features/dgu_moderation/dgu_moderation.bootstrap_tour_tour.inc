<?php
/**
 * @file
 * dgu_moderation.bootstrap_tour_tour.inc
 */

/**
 * Implements hook_default_bootstrap_tour().
 */
function dgu_moderation_default_bootstrap_tour() {
  $export = array();

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'content_moderation';
  $bootstrap_tour->title = 'Content moderation';
  $bootstrap_tour->roles = '3,4,7,10';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'Content moderation tour';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.nav-user',
      'path' => 'help',
      'placement' => 'left',
      'title' => 'User account',
      'content' => '<p>To moderate new content please go to user account page.</p>
',
      'format' => 'filtered_html',
    ),
    1 => array(
      'selector' => 'a[href="/admin/workbench/needs-review"]',
      'path' => 'user',
      'placement' => 'bottom',
      'title' => 'Needs review',
      'content' => '<p>All new content submitter by users is waiting for moderation, you can find it in &#39;Needs review&#39; list.</p>
',
      'format' => 'filtered_html',
    ),
    2 => array(
      'selector' => '.view-workbench-moderation .view-content',
      'path' => 'admin/workbench/needs-review',
      'placement' => 'top',
      'title' => 'List of all content awaiting moderation',
      'content' => '<p>On this list is listed all content submitted by users for moderation. When users create content they can save it as draft at any time, this content is not listed here. When they finish they submit content for moderation, this content is listed here and is waiting for approval.</p>
',
      'format' => 'filtered_html',
    ),
    3 => array(
      'selector' => 'body',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'more to follow',
      'content' => '<p>more tour steps to follow<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
  );
  $export['content_moderation'] = $bootstrap_tour;

  return $export;
}
