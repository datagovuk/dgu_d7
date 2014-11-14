<?php

/**
 * Implements hook_views_data_alter().
 *
 * Register a new Views filter for field_assignee.
 */
function dgu_assignee_views_data_alter(&$data) {
  $data['field_data_field_assignee']['field_assignee_uid']['filter']['handler'] = 'dgu_assignee_views_handler_filter_field_assignee';
}
