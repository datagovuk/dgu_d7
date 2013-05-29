<?php

/**
 * @file
 * CKAN Dataset editing UI.
 */

/**
 * UI controller.
 */
class CKANDatasetUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
  	$items = parent::hook_menu();
    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    // Menu item for viewing CKAN Datasets
    $items['ckan_dataset/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'ckan_dataset_page_title',
      'title arguments' => array(1),
      'page callback' => 'ckan_dataset_page_view',
      'page arguments' => array(1),
      'access callback' => 'ckan_dataset_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );

    $items['admin/structure/ckan_dataset'] = array(
      'title' => 'Datasets',
      'access arguments' => array('Administer CKAN'),
      'page callback' => 'ckan_dataset_structure_page',
    );

    return $items;
  }
}

/**
 * Sets the breadcrumb for administrative CKAN Dataset pages.
 */
function ckan_dataset_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Dataset'), 'admin/content/datasets'),
  );

  drupal_set_breadcrumb($breadcrumb);
}
