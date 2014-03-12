<?php
/**
 * @file
 * Template for a 3 column panel layout.
 *
 * This template provides a three column 25%-50%-25% panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['left']: Content in the left column.
 *   - $content['middle']: Content in the middle column.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-display panel-3col-33-stacked clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']): ?>
    <div class="center-wrapper row row-first">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last col-md-12">
        <div class="inside"><?php print $content['top']; ?></div>
      </div>
    </div>
  <?php endif ?>

  <?php if ($content['left'] || $content['middle'] || $content['right']): ?>
    <div class="center-wrapper row row-second row-middle">
      <?php if ($content['left']): ?>
        <div class="panel-panel panel-col-first col-md-4">
          <div class="inside"><?php print $content['left']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['middle']): ?>
        <div class="panel-panel panel-col-second panel-col-middle col-md-4">
          <div class="inside"><?php print $content['middle']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['right']): ?>
        <div class="panel-panel panel-col-third panel-col-last col-md-4">
          <div class="inside"><?php print $content['right']; ?></div>
        </div>
      <?php endif ?>
    </div>
  <?php endif ?>

  <?php if ($content['bottom']): ?>
    <div class="center-wrapper row-third row-last">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last col-md-12">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    </div>
  <?php endif ?>

</div>
