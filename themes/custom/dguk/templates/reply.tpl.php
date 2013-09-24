<div id="reply-<?php print $reply->id ?>" class="<?php print $classes ?> boxed">
  <?php print $avatar; ?>
  <?php hide($content['field_reply_subject']); ?>
  <h3><?php print $reply->field_reply_subject[LANGUAGE_NONE][0]['safe_value']; ?></h3>
  <span class="submitted">Posted by <?php print $author; ?> on <?php print $created; ?></span>
  <div class="reply-body"><?php print render($content) ?></div>
  <div class="reply-links"><?php print render($links) ?></div>
</div>