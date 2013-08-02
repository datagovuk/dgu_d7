<?php

// Plugin definition
$plugin = array(
  'title' => t('DGU two column'),
  'category' => t('Columns: 2'),
  'icon' => 'dgu_twocol.png',
  'theme' => 'dgu_twocol',
  'css' => 'dgu_twocol.css',
  'regions' => array(
    'left' => t('Left side'),
    'right' => t('Right side')
  ),
);
