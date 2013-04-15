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
                <a href="<?php print $link_up; ?>" rel="nofollow" class="button <?php print $link_class_up; ?>">
            <?php endif; ?>
            <span class="button"><?php print t('Endorse'); ?></span>
            <?php if ($show_up_as_link): ?>
                </a>
            <?php endif; ?>
        <?php endif; ?>
        <?php if ($show_reset): ?>
            <a href="<?php print $link_reset; ?>" rel="nofollow" class="<?php print $link_class_reset; ?>"
               title="<?php print $reset_long_text; ?>">
                <div class="<?php print $class_reset; ?>">
                    <?php print $reset_short_text; ?>
                </div>
            </a>
        <?php endif; ?>
    <?php endif; ?>
</div>
