<table class="search-area">
  <tbody><tr>
      <td class="left">
        <div class="count-wrapper">
          <div class="result-count"><?php print $count; ?></div>
          <div class="result-count-footer">Datasets</div>
        </div>
      </td>
      <td class="right">
        <form accept-charset="UTF-8" id="home-page-data-search-form" class="form-search" method="get" action="/data/search">
          <div class="form-type-textfield form-item controls textbox">
            <input type="text" class="form-text" maxlength="128" size="15" value="" name="q" id="home-page-data-search-box" title="Enter the terms you wish to search for." placeholder="search data">
          </div>
          <button type="submit" value="Search" id="edit-submit" class="btn btn-primary form-submit">Search</button>
        </form>
      </td>
    </tr>
</table>
