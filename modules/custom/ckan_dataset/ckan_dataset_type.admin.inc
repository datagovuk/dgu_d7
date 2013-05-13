<?php

/**
 * @file
 * CKAN Dataset type editing UI.
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
		$items[$this->path]['description'] = 'Manage CKAN Dataset types, including adding
		and removing fields and the display of fields.';
    return $items;
  }
}

/**
 * Generates the CKAN Dataset type editing form.
 */
function ckan_dataset_type_form($form, &$form_state, $ckan_dataset_type, $op = 'edit') {

  if ($op == 'clone') {
    $ckan_dataset_type->label .= ' (cloned)';
    $ckan_dataset_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $ckan_dataset_type->label,
    '#description' => t('The human-readable name of this Dataset type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($ckan_dataset_type->type) ? $ckan_dataset_type->type : '',
    '#maxlength' => 32,
    '#machine_name' => array(
      'exists' => 'ckan_dataset_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this Dataset type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['data']['#tree'] = TRUE;

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Dataset type'),
    '#weight' => 40,
  );
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function ckan_dataset_type_form_submit(&$form, &$form_state) {
  $ckan_dataset_type = entity_ui_form_submit_build_entity($form, $form_state);
  $ckan_dataset_type->save();
  $form_state['redirect'] = 'admin/structure/ckan_dataset_type';
}

/**
 * Form API submit callback for the delete button.
 */
function ckan_dataset_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/ckan_dataset_type/' . $form_state['ckan_dataset_type']->type . '/delete';
}
