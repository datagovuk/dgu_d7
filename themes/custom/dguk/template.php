<?php

/**
 *  Implements hook_preprocess_html().
 */
function dguk_preprocess_html(&$variables){
  module_load_include('inc', 'lexicon', 'lexicon.pages');

  # Add the shared dgu logo.
  $variables['logo'] = '/assets/img/dgu-header-cropped.png';
}

/**
 *  Implements hook_preprocess_page().
 */
function dguk_preprocess_page(&$variables) {

  // If this is a node view page add content type to the template suggestions.
  if (isset($variables['node'])) {
    $variables['theme_hook_suggestions'][] = 'page__node__' .$variables['node']->type;
  }

  // If this is a panel page.
  if ($panel_page = page_manager_get_current_page()) {
    // Add a generic suggestion for all panel pages.
    $variables['theme_hook_suggestions'][] = 'page__panel';
    // Add the panel page machine name to the template suggestions.
    $variables['theme_hook_suggestions'][] = 'page__panel__' . $panel_page['name'];

    // If this is node_view panel
    if (isset($variables['node'])) {
      // Add panel page machine name and content type to the template suggestions.
      // e.g. "page__panel__node_view__blog"
      $variables['theme_hook_suggestions'][] = 'page__panel__' . $panel_page['name'] . '__' . $variables['node']->type;
    }
  }
  if (!empty($variables['node']) && $variables['node']->type == 'book' && !empty($variables['node']->parent_book)) {
    $variables['title'] = $variables['node']->parent_book->title;
  }

}

/**
 *  Implements hook_preprocess_node().
 */
function dguk_preprocess_node(&$variables) {
  $variables['classes_array'][] = 'boxed';
  $full_node = node_load($variables['node']->nid);
  $variables['title'] = $full_node->title;

  $fields = field_info_instances('user', 'user');
  $field_id = $fields['field_avatar']['field_id'];
  $user = new stdClass();
  $user->uid = $variables['node']->uid;
  field_attach_load('user', array($variables['node']->uid => $user), FIELD_LOAD_CURRENT, array('field_id' => $field_id));

  if (!empty($user->field_avatar)) {
    $field = field_get_items('user', $user, 'field_avatar');
    $image = field_view_value('user', $user, 'field_avatar', $field[0], array('settings' => array('image_style' => 'profile')));
  }
  else {
    $image = theme_image_style_outside_files(
    array(
      'style_name' => 'profile',
      'path' => 'profiles/dgu/themes/custom/dguk/default_images/default_user.png',
      )
    );
  }
  $variables['avatar'] = render($image);
}

/**
 *  Implements hook_preprocess_panels_pane().
 */
function dguk_preprocess_panels_pane(&$variables) {

  //drupal_set_message($variables['pane']->type . ':' . $variables['pane']->subtype);

  // Add 'boxed' class to all panes apart of these.
  if ( $variables['pane']->type != 'node'
    && $variables['pane']->type != 'node_content'
    && $variables['pane']->type != 'apachesolr_result'
     ) {
    $variables['classes_array'][] = 'boxed';
  }
  else {
    unset($variables['title']);
  }

  // Add form-search class to search forms in panes
  if($variables['pane']->type == 'apachesolr_form'
      || ($variables['pane']->type == 'block' && $variables['pane']->subtype == 'dgu_search-searchapp')
      || ($variables['pane']->type == 'block' && $variables['pane']->subtype == 'dgu_search-searchblog')
      || ($variables['pane']->type == 'block' && $variables['pane']->subtype == 'dgu_search-searchforum')
    ) {
    $variables['content']['#attributes']['class'][] = 'form-search';
    $variables['content']['#attributes']['class'][] = 'form-search-solo';
  }

  if ($variables['pane']->type == 'fieldable_panels_pane') {
    $variables['theme_hook_suggestions'][] = 'panels_pane__fieldable_panels_pane__' . $variables['content']['#element']->bundle;
  }
}

/**
 *  Implements hook_preprocess_block().
 */
function dguk_preprocess_block(&$variables) {
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
 *  Implements hook_preprocess_reply().
 */
function dguk_preprocess_reply(&$variables) {
  $variables['classes_array'][] = 'boxed';

  // Add $avatar variable with rendered user picture linked to user profile;
  $fields = field_info_instances('user', 'user');
  $field_id = $fields['field_avatar']['field_id'];
  $user = new stdClass();
  $user->uid = $variables['reply']->uid;
  field_attach_load('user', array($variables['reply']->uid => $user), FIELD_LOAD_CURRENT, array('field_id' => $field_id));

  if (!empty($user->field_avatar)) {
    $field = field_get_items('user', $user, 'field_avatar');
    $image = field_view_value('user', $user, 'field_avatar', $field[0], array('settings' => array('image_style' => 'avatar')));
  }
  else {
    $image = theme_image_style_outside_files(
    array(
      'style_name' => 'avatar',
      'path' => 'profiles/dgu/themes/custom/dguk/default_images/default_user.png',
	    )
    );
  }

  $variables['avatar'] = l(render($image), 'user/'.$variables['reply']->uid, array('html' => true) );
}



/**
 * Implements hook_preprocess_replies().
 */
function dguk_preprocess_replies(&$variables) {
  if (($variables['access'] == REPLY_ACCESS_FULL && user_access('administer replies')) ||  user_access('administer replies') || user_access('post '. $variables['bundle'] .' reply')) {
     $variables['links']['add_reply']['#markup'] = l(t('Add new comment'), 'reply/add/'. $variables['entity_id'] .'/'. $variables['instance_id'] .'/0');
  } else {
    $options = array('query' => array('destination' => 'reply/add/'. $variables['entity_id'] .'/'. $variables['instance_id'] .'/0'));
    $variables['links']['reply_post_forbidden']['#markup'] = l(t('Login'), 'user/login' , $options) . ' to make a comment';
  }
}


/**
 *  Implements hook_preprocess_search_result().
 */
function dguk_preprocess_search_result(&$variables) {
  $variables['classes_array'][] = 'boxed';
  $variables['classes_array'][] = 'node-type-' . $variables['result']['bundle'];

  switch ($variables['result']['bundle']) {
    case 'app':
      $variables['info_split']['submitted'] = 'Submitted on ' . $variables['info_split']['date'];
      if (isset($variables['result']['fields']['sm_field_developed_by'][0])) {
        $variables['info_split']['other'] = 'Developed by: ' . $variables['result']['fields']['sm_field_developed_by'][0];
      }
      break;
    case 'blog':
      $variables['info_split']['submitted'] = 'Submitted by ' . $variables['info_split']['user'] . ' on ' . $variables['info_split']['date'];
      break;
    case 'dataset_request':
      $review_status_values = &drupal_static('odug_review_statuses');
      if (!isset($review_status_values)) {
        $all_fields_info = field_info_fields();
        $review_status_values = $all_fields_info['field_review_status']['settings']['allowed_values'];
      }
      $status_key = $variables['result']['fields']['im_field_review_status'][0];
      $status_value = $review_status_values[$status_key];

      $variables['info_split']['other'] = 'Review status: ' . $status_value;
      $variables['info_split']['submitted'] = 'Submitted on ' . $variables['info_split']['date'];
      break;
    case 'forum':
      $variables['info_split']['submitted'] = 'Submitted by ' . $variables['info_split']['user'] . ' on ' . $variables['info_split']['date'];
      break;
    case 'page':
      $variables['info_split']['submitted'] = 'Submitted by ' . $variables['info_split']['user'] . ' on ' . $variables['info_split']['date'];
      break;
    case 'resource':
      $variables['info_split']['submitted'] = 'Submitted on ' . $variables['info_split']['date'];
      break;
  }
}

/**
 *  Implements hook_form_alter().
 */
function dguk_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    case 'user_pass':
    case 'user_login':
    case 'user_register_form':
    case 'reply_add_form':
      $form['#attributes']['class'][] = 'boxed';
      break;
  }
}

/**
 *  Implements hook_css_alter().
 */
function dguk_css_alter(&$css) {
  // Remove style.css file added by bootstrap theme - issue #811.
  unset($css[drupal_get_path('theme', 'bootstrap') . '/css/style.css']);
  // Remove inherited bootstrap files because they are not actually installed or required.
  unset($css[drupal_get_path('theme', 'bootstrap') . '/bootstrap/css/bootstrap.css']);
  unset($css[drupal_get_path('theme', 'bootstrap') . '/bootstrap/css/bootstrap-responsive.css']);
}


///**
// * Get the output for the main menu.
// */
//function dguk_get_main_menu($main_menu2) {
//
//  $x = menu_tree_page_data('main-menu', 2);
//
//  //TODO add access control or check why menu_build_tree() remove the links
//  $menu = _menu_build_tree('main-menu');
//  $main_menu = array();
//
//  $active_path = menu_tree_get_path($menu_name);
//  $active_link = menu_link_get_preferred($active_path, $menu_name);
//  $router_item = menu_get_item();
//
//  $active_trail = array();
//  if (isset($active_link['menu_name']) && $active_link['menu_name'] == 'main-menu') {
//    // Check 4 level deep.
//    for ($i = 1; $i < 5; $i++) {
//      if ($active_link['p' . $i]) {
//        $active_trail[] = (int)$active_link['p' . $i];
//      }
//    }
//  }
//
//
//  foreach ($menu['tree'] as $item) {
//    if (!$item['link']['hidden']) {
//      $class = '';
//      $l = $item['link']['localized_options'];
//      $l['href'] = $item['link']['link_path'];
//      $l['title'] = $item['link']['title'];
//      if (in_array($item['link']['mlid'], $active_trail)) {
//        $class = ' active-trail';
//        $l['attributes']['class'][] = 'active-trail';
//      }
//      if ($item['link']['href'] == $router_item['tab_root_href'] && $item['link']['href'] != $_GET['q']) {
//        $l['attributes']['class'][] = 'active';
//      }
//      // Keyed with the unique mlid to generate classes in theme_links().
//      $main_menu['menu-' . $item['link']['mlid'] . $class] = $l;
//    }
//  }
//
//  $v = $main_menu['menu-770 active-trail'];
//
//	return theme('links__main_menu', array('links' => $main_menu));
//}
//
///**
// * Get the output for the sub menu (2nd level of main menu).
// */
//function dguk_get_sub_menu() {
//	$menu = menu_navigation_links('main-menu', 1);
//
//	return theme('links__sub_menu', array(
//	    'links' => $menu,
//	    'attributes' => array(
//	        'id' => 'subnav',
//	    ),
//	 ));
// }

/**
 * Get the output for Apps menu.
 */
function dguk_get_apps_menu() {
	$menu = menu_navigation_links('menu-apps');
  $classes = array('subnav', 'subnav-apps');

  foreach ($menu as $menu_item) {
    if(isset($menu_item['attributes']['class']) && (in_array('active', $menu_item['attributes']['class']) || in_array('active-trail', $menu_item['attributes']['class']))) {
      $classes[] = 'active';
    }
  }

	$menu_output = theme('links__menu-apps', array(
	    'links' => $menu,
	    'attributes' => array(
	        'class' => $classes,
	    ),
	 ));

	return $menu_output;
 }

/**
 * Get the output for Apps menu.
 */
function dguk_get_interact_menu() {
	$menu = menu_navigation_links('menu-interact');
  $classes = array('subnav', 'subnav-interact');

  foreach ($menu as $menu_item) {
    if(isset($menu_item['attributes']['class']) && (in_array('active', $menu_item['attributes']['class']) || in_array('active-trail', $menu_item['attributes']['class']))) {
      $classes[] = 'active';
    }
  }

	$menu_output = theme('links__menu-interact', array(
	    'links' => $menu,
	    'attributes' => array(
	        'class' => $classes,
	    ),
	 ));

	return $menu_output;
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


///**
// * Returns HTML for main mnavigation links.
// */
//function dguk_links__main_menu($variables) {
//
//  $v = $variables['links']['menu-770 active-trail'];
//
//  $links = $variables['links'];
//  global $language_url;
//  $output = '';
//
//  if (count($links) > 0) {
//    foreach ($links as $link) {
//      if (!isset($link['attributes']['class'])) {
//        $link['attributes']['class'] = array();
//      }
//      $link['attributes']['class'][] = 'trigger-subnav';
//      $link['attributes']['class'][] = 'nav-' . strtolower(str_replace(' ', '-', $link['title']));
//
//      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
//          && (empty($link['language']) || $link['language']->language == $language_url->language)) {
//        $link['attributes']['class'][] = 'active';
//      }
//
//      if (isset($link['href'])) {
//        // Pass in $link as $options, they share the same keys.
//        $output .= l($link['title'], $link['href'], $link);
//      }
//
//      elseif (!empty($link['title'])) {
//        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
//        if (empty($link['html'])) {
//          $link['title'] = check_plain($link['title']);
//        }
//        $span_attributes = '';
//        if (isset($link['attributes'])) {
//          $span_attributes = drupal_attributes($link['attributes']);
//        }
//        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
//      }
//
//    }
//  }
//
//  return $output;
//}


///**
// * Returns HTML for sub mnavigation links.
// */
//function dguk_links__sub_menu($variables) {
//  $links = $variables['links'];
//  $attributes = $variables['attributes'];
//  $output = '';
//
//  if (count($links) > 0) {
//    $output .= '<ul' . drupal_attributes($attributes) . '>';
//
//    $num_links = count($links);
//    $i = 1;
//
//    foreach ($links as $key => $link) {
//      $class = array($key);
//
//      // Add first, last and active classes to the list of links to help out themers.
//      if ($i == 1) {
//        $class[] = 'first';
//      }
//      if ($i == $num_links) {
//        $class[] = 'last';
//      }
//      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
//          && (empty($link['language']) || $link['language']->language == $language_url->language)) {
//        $class[] = 'active';
//      }
//      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';
//
//      if (isset($link['href'])) {
//        // Pass in $link as $options, they share the same keys.
//        $output .= l($link['title'], $link['href'], $link);
//      }
//      elseif (!empty($link['title'])) {
//        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
//        if (empty($link['html'])) {
//          $link['title'] = check_plain($link['title']);
//        }
//        $span_attributes = '';
//        if (isset($link['attributes'])) {
//          $span_attributes = drupal_attributes($link['attributes']);
//        }
//        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
//      }
//
//      $i++;
//      $output .= "</li>\n";
//
//      if ($i <= $num_links) {
//        $output .= "<span class=\"divider\">&nbsp;|&nbsp;</span>\n";
//      }
//    }
//
//    $output .= '</ul>';
//  }
//
//  return $output;
//}



/**
 * Remove jquery and bootstrap.
 * @see dguk/templates/html.tpl.php
 */
function dguk_js_alter(&$js){
  unset($js['profiles/dgu/themes/contrib/bootstrap/js/bootstrap.js']);
  unset($js['profiles/dgu/themes/contrib/bootstrap/js/misc/_progress.js']);
  unset($js['profiles/dgu/themes/contrib/bootstrap/js/misc/_vertical-tabs.js']);
  unset($js['profiles/dgu/themes/contrib/bootstrap/js/misc/ajax.js']);
  unset($js['profiles/dgu/themes/contrib/bootstrap/js/misc/autocomplete.js']);

  // Remove core jquery on all pages apart of defined in $paths_to_avoid array.
  $current_path = current_path();
  $paths_to_avoid = array(
      '^admin\/',
      '^node\/add\/',
      '^node\/\d*\/edit',
      '^user\/\d*\/edit',
    );

  $keep_jquery = FALSE;
  foreach ($paths_to_avoid as $path_to_avoid) {
    if(preg_match("/$path_to_avoid/", $current_path)) {
      $keep_jquery = TRUE;
      break;
    }
  }

  if (!$keep_jquery) {
    unset($js['misc/jquery.js']);
  }
}

function dguk_menu_breadcrumb_alter(&$active_trail, $item){
  $end = end($active_trail);
  foreach ($active_trail as $key => $crumb){
    if (!empty($crumb['path']) && $crumb['path'] == 'forum/%') {
      //special processing for forum items
      //Set the title and href and replace the current item with a link to forums
      $crumb['title'] = 'Discussion Forum';
      $crumb['href'] = 'forum';
      $active_trail[$key] = $crumb;
      //Set the title of the page to the current item's title which is appended to the crumbs link
      drupal_set_title($crumb['map'][$key]->title);
      //append an item to the active trail to prevent drupal from removing the last crumb
      $active_trail[] = $end;
    } elseif (!empty($crumb['link_path']) && $crumb['link_path'] == 'node/%'){
      //special processing for nodes
      $parent_path = '';
      $title = drupal_get_title();
      switch($item['map'][$key]->type){
        case 'app':
          $parent_path = 'apps';
          break;
        case 'blog':
          $parent_path = 'blog';
          break;
        case 'resource':
          $parent_path = 'library';
          break;
        case 'forum':
          //forum items need a link to the parent forum
          //Set the title and href and replace the current item with a link to forums
          $crumb['title'] = 'Discussion Forum';
          $parent_path = 'forum';
          $active_trail[$key] = $crumb;

          $tid = $item['map'][$key]->taxonomy_forums[LANGUAGE_NONE][0]['tid'];
          $forum = taxonomy_term_load($tid);
          $active_trail[] = array('title' => $forum->name, 'href' => 'forum/' . str_replace(' ', '-', strtolower($forum->name)), 'localized_options' => array());
      }
      //Set the current crumb to the page title
      $crumb['title'] = $title;
      $crumb['href'] = $parent_path;
      $active_trail[$key] = $crumb;
      //Set the page title to the node title
      drupal_set_title($crumb['map'][$key]->title);
      //append an item to the active trail to prevent drupal from removing the last crumb
      $active_trail[] = $end;
    }
  }
}

/**
 * Implements theme_breadcrumb()
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function dguk_breadcrumb($variables) {
  if (count($variables['breadcrumb']) > 0) {
    $crumbs = '<ul id="breadcrumbs">';
    $a=0;
    foreach($variables['breadcrumb'] as $value) {
      if ($a==0){
        $crumbs .= '<li>' . l('<i class="icon-home"></i>', '<front>', array('html' => TRUE)) . '</li>';
      }
      else {
        if ($value != '*:*'){
          $crumbs .= '<li>'. $value . '</li>';
        }
      }
      $a++;
    }
    $title = drupal_get_title();
    $crumbs .= '<li>' . $title . '</li>';
    return $crumbs;
   }
}

function dguk_preprocess_user_profile(&$variables) {
  $avatar = array(
      'style_name' => 'profile',
      'path' => $user->field_avatar[0]['uri'],
    );
  $variables['profile_image'] = theme('image_style', $avatar);

  $variables['first_name'] = $variables['field_first_name'][0]['safe_value'];
  $variables['surname'] = $variables['field_surname'][0]['safe_value'];
  $variables['bio'] = $variables['field_bio'][0]['safe_value'];
  $variables['member_for'] = $user_profile['summary']['member_for']['#markup'];
  $variables['twitter'] = $variables['field_twitter'][0]['safe_value'];
  $variables['job_title'] = $variables['field_job_title'][0]['safe_value'];
  $variables['linkedin_url'] = $variables['field_linkedin_url'][0]['url'];
  $variables['linkedin'] = l($linkedin_url, $linkedin_url);
  $variables['facebook_url'] = $variables['field_facebook_url'][0]['url'];
  $variables['facebook'] = l($facebook_url, $facebook_url);
}
