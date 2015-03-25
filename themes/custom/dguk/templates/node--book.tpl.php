<?php print render($content['book_navigation']); ?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <?php if (!$page && $title): ?>
        <h1 class="node-title" <?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h1>
    <?php elseif ($title): ?>
        <h1 class="node-title" <?php print $title_attributes; ?>><?php print $title; ?></h1>
    <?php endif; ?>

    <header>
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
        </div>
    </header>
    <?php if (!empty($body[0]['safe_summary'])): ?>
    <header>
        <div class="summary">
          <?php print $body[0]['safe_summary']; ?>
        </div>
    </header>
    <?php endif; ?>

    <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['links']);
    print render($content);
    print render($content['links']);
    ?>
</article> <!-- /.node -->
