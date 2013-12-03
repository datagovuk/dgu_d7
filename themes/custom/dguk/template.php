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

/**
 * Get the output for Data menu.
 */
function dguk_get_data_menu() {
  $menu = menu_navigation_links('menu-apps');

  $menu = array(
    'menu-datasets' => array(
      'title' => 'Datasets',
      'href' => 'data/search',
    ),
    'menu-map-search' => array(
      'title' => 'Map Search',
      'href' => 'data/map-based-search',
    ),
    'menu-data-requests' => array(
      'title' => 'Data Requests',
      'href' => 'odug',
    ),
    'menu-publishers' => array(
      'title' => 'Publishers',
      'href' => 'publisher',
    ),
    'menu-organogram' => array(
      'title' => 'Public Roles & Salaries',
      'href' => 'organogram/cabinet-office',
    ),
    'menu-openspending' => array(
      'title' => 'OpenSpending',
      'href' => 'data/openspending-browse',
    ),
    'menu-openspending-report' => array(
      'title' => 'Spend Reports',
      'href' => 'data/openspending-report/index',
    ),
    'menu-site-usage' => array(
      'title' => 'Site Analytics',
      'href' => 'data/site-usage',
    ),
  );

  global $user;
  if ($user->uid == 1 || in_array('ckan adminstrator', array_values($user->roles))) {
    $admin_menu = array(
      'divider-section' => array(
        'title' => 'Sys Admin:',
      ),

      'menu-system-dashboard' => array(
        'title' => 'System Dashboard',
        'href' => 'data/system_dashboard',
      ),
      'menu-harvest' => array(
        'title' => 'Harvest Sources',
        'href' => 'harvest',
      ),
      'menu-feedback-moderation' => array(
        'title' => 'Feedback moderation',
        'href' => 'data/feedback/moderation',
      ),
    );
    $menu = array_merge($menu, $admin_menu);
  }

  $classes = array('subnav', 'subnav-data');
  $current_path = $_SERVER['REQUEST_URI'];
  $a = strpos($current_path, 'odug');
  $b = strpos($current_path, 'data-request');

  // $current_path always starts from "/"
  if (strpos($current_path, 'odug') == 1 || strpos($current_path, 'data-request') == 1 || strpos($current_path, 'node/add/dataset-request') == 1) {
    $menu['menu-data-requests']['attributes']['class'][] = 'active';
    $classes[] = 'active';
  }
  if (strpos($current_path, 'organogram') == 1) {
    $menu['menu-organogram']['attributes']['class'][] = 'active';
    $classes[] = 'active';
  }

	$menu_output = theme('links__menu-data', array(
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
function dguk_get_apps_menu($menu) {
	//$menu = menu_navigation_links('menu-apps');
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
function dguk_get_interact_menu($menu) {
  //$menu = menu_navigation_links('menu-interact');
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

/**
 * Remove jquery and bootstrap.
 * @see dguk/templates/html.tpl.php
 */
function dguk_js_alter(&$js){
//  unset($js['profiles/dgu/themes/contrib/bootstrap/js/bootstrap.js']);
//  unset($js['profiles/dgu/themes/contrib/bootstrap/js/misc/_progress.js']);
//  unset($js['profiles/dgu/themes/contrib/bootstrap/js/misc/_vertical-tabs.js']);
//  unset($js['profiles/dgu/themes/contrib/bootstrap/js/misc/ajax.js']);
//  unset($js['profiles/dgu/themes/contrib/bootstrap/js/misc/autocomplete.js']);
//
//  // Remove core jquery on all pages apart of defined in $paths_to_avoid array.
//  $current_path = current_path();
//  $paths_to_avoid = array(
//      '^admin\/',
//      '^node\/add\/',
//      '^node\/\d*\/edit',
//      '^user\/\d*\/edit',
//    );
//
//  $keep_jquery = FALSE;
//  foreach ($paths_to_avoid as $path_to_avoid) {
//    if(preg_match("/$path_to_avoid/", $current_path)) {
//      $keep_jquery = TRUE;
//      break;
//    }
//  }
//
//  if (!$keep_jquery) {
//    unset($js['misc/jquery.js']);
//  }
  unset($js['misc/jquery.js']);
  unset($js['profiles/dgu/modules/contrib/jquery_update/replace/jquery/1.8/jquery.min.js']);



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
        case 'dataset_request':
          $parent_path = 'odug';
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
          break;
        default:
          $alias = drupal_get_path_alias('node/' . $crumb['map'][$key]->nid);
          $parts =  explode('/', $alias);
          $parent_path =  $parts[0];
          break;

      }
      //Set the current crumb to the page title
      $crumb['title'] = htmlspecialchars_decode($title);
      $crumb['href'] = $parent_path;
      $active_trail[$key] = $crumb;
      //Set the page title to the node title
      drupal_set_title($crumb['map'][$key]->title);
      //append an item to the active trail to prevent drupal from removing the last crumb
      $active_trail[] = $end;
    }  elseif (!empty($crumb['path']) && $crumb['path'] == 'reply/add/%/%/%') {
      $instance_id = $item['page_arguments'][1];
      $instance = reply_load_instance($instance_id);
      $entity_type = $instance->entity_type;
      $entity = entity_load($entity_type, array($item['page_arguments'][0]));
      $entity = reset($entity);
      $alias = drupal_get_path_alias($entity_type . '/' . $entity->nid);
      $parts =  explode('/', $alias);

      //set the parent path
      $parent_path =  $parts[0];
      $parent_menu = menu_get_item($parent_path);
      $crumb['title'] = htmlspecialchars_decode($parent_menu['title']);
      $crumb['href'] = $parent_path;
      $active_trail[$key] = $crumb;

      //Set the current crumb to the page title
      $crumb['title'] = htmlspecialchars_decode($entity->title);
      $crumb['href'] = $alias;
      $active_trail[] = $crumb;
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
    $title = drupal_get_title();
    foreach($variables['breadcrumb'] as $value) {
      if ($a==0){
        $crumbs .= '<li>' . l('<i class="icon-home"></i>', '<front>', array('html' => TRUE)) . '</li>';
      }
      else {
        if ($value != '*:*' && $title != 'Library'){
          $crumbs .= '<li>'. $value . '</li>';
        }
      }
      $a++;
    }
    $crumbs .= '<li>' . $title . '</li>';
    return $crumbs;
   }
}

function dguk_preprocess_user_profile(&$variables) {
  $variables['first_name'] = $variables['field_first_name'][0]['safe_value'];
  $variables['surname'] = $variables['field_surname'][0]['safe_value'];
  $variables['bio'] = $variables['field_bio'][0]['safe_value'];
  $variables['twitter'] = $variables['field_twitter'][0]['safe_value'];
  $variables['job_title'] = $variables['field_job_title'][0]['safe_value'];
  $variables['linkedin'] = $variables['field_linkedin_url'][0]['url'];
  $variables['facebook'] = $variables['field_facebook_url'][0]['url'];
}


function dguk_field__field_quality__glossary($variables){
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label']
      . '&nbsp;<a class="lexicon-term" href="/glossary/63" title="The APPSI quality score reflects our confidence in the accuracy and quality of a term and it\'s definition">(What is this?)</a>'
      . ':&nbsp;</div>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
}


function dguk_ajax_render_alter(&$commands) {
  $commands[] = ajax_command_remove('#messages');
  $commands[] = ajax_command_prepend('.drupal-messages', '<div id="messages">' . theme('status_messages') . '</div>');
}
