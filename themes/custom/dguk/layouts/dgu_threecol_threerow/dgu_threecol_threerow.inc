<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU three column three row'),
  'category' => t('Columns: 3'),
  'icon' => 'dgu_threecol_threerow.png',
  'theme' => 'dgu_threecol_threerow',
  'regions' => array(
    'top' => t('Top'),
    'top_left' => t('Top left'),
    'top_middle' => t('Top middle'),
    'top_right' => t('Top right'),
    'middle_left' => t('Middle left'),
    'middle_middle' => t('Middle middle'),
    'middle_right' => t('Middle right'),
    'bottom_left' => t('Bottom left'),
    'bottom_middle' => t('Bottom middle'),
    'bottom_right' => t('Bottom right'),
    'bottom' => t('Bottom'),
   ),
);
