<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * additional areas for the top and the bottom.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top row.
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 *   - $content['bottom']: Content in the bottom row.
 */
?>
<div class="panel-2col-stacked-right row clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']): ?>
    <div class="center-wrapper row-first">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last">
        <div class="inside"><?php print $content['top']; ?></div>
      </div>
    </div>
  <?php endif ?>

  <?php if ($content['left'] || $content['right']): ?>
    <div class="center-wrapper row-second row-middle">
      <?php if ($content['left']): ?>
        <div class="panel-panel panel-col-first col-md-4">
          <div class="inside"><?php print $content['left']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['right']): ?>
        <div class="panel-panel panel-col-second panel-col-last col-md-8">
          <div class="inside"><?php print $content['right']; ?></div>
        </div>
      <?php endif ?>
    </div>
  <?php endif ?>

  <?php if ($content['bottom']): ?>
    <div class="center-wrapper row-third row-last">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    </div>
  <?php endif ?>

</div>
