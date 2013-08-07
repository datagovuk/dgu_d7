<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU three column stacked'),
  'category' => t('Columns: 3'),
  'icon' => 'dgu_threecol_stacked.png',
  'theme' => 'dgu_threecol_stacked',
  'css' => 'dgu_threecol_stacked.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'middle' => t('Middle column'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
