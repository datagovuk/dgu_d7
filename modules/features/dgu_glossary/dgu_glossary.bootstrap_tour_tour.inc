<?php
/**
 * @file
 * dgu_glossary.bootstrap_tour_tour.inc
 */

/**
 * Implements hook_default_bootstrap_tour().
 */
function dgu_glossary_default_bootstrap_tour() {
  $export = array();

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'glossary';
  $bootstrap_tour->title = 'Glossary';
  $bootstrap_tour->roles = '2,3';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'Glossary Tour';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '#glossary_filter',
      'path' => 'glossary',
      'placement' => 'left',
      'title' => 'Filter terms',
      'content' => '<p>You can use these tabs to show only terms published by APPSI, terms suggested by the public or both.</p>',
      'format' => 'full_html',
    ),
    1 => array(
      'selector' => '.suggest-new',
      'path' => '',
      'placement' => 'left',
      'title' => 'Suggest a new Term',
      'content' => '<p>If you think that we\'ve  missed an important term, you can suggest it by clicking this link. We will review your suggestion and get back to you.</p>',
      'format' => 'full_html',
    ),
    2 => array(
      'selector' => '.alphabet-search',
      'path' => '',
      'placement' => 'left',
      'title' => 'Find terms',
      'content' => '<p><span>You can jump to the section of the Glossary to help you find the term you are looking for. The grey letters do not currently have any terms defined within them.</span></p>',
      'format' => 'full_html',
    ),
    3 => array(
      'selector' => '.glossary-term:first',
      'path' => '',
      'placement' => 'left',
      'title' => 'Glossary Terms and definitions',
      'content' => '<p>Each term and its definition appear in the list.  If you click the term, you will be taken to  the term page where you can comment on the term or suggest a better definition</p>',
      'format' => 'full_html',
    ),
    4 => array(
      'selector' => '.glossary-appsi-quality',
      'path' => 'glossary/1',
      'placement' => 'left',
      'title' => 'APPSI Quality score',
      'content' => '<p>The APPSI quality score reflects our confidence in the accuracy and quality of a term and its definition. You can learn more about APPSI by clicking on the link.</p>',
      'format' => 'full_html',
    ),
    5 => array(
      'selector' => '.vud-widget:first',
      'path' => '',
      'placement' => 'right',
      'title' => 'Endorse our definition',
      'content' => '<p>If you agree with our definition, them please tell us by clicking the Endorse button. We won\'t show how many other people have endorsed a defintion, and you are able to revoke your endorsement by clicking the button again.</p>',
      'format' => 'full_html',
    ),
    6 => array(
      'selector' => '#suggest-def',
      'path' => '',
      'placement' => 'left',
      'title' => 'Suggest a better definition',
      'content' => '<p>If you think that you can provide a better definition than our current one, let us know by clicking this button and filling in the form.  Your suggestion will be notified to our moderators who will usually contact you within a week.</p>',
      'format' => 'full_html',
    ),
    7 => array(
      'selector' => '#make-comment',
      'path' => '',
      'placement' => 'right',
      'title' => 'Make a comment',
      'content' => '<p>If you would like to discuss the term or the definition with other users, you can do that by making a comment.</p>',
      'format' => 'full_html',
    ),
  );
  $export['glossary'] = $bootstrap_tour;

  return $export;
}
