<h1>Dataset comments</h1>
<h3>Latest comments on all datasets published by <a href="/publisher/<?php print $publisher->name ?>"><?php print $publisher->title; ?></a></h3>
<div class="dataset-comment-report">
<?php
foreach  ($datasets_comments as $dataset):?>
  <h3 class="dataset-title">Dataset: <a href="/dataset/<?php print $dataset['name']; ?>"><?php print $dataset['title']; ?></a></h3>
    <?php print $dataset['comments']; ?>
<?php endforeach ?>
</div>
