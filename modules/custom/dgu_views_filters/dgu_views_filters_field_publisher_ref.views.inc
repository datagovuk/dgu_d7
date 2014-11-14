<?php

/**
 * @file
 * Definition of dgu_views_filters_field_publisher_ref.
 */


/**
 * Filter allows the user to select from all the users who currently appear in field_publisher_ref.
 *
 * @ingroup views_filter_handlers
 */
class dgu_views_filters_field_publisher_ref extends views_handler_filter_in_operator {

  /**
   * Pre-populate options drop-down with all field_assignee currently in use.
   */
  function get_value_options() {
    $sql = 'SELECT DISTINCT field_publisher_ref_id, title FROM {field_data_field_publisher_ref} JOIN {ckan_publisher} ON field_publisher_ref_id = id ORDER BY title';
    $result = db_query($sql);

    return $this->value_options = $result->fetchAllKeyed();
  }
}
