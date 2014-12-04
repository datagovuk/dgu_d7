<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Data requests progress summary'),
  'description' => t('Visualisation of data requests progress.'),
  'category' => 'Miscellaneous',
  'render callback' => 'dgu_data_set_request_progress_render',
  'defaults' => array(
    'title_override' => FALSE,
    'title_override_text' => '',
  ),
);

/**
 * Renders report about data requests progress.
 */
function dgu_data_set_request_progress_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  // TODO include only published requests.

  $query = db_select('field_data_field_review_outcome', 'o');
  $query->join('field_data_field_review_status', 's', 's.entity_id = o.entity_id');
  $query->join('node', 'n', 's.entity_id = n.nid');
  $query->fields('o', array('field_review_outcome_value'))
    ->groupBy('field_review_outcome_value')
    ->condition('n.status', 1)
    ->condition('field_review_status_value', 6)
    ->addExpression('COUNT(o.entity_id)', 'outcome_count');
  $result = $query->execute();

  $outcome_field_info = field_info_field('field_review_outcome');
  $allowed_values = list_allowed_values($outcome_field_info);

  $id = 'data_requests_by_outcome';
  $rows = array();
  foreach($result as $row) {
    $rows[] = array($allowed_values[$row->field_review_outcome_value], $row->outcome_count, $id);
  }

  $chart = array(
    'id' => $id,
    'type' => 'dgu_piechart',
    'title' => 'Requests by outcome',
    'width' => '0.49',
    'rows' => $rows,
  );

  $block->content = d3_draw($chart);


  $query = db_select('field_data_field_review_status', 's');
  $query->join('node', 'n', 's.entity_id = n.nid');
  $query->fields('s', array('field_review_status_value'))
    ->groupBy('field_review_status_value')
    ->condition('field_review_status_value', array(1, 2, 3, 4, 5), 'IN')
    ->addExpression('COUNT(s.entity_id)', 'status_count');
  $result = $query->execute();

  $status_field_info = field_info_field('field_review_status');
  $allowed_values = list_allowed_values($status_field_info);

  $id = 'data_requests_by_status';
  $rows = array();
  foreach($result as $row) {
    $rows[] = array($allowed_values[$row->field_review_status_value], $row->status_count, $id);
  }

  $chart = array(
    'id' => $id,
    'type' => 'dgu_piechart',
    'title' => 'Requests by status',
    'width' => '0.49',
    'rows' => $rows,
  );

  $block->content .= d3_draw($chart);

  return $block;
}

/**
 * Empty form so we can have the default override title.
 */
function dgu_data_set_request_progress_render_edit_form($form, &$form_state) {
  return $form;
}

