<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (!$page && $title): ?>
    <h1 class="node-title" <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h1>
  <?php elseif ($title): ?>
    <h1 class="node-title" <?php print $title_attributes; ?>><?php print $title; ?></h1>
  <?php endif; ?>

  <header class="with-avatar">

    <?php print $avatar; ?>

    <span class="submitted">
        <?php print $submitted; ?>
      </span>
    <?php if ($updated): ?>
      <span class="submitted">
          <?php print $updated; ?>
        </span>
    <?php endif; ?>
    <div class="taxonomy">
      <?php print render($content['field_category']); ?>
      <?php print render($content['field_tags']); ?>
    </div>
  </header>

  <?php
  // Hide comments, tags, and links now so that we can render them later.
  hide($content['links']);
  hide($content['field_comment']);
  print render($content);
  ?>
</article> <!-- /.node -->

<?php if (!empty($content['links']) || !empty($content['field_comment'])): ?>
  <footer>
    <?php print render($content['field_comment']); ?>
    <?php print render($content['links']); ?>
  </footer>
<?php endif; ?>
