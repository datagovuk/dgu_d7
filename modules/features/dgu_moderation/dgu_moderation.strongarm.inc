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
  $strongarm->name = 'field_bundle_settings_message__dgu_moderation_state_change';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__dgu_moderation_state_change'] = $strongarm;

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
