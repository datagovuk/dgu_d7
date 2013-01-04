<?php

/**
 * @file
 * CKAN Package editing UI.
 */

/**
 * UI controller.
 */
class CKANUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
  	$items = parent::hook_menu();
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title' => 'CKAN Packages',
      'description' => 'Add edit and update CKAN Packages.',
      'page callback' => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path' => drupal_get_path('module', 'system'),
      'file' => 'system.admin.inc',
    );
    
    // Change the overview menu type for the list.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;
    
    // Change the add page menu to multiple types of entities
    $items[$this->path . '/add'] = array(
      'title' => 'Add a CKAN Package',
      'description' => 'Add a new CKAN Package',
      'page callback'  => 'ckan_package_add_page',
      'access callback'  => 'ckan_package_access',
      'access arguments' => array('edit'),
      'type' => MENU_NORMAL_ITEM,
      'weight' => 20,
      'file' => 'ckan_package.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Add CKAN Package items to add each different type of entity.
    foreach (ckan_package_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title' => 'Add ' . $type->label,
        'page callback' => 'ckan_package_form_wrapper',
        'page arguments' => array(ckan_package_create(array('type' => $type->type))),
        'access callback' => 'ckan_package_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file' => 'ckan_package.admin.inc',
        'file path' => drupal_get_path('module', $this->entityInfo['module'])
      );
    }

    // Loading and editing CKAN Packages
    $items[$this->path . '/ckan_package/' . $wildcard] = array(
      'page callback' => 'ckan_package_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'ckan_package_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight' => 0,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file' => 'ckan_package.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    $items[$this->path . '/ckan_package/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );
    
    $items[$this->path . '/ckan_package/' . $wildcard . '/delete'] = array(
      'title' => 'Delete',
      'page callback' => 'ckan_package_delete_form_wrapper',
      'page arguments' => array($id_count + 1),
      'access callback' => 'ckan_package_access',
      'access arguments' => array('edit', $id_count + 1),
      'type' => MENU_LOCAL_TASK,
      'context' => MENU_CONTEXT_INLINE,
      'weight' => 10,
      'file' => 'ckan_package.admin.inc',
      'file path' => drupal_get_path('module', $this->entityInfo['module'])
    );
    
    // Menu item for viewing CKAN Packages
    $items['ckan_package/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'ckan_package_page_title',
      'title arguments' => array(1),
      'page callback' => 'ckan_package_page_view',
      'page arguments' => array(1),
      'access callback' => 'ckan_package_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );
    return $items;
  }
  
  
  /**
   * Create the markup for the add CKAN Packages page within the class
   * so it can easily be extended/overriden.
   */ 
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }    
        
    return theme('ckan_package_add_list', array('content' => $content));
  }
  
}


/**
 * Form callback wrapper: create or edit a CKAN Package.
 *
 * @param $ckan
 *   The CKAN Package object being edited by this form.
 *
 * @see ckan_package_edit_form()
 */
function ckan_package_form_wrapper($ckan) {
  // Add the breadcrumb for the form's location.
  ckan_package_set_breadcrumb();
  return drupal_get_form('ckan_package_edit_form', $ckan);
}


/**
 * Form callback wrapper: delete a CKAN Package.
 *
 * @param $ckan
 *   The CKAN Package object being edited by this form.
 *
 * @see ckan_package_edit_form()
 */
function ckan_package_delete_form_wrapper($ckan) {
  return drupal_get_form('ckan_package_delete_form', $ckan);
}


/**
 * Form callback: create or edit a CKAN Package.
 *
 * @param $ckan
 *   The CKAN Package object to edit or for a create form an empty object
 *  
 */
function ckan_package_edit_form($form, &$form_state, $ckan) {
  // Add the default field elements.
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('CKAN Package Name'),
    '#default_value' => isset($ckan->name) ? $ckan->name : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
  
  $form['data']['#tree'] = TRUE;
  $form['data']['sample_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('An interesting switch'),
    '#default_value' => isset($ckan->data['sample_data']) ? $ckan->data['sample_data'] : 1,
  );

  // Add the field related form elements.
  $form_state['ckan_package'] = $ckan;
  field_attach_form('ckan_package', $ckan, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight' => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save CKAN Package'),
    '#submit' => $submit + array('ckan_package_edit_form_submit'),
  );
  
  if (!empty($ckan->name)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete CKAN Package'),
      '#suffix' => l(t('Cancel'), 'admin/content/ckan_packages'),
      '#submit' => $submit + array('ckan_package_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'ckan_package_edit_form_validate';
  return $form;
}


/**
 * Form API validate callback for the CKAN Package form
 */
function ckan_package_edit_form_validate(&$form, &$form_state) {
  $ckan = $form_state['ckan_package'];
  
  // Notify field widgets to validate their data.
  field_attach_form_validate('ckan_package', $ckan, $form, $form_state);
}


/**
 * Form API submit callback for the CKAN Package form.
 */
function ckan_package_edit_form_submit(&$form, &$form_state) {
  
  $ckan = entity_ui_controller('ckan_package')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the CKAN Package and go back to the list
  
  // Add in created and changed times.
  if ($ckan->is_new = isset($ckan->is_new) ? $ckan->is_new : 0){
    $ckan->created = time();
  }

  $ckan->changed = time();
  
  $ckan->save();
  $form_state['redirect'] = 'admin/content/ckan_packages';
}

/**
 * Form API submit callback for the delete button.
 */
function ckan_package_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/ckan_packages/ckan_package' . $form_state['ckan_package']->ckan_id . '/delete';
}


/**
 * Form callback: confirmation form for deleting a CKAN Package.
 *
 * @param $ckan
 *   The CKAN Package to delete
 *
 * @see confirm_form()
 */
function ckan_package_delete_form($form, &$form_state, $ckan) {
  $form_state['ckan'] = $ckan;

  $form['#submit'][] = 'ckan_package_delete_form_submit';

  $form = confirm_form($form,
    t('Are you sure you want to delete CKAN Package %name?', array('%name' => $ckan->name)),
    'admin/content/ckan_packages/ckan_package/',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );
  
  return $form;
}

/**
 * Submit callback for ckan_package_delete_form
 */
function ckan_package_delete_form_submit($form, &$form_state) {
  $ckan = $form_state['ckan_package'];

  ckan_package_delete($ckan);

  drupal_set_message(t('The CKAN Package %name has been deleted.', array('%name' => $ckan->name)));
  watchdog('ckan_package', 'Deleted ckan_package %name.', array('%name' => $ckan->name));

  $form_state['redirect'] = 'admin/content/ckan_packages';
}



/**
 * Page to add CKAN Packages
 *
 * @todo Pass this through a proper theme function
 */
function ckan_package_add_page() {
  $controller = entity_ui_controller('ckan_package');
  return $controller->addPage();
}


/**
 * Displays the list of available CKAN Package types for CKAN Packages.
 *
 * @ingroup themeable
 */
function theme_ckan_package_add_list($variables) {
  $content = $variables['content'];
  $output = '';
  if ($content) {
    $output = '<dl class="ckan_package-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer CKAN Package types')) {
      $output = '<p>' . t('CKAN Packages cannot be added because you have not created any CKAN Package types yet. Go to the <a href="@create-ckan_package-type">CKAN Package type creation page</a> to add a new CKAN Package type.', array('@create-ckan_package-type' => url('admin/structure/ckan_package_type/add'))) . '</p>';
    }
    else {
      $output = '<p>' . t('No CKAN Package types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative CKAN Package pages.
 */
function ckan_package_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('CKAN Package'), 'admin/content/ckan_packages'),
  );

  drupal_set_breadcrumb($breadcrumb);
}



