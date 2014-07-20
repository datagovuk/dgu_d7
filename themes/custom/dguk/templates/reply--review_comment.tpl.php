<div id="reply-<?php print $reply->id; ?>" class="<?php print $classes ?> boxed">
  <div class="inner">
      <span class="note-author"><?php print $author; ?> on <?php print $created; ?></span>
    <div class="reply-body"><?php print render($content) ?></div>
    <div class="reply-links"><?php print render($links) ?></div>
  </div>
</div>
