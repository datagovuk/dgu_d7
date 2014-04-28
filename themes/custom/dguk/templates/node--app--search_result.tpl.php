<div class="search-result-body">

  <div class="right">
    <?php if (isset($field_developed_by[0]['safe_value'])): ?>
      <div class="search-result-developed-by">
        <?php
        // fitler_xss changes & to &amp;
        // We change it back to & only if it's surrounded by spaces.
        ?>
        <div>Developed by</div><?php print l(str_replace(' &amp; ', ' & ', filter_xss($field_developed_by[0]['value'])), 'search/everything/' . $field_developed_by[0]['safe_value'], array('query' => array('f[0]' => 'bundle:app'))) ; ?>
      </div>
    <?php endif; ?>

    <?php if (isset($field_rating[0]['average'])): ?>
      <div class="search-result-rating">
        <?php print theme('fivestar_static', (array('rating' => $field_rating[0]['average'], 'stars' => 5))); ?>
      </div>
    <?php endif; ?>
  </div>

  <div class="left">

    <div class="search-info">
      <?php if (isset($submitted)): ?>
        <span><?php print $submitted; ?></span>
      <?php endif; ?>

      <?php if (isset($updated)): ?>
        <span><?php print $updated; ?></span>
      <?php endif; ?>
    </div>

    <div class="search-snippet-info">
      <?php if ($content['body']): ?>
        <p class="field-body"><?php print render($content['body']); ?></p>
      <?php endif; ?>
    </div>

    <?php if (isset($content['field_screen_shots'])): ?>
        <?php print render($content['field_screen_shots']); ?>
    <?php endif; ?>

  </div>
</div>
