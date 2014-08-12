<?php
/**
 * @file
 * dgu_data_set_request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_data_set_request_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dgu_data_set_request_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function dgu_data_set_request_default_message_type() {
  $items = array();
  $items['data_request_assignee'] = entity_import('message_type', '{
    "name" : "data_request_assignee",
    "description" : "Data request has been assigned to you",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003EData request \\u0022\\u003Ca href=\\u0022[message:field-data-request-reference:url]\\u0022\\u003E[message:field-data-request-reference:title]\\u003C\\/a\\u003E\\u0022 has been assigned to you by \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EData request \\u0022\\u003Ca href=\\u0022[message:field-data-request-reference:url]\\u0022\\u003E[message:field-data-request-reference:title]\\u003C\\/a\\u003E\\u0022 has been assigned to you by \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EData request \\u0022[message:field-data-request-reference:title]\\u0022 has been assigned to you\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EData request \\u0022[message:field-data-request-reference:title]\\u0022 has been assigned to you\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser \\u0022[message:user:name]\\u0022 ([message:user:url])\\u003Cbr\\u003Ehas assigned you to deal with the data request:\\u003Cbr\\u003E\\u0022[message:field-data-request-reference:title]\\u0022.\\u003C\\/p\\u003E\\u003Cp\\u003EPlease login to review this request at:\\u003Cbr\\u003E[message:field-data-request-reference:url]\\u003Cbr\\u003Eto progress it further.\\u003C\\/p\\u003E\\u003Cp\\u003EYou have been also subscribed to notifications about this data request.\\u003Cbr\\u003EYou can unsubscribe at:\\u003Cbr\\u003E[site:url]user\\/[message:field-data-request-assignee:uid]\\/message-subscribe\\u003C\\/p\\u003E\\u003Cp\\u003EYou can see all data requests\\u0026nbsp;assigned to you at:\\u003Cbr\\u003E[site:url]admin\\/workbench\\/content\\/active\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u0022[message:user:name]\\u0022 ([message:user:url])\\u003Cbr \\/\\u003Ehas assigned you to deal with the data request:\\u003Cbr \\/\\u003E\\u0022[message:field-data-request-reference:title]\\u0022.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EPlease login to review this request at:\\u003Cbr \\/\\u003E[message:field-data-request-reference:url]\\u003Cbr \\/\\u003Eto progress it further.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have been also subscribed to notifications about this data request.\\u003Cbr \\/\\u003EYou can unsubscribe at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:field-data-request-assignee:uid]\\/message-subscribe\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can see all data requests\\u00a0assigned to you at:\\u003Cbr \\/\\u003E[site:url]admin\\/workbench\\/content\\/active\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['data_request_update'] = entity_import('message_type', '{
    "name" : "data_request_update",
    "description" : "Data request has been updated",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "",
    "arguments" : null,
    "message_text" : { "und" : [
        {
          "value" : "\\u003Cp\\u003EData request \\u0022\\u003Ca href=\\u0022[message:field-data-request-reference:url]\\u0022\\u003E[message:field-data-request-reference:title]\\u003C\\/a\\u003E\\u0022 has been updated by \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EData request \\u0022\\u003Ca href=\\u0022[message:field-data-request-reference:url]\\u0022\\u003E[message:field-data-request-reference:title]\\u003C\\/a\\u003E\\u0022 has been updated by \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url})\\u0026nbsp;has updated data request:\\u003Cbr\\u003E\\u0022[message:field-data-request-reference:title]\\u0022.\\u003C\\/p\\u003E\\u003Cp\\u003EYou can see this request at:\\u003Cbr\\u003E[message:field-data-request-reference:url]\\u003C\\/p\\u003E\\u003Cp\\u003EYou have received this message because you\\u0026nbsp;are subscribed to notifications about this data request.\\u003C\\/p\\u003E\\u003Cp\\u003EYou can unsubscribe at:\\u003Cbr\\u003E[site:url]user\\/[message:user:uid]\\/message-subscribe\\u003C\\/p\\u003E\\u003Cp\\u003ESummary of changes:\\u003C\\/p\\u003E\\u003Cp\\u003E[message:data_request-summary_of_changes]\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url})\\u00a0has updated data request:\\u003Cbr \\/\\u003E\\u0022[message:field-data-request-reference:title]\\u0022.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can see this request at:\\u003Cbr \\/\\u003E[message:field-data-request-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have received this message because you\\u00a0are subscribed to notifications about this data request.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can unsubscribe at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:user:uid]\\/message-subscribe\\u003C\\/p\\u003E\\n\\u003Cp\\u003ESummary of changes:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:data_request-summary_of_changes]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function dgu_data_set_request_node_info() {
  $items = array(
    'dataset_request' => array(
      'name' => t('Dataset Request'),
      'base' => 'node_content',
      'description' => t('You can create a data request for any data that you believe should be released as open Data but you have had difficulty obtaining.  You will be asked questions about how you plan to use the data and what benefits you can see to releasing this data.  You may choose to keep your data request confidential.  Before creating a new data request please look through any published data requests to make sure that someone else has not already started this process.'),
      'has_title' => '1',
      'title_label' => t('Data request title'),
      'help' => '',
    ),
  );
  return $items;
}
