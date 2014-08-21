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
      ),
    ),
  );
  $export['field_bundle_settings_message__dgu_notifications_reply_new'] = $strongarm;

  return $export;
}
