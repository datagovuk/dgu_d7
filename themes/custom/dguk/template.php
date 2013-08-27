<?php

/**
 *  Implements theme_preprocess().
 */
function dguk_preprocess(&$variables){
  module_load_include('inc', 'lexicon', 'lexicon.pages');

  # Add the shared dgu logo.
  $variables['logo'] = '/assets/img/dgu-header-cropped.png';
}

/**
 *  Implements hook_preprocess_field().
 */
function dguk_preprocess_field(&$variables) {

	if($variables['element']['#field_name'] == 'field_uses_dataset') {
    // Render direct link to dataset in CKAN instead of dataset copy in Drupal.
    $title = $variables['element']['#items'][0]['entity']->title;
    $name = $variables['element']['#items'][0]['entity']->name;
    $variables['items'][0]['#markup'] = l($title, 'dataset/' . $name);
  }
}

/**
 * Get the output for the main menu.
 * Used in template and for ckan to pull in externally.
 */
function dguk_get_main_menu() {
	$menu = menu_navigation_links('main-menu');
	$menu_output = theme('links__main-menu', array(
	    'links' => $menu,
	    'attributes' => array(
	        'id' => 'dgu-nav',
	        'class' => array('nav'),
	    ),
	 ));

    $output = '<div class="navbar navbar-inverse"> <div class="main-nav-collapse">';
    $output .=  $menu_output;
    $output .= '</div><!--/.main-nav-collapse --></div>';

	return $output;
 }



/**
 * Get the output for the footer menu.
 * Used in template and for ckan to pull in externally.
 */
function dguk_get_footer_menu() {
	$menu = menu_navigation_links('menu-footer');
	$menu_output = theme('links__menu-footer', array(
	    'links' => $menu,
	    'attributes' => array(
	        'class' => array('links'),
	    ),
	 ));

	return $menu_output;
 }


function dguk_js_alter(&$js){
 /**
  * Remove jquery and bootstrap.
  * @see dguk/templates/html.tpl.php
  */
  unset($js['misc/jquery.js']);
  unset($js['profiles/dgu/themes/contrib/bootstrap/bootstrap/js/bootstrap.js']);
}