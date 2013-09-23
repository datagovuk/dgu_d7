<?php

/**
 * Variables $
 */

?>
<div class="result-info">
    <div class="result-count"><?php print $found ?></div>
    <div class="result-count-footer"><?php print $type ?></div>
    <?php if (isset($dataset_request_count)): ?>
    <div class="result-private-dataset-request">+ <?php print $dataset_request_count ?> private data requests</div>
    <?php endif ?>
</div>
