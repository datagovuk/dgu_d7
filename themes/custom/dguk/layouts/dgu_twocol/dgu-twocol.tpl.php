<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * each column roughly equal in width.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 */
?>
<div class="panel-display panel-2col clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['left'] || $content['right']): ?>
    <div class="center-wrapper row row-first row-last">
      <?php if ($content['left']): ?>
        <div class="panel-panel panel-col-first col-md-9">
          <div class="inside"><?php print $content['left']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['right']): ?>
        <div class="panel-panel panel-col-second panel-col-last col-md-3">
          <div class="inside"><?php print $content['right']; ?></div>
        </div>
      <?php endif ?>
    </div>
  <?php endif ?>

</div>
