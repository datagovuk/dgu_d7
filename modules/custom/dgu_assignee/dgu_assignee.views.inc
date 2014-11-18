<?php

/**
 * Implements hook_views_data_alter().
 *
 * Register a new Views filter for assignee fields.
 */
function dgu_assignee_views_data_alter(&$data) {

  // For all fields of type 'assignee', replace the default filter handler with our custom one.
  foreach ($data as $table_name => $table_info) {
    // If we're examining a Field.
    if (strpos($table_name, 'field_data_field_') === 0) {
      // Retrieve data about it.
      $field_name = substr($table_name, strlen('field_data_'));
      $field_info = field_info_field($field_name);

      // If it's an assignee field.
      if ($field_info['type'] == 'assignee') {
        // Give it our custom filter.
        $data[$table_name][$field_name . '_uid']['filter']['handler'] = 'dgu_assignee_views_handler_filter_assignee';
      }
    }
  }
}
