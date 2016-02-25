<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Data requests by status'),
  'description' => t('Visualisation of data request by status field.'),
  'category' => 'Miscellaneous',
  'render callback' => 'dgu_data_set_request_status_render',
  'defaults' => array(
    'title_override' => FALSE,
    'title_override_text' => '',
  ),
);

/**
 * Renders report about data requests outcome.
 */
function dgu_data_set_request_status_render($subtype, $conf, $panel_args, $context) {

  $query = db_select('field_data_field_review_status', 's');
  $query->join('node', 'n', 's.entity_id = n.nid');
  $query->fields('s', array('field_review_status_value'))
    ->groupBy('field_review_status_value')
    ->condition('n.status', NODE_PUBLISHED)
    ->condition('field_review_status_value', array(1, 2, 3, 4, 5), 'IN')
    ->addExpression('COUNT(s.entity_id)', 'status_count');
  $result = $query->execute();

  $status_field_info = field_info_field('field_review_status');
  $allowed_values = list_allowed_values($status_field_info);

  $rows = array();
  foreach($result as $row) {
    $rows[] = array($allowed_values[$row->field_review_status_value], $row->status_count);
  }

  $chart = array(
    'id' => 'data_requests_by_status',
    'type' => 'piechart',
    'rows' => $rows,
  );

  $block = new stdClass();
  $block->content = d3_draw($chart);

  return $block;
}

/**
 * Empty form so we can have the default override title.
 */
function dgu_data_set_request_status_render_edit_form($form, &$form_state) {
  return $form;
}


