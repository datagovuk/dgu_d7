<?php
/**
 * @file
 * dgu_issue.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dgu_issue_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'ckan_issue-ckan_issue-field_comment'
  $field_instances['ckan_issue-ckan_issue-field_comment'] = array(
    'bundle' => 'ckan_issue',
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'comments' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'reply',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
          'quickedit' => array(
            'editor' => 'form',
          ),
        ),
        'type' => 'reply_default',
        'weight' => '0',
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'ckan_issue',
    'field_name' => 'field_comment',
    'label' => 'Comments',
    'required' => 0,
    'settings' => array(
      'access' => '-1',
      'allow_reply' => '-1',
      'display' => '-1',
      'form' => '-1',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'reply',
      'settings' => array(),
      'type' => 'reply',
      'weight' => '0',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Comments');

  return $field_instances;
}
