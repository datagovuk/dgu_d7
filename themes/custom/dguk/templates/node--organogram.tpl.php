<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php elseif ($title): ?>
      <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
  </header>

  <?php
    // Hide tags and links now so that we can render them later.
    hide($content['links']);

    print views_embed_view('organograms', 'block');
  ?>

  <iframe width='100%' height='700px' src="<?php print $content['field_endpoint'][0]['#markup']; ?>" title="Content from external site: Application-orientated dynamic content, describing structure of government in organogram format"></iframe>
</article> <!-- /.node -->

<?php if (!empty($content['links'])): ?>
  <footer>
    <?php print render($content['links']); ?>
  </footer>
<?php endif; ?>
