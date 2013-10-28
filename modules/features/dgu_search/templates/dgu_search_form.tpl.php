<?php $output = drupal_render_children($form);?>
<div class="search-area" >
  <div class="clearfix dgu-equal-height" data-selector=".auto-height">
    <div class="left">
      <div class="left-inner auto-height form-search">
        <div class="input-group">
        <form action="<?php print $form['#action']?>" method="post" id="<?php print $form['#form_id']?>" >
            <input class="form-control" type="text" name="<?php print $form['search_block_form']['#name'] ?>" value="" results="0" placeholder="Search <?php print $form['content_type']['#value']?>...">
            <span class="input-group-btn">
              <button type="submit" class="btn btn-default">
                <i class="icon-search"></i>
              </button>
            </span>
            <input type="hidden" name="form_build_id" value="<?php print $form['form_build_id']['#value'] ?>">
            <input type="hidden" name="form_id" value="<?php print $form['form_id']['#value'] ?>">
            <input type="hidden" name="form_token" value="<?php print $form['form_token']['#default_value'] ?>">
            <input type="hidden" name="searchtype" value="<?php print $form['searchtype']['#value'] ?>">
          <input type="hidden" name="submit" value="search">
          </form>
        </div>
      </div>
    </div>
    <div class="right">
      <div class="right-inner auto-height">
        <div class="chevron"></div>
        <div class="result-count"><?php print $form['count']['#value']?></div>
        <div class="result-count-footer"><?php print $form['content_type']['#value']?></div>
      </div>
    </div>
  </div>
</div>
