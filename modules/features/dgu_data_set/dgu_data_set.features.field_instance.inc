<?php
/**
 * @file
 * dgu_data_set.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dgu_data_set_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'ckan_dataset-ckan_dataset-field_comment'
  $field_instances['ckan_dataset-ckan_dataset-field_comment'] = array(
    'bundle' => 'ckan_dataset',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'reply',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'reply_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'ckan_dataset',
    'field_name' => 'field_comment',
    'label' => 'Comments',
    'required' => 0,
    'settings' => array(
      'access' => -1,
      'allow_reply' => -1,
      'display' => -1,
      'form' => -1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'reply',
      'settings' => array(),
      'type' => 'reply',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'ckan_dataset-ckan_dataset-field_dataset_feedback'
  $field_instances['ckan_dataset-ckan_dataset-field_dataset_feedback'] = array(
    'bundle' => 'ckan_dataset',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'reply',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'reply_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'ckan_dataset',
    'field_name' => 'field_dataset_feedback',
    'label' => 'Feedback',
    'required' => 0,
    'settings' => array(
      'access' => -1,
      'allow_reply' => -1,
      'display' => -1,
      'form' => -1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'reply',
      'settings' => array(),
      'type' => 'reply',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_are_you_responding_as'
  $field_instances['reply-dataset_feedback-field_df_are_you_responding_as'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_are_you_responding_as',
    'label' => 'Are you responding',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_economic_growth'
  $field_instances['reply-dataset_feedback-field_df_economic_growth'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'i.e. releasing this dataset as open data means you or your organisation are able to provide a commercial product or service or has other positive economic impacts such as better functioning of markets.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_economic_growth',
    'label' => 'Economic Growth',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_economic_growth_det'
  $field_instances['reply-dataset_feedback-field_df_economic_growth_det'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_economic_growth_det',
    'label' => 'Please give details for selection below',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_effective_pub_serv'
  $field_instances['reply-dataset_feedback-field_df_effective_pub_serv'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'i.e. releasing this dataset as open data means that a public service are able to run more effectively by giving greater transparency of its operation to citizens, allowing greater choice or supporting new models of provision of services.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_effective_pub_serv',
    'label' => 'Effective Public Services',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_effective_pub_serv_det'
  $field_instances['reply-dataset_feedback-field_df_effective_pub_serv_det'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_effective_pub_serv_det',
    'label' => 'Please give details for selection below',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_link_to_other'
  $field_instances['reply-dataset_feedback-field_df_link_to_other'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_link_to_other',
    'label' => 'Does this dataset contain data which could be used to link it to other datasets?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_link_to_other_det'
  $field_instances['reply-dataset_feedback-field_df_link_to_other_det'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_link_to_other_det',
    'label' => 'Please explain further',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_organisation_name'
  $field_instances['reply-dataset_feedback-field_df_organisation_name'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_organisation_name',
    'label' => 'Organisation name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_other_benefits'
  $field_instances['reply-dataset_feedback-field_df_other_benefits'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_other_benefits',
    'label' => 'Other Benefits',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_other_benefits_det'
  $field_instances['reply-dataset_feedback-field_df_other_benefits_det'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_other_benefits_det',
    'label' => 'Please give details below of other benefits of releasing this data as open data',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_social_growth'
  $field_instances['reply-dataset_feedback-field_df_social_growth'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'i.e. releasing this dataset as open data means you or your organisation are able to more easily undertake social action, deliver the services of a community group or charity or has a positive environmental impact.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_social_growth',
    'label' => 'Social Growth',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_social_growth_det'
  $field_instances['reply-dataset_feedback-field_df_social_growth_det'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_social_growth_det',
    'label' => 'Please give details for selection below',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_willing_to_be_contacted'
  $field_instances['reply-dataset_feedback-field_df_willing_to_be_contacted'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_willing_to_be_contacted',
    'label' => 'We will use the email contact in your data.gov.uk profile.',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'reply-dataset_feedback-field_df_your_organisation'
  $field_instances['reply-dataset_feedback-field_df_your_organisation'] = array(
    'bundle' => 'dataset_feedback',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_replies' => '',
          'field_replies_settings' => array(
            'field_replies_reply_field_name' => '',
            'field_replies_revision' => '',
          ),
        ),
        'type' => 'list_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'reply',
    'field_name' => 'field_df_your_organisation',
    'label' => 'Is your organisation',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Are you responding');
  t('Comments');
  t('Does this dataset contain data which could be used to link it to other datasets?');
  t('Economic Growth');
  t('Effective Public Services');
  t('Feedback');
  t('Is your organisation');
  t('Organisation name');
  t('Other Benefits');
  t('Please explain further');
  t('Please give details below of other benefits of releasing this data as open data');
  t('Please give details for selection below');
  t('Social Growth');
  t('We will use the email contact in your data.gov.uk profile.');
  t('i.e. releasing this dataset as open data means that a public service are able to run more effectively by giving greater transparency of its operation to citizens, allowing greater choice or supporting new models of provision of services.');
  t('i.e. releasing this dataset as open data means you or your organisation are able to more easily undertake social action, deliver the services of a community group or charity or has a positive environmental impact.');
  t('i.e. releasing this dataset as open data means you or your organisation are able to provide a commercial product or service or has other positive economic impacts such as better functioning of markets.');

  return $field_instances;
}
