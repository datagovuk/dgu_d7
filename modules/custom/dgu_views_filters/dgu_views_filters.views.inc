<?php

/**
 * Implements hook_views_data_alter().
 *
 * Register a new Views filters for field_publisher_assignee and field_publisher_ref.
 */
function dgu_views_filters_views_data_alter(&$data) {
  $data['field_data_field_publisher_assignee']['field_publisher_assignee_uid']['filter']['handler'] = 'dgu_views_filters_field_publisher_assignee';
  $data['field_data_field_publisher_ref']['field_publisher_ref_id']['filter']['handler'] = 'dgu_views_filters_field_publisher_ref';
}
