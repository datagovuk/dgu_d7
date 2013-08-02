<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU two column stacked'),
  'category' => t('Columns: 2'),
  'icon' => 'dgu_twocol_stacked.png',
  'theme' => 'dgu_twocol_stacked',
  'css' => 'dgu_twocol_stacked.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
