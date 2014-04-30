<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU two column for search page'),
  'category' => t('Columns: 2'),
  'icon' => 'dgu_search.png',
  'theme' => 'dgu_search',
  'regions' => array(
    'left_top' => t('Left top'),
    'left_bottom' => t('Left bottom'),
    'right' => t('Right side'),
  ),
);
