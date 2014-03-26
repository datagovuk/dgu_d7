<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
// Get raw second argument, not converted by drupal to internal path.
list($active_category) = array_slice(explode('/', $_SERVER['REQUEST_URI']), 2, 1);
?>
<?php if (!empty($title)): ?>
  <h2><?php print $title; ?></h2>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <?php if (strpos(str_replace('.', '', $row), $active_category) > 0 || strpos($row, $active_category) > 0) { $classes_array[$id] .= ' active'; } // Check for an argument wih and without '.' to avoid problems with 'police.uk-data' in the url.?>
  <div <?php if ($classes_array[$id]) { print 'class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
