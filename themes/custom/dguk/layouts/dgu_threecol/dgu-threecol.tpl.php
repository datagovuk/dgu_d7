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

  <?php if ($content['left'] || $content['middle'] || $content['right']): ?>
    <div class="center-wrapper row-first row-last">
      <div class="panel-panel panel-col-first col-md-4">
        <div class="inside"><?php print $content['left']; ?></div>
      </div>

      <div class="panel-panel panel-col-second panel-col-middle col-md-4">
        <div class="inside"><?php print $content['middle']; ?></div>
      </div>

      <div class="panel-panel panel-col-third panel-col-last col-md-4">
        <div class="inside"><?php print $content['right']; ?></div>
      </div>
    </div>
  <?php endif ?>

</div>
