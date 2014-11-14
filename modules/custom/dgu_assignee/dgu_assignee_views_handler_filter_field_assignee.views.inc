<?php

/**
 * @file
 * Definition of dgu_data_set_request_views_handler_filter_field_assignee.
 */


/**
 * Filter allows the user to select from all the users who can appear in field_assignee.
 *
 * @ingroup views_filter_handlers
 */
class dgu_assignee_views_handler_filter_field_assignee extends views_handler_filter_in_operator {

  /**
   * Pre-populate options drop-down with all field_assignee currently in use.
   */
  function get_value_options() {
    $sql = 'SELECT DISTINCT field_assignee_uid, name FROM {field_data_field_assignee} JOIN {users} ON field_assignee_uid = uid ORDER BY name';
    $result = db_query($sql);

    return $this->value_options = $result->fetchAllKeyed();
  }
}
