<?php 



function dguk_preprocess(&$variables){
    global $base_root;

    module_load_include('inc', 'lexicon', 'lexicon.pages');

    # Add the shared dgu logo.
    $variables['logo'] = $base_root."/assets/img/dgu-header-cropped.png";


    # Add shared CSS and JS. Added here because the info file won't allow inclusion from site root.

    
    drupal_add_js('/assets/js/vendor.compiled.js', array(
      'type' => 'file',
      'scope' => 'header',
      'group' => JS_THEME,
      'every_page' => TRUE,
    ));

}