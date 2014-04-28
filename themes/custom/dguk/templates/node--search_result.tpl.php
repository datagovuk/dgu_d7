<div class="search-result-body">

  <div class="right">
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
    <?php
      hide($content['links']);
      hide($content['field_comment']);
      print render($content);
    ?>

  </div>
</div>

