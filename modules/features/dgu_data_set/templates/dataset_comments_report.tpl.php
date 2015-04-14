<h1>Latest comments report for <a href="http://data.gov.uk/publisher/<?php print $publisher->ckan_id ?>"><?php print($publisher->title); ?></a></h1>
<p>Latest comments on all datasets published by <a href="http://data.gov.uk/publisher/<?php print $publisher->ckan_id ?>"><?php print($publisher->title); ?></a> </p>
<div class="dataset-comment-report">
<?php
foreach  ($dataset_comments as $row):?>
  <div class="result boxed">
    <h2><a href="http://data.gov.uk/dataset/<?php print($row->ckan_id)?>"><?php print($row->dataset_title)?></a></h2>
    <div class="comment">
      <div class="reply-header">
        <h3><?php print($row->subject); ?></h3>
        <span class=""submitted">Posted on <?php print($row->post_date);?> </span>
      </div>
      <?php print($row->comment);?>
    </div>
  </div>
<?php endforeach ?>
</div>
