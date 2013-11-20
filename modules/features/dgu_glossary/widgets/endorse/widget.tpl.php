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
    <?php if (!$show_reset): ?>
      <?php if ($show_down_as_link): ?>
        <a href="<?php print $link_down; ?>" rel="nofollow" class="<?php print $link_class_reset; ?>"
           title="<?php print $reset_long_text; ?>">
          <button type="button" class="btn btn-default">
            <i class="icon-thumbs-down"></i>
            <?php print t('Cancel Endorsement'); ?>
          </button>
        </a>
      <?php elseif ($show_up_as_link): ?>
        <a href="<?php print $link_up; ?>" rel="nofollow" class="<?php print $link_class_up; ?>">
        <button type="button" class="btn btn-default">
          <i class="icon-thumbs-up"></i>
          <?php print t('Endorse'); ?>
        </button>
        </a>
      <?php endif; ?>
    <?php endif; ?>
  <?php endif; ?>
<?php endif; ?>
</div>
