<h1>Dataset comments</h1>
<h3>Latest comments on all datasets published by <a href="/publisher/<?php print $publisher->name ?>"><?php print $publisher->title; ?></a></h3>
<?php if($is_admin): ?>
<h4>Email notifications for dataset comments are <strong><?php print $email_notifications;?></strong>. You can change this preference in your <a href="/user/<?php print $uid; ?>/edit?destination=<?php $destination = drupal_get_destination(); print $destination['destination']; ?>">account settings</a></h4>
<?php endif; ?>
<div class="dataset-comment-report">
<?php
foreach  ($datasets_comments as $dataset):?>
  <h3 class="dataset-title">Dataset: <a href="/dataset/<?php print $dataset['name']; ?>"><?php print $dataset['title']; ?></a></h3>
    <?php print $dataset['comments']; ?>
<?php endforeach ?>
</div>
