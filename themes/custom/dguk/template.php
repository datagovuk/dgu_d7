<?php 



function dguk_preprocess(&$variables){
    global $base_root;

    module_load_include('inc', 'lexicon', 'lexicon.pages');

    # Add the shared dgu logo.
    $variables['logo'] = $base_root."/assets/img/dgu-header-cropped.png";


    # Add shared CSS and JS. Added here because the info file won't allow inclusion from site root.
    # CSS is added pseudo externally as drupal_add_css can't add from domain root.
    drupal_add_css($base_root . '/assets/css/dgu-joint.compiled.css', array('type' => 'external'));
    
    drupal_add_js('/assets/js/vendor.compiled.js', array(
      'type' => 'file',
      'scope' => 'header',
      'group' => JS_THEME,
      'every_page' => TRUE,
    ));

}