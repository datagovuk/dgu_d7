<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU two column stacked right content'),
  'category' => t('Columns: 2'),
  'icon' => 'dgu_twocol_stacked_right.png',
  'theme' => 'dgu_twocol_stacked_right',
  'css' => 'dgu_twocol_stacked_right.css',
  'regions' => array(
    'top' => t('Top'),
    'left' => t('Left side'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
