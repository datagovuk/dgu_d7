<div id="reply-<?php print $reply->id; ?>" class="<?php print $classes ?> boxed">
  <div class="inner">
    <?php if($new): ?>
      <div class="new">New</div>
    <?php endif; ?>
    <div class="reply-header">
      <?php print $avatar; ?>
      <?php hide($content['field_reply_subject']); ?>
      <h3><?php print $reply->field_reply_subject[LANGUAGE_NONE][0]['safe_value']; ?></h3>
      <span class="submitted">Posted by <?php print $author; ?> on <?php print $created; ?></span>
    </div>
    <div class="reply-body"><?php print render($content) ?></div>
    <?php print flag_create_link('spam_reply', $reply->id); ?>
    <div class="reply-links pull-left"><?php print render($links) ?></div>
  </div>
</div>
