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
<div class="panel-2col-search clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <div class="center-wrapper row row-first row-last">
    <?php if ($content['left_top'] || $content['left_bottom']): ?>
      <div class="panel-panel panel-col-first col-md-4">
        <?php if ($content['left_top']): ?>
          <div class="inside panel-left-top"><?php print $content['left_top']; ?></div>
        <?php endif ?>

        <?php if ($content['left_bottom']): ?>
          <div class="inside panel-left-bottom"><?php print $content['left_bottom']; ?></div>
        <?php endif ?>
      </div>
    <?php endif ?>

    <?php if ($content['right']): ?>
      <div class="panel-panel panel-col-second panel-col-last col-md-8">
        <div class="inside"><?php print $content['right']; ?></div>
      </div>
    <?php endif ?>
  </div>

</div>
