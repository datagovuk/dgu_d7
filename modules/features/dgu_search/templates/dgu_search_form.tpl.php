<?php $output = drupal_render_children($form);?>
<div class="search-area" >
  <div class="clearfix dgu-equal-height" data-selector=".auto-height">
    <div class="left">
      <div class="left-inner auto-height form-search">
        <div class="input-group">
        <form action="<?php print $form['#action']?>" method="post" id="<?php print $form['#form_id']?>" >
            <input class="form-control" type="text" name="<?php print $form['search_block_form']['#name'] ?>" value="<?php if(!empty($form['keyword']['#value']))print $form['keyword']['#value']?>" results="0" placeholder="Search <?php print strtolower($form['content_type']['#value']); ?>...">
            <span class="input-group-btn">
              <button type="submit" class="btn btn-default">
                <i class="icon-search"></i>
              </button>
            </span>
            <input type="hidden" name="form_build_id" value="<?php print $form['form_build_id']['#value'] ?>">
            <input type="hidden" name="form_id" value="<?php print $form['form_id']['#value'] ?>">
            <input type="hidden" name="form_token" value="<?php print $form['form_token']['#default_value'] ?>">
            <?php if(!empty($form['f']['#value']))foreach($form['f']['#value'] as $i => $value): ?>
            <input type="hidden" name="f[<?php print $i; ?>]" value="<?php print $value ?>">
            <?php endforeach ?>
            <input type="hidden" name="searchtype" value="<?php print $form['searchtype']['#value'] ?>">
            <input type="hidden" name="solrsort" value="<?php print $form['solrsort']['#value'] ?>">
            <input type="hidden" name="submit" value="search">
          </form>
        </div>
        <?php if ($form['show_counter']['#value']): // Show this text only on landing pages (show_counter is set to true on landing pages) ?>
        <span class="search-all-label">Click search now to see all content in this category</span>
        <?php endif; ?>
      </div>
    </div>
    <?php if ($form['show_counter']['#value']): ?>
    <div class="right">
      <div class="right-inner auto-height">
        <div class="chevron"></div>
        <div class="result-count"><?php print $form['count']['#value']?></div>
        <div class="result-count-footer"><?php print $form['content_type']['#value']?>
        <?php if (isset($form['dataset_request_count']['#value'])): ?>
          <div class="result-private-dataset-request">
          <?php if (user_access('edit any dataset_request content')): ?>
            including
          <?php else: ?>
            +
          <?php endif; ?>
            <?php print$form['dataset_request_count']['#value'] ?> confidential requests</div>
        <?php endif; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>
  </div>
</div>
