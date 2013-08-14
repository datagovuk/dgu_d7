<?php 


/**
 *  Implements theme_preprocess().
 */
function dguk_preprocess(&$variables){
    module_load_include('inc', 'lexicon', 'lexicon.pages');

    # Add the shared dgu logo.
    $variables['logo'] = '/assets/img/dgu-header-cropped.png';
}