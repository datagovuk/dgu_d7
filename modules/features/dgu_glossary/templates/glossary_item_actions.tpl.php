<a href="<?php print $suggest_path ?>">
<button type="button" class="btn btn-default">
  <?php print t($suggest_text); ?>
</button>
</a>
<a href="<?php print $comment_path ?>">
<button type="button" class="btn btn-default">
  <?php print t($comment_text); ?>
</button>
</a>
<p>
  You can help us refine and improve the definition of the term: Aggregated data.
  You can <?php print l($suggest_text, $suggest_path, $suggest_link_options); ?>
  or you can participate in the conversation and <?php print l($comment_text, $comment_path, $comment_link_options); ?>.
</p>
