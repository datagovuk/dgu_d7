<div class="panel-display panel-1col clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']): ?>
    <div class="center-wrapper row row-first">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last col-md-12">
        <div class="inside"><?php print $content['top']; ?></div>
      </div>
    </div>
  <?php endif ?>

  <?php if ($content['middle']): ?>
    <div class="center-wrapper row row-second">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last col-md-12">
        <div class="inside"><?php print $content['middle']; ?></div>
      </div>
    </div>
  <?php endif ?>

  <?php if ($content['bottom']): ?>
    <div class="center-wrapper row row-third">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last col-md-12">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    </div>
  <?php endif ?>

</div>
