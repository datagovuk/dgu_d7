<div class="panel-display panel-3col-33 row clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']): ?>
    <div class="panel-panel panel-col-top">
      <div class="inside"><?php print $content['top']; ?></div>
    </div>
  <?php endif ?>

  <div class="center-wrapper row-top">
    <div class="panel-panel panel-col-first col-md-4">
      <div class="inside"><?php print $content['top_left']; ?></div>
    </div>
    <div class="panel-panel panel-col col-md-4">
      <div class="inside"><?php print $content['top_middle']; ?></div>
    </div>
    <div class="panel-panel panel-col-last col-md-4">
      <div class="inside"><?php print $content['top_right']; ?></div>
    </div>
  </div>

  <div class="center-wrapper row-middle">
    <div class="panel-panel panel-col-first col-md-4">
      <div class="inside"><?php print $content['middle_left']; ?></div>
    </div>
    <div class="panel-panel panel-col col-md-4">
      <div class="inside"><?php print $content['middle_middle']; ?></div>
    </div>
    <div class="panel-panel panel-col-last col-md-4">
      <div class="inside"><?php print $content['middle_right']; ?></div>
    </div>
  </div>

  <div class="center-wrapper row-bottom">
    <div class="panel-panel panel-col-first col-md-4">
      <div class="inside"><?php print $content['bottom_left']; ?></div>
    </div>
    <div class="panel-panel panel-col col-md-4">
      <div class="inside"><?php print $content['bottom_middle']; ?></div>
    </div>
    <div class="panel-panel panel-col-last col-md-4">
      <div class="inside"><?php print $content['bottom_right']; ?></div>
    </div>
  </div>

  <?php if ($content['bottom']): ?>
    <div class="panel-panel panel-col-bottom">
      <div class="inside"><?php print $content['bottom']; ?></div>
    </div>
  <?php endif ?>

</div>

