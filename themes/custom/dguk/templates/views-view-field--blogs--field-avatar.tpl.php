<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>

<?php

// Check if we are missing the avatar image.
if (empty($output)) {

  // Use custom themer to output images in theme like those uploaded to the drupal files table.
	$image = theme_image_style_outside_files(array(
    'style_name' => 'avatar',
	  'path' => 'profiles/dgu/themes/custom/dguk/default_images/default_user.png',
	));

  $linkedimage = l($image, 'users/'.$row->users_node_name, array('html' => true) );
  print($linkedimage);
}
else {
  // Use the default output from views;
  print $output;
}

?>