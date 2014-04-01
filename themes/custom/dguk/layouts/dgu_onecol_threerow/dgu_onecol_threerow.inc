<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('DGU single column with three rows'),
  'category' => t('Columns: 1'),
  'icon' => 'dgu_onecol_threerow.png',
  'theme' => 'dgu_onecol_threerow',
  'regions' => array(
    'top' => t('Top'),
    'middle' => t('Middle'),
    'bottom' => t('Bottom')
  ),
);
