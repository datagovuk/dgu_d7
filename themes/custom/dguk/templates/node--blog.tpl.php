<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix col-md-9 col-md-offset-2"<?php print $attributes; ?>>
  <div class="avatar"><?php print $avatar; ?></div>
  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h1<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h1>
    <?php elseif ($title): ?>
      <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
    <?php endif; ?>
    <?php print render($title_suffix); ?>

    <?php if ($display_submitted): ?>
      <span class="submitted">
        <?php print $submitted; ?>
      </span>
    <?php endif; ?>
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
