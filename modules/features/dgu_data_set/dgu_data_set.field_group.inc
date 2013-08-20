<?php
/**
 * @file
 * dgu_data_set.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dgu_data_set_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_be_contacted|reply|dataset_feedback|form';
  $field_group->group_name = 'group_be_contacted';
  $field_group->entity_type = 'reply';
  $field_group->bundle = 'dataset_feedback';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Would you be willing to be contacted to discuss the responses you have given above?',
    'weight' => '15',
    'children' => array(
      0 => 'field_df_willing_to_be_contacted',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_be_contacted|reply|dataset_feedback|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_benefits_of_releasing|reply|dataset_feedback|form';
  $field_group->group_name = 'group_benefits_of_releasing';
  $field_group->entity_type = 'reply';
  $field_group->bundle = 'dataset_feedback';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What are the benefits of releasing this dataset as open data?',
    'weight' => '0',
    'children' => array(
      0 => 'field_df_economic_growth',
      1 => 'field_df_effective_pub_serv_det',
      2 => 'field_df_economic_growth_det',
      3 => 'field_df_effective_pub_serv',
      4 => 'field_df_social_growth',
      5 => 'field_df_social_growth_det',
      6 => 'field_df_other_benefits',
      7 => 'field_df_other_benefits_det',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_benefits_of_releasing|reply|dataset_feedback|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_information_about_response|reply|dataset_feedback|form';
  $field_group->group_name = 'group_information_about_response';
  $field_group->entity_type = 'reply';
  $field_group->bundle = 'dataset_feedback';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Information about your response',
    'weight' => '2',
    'children' => array(
      0 => 'field_df_are_you_responding_as',
      1 => 'field_df_your_organisation',
      2 => 'field_df_organisation_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_information_about_response|reply|dataset_feedback|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links_to_other_datasets|reply|dataset_feedback|form';
  $field_group->group_name = 'group_links_to_other_datasets';
  $field_group->entity_type = 'reply';
  $field_group->bundle = 'dataset_feedback';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links to other datasets',
    'weight' => '1',
    'children' => array(
      0 => 'field_df_link_to_other',
      1 => 'field_df_link_to_other_det',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_links_to_other_datasets|reply|dataset_feedback|form'] = $field_group;

  return $export;
}
