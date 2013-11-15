<?php
/**
 * @file
 * widget.tpl.php
 *
 * Endorse widget theme for Vote Up/Down
 */
?>
<div class="vud-widget vud-widget-endorse" id="<?php print $id; ?>">
<?php if ($class_up) : ?>
  <?php if ($show_links): ?>
    <?php if ($show_up_as_link): ?>
      <a href="<?php print $link_up; ?>" rel="nofollow" class="<?php print $link_class_up; ?>">
    <?php endif; ?>
    <button type="button" class="btn btn-default">
      <span class="glyphicon glyphicon-thumbs-up"></span>
      <?php print t('Endorse'); ?>
    </button>
    <?php if ($show_up_as_link): ?>
      </a>
    <?php endif; ?>

    <?php if ($show_reset): ?>
        <a href="<?php print $link_reset; ?>" rel="nofollow" class="<?php print $link_class_reset; ?>"
           title="<?php print $reset_long_text; ?>">
          <button type="button" class="btn btn-default">
            <span class=".glyphicon .glyphicon-ban-circle"></span>
            <?php print $reset_short_text; ?>
          </button>
        </a>
    <?php endif; ?>
  <?php endif; ?>
<?php endif; ?>
</div>
