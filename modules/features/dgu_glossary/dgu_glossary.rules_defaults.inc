<?php
/**
 * @file
 * dgu_glossary.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dgu_glossary_default_rules_configuration() {
  $items = array();
  $items['rules_sugggest_new_definition'] = entity_import('rules_config', '{ "rules_sugggest_new_definition" : {
      "LABEL" : "Sugggest new definition",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "suggested_definition" : "suggested_definition" } }
          }
        }
      ],
      "DO" : [
        { "redirect" : { "url" : "\\/glossary\\/suggest_definition\\/thanks?destination=\\/glossary" } }
      ]
    }
  }');
  return $items;
}
