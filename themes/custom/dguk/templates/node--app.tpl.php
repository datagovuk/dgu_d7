<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if (!$page && $title): ?>
    <h1 class="node-title" <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h1>
  <?php elseif ($title): ?>
    <h1 class="node-title" <?php print $title_attributes; ?>><?php print $title; ?></h1>
  <?php endif; ?>

  <header>
    <?php print render($content['field_rating']); ?>
    <span class="submitted">
      <?php print $user_picture; ?>
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
    <?php print render($content['field_developed_by']); ?>
    <?php print render($content['field_app_link']); ?>
    <?php print render($content['field_app_charge']); ?>


  </header>
  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['links']);
    hide($content['field_comment']);
    print render($content);
  ?>

  <div class="disclaimer disclaimer-app">
    Apps submitted to data.gov.uk are currently approved for publication on the general level of their context and appropriateness.
    Whilst we review these on a periodical basis, we do not own responsibility for the regular update and maintenance of these apps. Any queries about individual apps or tools published need to be directed to the originator.
  </div>
</article> <!-- /.node -->

<?php if (!empty($content['links']) || !empty($content['field_comment'])): ?>
  <footer>
    <?php print render($content['field_comment']); ?>
    <?php print render($content['links']); ?>
  </footer>
<?php endif; ?>

