<?php
/**
 * @file
 * dgu_notifications.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dgu_notifications_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__dgu_notifications_node_update';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_body' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__dgu_notifications_node_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__dgu_notifications_reply_new';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'message__message_text__0' => array(
          'message_notify_email_subject' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
        ),
        'message__message_text__1' => array(
          'message_notify_email_subject' => array(
            'visible' => FALSE,
            'weight' => 0,
          ),
          'message_notify_email_body' => array(
            'visible' => TRUE,
            'weight' => 0,
          ),
        ),
        'message__message_text__2' => array(
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
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
      ),
    ),
  );
  $export['field_bundle_settings_message__dgu_notifications_reply_new'] = $strongarm;

  return $export;
}
