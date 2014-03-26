<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>
<?php if (!empty($title)): ?>
  <h2><?php print $title; ?></h2>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="col-md-4 ' . $classes_array[$id] .'"';  } ?>>
    <a href="/forum/<?php print str_replace(' ', '-', strtolower($variables['view']->result[$id]->taxonomy_term_data_name)); ?>" class="inner">
      <?php print $row; ?>
    </a>
  </div>
<?php endforeach; ?>