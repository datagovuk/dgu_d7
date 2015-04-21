<?php
/**
 * @file
 * dgu_user.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dgu_user_default_rules_configuration() {
  $items = array();
  $items['rules_login_redirection'] = entity_import('rules_config', '{ "rules_login_redirection" : {
      "LABEL" : "Login redirection",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "rules_url_argument", "rules" ],
      "IF" : [
        { "NOT rules_url_argument_argument_exists" : { "argument" : "destination" } }
      ],
      "DO" : [ { "redirect" : { "url" : "user\\/[account:uid]" } } ]
    }
  }');
  return $items;
}
