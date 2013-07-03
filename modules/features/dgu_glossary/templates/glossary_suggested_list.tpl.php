<?php

/*  Template file for theming list of suggested definition nodes. 
	Variables nids
*/

?>
<ul class="suggested_defs">
    <?php foreach ($suggested_definitions as $suggested_definition): ?>
        <?php print_r($suggested_definition); ?>
    <?php endforeach; ?>
</ul>