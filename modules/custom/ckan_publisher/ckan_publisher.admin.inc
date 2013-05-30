<?php

/**
 * @file
 * CKAN Publisher editing UI.
 */

/**
 * UI controller.
 */
class CKANPublisherUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {
    $items = array();
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    // Menu item for viewing CKAN Publishers
    $items['ckan_publisher/' . $wildcard] = array(
      //'title' => 'Title',
      'title callback' => 'ckan_publisher_page_title',
      'title arguments' => array(1),
      'page callback' => 'ckan_publisher_page_view',
      'page arguments' => array(1),
      'access callback' => 'ckan_publisher_access',
      'access arguments' => array('view', 1),
      'type' => MENU_CALLBACK,
    );

    $items['admin/structure/ckan_publisher'] = array(
      'title' => 'Publishers',
      'access arguments' => array('Administer CKAN'),
      'page callback' => 'ckan_publisher_structure_page',
    );

    return $items;
  }
}

/**
 * Sets the breadcrumb for administrative CKAN Publisher pages.
 */
function ckan_publisher_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('Publisher'), 'admin/content/publishers'),
  );

  drupal_set_breadcrumb($breadcrumb);
}
