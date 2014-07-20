<?php
/**
 * @file
 * dgu_moderation.features.workbench_moderation_transitions.inc
 */

/**
 * Implements hook_workbench_moderation_export_transitions().
 */
function dgu_moderation_workbench_moderation_export_transitions() {
  $items = array(
    'draft:needs_review' => array(
      'from_name' => 'draft',
      'to_name' => 'needs_review',
    ),
    'draft:published' => array(
      'from_name' => 'draft',
      'to_name' => 'published',
    ),
    'needs_review:draft' => array(
      'from_name' => 'needs_review',
      'to_name' => 'draft',
    ),
    'needs_review:published' => array(
      'from_name' => 'needs_review',
      'to_name' => 'published',
    ),
    'published:draft' => array(
      'from_name' => 'published',
      'to_name' => 'draft',
    ),
    'published:needs_review' => array(
      'from_name' => 'published',
      'to_name' => 'needs_review',
    ),
  );
  return $items;
}
