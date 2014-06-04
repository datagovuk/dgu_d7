<?php
/**
 * @file
 * dgu_data_set_request.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dgu_data_set_request_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_benefits|node|dataset_request|default';
  $field_group->group_name = 'group_about_benefits';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Benefits of using data in this way',
    'weight' => '6',
    'children' => array(
      0 => 'field_benefits_overview',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Benefits of using data in this way',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_about_benefits|node|dataset_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_benefits|node|dataset_request|form';
  $field_group->group_name = 'group_about_benefits';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '5. Please describe the benefits of using data in this way.',
    'weight' => '9',
    'children' => array(
      0 => 'field_benefits_overview',
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
  $export['group_about_benefits|node|dataset_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_challenges|node|dataset_request|default';
  $field_group->group_name = 'group_about_challenges';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Challenges in accessing this data',
    'weight' => '4',
    'children' => array(
      0 => 'field_barriers_detail',
      1 => 'field_barriers_reason',
      2 => 'field_issue_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Challenges in accessing this data',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_about_challenges|node|dataset_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_challenges|node|dataset_request|form';
  $field_group->group_name = 'group_about_challenges';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '3. Have you faced challenges in accessing this data?',
    'weight' => '7',
    'children' => array(
      0 => 'field_barriers_attempted',
      1 => 'field_barriers_detail',
      2 => 'field_barriers_reason',
      3 => 'field_issue_type',
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
  $export['group_about_challenges|node|dataset_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_data|node|dataset_request|default';
  $field_group->group_name = 'group_about_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'What data should be released',
    'weight' => '3',
    'children' => array(
      0 => 'field_data_holder',
      1 => 'field_data_set_description',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'What data should be released',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_about_data|node|dataset_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_data|node|dataset_request|form';
  $field_group->group_name = 'group_about_data';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '2. What data would you like released?',
    'weight' => '6',
    'children' => array(
      0 => 'field_data_holder',
      1 => 'field_data_set_description',
      2 => 'field_data_themes',
      3 => 'title',
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
  $export['group_about_data|node|dataset_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_usage|node|dataset_request|default';
  $field_group->group_name = 'group_about_usage';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Purpose of using this data',
    'weight' => '5',
    'children' => array(
      0 => 'field_data_use',
      1 => 'field_data_use_detail',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Purpose of using this data',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_about_usage|node|dataset_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_usage|node|dataset_request|form';
  $field_group->group_name = 'group_about_usage';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '4. What do you plan to do with the data?',
    'weight' => '8',
    'children' => array(
      0 => 'field_data_use',
      1 => 'field_data_use_detail',
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
  $export['group_about_usage|node|dataset_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_about_you|node|dataset_request|form';
  $field_group->group_name = 'group_about_you';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '1. Who are you?',
    'weight' => '5',
    'children' => array(
      0 => 'field_organisation_name',
      1 => 'field_organisation_type',
      2 => 'field_submitter_email',
      3 => 'field_submitter_name',
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
  $export['group_about_you|node|dataset_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_estimates|node|dataset_request|default';
  $field_group->group_name = 'group_estimates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Estimates of the economic or financial benefit of data release',
    'weight' => '7',
    'children' => array(
      0 => 'field_estimates_detail',
      1 => 'field_provide_estimates',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Estimates of the economic or financial benefit of data release',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_estimates|node|dataset_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_estimates|node|dataset_request|form';
  $field_group->group_name = 'group_estimates';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '6. Are you able to provide estimates of the economic or financial benefit of data release?',
    'weight' => '10',
    'children' => array(
      0 => 'field_estimates_detail',
      1 => 'field_provide_estimates',
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
  $export['group_estimates|node|dataset_request|form'] = $field_group;

  return $export;
}
