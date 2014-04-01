<div class="panel-display panel-3col-33 clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

  <?php if ($content['top']): ?>
    <div class="center-wrapper row row-first">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last col-md-12">
        <div class="inside"><?php print $content['top']; ?></div>
      </div>
    </div>
  <?php endif ?>

  <?php if ($content['top_left'] || $content['top_middle'] || $content['top_right']): ?>
    <div class="center-wrapper row row-second">
      <?php if ($content['top_left']): ?>
        <div class="panel-panel panel-col-first col-md-4">
          <div class="inside"><?php print $content['top_left']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['top_middle']): ?>
        <div class="panel-panel panel-col-second panel-col-middle col-md-4">
          <div class="inside"><?php print $content['top_middle']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['top_right']): ?>
        <div class="panel-panel panel-col-third panel-col-last col-md-4">
          <div class="inside"><?php print $content['top_right']; ?></div>
        </div>
      <?php endif ?>
    </div>
  <?php endif ?>

  <?php if ($content['bottom_left'] || $content['bottom_right']): ?>
    <div class="center-wrapper row row-third">
      <?php if ($content['bottom_left']): ?>
        <div class="panel-panel panel-col-first col-md-6">
          <div class="inside"><?php print $content['bottom_left']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['bottom_right']): ?>
        <div class="panel-panel panel-col-second panel-col-last col-md-6">
          <div class="inside"><?php print $content['bottom_right']; ?></div>
        </div>
      <?php endif ?>
    </div>
  <?php endif ?>

  <?php if ($content['bottom']): ?>
    <div class="center-wrapper row row-fourth row-last">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last col-md-12">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    </div>
  <?php endif ?>

</div>
