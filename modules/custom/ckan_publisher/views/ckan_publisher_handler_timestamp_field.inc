<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying timestamps.
 */

class ckan_publisher_handler_timestamp_field extends views_handler_field {
  function render($values) {
    return date('j/m/Y - H:i', $values->{$this->field_alias}); //l($text, 'ckan_publisher/' . $ckan_id);
  }
}
