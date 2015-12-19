<?php

/**
 * @file
 * Page callbacks for the dgu_notifications module.
 */

function dgu_notifications_my_subscriptions($form, &$form_state, $account) {

  $types = array(
    'all' => '- Any -',
    'ckan_dataset' => 'Dataset',
    'app' => 'App',
    'blog' => 'Blog entry',
    'dataset_request' => 'Data request',
    'forum' => 'Forum topic',
    'resource' => 'Library resource',
  );

  $empty = 'You are not subscribed to any content.';
  $query_parameters = drupal_get_query_parameters();
  $title = !empty($query_parameters['title']) ? check_plain($query_parameters['title']) : '';
  $type = !empty($query_parameters['type']) ? check_plain($query_parameters['type']) : 'all';
  $items_per_page = !empty($query_parameters['items_per_page']) ? (int) $query_parameters['items_per_page'] : 25;

  $query = db_select('flagging', 'fl')->extend('PagerDefault'); //->extend('TableSort');
  $query->join('flag', 'fg', 'fl.fid = fg.fid ');
  $query->leftJoin('node', 'n', 'fl.entity_id = n.nid ');
  $query->leftJoin('ckan_dataset', 'd', 'fl.entity_id = d.id');
  $query->fields('fl', array('flagging_id'));
  $query->fields('fg', array('name', 'title','name'));
  $query->addField('fg', 'name', 'flag_name');
  $query->fields('d', array('id', 'title','name'));
  $query->addField('d', 'title', 'dataset_title');
  $query->addField('d', 'name', 'dataset_path');
  $query->fields('n', array('nid', 'title','type'));
  $query->addField('n', 'title', 'node_title');


  if (!empty($query_parameters['type']) && $query_parameters['type'] != 'all') {
    if ($query_parameters['type'] == 'ckan_dataset') {
      $query->condition('fg.name', array('subscribe_dataset_comment', 'subscribe_dataset_update'), 'IN');
      $empty = 'You are not subscribed to any datasets.';
    }
    else {
      $query->condition('fg.name', array('subscribe_node'), 'IN')
        ->condition('n.type', check_plain($query_parameters['type']));
      $empty = 'You are not subscribed to any ' . $types[$query_parameters['type']] . '.';
    }

  }
  else {
    $query->condition('fg.name', array('subscribe_node', 'subscribe_dataset_comment', 'subscribe_dataset_update'), 'IN');
  }

  if (!empty($title)) {
    $or = db_or();
    $or->condition('n.title', '%' . $title . '%', 'LIKE');
    $or->condition('d.title', '%' . $title . '%', 'LIKE');
    $query->condition($or);
  }

  $query->condition('fl.uid', $account->uid)
    ->orderBy('fl.timestamp', 'DESC');
  $query->limit($items_per_page);
  $result = $query->execute()->fetchAll();

  $header = array(
    array('data' => 'Title'),
    array('data' => 'Type'),
  );

  if(dgu_user_accessing_own_account()) {
    $header[] = array('data' => 'Actions', 'class' => 'actions');
  }
  $rows = array();

  foreach ($result as $row) {

    if ($row->flag_name == 'subscribe_node') {
      $cells = array(
        l($row->node_title, 'node/'. $row->nid),
        $types[$row->type],
      );

      if(dgu_user_accessing_own_account()) {
        $cells[] = array('data' => flag_create_link('subscribe_node', $row->nid), 'class' => 'views-field');
      }
      $rows[$row->flagging_id] = $cells;
    }
    else {
      $cells = array(
        l($row->dataset_title, 'dataset/' . $row->dataset_path),
        'Dataset',
      );

      if(dgu_user_accessing_own_account()) {
        $cells[] = array('data' => flag_create_link($row->flag_name, $row->id), 'class' => 'views-field');
      }
      $rows[$row->flagging_id] = $cells;
    }
  }

  $form = array();
  $form['uid'] = array('#type' => 'value', '#value' => $account->uid);

  $form['filter'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array(
        'views-exposed-form',
      ),
    ),
  );

  $form['filter']['unsubscribe'] = array(
    '#type' => 'submit',
    '#value' => t('Unsubscribe'),
    '#prefix' => '<div class="views-exposed-widget" style="padding-bottom: 20px;">',
    '#suffix' => '</div>',
    '#attributes' => array(
      'style' => array('background-color: #5bc0de; border-color: #46b8da; color: #fff; padding: 6px 12px;'),
      'disabled' => array('disabled'),
    ),

  );

  $form['filter']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#size' => 30,
    '#maxlength' => 128,
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div>',
    '#default_value' => $title,
  );

  $form['filter']['type'] = array(
    '#type' => 'select',
    '#title' => 'Type',
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div>',
    '#options' => $types,
    '#default_value' => $type,
  );

  $form['filter']['items_per_page'] = array(
    '#type' => 'select',
    '#title' => 'Items per page',
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div>',
    '#options' => drupal_map_assoc(array(10, 25, 50, 100, 200)),
    '#default_value' => $items_per_page,
  );

  $form['filter']['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div>',
  );

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $rows,
    '#empty' => $empty,
    '#attributes' => array('class' => array('view')),
    '#prefix' => '<p></p>',
  );

  $form['pager'] = array('#markup' => theme('pager'));

  $form['#attached']['js'] = array(
    drupal_get_path('module', 'dgu_notifications') . '/js/dgu_notifications.js',
  );

  return $form;
}

function dgu_notifications_my_subscriptions_submit($form, &$form_state) {

  $query = array();

  if (!empty($form_state['values']['type'])) {
    $query['type'] = $form_state['values']['type'];
  }
  if (!empty($form_state['values']['title'])) {
    $query['title'] = $form_state['values']['title'];
  }
  if (!empty($form_state['values']['items_per_page'])) {
    $query['items_per_page'] = $form_state['values']['items_per_page'];
  }

  $form_state['redirect'] = array(
    '/user/' . $form['uid']['#value'] . '/subscriptions',
    array('query' => $query),
  );

  if ($form_state['clicked_button']['#value'] == 'Unsubscribe') {
    foreach ($form_state['values']['table'] as $flagging_id => $selected) {
      if ($selected) {
        $flagging = flagging_load($flagging_id);
        $account = user_load($flagging->uid);
        flag('unflag', $flagging->flag_name, $flagging->entity_id, $account);
      }
    }
  }
}

function dgu_notifications_publisher_subscribe($form, &$form_state, $account) {

  $form = array('account' => array('#type' => 'value', '#account' => $account));

  $form_tmp = array();
  field_attach_form('user', $account, $form_tmp, $form_state, NULL, array(
    'field_name' => 'field_publisher_subscribe'
  ));

  $form['field_publisher_subscribe'] = $form_tmp['field_publisher_subscribe'];

  unset($form['field_publisher_subscribe'][LANGUAGE_NONE]['#title']);

  $form['submit'] = array(
    '#type' => 'submit',
    '#weight' => 200,
    '#value' => t('Save'),
  );

  return $form;
}

function dgu_notifications_publisher_subscribe_submit($form, &$form_state) {
  $account = user_load($form['account']['#account']->uid);
  if (!empty($form_state['values']['field_publisher_subscribe'][LANGUAGE_NONE])) {
    $account->field_publisher_subscribe = $form_state['values']['field_publisher_subscribe'];
    user_save($account);
  }

  if (empty($account->field_digest_notifier[LANGUAGE_NONE][0]['value'])
    || (isset($account->field_digest_notifier[LANGUAGE_NONE][0]['value']) && $account->field_digest_notifier[LANGUAGE_NONE][0]['value'] == 'email')) {
    $form_state['redirect'] = '/about';
  }
}

function dgu_notifications_delivery($form, &$form_state, $account) {

  $field = field_info_field('field_digest_notifier');
  $allowed_values = list_allowed_values($field);

  $form = array('account' => array('#type' => 'value', '#account' => $account));

  $form['digest_notifier'] = array(
    '#type' => 'radios',
    '#title' => t('How often would you like to receive email notifications?'),
    '#options' => $allowed_values,
  );

  if (!empty($account->field_digest_notifier)) {
    $form['digest_notifier']['#default_value'] = $account->field_digest_notifier[LANGUAGE_NONE][0]['value'];
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

function dgu_notifications_delivery_submit($form, &$form_state) {
  $wrapper = entity_metadata_wrapper('user', $form['account']['#account']);
  $wrapper->field_digest_notifier->set($form_state['values']['digest_notifier']);
  $wrapper->save();
}


function dgu_notifications_delivery_confirm($form, &$form_state, $account) {

  $field = field_info_field('field_digest_notifier');
  $allowed_values = list_allowed_values($field);
  unset($allowed_values['email']);

  $form = array('account' => array('#type' => 'value', '#account' => $account));

  $form['message'] = array(
    '#markup' => '<p>Message here</p>',
  );

  $form['email'] = array(
    '#type' => 'submit',
    '#value' => t('Keep immediate delivery'),
    '#name' => 'email',
  );

  foreach ($allowed_values as $key => $notifier) {
    $form[$key] = array(
      '#type' => 'submit',
      '#value' => t('Change to ' . strtolower($notifier) . ' digest'),
      '#name' => $key,
    ) ;
  }

  return $form;
}

function dgu_notifications_delivery_confirm_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#name'] != 'email') {
    $wrapper = entity_metadata_wrapper('user', $form['account']['#account']);
    $wrapper->field_digest_notifier->set($form_state['triggering_element']['#name']);
    $wrapper->save();
  }
}