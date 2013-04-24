<div id="reply-<?php print $reply->id ?>" class="<?php print $classes ?>">
    <?php
    //$author=user_load($reply->uid);
    print l($author->name, "user/" . $author->uid);?>

    <div class="reply-body"><?php print render($content) ?></div>
  <div class="reply-links"><?php print render($links) ?></div>
</div>
