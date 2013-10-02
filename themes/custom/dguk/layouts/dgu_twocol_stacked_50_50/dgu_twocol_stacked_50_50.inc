<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU two column stacked 50/50'),
  'category' => t('Columns: 2'),
  'icon' => 'dgu_twocol_stacked_50_50.png',
  'theme' => 'dgu_twocol_stacked_50_50',
  'css' => 'dgu_twocol_stacked_50_50.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
