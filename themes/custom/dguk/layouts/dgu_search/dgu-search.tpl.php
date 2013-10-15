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
<div class="panel-2col-stacked-right row-fluid clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <?php if ($content['top-left'] || $content['top-right']): ?>
    <div class="center-wrapper boxed">
      <table class="search-area">
        <tr>
          <td class="left">
            <div class="panel-col-top-left panel-panel">
              <?php print $content['top-left']; ?>
            </div>
          </td>
          <td class="right">
            <div class="panel-col-top-right panel-panel">
              <?php print $content['top-right']; ?>
            </div>
          </td>
        </tr>
      </table>
    </div>
  <?php endif; ?>

  <div class="center-wrapper">
    <?php if ($content['left']): ?>
      <div class="panel-col-first panel-panel span4">
        <div class="inside boxed    "><?php print $content['left']; ?></div>
      </div>
    <?php endif; ?>
    <?php if ($content['right']): ?>
      <div class="panel-col-last panel-panel span8">
        <div class="inside"><?php print $content['right']; ?></div>
      </div>
    <?php endif; ?>
  </div>

  <?php if ($content['bottom']): ?>
    <div class="panel-col-bottom panel-panel">
      <div class="inside"><?php print $content['bottom']; ?></div>
    </div>
  <?php endif; ?>
</div>
