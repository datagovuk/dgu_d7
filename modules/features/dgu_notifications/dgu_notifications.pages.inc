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




  $query->condition('fl.uid', $account->uid)
    ->orderBy('fl.timestamp', 'DESC');
  $query->limit(10);
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

  $form['filter']['type'] = array(
    '#type' => 'select',
    '#title' => 'Type',
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div>',
    '#options' => $types,
    '#default_value' => !empty($query_parameters['type']) ? $query_parameters['type'] : 'all',
  );

  $form['filter']['filter'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
    '#prefix' => '<div class="views-exposed-widget">',
    '#suffix' => '</div>',
    '#attributes' => array('style' => array('background-color: #5bc0de; border-color: #46b8da; color: #fff; padding: 6px 12px;')),
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

  $form['#attached']['js']['
    jQuery( document ).ready(function() {
        jQuery(\'#dgu-notifications-my-subscriptions .form-checkbox\').on(\'click\', function(){
          if ( jQuery(\'#dgu-notifications-my-subscriptions .form-checkbox\').is(\':checked\') ) {
              jQuery("#edit-unsubscribe").removeAttr("disabled");
          }
          else {
              jQuery("#edit-unsubscribe").attr("disabled","disabled");
          }
        });
    });
  '] = array( 'type' => 'inline');

  return $form;
}

function dgu_notifications_my_subscriptions_submit($form, &$form_state) {

  $form_state['redirect'] = array(
    '/user/' . $form['uid']['#value'] . '/subscriptions',
    array('query' => array('type' => $form_state['values']['type'])),
  );

  if ($form_state['clicked_button']['#value'] == 'Unsubscribe') {
    drupal_set_message(print_r($form_state['values']['table'], 1));
    foreach ($form_state['values']['table'] as $flagging_id => $selected) {
      if ($selected) {
        $flagging = flagging_load($flagging_id);
        $account = user_load($flagging->uid);
        flag('unflag', $flagging->flag_name, $flagging->entity_id, $account);
      }
    }
  }
}

function dgu_notifications_auto_subscribe($form, &$form_state, $account) {

  $path = drupal_get_path('module', 'dgu_notifications');

  $content_types = array(
    'ckan_dataset' => 'Dataset',
    'ckan_dataset_update_subscribe' => 'Automatically subscribe to dataset updates',
    'ckan_dataset_comment_subscribe' => 'Automatically subscribe to comments on datasets',
    'app' => 'App',
    'app_subscribe' => 'Automatically subscribe to updates and comments',
    'blog' => 'Blog entry',
    'blog_subscribe' => 'Automatically subscribe to updates and comments',
    'dataset_request' => 'Data request',
    'dataset_request_subscribe' => 'Automatically subscribe to updates and comments',
    'forum' => 'Forum topic',
    'forum_subscribe' => 'Automatically subscribe to updates and comments',
    'resource' => 'Library resource',
    'resource_subscribe' => 'Automatically subscribe to updates',
  );

  $form = array('account' => array('#type' => 'value', '#account' => $account));

  $form['content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Notifications about new content'),
    '#options' => $content_types,
    '#attached' => array (
      'js' => array($path . '/js/dgu_notifications.js'),
      'css' => array($path . '/css/dgu_notifications.css'),
    ),
  );

  $options = db_select('users_auto_subscribe', 'uas')->fields('uas', array('type'))->condition('uid', $account->uid)->execute()->fetchCol();

  $form['content_types']['#default_value'] = $options;

  if (isset($account->data['ckan_publishers']) && in_array('admin', $account->data['ckan_publishers'])) {
    $form['dataset_comments_label'] = array('#markup' => '<strong>Comments on datasets</strong>',);

    $form['dataset_comments'] = array(
      '#type' => 'checkbox',
      '#title' => t('Receive email notifications about comments on all datasets published by publishers I administer'),
    );
    if (!empty($account->data['dataset_comments'])) {
      $form['dataset_comments']['#default_value'] = $account->data['dataset_comments'];
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

function dgu_notifications_auto_subscribe_submit($form, &$form_state) {

  $account = user_load($form['account']['#account']->uid);

  $types = array_filter($form_state['values']['content_types']);
  db_delete('users_auto_subscribe')->condition('uid', $account->uid)->execute();
  $query = db_insert('users_auto_subscribe')->fields(array('uid', 'type'));
  foreach ($types as $type) {
    $query->values(array($account->uid, $type));
  }
  $query->execute();

  if (isset($account->data['ckan_publishers']) && in_array('admin', $account->data['ckan_publishers'])) {
    $account->data['dataset_comments'] = $form_state['values']['dataset_comments'];
    user_save($account);
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