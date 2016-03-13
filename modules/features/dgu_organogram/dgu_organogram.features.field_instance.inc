<?php
/**
 * @file
 * dgu_organogram.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dgu_organogram_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'ckan_publisher-ckan_publisher-field_organogram'
  $field_instances['ckan_publisher-ckan_publisher-field_organogram'] = array(
    'bundle' => 'ckan_publisher',
    'deleted' => '0',
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
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
        'type' => 'file_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'ckan_publisher',
    'field_name' => 'field_organogram',
    'label' => 'Organogram',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'organogram/uploads',
      'file_extensions' => 'xls xlsx',
      'max_filesize' => '10 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Organogram');

  return $field_instances;
}
