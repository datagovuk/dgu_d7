<?php
/**
 * @file panels-pane.tpl.php
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<div class="<?php print $classes; ?>" <?php print $id; ?>>
  <?php if ($admin_links): ?>
    <?php print $admin_links; ?>
  <?php endif; ?>

  <div class="pane-content">
    <a href="<?php print $content['field_link'][0]['#element']['url']; ?>">
      <?php print render($content['field_image_tile_big']); ?>
    </a>
    <a class="tile-text" href="<?php print $content['field_link'][0]['#element']['url']; ?>">
      <h2><?php print $title; ?></h2>
      <p><?php print $content['field_description'][0]['#markup']; ?></p>
    </a>
  </div>
</div>
