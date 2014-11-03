<div class="replies-wrapper">
  <a id="comments"></a> <!--Anchor to display nodes' comments.-->
  <?php if (!empty($replies)) : ?>
    <?php if (!empty($header)) : ?>
      <div class="replies-header"><h3><?php print $header ?></h3></div>
    <?php endif; ?>
    <div class="replies"><?php print render($replies) ?></div>
  <?php endif; ?>
  <?php if (!empty($links)): ?>
    <div class="replies-links"><?php print render($links) ?></div>
  <?php endif; ?>
  <?php if (!empty($reply_form)): ?>
    <div class="replies-form"><?php print render($reply_form) ?></div>
  <?php endif; ?>
</div>
