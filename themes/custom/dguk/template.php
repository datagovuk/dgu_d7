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
}

/**
 *  Implements hook_preprocess_node().
 */
function dguk_preprocess_node(&$variables) {
  $variables['classes_array'][] = 'boxed';
  $full_node = node_load($variables['node']->nid);
  $variables['title'] = $full_node->title;
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
 * Get the output for the main menu.
 */
function dguk_get_main_menu($main_menu) {
  $menu_new_classes = array();
  foreach ($main_menu as $key => $item) {
    $menu_new_classes['nav-' . strtolower(str_replace(' ', '-', $item['title'])) . ' ' . $key] = $item;
  }

	$menu_output = theme('links__main_menu', array(
	    'links' => $menu_new_classes,
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
 * Get the output for the sub menu (2nd level of main menu).
 */
function dguk_get_sub_menu() {
	$menu = menu_navigation_links('main-menu', 1);

	return theme('links__sub_menu', array(
	    'links' => $menu,
	    'attributes' => array(
	        'id' => 'subnav',
	    ),
	 ));
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
 * Returns HTML for sub mnavigation links.
 */
function dguk_links__sub_menu($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $output = '';

  if (count($links) > 0) {
    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
          && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";

      if ($i <= $num_links) {
        $output .= "<span class=\"divider\">&nbsp;|&nbsp;</span>\n";
      }
    }

    $output .= '</ul>';
  }

  return $output;
}

function dguk_js_alter(&$js){
 /**
  * Remove jquery and bootstrap.
  * @see dguk/templates/html.tpl.php
  */
  unset($js['misc/jquery.js']);
  unset($js['profiles/dgu/themes/contrib/bootstrap/bootstrap/js/bootstrap.js']);
}
