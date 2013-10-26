<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU three/two column'),
  'category' => t('Columns: 3'),
  'icon' => 'dgu_threecol_twocol.png',
  'theme' => 'dgu_threecol_twocol',
  'regions' => array(
    'top' => t('Top'),
    'top_left' => t('Top left'),
    'top_middle' => t('Top middle'),
    'top_right' => t('Top right'),
    'bottom_left' => t('Bottom left'),
    'bottom_right' => t('Bottom right'),
    'bottom' => t('Bottom'),
   ),
);
