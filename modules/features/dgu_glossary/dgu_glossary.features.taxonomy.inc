<?php
/**
 * @file
 * dgu_glossary.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dgu_glossary_taxonomy_default_vocabularies() {
  return array(
    'glossary' => array(
      'name' => 'Glossary',
      'machine_name' => 'glossary',
      'description' => 'DGU Glossary',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
