<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU three column'),
  'category' => t('Columns: 3'),
  'icon' => 'dgu_threecol.png',
  'theme' => 'dgu_threecol',
  'css' => 'dgu_threecol.css',
  'regions' => array(
    'left' => t('Left side'),
    'middle' => t('Middle column'),
    'right' => t('Right side')
   ),
);
