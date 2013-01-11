<?php
/**
 * @file
 * dgu_reply.features.inc
 */

/**
 * Implements hook_default_reply_bundle().
 */
function dgu_reply_default_reply_bundle() {
  $items = array();
  $items['comment'] = entity_import('reply_bundle', '{
    "bundle" : "comment",
    "name" : "Comment",
    "access" : "2",
    "display" : "2",
    "description" : "",
    "form" : "2",
    "allow_reply" : "1",
    "locked" : "0"
  }');
  return $items;
}
