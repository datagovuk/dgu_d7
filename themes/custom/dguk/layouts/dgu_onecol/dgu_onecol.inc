<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('DGU single column'),
  'category' => t('Columns: 1'),
  'icon' => 'dgu_onecol.png',
  'theme' => 'dgu_onecol',
  'regions' => array('middle' => t('Middle column')),
);
