<div class="panel-display panel-1col clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['middle']): ?>
    <div class="center-wrapper row-first">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last">
        <div class="inside"><?php print $content['middle']; ?></div>
      </div>
    </div>
  <?php endif ?>

</div>
