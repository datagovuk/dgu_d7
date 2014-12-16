<?php
  $hyphen = empty($consultation_index['section'])? '' : ' - ';
  $active = $consultation_index['selected']?  " class='active' " : "";
?>
<h4><a href="<?php print($consultation_index['href']); ?>"<?php print $active ?>><?php print $consultation_index['section']; ?><?php print $hyphen; ?><?php print $consultation_index['title']; ?></a></h4>
<ul>
  <?php foreach ($consultation_index['paragraphs'] as $paragraph): ?>
  <li class="subsection"><a href="<?php print($consultation_index['href']); ?>#<?php print $paragraph['section']; ?>"><?php print $paragraph['section']; ?> - <?php print $paragraph['title'] ?></a></li>
  <?php endforeach; ?>

  <?php if (!empty($consultation_index['subsections'])): ?>
    <?php foreach ($consultation_index['subsections'] as $subsection): ?>
      <li><?php print(theme('consultation_index', array('consultation_index' => $subsection))); ?></li>
    <?php endforeach; ?>
  <?php endif; ?>
</ul>
