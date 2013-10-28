<form accept-charset="UTF-8" id="dgu-search-form" class="search-area" method="get" action="/data/search">
  <div>
    <div  class="search-area">
      <div data-selector=".auto-height" class="clearfix dgu-equal-height">
        <div class="left">
          <div class="left-inner auto-height form-search">
            <div class="input-group">
                <input type="text" placeholder="Search for datasets..." results="0" value="" name="search_block_form" class="form-control">
                <span class="input-group-btn">
                  <button class="btn btn-default" type="submit">
                    <i class="icon-search"></i>
                  </button>
                </span>
            </div>
          </div>
        </div>
        <div class="right">
          <div class="right-inner auto-height">
            <div class="chevron"></div>
            <?php if($count): ?>
              <div class="result-count"><?php print $count; ?></div>
              <div class="result-count-footer">Datasets</div>
            <?php endif; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
</form>
