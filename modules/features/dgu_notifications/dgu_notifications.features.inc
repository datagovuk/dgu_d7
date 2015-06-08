<?php
/**
 * @file
 * dgu_notifications.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dgu_notifications_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function dgu_notifications_default_message_type() {
  $items = array();
  $items['dgu_notifications_node_update'] = entity_import('message_type', '{
    "name" : "dgu_notifications_node_update",
    "description" : "Node updated",
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
          "value" : "\\u003Cp\\u003E@{message:field-node-reference:content-type} \\u0022\\u003Ca href=\\u0022[message:field-node-reference::url]\\u0022\\u003E[message:field-node-reference::title]\\u003C\\/a\\u003E\\u0022 has been updated by \\u003Ca href=\\u0022message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E@{message:field-node-reference:content-type} \\u0022\\u003Ca href=\\u0022[message:field-node-reference::url]\\u0022\\u003E[message:field-node-reference::title]\\u003C\\/a\\u003E\\u0022 has been updated by \\u003Ca href=\\u0022message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003E@{message:field-node-reference:content-type} \\u0022[message:field-node-reference:title]\\u0022 has been updated by @{message:user:name}\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E@{message:field-node-reference:content-type} \\u0022[message:field-node-reference:title]\\u0022 has been updated by @{message:user:name}\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url}) has updated @{message:field-node-reference:content-type}:\\u003Cbr\\u003E\\u0022[message:field-node-reference:title]\\u0022.\\u003C\\/p\\u003E\\u003Cp\\u003EYou can see this @{message:field-node-reference:content-type} at:\\u003Cbr\\u003E[message:field-node-reference:url]\\u003C\\/p\\u003E\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about this content.\\u003Cbr\\u003EYou can unsubscribe at:\\u003Cbr\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E\\u003Cp\\u003E@{message:data_request-summary_of_changes}\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url}) has updated @{message:field-node-reference:content-type}:\\u003Cbr \\/\\u003E\\u0022[message:field-node-reference:title]\\u0022.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can see this @{message:field-node-reference:content-type} at:\\u003Cbr \\/\\u003E[message:field-node-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about this content.\\u003Cbr \\/\\u003EYou can unsubscribe at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E\\n\\u003Cp\\u003E@{message:data_request-summary_of_changes}\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['dgu_notifications_reply_new'] = entity_import('message_type', '{
    "name" : "dgu_notifications_reply_new",
    "description" : "Reply created",
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
          "value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E commented on\\u0026nbsp;[message:field-node-reference:content-type] \\u0022\\u003Ca href=\\u0022[message:field-node-reference:url]\\u0022\\u003E[message:field-node-reference:title]\\u003C\\/a\\u003E\\u0022\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u003Ca href=\\u0022[message:user:url]\\u0022\\u003E@{message:user:name}\\u003C\\/a\\u003E commented on\\u00a0[message:field-node-reference:content-type] \\u0022\\u003Ca href=\\u0022[message:field-node-reference:url]\\u0022\\u003E[message:field-node-reference:title]\\u003C\\/a\\u003E\\u0022\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser @{message:user:name} posted a comment on [message:field-node-reference:content-type] \\u0022[message:field-node-reference:title]\\u0022\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser @{message:user:name} posted a comment on [message:field-node-reference:content-type] \\u0022[message:field-node-reference:title]\\u0022\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EUser \\u0026quot;@{message:user:name}\\u0026quot; (@{message:user:url})\\u003Cbr \\/\\u003E\\r\\n\\t\\u0026quot;[message:field-node-reference:title]\\u0026quot;\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou can see this comment at:\\u003Cbr \\/\\u003E\\r\\n\\t[message:field-node-reference:url]#reply-[message:field-reply-reference:entity-id]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about this [message:field-node-reference:content-type].\\u003Cbr \\/\\u003E\\r\\n\\tYou can unsubscribe at:\\u003Cbr \\/\\u003E\\r\\n\\t[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EComment:\\u003Cbr \\/\\u003E\\r\\n\\t[message:field-reply-reference:field_reply_comment]\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EUser \\u0022@{message:user:name}\\u0022 (@{message:user:url})\\u003Cbr \\/\\u003E\\n\\t\\u0022[message:field-node-reference:title]\\u0022\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can see this comment at:\\u003Cbr \\/\\u003E\\n\\t[message:field-node-reference:url]#reply-[message:field-reply-reference:entity-id]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about this [message:field-node-reference:content-type].\\u003Cbr \\/\\u003E\\n\\tYou can unsubscribe at:\\u003Cbr \\/\\u003E\\n\\t[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E\\n\\u003Cp\\u003EComment:\\u003Cbr \\/\\u003E\\n\\t[message:field-reply-reference:field_reply_comment]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
