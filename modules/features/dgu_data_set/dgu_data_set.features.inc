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
    "description" : "Dataset reply created",
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
          "value" : "\\u003Cp\\u003EUser @{message:user:name} posted a comment on dataset \\u0022[message:field-dataset-reference:title]\\u0022\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EUser @{message:user:name} posted a comment on dataset \\u0022[message:field-dataset-reference:title]\\u0022\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDataset URL: [message:field-dataset-reference:url]\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Cp\\u003EComment:\\u003Cbr \\/\\u003E\\r\\n\\t[message:field-reply-reference:field-reply-comment:value]\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EDataset URL: [message:field-dataset-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EComment:\\u003Cbr \\/\\u003E\\n\\t[message:field-reply-reference:field-reply-comment:value]\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['dataset_new'] = entity_import('message_type', '{
    "name" : "dataset_new",
    "description" : "Dataset created",
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
          "value" : "\\u003Cp\\u003EDataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E has been created\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E has been created\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDataset \\u0022[message:field-dataset-reference:title]\\u0022 has been created\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDataset \\u0022[message:field-dataset-reference:title]\\u0022 has been created\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EYou can see this dataset at:\\u003Cbr\\u003E[message:field-dataset-reference:url]\\u003C\\/p\\u003E\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about new datasets.\\u003Cbr\\u003EYou can change your auto subscription preferences at:\\u003Cbr\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\/auto-subscribe\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EYou can see this dataset at:\\u003Cbr \\/\\u003E[message:field-dataset-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about new datasets.\\u003Cbr \\/\\u003EYou can change your auto subscription preferences at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\/auto-subscribe\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['dataset_new_subscribe_comment'] = entity_import('message_type', '{
    "name" : "dataset_new_subscribe_comment",
    "description" : "Dataset created and subscribed to comments",
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
          "value" : "\\u003Cp\\u003EDataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E has been created\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E has been created\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EYou have been subscribed to comments on new dataset \\u0022[message:field-dataset-reference:title]\\u0022\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EYou have been subscribed to comments on new dataset \\u0022[message:field-dataset-reference:title]\\u0022\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EYou can see this dataset at:\\u003Cbr\\u003E[message:field-dataset-reference:url]\\u003C\\/p\\u003E\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about dataset comments.\\u003C\\/p\\u003E\\u003Cp\\u003EYou can change your auto subscription preferences at:\\u003Cbr\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\/auto-subscribe\\u003C\\/p\\u003E\\u003Cp\\u003EYou can also keep your subscription preferences but unsubscribe from notifications about comments on this dataset at:\\u003Cbr\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EYou can see this dataset at:\\u003Cbr \\/\\u003E[message:field-dataset-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about dataset comments.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can change your auto subscription preferences at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\/auto-subscribe\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can also keep your subscription preferences but unsubscribe from notifications about comments on this dataset at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['dataset_new_subscribe_update'] = entity_import('message_type', '{
    "name" : "dataset_new_subscribe_update",
    "description" : "Dataset created and subscribed to updates",
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
          "value" : "\\u003Cp\\u003EDataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E has been created\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E has been created\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDataset \\u0022[message:field-dataset-reference:title]\\u0022 has been created\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDataset \\u0022[message:field-dataset-reference:title]\\u0022 has been created\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EYou can see this dataset at:\\u003Cbr\\u003E[message:field-dataset-reference:url]\\u003C\\/p\\u003E\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about new datasets.\\u003C\\/p\\u003E\\u003Cp\\u003EYou can change your auto subscription preferences at:\\u003Cbr\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\/auto-subscribe\\u003C\\/p\\u003E\\u003Cp\\u003EYou can also keep your subscription preferences but unsubscribe from further notifications about this dataset updates at:\\u003Cbr\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EYou can see this dataset at:\\u003Cbr \\/\\u003E[message:field-dataset-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about new datasets.\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can change your auto subscription preferences at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\/auto-subscribe\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou can also keep your subscription preferences but unsubscribe from further notifications about this dataset updates at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['dataset_update'] = entity_import('message_type', '{
    "name" : "dataset_update",
    "description" : "Dataset updated",
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
          "value" : "\\u003Cp\\u003EDataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E has been updated\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDataset \\u003Ca href=\\u0022[message:field-dataset-reference:url]\\u0022\\u003E[message:field-dataset-reference:title]\\u003C\\/a\\u003E has been updated\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EDataset \\u0022[message:field-dataset-reference:title]\\u0022 has been updated\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EDataset \\u0022[message:field-dataset-reference:title]\\u0022 has been updated\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "\\u003Cp\\u003EYou can see this dataset at:\\u003Cbr\\u003E[message:field-dataset-reference:url]\\u003C\\/p\\u003E\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about updates of this dataset.\\u003Cbr\\u003EYou can unsubscribe at:\\u003Cbr\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EYou can see this dataset at:\\u003Cbr \\/\\u003E[message:field-dataset-reference:url]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EYou have received this message because you are subscribed to notifications about updates of this dataset.\\u003Cbr \\/\\u003EYou can unsubscribe at:\\u003Cbr \\/\\u003E[site:url]user\\/[message:current-subscriber-uid]\\/subscriptions\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
