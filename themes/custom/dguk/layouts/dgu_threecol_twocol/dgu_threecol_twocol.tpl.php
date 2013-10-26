<?php
/**
 * @file
 * Template for a 3 column panel layout.
 *
 * This template provides a three column panel display layout, with
 * each column roughly equal in width.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['middle']: Content in the middle column.
 *   - $content['right']: Content in the right column.
 */
?>

<div class="panel-display panel-3col-33 row clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']): ?>
    <div class="panel-panel panel-col-top">
      <div class="inside"><?php print $content['top']; ?></div>
    </div>
  <?php endif ?>

  <div class="center-wrapper row-top">
    <div class="panel-panel panel-col-first col-md-4">
      <div class="inside"><?php print $content['top_left']; ?></div>
    </div>
    <div class="panel-panel panel-col col-md-4">
      <div class="inside"><?php print $content['top_middle']; ?></div>
    </div>
    <div class="panel-panel panel-col-last col-md-4">
      <div class="inside"><?php print $content['top_right']; ?></div>
    </div>
  </div>

  <div class="center-wrapper row-bottom">
    <div class="panel-panel panel-col-first col-md-6">
      <div class="inside"><?php print $content['bottom_left']; ?></div>
    </div>
    <div class="panel-panel panel-col-last col-md-6">
      <div class="inside"><?php print $content['bottom_right']; ?></div>
    </div>
  </div>

  <?php if ($content['bottom']): ?>
    <div class="panel-panel panel-col-bottom">
      <div class="inside"><?php print $content['bottom']; ?></div>
    </div>
  <?php endif ?>

</div>

