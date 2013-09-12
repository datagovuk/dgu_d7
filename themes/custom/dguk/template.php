<?php

/**
 *  Implements hook_preprocess().
 */
function dguk_preprocess(&$variables){
  module_load_include('inc', 'lexicon', 'lexicon.pages');

  # Add the shared dgu logo.
  $variables['logo'] = '/assets/img/dgu-header-cropped.png';
}

/**
 *  Implements hook_preprocess_node().
 */
function dguk_preprocess_node(&$variables) {
  $variables['classes_array'][] = 'boxed';
}

/**
 *  Implements hook_preprocess_panels_pane().
 */
function dguk_preprocess_panels_pane(&$variables) {
  $variables['classes_array'][] = 'boxed';
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
	$menu = dguk_menu_navigation_links('main-menu');
//      <li class=""><a href="/home"><div class="nav-icon"></div>Home</a></li>
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
  $output = str_replace('Home</a>', '<div class="nav-icon"></div>Home</a>', $output);

	return $output;
 }

/**
 * Returns an array of links for a navigation menu with
 * classes corresponding with menu items names.
 *
 * @param $menu_name
 *   The name of the menu.
 * @param $level
 *   Optional, the depth of the menu to be returned.
 *
 * @return
 *   An array of links of the specified menu and level.
 */
function dguk_menu_navigation_links($menu_name, $level = 0) {
  // Don't even bother querying the menu table if no menu is specified.
  if (empty($menu_name)) {
    return array();
  }

  // Get the menu hierarchy for the current page.
  $tree = menu_tree_page_data($menu_name, $level + 1);

  // Go down the active trail until the right level is reached.
  while ($level-- > 0 && $tree) {
    // Loop through the current level's items until we find one that is in trail.
    while ($item = array_shift($tree)) {
      if ($item['link']['in_active_trail']) {
        // If the item is in the active trail, we continue in the subtree.
        $tree = empty($item['below']) ? array() : $item['below'];
        break;
      }
    }
  }

  // Create a single level of links.
  $router_item = menu_get_item();
  $links = array();
  foreach ($tree as $item) {
    if (!$item['link']['hidden']) {
      $class = '';
      $l = $item['link']['localized_options'];
      $l['href'] = $item['link']['href'];
      $l['title'] = $item['link']['title'];
      if ($item['link']['in_active_trail']) {
        $class = ' active-trail';
        $l['attributes']['class'][] = 'active-trail';
      }
      // Normally, l() compares the href of every link with $_GET['q'] and sets
      // the active class accordingly. But local tasks do not appear in menu
      // trees, so if the current path is a local task, and this link is its
      // tab root, then we have to set the class manually.
      if ($item['link']['href'] == $router_item['tab_root_href'] && $item['link']['href'] != $_GET['q']) {
        $l['attributes']['class'][] = 'active';
      }
      // Keyed with the unique mlid to generate classes in theme_links().
      $links['nav-' . strtolower(str_replace(' ', '-', $item['link']['link_title'])) . $class] = $l;
    }
  }
  return $links;
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