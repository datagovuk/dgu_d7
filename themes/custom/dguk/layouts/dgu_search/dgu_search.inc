<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU two column stacked styled for search'),
  'category' => t('Columns: 2'),
  'icon' => 'dgu_search.png',
  'theme' => 'dgu_search',
  'css' => 'dgu_search.css',
  'regions' => array(
    'top-left' => t('Top left'),
    'top-right' => t('Top right'),
    'left' => t('Left side'),
    'right' => t('Right side'),
    'bottom' => t('Bottom')
  ),
);
