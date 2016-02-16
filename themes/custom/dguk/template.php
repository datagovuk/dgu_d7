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

  $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['node']->type . '__' . $variables['view_mode'];

  if ($variables['node']->type == 'resource' || $variables['node']->type == 'book'){
    $variables['submitted'] = 'Submitted on ' . format_date($variables['created']);
  }

  $variables['updated'] = $variables['created'] != $variables['changed'] ? '| Updated on ' . format_date($variables['changed']) : FALSE;

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
  global $user;
  if($user->uid && $user->uid == $variables['reply']->uid) {
    $variables['classes_array'][] = 'own-reply';
  }

  $variables['classes_array'][] = 'boxed';
  $variables['classes_array'][] = 'parent-' . $variables['reply']->parent;


  // Add $avatar variable with rendered user picture linked to user profile;
  $fields = field_info_instances('user', 'user');
  $field_id = $fields['field_avatar']['field_id'];


  $account = new stdClass();
  $account->uid = $variables['reply']->uid;
  field_attach_load('user', array($account->uid => $account), FIELD_LOAD_CURRENT, array('field_id' => $field_id));

  if (!empty($account->field_avatar)) {
    $field = field_get_items('user', $account, 'field_avatar');
    $image = field_view_value('user', $account, 'field_avatar', $field[0], array('settings' => array('image_style' => 'avatar')));
  }
  else {
    $image_info = dguk_default_field_image('field_avatar');
    $image = field_view_value('user', $account, 'field_avatar', (array) $image_info, array('settings' => array('image_style' => 'avatar')));
  }

  $colour = $variables['reply']->uid % 10;
  if ($variables['reply']->uid) {
    $variables['avatar'] = l(render($image), 'user/' . $variables['reply']->uid, array('html' => true, 'attributes' => array('class' => array('field-avatar','bg-colour-' . $colour))));
  }
  else {
    $variables['avatar'] = '<div class="field-avatar bg-colour-0">' . render($image) . '</div>';
  }

  $variables['theme_hook_suggestions'][] = 'reply__' . $variables['bundle'];


}



/**
 * Implements hook_preprocess_replies().
 */
function dguk_preprocess_replies(&$variables) {
  $options = array('attributes' => array('class' => array('btn-default', 'btn', 'btn-primary')));

  if ($variables['bundle'] == 'comment') {
    if (($variables['access'] == REPLY_ACCESS_FULL && user_access('administer replies')) ||  user_access('administer replies') || user_access('post '. $variables['bundle'] .' reply')) {
      $variables['links']['add_reply']['#markup'] = l(t('Add new comment'), 'reply/add/'. $variables['entity_id'] .'/'. $variables['instance_id'] .'/0', $options);
    }
    else {
      $options['query'] = array('destination' => 'reply/add/'. $variables['entity_id'] .'/'. $variables['instance_id'] .'/0');
      $variables['links']['reply_post_forbidden']['#markup'] = l(t('Login to make a comment'), 'user/login', $options);
    }
  }
}


/**
 *  Implements hook_preprocess_search_result().
 */
function dguk_preprocess_search_result(&$variables) {
  $variables['classes_array'][] = 'boxed';
  $variables['classes_array'][] = 'node-type-' . $variables['result']['bundle'];
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
      'href' => 'data-request',
    ),
    'menu-publishers' => array(
      'title' => 'Publishers',
      'href' => 'publisher',
    ),
     'menu-data-api' => array(
     'title' => 'Data API',
      'href' => 'data/api',
     ),
    'menu-organogram' => array(
      'title' => 'Organograms',
      'href' => 'organogram/cabinet-office',
    ),
    'menu-site-usage' => array(
      'title' => 'Site Analytics',
      'href' => 'data/site-usage',
    ),
    'menu-reports' => array(
      'title' => 'Reports',
      'href' => 'data/report',
    ),
    'menu-contracts' => array(
      'title' => 'Contracts',
      'href' => 'data/contracts-finder-archive',
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
    if (!empty($query['f'])) {
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
    if(!empty($menu_item['attributes']['class']) && (in_array('active', $menu_item['attributes']['class']) || in_array('active-trail', $menu_item['attributes']['class']))) {
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
      . '&nbsp;<a class="lexicon-term" href="http://www.nationalarchives.gov.uk/appsi/open-data-psi-glossary.htm" target="_blank" title="The APPSI quality score reflects our confidence in the accuracy and quality of a term and its definition. You can learn more about APPSI by clicking on the link.">(What is this?)</a>'
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
    $variables['primary']['#prefix'] = '<div id="menu-tabs"><h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="tabs--primary nav">';
    $variables['primary']['#suffix'] = '</ul></div>';
    $output .= drupal_render($variables['primary']);
  }

  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="tabs--secondary pagination pagination-sm">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

function dguk_facetapi_title($variables) {
  return drupal_strtolower($variables['title']);
}

/**
 * Overrides theme_panels_default_style_render_region().
 *
 * To add numbered classes to panel separators to be able to target particular separator in CSS.
 */
function dguk_panels_default_style_render_region($vars) {
  $output = '';
  $counter = 0;
  $total = count($vars['panes']);
  foreach ($vars['panes'] as $pane) {
    $output .= $pane;
    if ($counter < $total -1) {
      $output .= '<div class="panel-separator panel-separator-' . $counter++ . '"></div>';
    }
  }
  return $output;
}

/**
 * Overrides theme_facetapi_link_active().
 *
 * To get rid of '(-)'.
 */
function dguk_facetapi_link_active($variables) {
  $accessible_markup = theme('facetapi_accessible_markup', array('text' => $variables['text'], 'active' => TRUE));
  $variables['text'] = '<span class="facet-name">' . $variables['text'] . '</span>' . $accessible_markup . '<div class="facet-kill pull-right"><i class="icon-large icon-remove-sign"></i></div>';
  $variables['options']['html'] = TRUE;
  return '<span class="facet-selected">' . theme_link($variables) . '</span>';
}

/**
 * Overrides theme_pager().
 */
function dguk_pager($variables) {

  // Don't allow pagers longer than 3 pages.
  if ($variables['quantity'] > 3) {
    $variables['quantity'] = 3;
  }

  $output = "";
  $items = array();
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];

  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // Current is the page we are currently paged to.
  $pager_current = $pager_page_array[$element] + 1;
  // First is the first page listed by this pager piece (re quantity).
  $pager_first = $pager_current - $pager_middle + 1;
  // Last is the last page listed by this pager piece (re quantity).
  $pager_last = $pager_current + $quantity - $pager_middle;
  // Max is the maximum page number.
  $pager_max = $pager_total[$element];

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_previous = theme('pager_previous', array(
    'text' => (isset($tags[1]) ? $tags[1] : '«'),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));
  $li_next = theme('pager_next', array(
    'text' => (isset($tags[3]) ? $tags[3] : '»'),
    'element' => $element,
    'interval' => 1,
    'parameters' => $parameters,
  ));

  if ($pager_total[$element] > 1) {

    if ($li_previous) {
      $items[] = array(
        'class' => array('prev'),
        'data' => $li_previous,
      );
    }
    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis', 'disabled'),
          'data' => '<span>…</span>',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            // 'class' => array('pager-item'),
            'data' => theme('pager_previous', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($pager_current - $i),
              'parameters' => $parameters,
            )),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            // Add the active class.
            'class' => array('active'),
            'data' => l($i, '#', array('fragment' => '', 'external' => TRUE)),
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'data' => theme('pager_next', array(
              'text' => $i,
              'element' => $element,
              'interval' => ($i - $pager_current),
              'parameters' => $parameters,
            )),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis', 'disabled'),
          'data' => '<span>…</span>',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('next'),
        'data' => $li_next,
      );
    }

    return '<div class="text-center">' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pagination')),
    )) . '</div>';
  }
  return $output;
}

/**
 * Implements hook_preprocess_region().
 */
function dguk_preprocess_region(&$variables) {
  // Get rid of the icon and 'boxed' class in help block.
  if ($variables['region'] == 'help') {
    $variables['content'] = str_replace('boxed', '', $variables['elements']['#children']);
  }
}

