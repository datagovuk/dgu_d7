<?php

/**
 * @file
 * A basic template for CKAN Datasets
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The name of the CKAN Dataset
 * - $url: The standard URL for viewing a CKAN Dataset
 * - $page: TRUE if this is the main view page $url points too.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-profile
 *   - ckan_dataset-{TYPE}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
$publisher = entity_load_single('ckan_publisher', $ckan_dataset->publisher_id);

?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <h1 class="node-title"><a href="/dataset/<?php print $ckan_dataset->name ?>"><?php print $ckan_dataset->title; ?></a></h1>
  <p class="submitted">
    <span>Published by </span><?php print l($publisher->title, 'ckan_publisher/' . $ckan_dataset->publisher_id); ?>
  </p>
  <?php  if ($user->uid == 1): ?>
    <p>
      <div>ID: <?php print $ckan_dataset->id;?></div>
      <div>CKAN ID: <?php print $ckan_dataset->ckan_id;?></div>
      <div>Inventory: <?php print $ckan_dataset->inventory;?></div>
    </p>
  <?php endif; ?>
  <p><?php print $ckan_dataset->notes; ?></p>

</div>
