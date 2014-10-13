<?php
/**
 * @file
 * dgu_moderation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_moderation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bootstrap_tour" && $api == "bootstrap_tour_tour") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function dgu_moderation_default_message_type() {
  $items = array();
  $items['dgu_moderation_state_change'] = entity_import('message_type', '{
    "name" : "dgu_moderation_state_change",
    "description" : "Moderation state changed",
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
          "value" : "\\u003Cp\\u003EContent \\u0026quot;\\u003Ca href=\\u0022[message:field-node-reference:url]\\u0022\\u003E[message:field-node-reference:title]\\u003C\\/a\\u003E\\u0026quot; has been\\u0026nbsp;@{message:dgu_moderation_state_change_short}\\u0026nbsp;by \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EContent \\u0022\\u003Ca href=\\u0022url]\\u0022 rel=\\u0022nofollow\\u0022\\u003E[message:field-node-reference:title]\\u003C\\/a\\u003E\\u0022 has been\\u00a0@{message:dgu_moderation_state_change_short}\\u00a0by \\u003Ca href=\\u0022url]\\u0022 rel=\\u0022nofollow\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EContent\\u0026nbsp;submitted by you for moderation has been @{message:dgu_moderation_state_change_short}\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EContent\\u00a0submitted by you for moderation has been @{message:dgu_moderation_state_change_short}\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:dgu_moderation_state_change_full}\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can choose how often you receive email notifications in your account settings:\\u003Cbr \\/\\u003E\\r\\n\\t[site:url]user\\/[message:current-subscriber-uid]\\/edit\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E@{message:dgu_moderation_state_change_full}\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can choose how often you receive email notifications in your account settings:\\u003Cbr \\/\\u003E\\n\\t[site:url]user\\/[message:current-subscriber-uid]\\/edit\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
