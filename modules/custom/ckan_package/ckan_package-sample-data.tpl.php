<?php

/**
 * @file
 * Example tpl file for theming a single CKAN-specific theme
 *
 * Available variables:
 * - $status: The variable to theme (while only show if you tick status)
 * 
 * Helper variables:
 * - $ckan: The CKAN object this status is derived from
 */
?>

<div class="ckan_package-status">
  <?php print '<strong>CKAN Package Sample Data:</strong> ' . $ckan_pacakage_sample_data = ($ckan_package_sample_data) ? 'Switch On' : 'Switch Off' ?>
</div>