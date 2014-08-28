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
          "value" : "New comment on \\u003Cnode title here\\u003E\\r\\n",
          "format" : "plain_text"
        },
        {
          "value" : "\\u003Cnode author here\\u003E commented on \\u003Cnode title here\\u003E\\r\\n\\r\\n\\u003Creply body field here\\u003E\\r\\n\\r\\nRead and respond:\\r\\n\\u003Creply url here\\u003E\\r\\n\\r\\nUpdate your notification settings:\\r\\n[site:url]\\/user\\/[message:user:uid]\\/notification-settings",
          "format" : "plain_text"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
