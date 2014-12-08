<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>
        <div class="consultation-paragraph">
          <span class="subsection"><a id="<?php print $item['section']; ?>" ><?php print $item['section']; ?></a></span>
          <div class="consultation-paragraph-inner"><?php print render($item['field']); ?></div>
        </div>
          <?php print render($item['replies']) ?>
          <?php print render($item['links']) ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
