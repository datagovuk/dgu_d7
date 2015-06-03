<?php
/**
 * @file
 * dgu_data_set_request.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_data_set_request_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bootstrap_tour" && $api == "bootstrap_tour_tour") {
    return array("version" => "1");
  }
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
    "description" : "Data request assigned",
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
          "value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url}) has assigned you to deal with the data request:\\u003Cbr\\u003E\\u0022[message:field-data-request-reference:title]\\u0022.\\u003C\\/p\\u003E\\u003Cp\\u003EPlease login to review this request at:\\u003Cbr\\u003E[message:field-data-request-reference:url]\\u003Cbr\\u003Eto progress it further.\\u003C\\/p\\u003E\\u003Cp\\u003EYou can see all data requests assigned to you at:\\u003Cbr\\u003E[site:url]admin\\/workbench\\/content\\/active\\u003C\\/p\\u003E\\u003Cp\\u003EYou have been also subscribed to notifications about this data request.\\u003Cbr\\u003EYou can unsubscribe at:\\u003Cbr\\u003E[site:url]user\\/[message:field-data-request-assignee:uid]\\/message-subscribe\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url}) has assigned you to deal with the data request:\\u003Cbr \\/\\u003E\\u0022[message:field-data-request-reference:title]\\u0022.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EPlease login to review this request at:\\u003Cbr \\/\\u003E[message:field-data-request-reference:url]\\u003Cbr \\/\\u003Eto progress it further.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can see all data requests assigned to you at:\\u003Cbr \\/\\u003E[site:url]admin\\/workbench\\/content\\/active\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have been also subscribed to notifications about this data request.\\u003Cbr \\/\\u003EYou can unsubscribe at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:field-data-request-assignee:uid]\\/message-subscribe\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['data_request_review_comment_new'] = entity_import('message_type', '{
    "name" : "data_request_review_comment_new",
    "description" : "Data request new review comment",
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
          "value" : "\\u003Cp\\u003EData request\\u0026nbsp;\\u003Ca href=\\u0022[message:field-data-request-reference:url]\\u0022\\u003E[message:field-data-request-reference:title]\\u003C\\/a\\u003E has been updated with a new note by \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EData request\\u00a0\\u003Ca href=\\u0022[message:field-data-request-reference:url]\\u0022\\u003E[message:field-data-request-reference:title]\\u003C\\/a\\u003E has been updated with a new note by \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EData request \\u0022[message:field-data-request-reference:title]\\u0022 has been updated with a new review note by @{message:user:name}\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EData request \\u0022[message:field-data-request-reference:title]\\u0022 has been updated with a new review note by @{message:user:name}\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EA new review note has been posted by user \\u0026quot;@{message:user:name}\\u0026quot; (@{message:user:url}) on data request:\\u003Cbr \\/\\u003E\\r\\n\\t\\u0026quot;[message:field-data-request-reference:title]\\u0026quot;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can see this request at:\\u003Cbr \\/\\u003E\\r\\n\\t[message:field-data-request-reference:url]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about this data request.\\u003Cbr \\/\\u003E\\r\\n\\tYou can unsubscribe at:\\u003Cbr \\/\\u003E\\r\\n\\t[site:url]user\\/[message:current-subscriber-uid]\\/message-subscribe\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EReview note:\\u003Cbr \\/\\u003E\\r\\n\\t[message:field-reply-reference:field_review_comment]\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EA new review note has been posted by user \\u0022@{message:user:name}\\u0022 (@{message:user:url}) on data request:\\u003Cbr \\/\\u003E\\n\\t\\u0022[message:field-data-request-reference:title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can see this request at:\\u003Cbr \\/\\u003E\\n\\t[message:field-data-request-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about this data request.\\u003Cbr \\/\\u003E\\n\\tYou can unsubscribe at:\\u003Cbr \\/\\u003E\\n\\t[site:url]user\\/[message:current-subscriber-uid]\\/message-subscribe\\u003C\\/p\\u003E\\n\\u003Cp\\u003EReview note:\\u003Cbr \\/\\u003E\\n\\t[message:field-reply-reference:field_review_comment]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['data_request_update'] = entity_import('message_type', '{
    "name" : "data_request_update",
    "description" : "Data request updated",
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
          "value" : "\\u003Cp\\u003EData request \\u0022[message:field-data-request-reference:title]\\u0022 has been updated by @{message:user:name}\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EData request \\u0022[message:field-data-request-reference:title]\\u0022 has been updated by @{message:user:name}\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url}) has updated data request:\\u003Cbr\\u003E\\u0022[message:field-data-request-reference:title]\\u0022.\\u003C\\/p\\u003E\\u003Cp\\u003EYou can see this request at:\\u003Cbr\\u003E[message:field-data-request-reference:url]\\u003C\\/p\\u003E\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about this data request.\\u003Cbr\\u003EYou can unsubscribe at:\\u003Cbr\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/message-subscribe\\u003C\\/p\\u003E\\u003Cp\\u003E@{message:data_request-summary_of_changes}\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url}) has updated data request:\\u003Cbr \\/\\u003E\\u0022[message:field-data-request-reference:title]\\u0022.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can see this request at:\\u003Cbr \\/\\u003E[message:field-data-request-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about this data request.\\u003Cbr \\/\\u003EYou can unsubscribe at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/message-subscribe\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@{message:data_request-summary_of_changes}\\u003C\\/p\\u003E\\n"
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
