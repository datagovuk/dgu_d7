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

  if ($variables['created'] != $variables['changed']) {
    $variables['updated'] = '| Updated on ' . format_date($variables['changed']);
  }
  // We render user picture only on forum and blog nodes.
  if ($variables['node']->type == 'forum' || $variables['node']->type == 'blog') {
    $fields = field_info_instances('user', 'user');
    $field_id = $fields['field_avatar']['field_id'];
    $user = new stdClass();
    $user->uid = $variables['node']->uid;
    field_attach_load('user', array($user->uid => $user), FIELD_LOAD_CURRENT, array('field_id' => $field_id));

    if (!empty($user->field_avatar)) {
      $field = field_get_items('user', $user, 'field_avatar');
      $image = field_view_value('user', $user, 'field_avatar', $field[0], array('settings' => array('image_style' => 'avatar')));
    }
    else {
      $image_info = dguk_default_field_image('field_avatar');
      $image = field_view_value('user', $user, 'field_avatar', (array) $image_info, array('settings' => array('image_style' => 'avatar')));
    }

    $colour = $variables['node']->uid % 10;
    if ($variables['node']->uid) {
      $variables['avatar'] = l(render($image), 'user/' . $variables['node']->uid, array('html' => true, 'attributes' => array('class' => array('field-avatar','bg-colour-' . $colour))));
    }
    else {
      $variables['avatar'] = '<div class="field-avatar bg-colour-0">' . render($image) . '</div>';
    }
  }
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

  // To add a class to field_avatar passed from preprocess_user_profile().
  if(isset($variables['element']['classes_array'])){
    $variables['classes_array'] = array_merge($variables['classes_array'], $variables['element']['classes_array']);
  }

  if($variables['element']['#field_name'] == 'field_uses_dataset') {
    // Render direct link to dataset in CKAN instead of dataset copy in Drupal.
    foreach ($variables['element']['#items'] as $index => $item){
      $title = $item['entity']->title;
      $name = $item['entity']->name;
      $variables['items'][$index]['#markup'] = l($title, 'dataset/' . $name);
    }
  }
}

/**
 *  Implements hook_preprocess_reply().
 */
function dguk_preprocess_reply(&$variables) {
  $variables['classes_array'][] = 'boxed';
  $variables['classes_array'][] = 'parent-' . $variables['reply']->parent;

  // Add $avatar variable with rendered user picture linked to user profile;
  $fields = field_info_instances('user', 'user');
  $field_id = $fields['field_avatar']['field_id'];
  $user = new stdClass();
  $user->uid = $variables['reply']->uid;
  field_attach_load('user', array($user->uid => $user), FIELD_LOAD_CURRENT, array('field_id' => $field_id));

  if (!empty($user->field_avatar)) {
    $field = field_get_items('user', $user, 'field_avatar');
    $image = field_view_value('user', $user, 'field_avatar', $field[0], array('settings' => array('image_style' => 'avatar')));
  }
  else {
    $image_info = dguk_default_field_image('field_avatar');
    $image = field_view_value('user', $user, 'field_avatar', (array) $image_info, array('settings' => array('image_style' => 'avatar')));
  }

  $colour = $variables['reply']->uid % 10;
  if ($variables['reply']->uid) {
    $variables['avatar'] = l(render($image), 'user/' . $variables['reply']->uid, array('html' => true, 'attributes' => array('class' => array('field-avatar','bg-colour-' . $colour))));
  }
  else {
    $variables['avatar'] = '<div class="field-avatar bg-colour-0">' . render($image) . '</div>';
  }
}



/**
 * Implements hook_preprocess_replies().
 */
function dguk_preprocess_replies(&$variables) {
  $options = array('attributes' => array('class' => array('btn-default', 'btn', 'btn-primary')));

  if (($variables['access'] == REPLY_ACCESS_FULL && user_access('administer replies')) ||  user_access('administer replies') || user_access('post '. $variables['bundle'] .' reply')) {
     $variables['links']['add_reply']['#markup'] = l(t('Add new comment'), 'reply/add/'. $variables['entity_id'] .'/'. $variables['instance_id'] .'/0', $options);
  }
  else {
    $options['query'] = array('destination' => 'reply/add/'. $variables['entity_id'] .'/'. $variables['instance_id'] .'/0');
    $variables['links']['reply_post_forbidden']['#markup'] = l(t('Login to make a comment'), 'user/login', $options);
  }
}


/**
 *  Implements hook_preprocess_search_result().
 */
function dguk_preprocess_search_result(&$variables) {
  $variables['classes_array'][] = 'boxed';
  $variables['classes_array'][] = 'node-type-' . $variables['result']['bundle'];


  $variables['info_split']['changed'] = $variables['info_split']['date'];
  unset($variables['info_split']['date']);
  $variables['info_split']['created'] = format_date($variables['result']['fields']['created'], 'short');


  switch ($variables['result']['bundle']) {
    case 'app':
      $variables['submitted'] = 'Submitted on ' . $variables['info_split']['created'];
      $variables['updated'] = 'Updated on ' . $variables['info_split']['changed'];

      if (isset($variables['result']['fields']['sm_field_developed_by'][0])) {
        $variables['other'] = 'Developed by: ' . $variables['result']['fields']['sm_field_developed_by'][0];
      }
      break;
    case 'blog':
      $variables['submitted'] = 'Submitted by ' . $variables['info_split']['user'];
      $variables['updated'] = 'Updated on ' . $variables['info_split']['changed'];
      break;
    case 'dataset_request':
      $review_status_values = &drupal_static('odug_review_statuses');
      if (!isset($review_status_values)) {
        $all_fields_info = field_info_fields();
        $review_status_values = $all_fields_info['field_review_status']['settings']['allowed_values'];
      }
      $status_key = $variables['result']['fields']['im_field_review_status'][0];
      $status_value = $review_status_values[$status_key];

      $variables['other'] = 'Review status: ' . $status_value;
      $variables['updated'] = 'Updated on ' . $variables['info_split']['changed'];

      break;
    case 'forum':
      $variables['submitted'] = 'Submitted by ' . $variables['info_split']['user'];
      $variables['updated'] = 'Updated on ' . $variables['info_split']['changed'];
      break;
    case 'page':
      $variables['submitted'] = 'Submitted by ' . $variables['info_split']['user'] . ' on ' . $variables['info_split']['created'];
      if($variables['info_split']['created'] != $variables['info_split']['changed']) {
        $variables['updated'] = 'Updated on ' . $variables['info_split']['changed'];
      }
      break;
    case 'resource':
      $variables['submitted'] = 'Submitted on ' . $variables['info_split']['created'];
      if($variables['info_split']['created'] != $variables['info_split']['changed']) {
        $variables['updated'] = 'Updated on ' . $variables['info_split']['changed'];
      }
      break;
  }
}

/**
 * Loads default image from image field.
 */
function dguk_default_field_image($field_name) {
  $field_info = field_info_field($field_name);
  $fid = $field_info['settings']['default_image'];
  return file_load($fid);
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

  if(dguk_get_search_content_type() == 'dataset_request') {
    $menu['menu-data-requests']['attributes'] = array('class' => array('active', 'active-trail'));
    $classes[] = 'active';
  }


  $current_path = $_SERVER['REQUEST_URI'];

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

function dguk_get_search_content_type() {
  if ($is_search_page = arg(0) == 'search' && arg(1) == 'everything') {
    $query = drupal_get_query_parameters();
     if(!empty($query['f'])){
      foreach ($query['f'] as $facet) {
        if (strpos($facet, 'bundle') === 0) {
          return substr($facet, 7);
        }
      }
     }
  }
}

/**
 * Get the output for Apps menu.
 */
function dguk_get_apps_menu($menu) {
	//$menu = menu_navigation_links('menu-apps');
  $classes = array('subnav', 'subnav-apps');
  if (dguk_get_search_content_type() == 'app') {
    $classes[] = 'active';
    $search_apps_link_ref = &$menu[key($menu)];;
    $search_apps_link_ref['attributes']['class'] = 'active';
  }

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
 * Get the output for Interact menu.
 */
function dguk_get_interact_menu($menu) {
  $classes = array('subnav', 'subnav-interact');
  $bundle_facet = dguk_get_search_content_type();

  $activated = FALSE;
  foreach ($menu as &$menu_item) {
    if(isset($menu_item['attributes']['class']) && (in_array('active', $menu_item['attributes']['class'])|| in_array('active-trail', $menu_item['attributes']['class']))) {
      $classes[] = 'active';
    }
    if($menu_item['href'] == $bundle_facet) {
      $menu_item['attributes']['class'] = 'active';
      $activated = TRUE;
    }
  }

	$menu_output = theme('links__menu-interact', array(
    'links' => $menu,
    'attributes' => array(
      'class' => $classes,
    ),
	 ));

  if ($bundle_facet) {
    if ($bundle_facet == 'app' || $bundle_facet == 'dataset_request') {
      $menu_output = str_replace('active', '', $menu_output);
    }
    elseif($bundle_facet == 'resource') {
      $menu_output = str_replace('>Library', 'class="active-trail active">Library', $menu_output);
      $menu_output = str_replace('active-trail active">Search content', '">Search content', $menu_output);
    }
    elseif($activated) {
      $menu_output = str_replace('active-trail active">Search content', '">Search content', $menu_output);
    }
  }
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
  unset($js['misc/jquery.js']);
  unset($js['profiles/dgu/modules/contrib/jquery_update/replace/jquery/1.8/jquery.min.js']);
}

function dguk_menu_breadcrumb_alter(&$active_trail, $item){

  $end = end($active_trail);
  foreach ($active_trail as $key => $crumb){
    if (!empty($crumb['link_path']) && $crumb['link_path'] == 'node/%'){
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
      //append an item to the active trail to prevent drupal from removing the last crumb
      $active_trail[] = $end;
    }
    elseif (!empty($crumb['path']) && $crumb['path'] == 'reply/add/%/%/%') {
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
    $title = drupal_get_title();
    $node = menu_get_object();
    if ($node){
      $title = $node->title;
    }
    $a = 0;
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

function dguk_field__field_quality__glossary($variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label']
      . '&nbsp;<a class="lexicon-term" href="http://www.nationalarchives.gov.uk/appsi/open-data-psi-glossary-pilot.htm" target="_blank" title="The APPSI quality score reflects our confidence in the accuracy and quality of a term and its definition. You can learn more about APPSI by clicking on the link.">(What is this?)</a>'
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


function dguk_button($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'value', 'type'));

  // If a button type class isn't present then add in default.
  $button_classes = array(
    'btn-default',
    'btn-primary',
    'btn-success',
    'btn-info',
    'btn-warning',
    'btn-danger',
    'btn-link',
  );
  $class_intersection = array_intersect($button_classes, $element['#attributes']['class']);
  if (empty($class_intersection)) {
    $element['#attributes']['class'][] = 'btn-default';
  }

  // Add in the button type class.
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];

  // This line break adds inherent margin between multiple buttons.
  return '<input' . drupal_attributes($element['#attributes']) .  "/>\n";
}

/**
 * Overrides theme_menu_local_tasks().
 */
function dguk_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] = '<ul class="tabs--primary nav nav-pills">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['secondary']['#prefix'] = '<ul class="tabs--secondary pagination pagination-sm">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}
