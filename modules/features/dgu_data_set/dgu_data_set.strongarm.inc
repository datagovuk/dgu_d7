<?php
/**
 * @file
 * dgu_data_set.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dgu_data_set_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_ckan_dataset__ckan_dataset';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'comments' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_ckan_dataset__ckan_dataset'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__dataset_comment_new';
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
          'message_notify_weekly_digest' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
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
          'message_notify_weekly_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '0',
            'visible' => TRUE,
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
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__dataset_comment_new'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__dataset_new';
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
            'weight' => '2',
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
            'weight' => '1',
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
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__dataset_new'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__dataset_new_subscribe_comment';
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
            'weight' => '2',
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
            'weight' => '1',
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
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__dataset_new_subscribe_comment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__dataset_new_subscribe_update';
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
            'weight' => '2',
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
            'weight' => '1',
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
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__dataset_new_subscribe_update'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_message__dataset_update';
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
          'message_notify_email_body' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'message_notify_email_subject' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'message_notify_daily_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'message_notify_weekly_digest' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_message__dataset_update'] = $strongarm;

  return $export;
}
