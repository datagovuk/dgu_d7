<?php
/**
 * @file
 * dgu_moderation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dgu_moderation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_dataset_request';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_dataset_request'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_forum';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_forum'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_user_story';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_user_story'] = $strongarm;

  return $export;
}
