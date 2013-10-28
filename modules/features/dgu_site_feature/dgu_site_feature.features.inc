<?php
/**
 * @file
 * dgu_site_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_site_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function dgu_site_feature_image_default_styles() {
  $styles = array();

  // Exported image style: tile_big.
  $styles['tile_big'] = array(
    'name' => 'tile_big',
    'label' => 'tile_big',
    'effects' => array(
      1 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 330,
          'height' => 500,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: tile_small.
  $styles['tile_small'] = array(
    'name' => 'tile_small',
    'label' => 'tile_small',
    'effects' => array(
      2 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 330,
          'height' => 120,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function dgu_site_feature_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('A <em>page</em>, similar in form to a <em>story</em>, is a simple method for creating and displaying information that rarely changes, such as an "About us" section of a website. By default, a <em>page</em> entry does not allow visitor comments and is not featured on the site\'s initial home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
