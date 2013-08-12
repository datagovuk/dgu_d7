<?php 



function dguk_preprocess(&$variables){
    global $base_root;

    module_load_include('inc', 'lexicon', 'lexicon.pages');

    # Add the shared dgu logo.
    $variables['logo'] = $base_root."/assets/img/dgu-header-cropped.png";

}