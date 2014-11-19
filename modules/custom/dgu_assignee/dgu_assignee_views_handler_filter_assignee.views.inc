<?php

/**
 * @file
 * Definition of dgu_data_set_request_views_handler_filter_assignee.
 */


/**
 * Filter allows the user to select from all the users who appear in the current instance of an assignee field.
 *
 * @ingroup views_filter_handlers
 */
class dgu_assignee_views_handler_filter_assignee extends views_handler_filter_in_operator {

  /**
   * Pre-populate options drop-down with all rows currently in use.
   */
  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }

    $this->value_options = array();

    // If we can populate the drop-down with real data, do so.
    if ($this->ensure_my_table()) {
      // SELECT DISTINCT :uid_field, name FROM {field_data_table} JOIN {users} ON :uid_field = uid ORDER BY name;
      $query = db_select($this->table_alias, 'ta')
        ->distinct()
        ->fields('ta', array($this->real_field))
        ->fields('u', array('name'))
        ->orderBy('name');

      $query->innerJoin('users', 'u', "ta.{$this->real_field} = u.uid");

      return $this->value_options = $query->execute()->fetchAllKeyed();
    }

    return $this->value_options = array();
  }
}
