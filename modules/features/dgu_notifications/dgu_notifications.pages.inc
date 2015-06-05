<?php

/**
 * @file
 * Page callbacks for the dgu_notifications module.
 */

function dgu_notifications_my_subscriptions($user) {

  $uid = $user->uid;

  $sql = "SELECT d.title as dataset_title, n.title as node_title, d.id, d.name, n.nid, n.type
          FROM {flagging} fl
          LEFT JOIN {node} n ON fl.entity_id = n.nid AND fl.entity_type = 'node'
          LEFT JOIN {ckan_dataset} d ON fl.entity_id = d.id AND fl.entity_type = 'ckan_dataset'
          WHERE fl.uid = :uid
          AND fl.fid = 3 OR fl.fid = 4
          ORDER BY fl.timestamp DESC";

  $query = db_query($sql, array(':uid' => $user->uid));

  $result = $query->fetchAll();


  $header = array('Title', 'Type', 'Actions');
  $rows = array();
  $types = _node_types_build()->names;

  foreach ($result as $row) {

    if (empty($row->dataset_title)) {
      $rows[] = array(
        l($row->node_title, 'node/'. $row->nid),
        $types[$row->type],
        flag_create_link('subscribe_node', $row->nid),
      );
    }
    else {
      $rows[] = array(
        l($row->dataset_title, 'dataset/' . $row->name),
        'Dataset',
        flag_create_link('dataset', $row->id),
      );
    }
  }
  return theme('table', array('header' => $header, 'rows' => $rows));
}

function dgu_notifications_auto_subscribe($form, &$form_state, $account) {

  $content_types = array(
    'ckan_dataset' => 'Dataset',
    'app' => 'App',
    'blog' => 'Blog entry',
    'dataset_request' => 'Data request',
    'forum' => 'Forum topic',
    'resource' => 'Library resource',
  );

  $form = array('account' => array('#type' => 'value', '#account' => $account));

  $form['content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Auto subscribe to new content'),
    '#options' => $content_types,
  );

  if (!empty($account->data['auto_subscribe'])) {
    $form['content_types']['#default_value'] = $account->data['auto_subscribe'];
  }

  if (in_array('admin', $account->data['ckan_publishers'])) {

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
  $account->data['auto_subscribe'] = $form_state['values']['content_types'];
  if (in_array('admin', $account->data['ckan_publishers'])) {
    $account->data['dataset_comments'] = $form_state['values']['dataset_comments'];
  }
  user_save($account);
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