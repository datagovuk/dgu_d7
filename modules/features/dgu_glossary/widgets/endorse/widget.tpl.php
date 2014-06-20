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
    <?php if ($show_reset): ?>
        <a class="btn btn-default btn-primary" href="<?php print $link_reset; ?>" rel="nofollow" class="<?php print $link_class_reset; ?>"
           title="<?php print $reset_long_text; ?>">
          <i class="icon-thumbs-down"></i>
          <?php print t('Cancel Endorsement'); ?>
          <?php print "($points)"; ?>
        </a>
    <?php elseif ($show_up_as_link): ?>
        <a class="btn btn-default btn-primary" href="<?php print $link_up; ?>" rel="nofollow" class="<?php print $link_class_up; ?>">
          <i class="icon-thumbs-up"></i>
          <?php print t('Endorse'); ?>
          <?php print "($points)"; ?>
        </a>
    <?php endif; ?>
  <?php endif; ?>
<?php endif; ?>
</div>
