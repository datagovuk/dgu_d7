<?php
/**
 * @file
 * dgu_data_set.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_data_set_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function dgu_data_set_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function dgu_data_set_default_message_type() {
  $items = array();
  $items['dataset_comment_new'] = entity_import('message_type', '{
    "name" : "dataset_comment_new",
    "description" : "Dataset new reply",
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
          "value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E commented on dataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E commented on dataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser @{message:user:name} commented on dataset \\u0022[message:field-dataset-reference:title]\\u0022\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser @{message:user:name} commented on dataset \\u0022[message:field-dataset-reference:title]\\u0022\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser \\u0026quot;@{message:user:name}\\u0026quot; (@{message:user:url}) commented on dataset:\\u003Cbr \\/\\u003E\\r\\n\\t\\u0026quot;[message:field-dataset-reference:title]\\u0026quot;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EDataset URL: [message:field-dataset-reference:url]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EComment:[message:field-reply-reference:field-reply-comment:value]\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url}) commented on dataset:\\u003Cbr \\/\\u003E\\n\\t\\u0022[message:field-dataset-reference:title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003EDataset URL: [message:field-dataset-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EComment:[message:field-reply-reference:field-reply-comment:value]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
