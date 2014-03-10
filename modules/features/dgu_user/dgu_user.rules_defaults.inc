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
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_login" ],
      "DO" : [ { "redirect" : { "url" : "user\\/[account:uid]" } } ]
    }
  }');
  return $items;
}
