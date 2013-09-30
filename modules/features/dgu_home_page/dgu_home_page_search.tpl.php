<form accept-charset="UTF-8" id="home-page-data-search-form" method="get" action="/data/search">
  <div>
    <div class="count-wrapper">
      <div class="result-count"><?php print $count; ?></div>
      <div class="result-count-footer">Datasets</div>
    </div>

    <div class="form-type-textfield form-item">
      <input type="text" class="form-text" maxlength="128" size="15" value="" name="q" id="home-page-data-search-box" title="Enter the terms you wish to search for." placeholder="search data">
    </div>
    <button type="submit" value="Search" id="edit-submit" class="btn btn-primary form-submit">Search</button>
  </div>
</form>