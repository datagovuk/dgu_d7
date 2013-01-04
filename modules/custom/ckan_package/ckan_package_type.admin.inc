<?php

/**
 * @file
 * CKAN Package type editing UI.
 */

/**
 * UI controller.
 */
class CKANTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
		$items[$this->path]['description'] = 'Manage CKAN Package types, including adding
		and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the CKAN Package type editing form.
 */
function ckan_package_type_form($form, &$form_state, $ckan_package_type, $op = 'edit') {

  if ($op == 'clone') {
    $ckan_package_type->label .= ' (cloned)';
    $ckan_package_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $ckan_package_type->label,
    '#description' => t('The human-readable name of this CKAN Package type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($ckan_package_type->type) ? $ckan_package_type->type : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'ckan_package_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this CKAN Package type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting switch'),
    '#default_value' => !empty($ckan_package_type->data['sample_data']),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save CKAN Package type'),
    '#weight' => 40,
  );
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function ckan_package_type_form_submit(&$form, &$form_state) {
  $ckan_package_type = entity_ui_form_submit_build_entity($form, $form_state);
  $ckan_package_type->save();
  $form_state['redirect'] = 'admin/structure/ckan_package_type';
}

/**
 * Form API submit callback for the delete button.
 */
function ckan_package_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/ckan_package_type/' . $form_state['ckan_package_type']->type . '/delete';
}
