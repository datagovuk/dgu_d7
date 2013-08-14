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