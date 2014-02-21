<div class="panel-display panel-3col-33 row clearfix" <?php if (!empty($css_id)) {print "id=\"$css_id\"";} ?>>

  <?php if ($content['top']): ?>
    <div class="center-wrapper row-first">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last">
        <div class="inside"><?php print $content['top']; ?></div>
      </div>
    </div>
  <?php endif ?>

  <?php if ($content['top_left'] || $content['top_middle'] || $content['top_right']): ?>
    <div class="center-wrapper row-second">
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

  <?php if ($content['middle_left'] || $content['middle_middle'] || $content['middle_right']): ?>
    <div class="center-wrapper row-third">
      <?php if ($content['middle_left']): ?>
        <div class="panel-panel panel-col-first col-md-4">
          <div class="inside"><?php print $content['middle_left']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['middle_middle']): ?>
        <div class="panel-panel panel-col-second panel-col-middle col-md-4">
          <div class="inside"><?php print $content['middle_middle']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['middle_right']): ?>
        <div class="panel-panel panel-col-third panel-col-last col-md-4">
          <div class="inside"><?php print $content['middle_right']; ?></div>
        </div>
      <?php endif ?>
    </div>
  <?php endif ?>

  <?php if ($content['bottom_left'] || $content['bottom_middle'] || $content['bottom_right']): ?>
    <div class="center-wrapper row-fourth">
      <?php if ($content['bottom_left']): ?>
        <div class="panel-panel panel-col-first col-md-4">
          <div class="inside"><?php print $content['bottom_left']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['bottom_middle']): ?>
        <div class="panel-panel panel-col-second panel-col-middle col-md-4">
          <div class="inside"><?php print $content['bottom_middle']; ?></div>
        </div>
      <?php endif ?>

      <?php if ($content['bottom_right']): ?>
        <div class="panel-panel panel-col-third panel-col-last col-md-4">
          <div class="inside"><?php print $content['bottom_right']; ?></div>
        </div>
      <?php endif ?>
    </div>
  <?php endif ?>

  <?php if ($content['bottom']): ?>
    <div class="center-wrapper row-fifth row-last">
      <div class="panel-panel panel-col-single panel-col-first panel-col-last">
        <div class="inside"><?php print $content['bottom']; ?></div>
      </div>
    </div>
  <?php endif ?>

</div>

