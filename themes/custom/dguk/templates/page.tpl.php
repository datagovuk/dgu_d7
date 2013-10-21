<div id="blackbar">
    <div class="container">
        <a class="brand" href="/" rel="home">
          <!--
            <div id="dgu-header" class="retina-img">
                <img src="/assets/img/dgu-header-cropped.png" alt="DATA.GOV.UK - Opening up Government" />
            </div>
            -->
        </a>
        <div class="chevron position1"></div>
        <nav id="dgu-nav">
          <?php //print dguk_get_main_menu($main_menu);?>
          <a href="/" class="trigger-subnav nav-home">Home</a>
          <a href="/data" class="trigger-subnav nav-data">Data</a>
          <a href="/apps" class="trigger-subnav nav-apps">Apps</a>
          <a href="/blog" class="trigger-subnav nav-interact">Interact</a>
          <div class="nav-search" style="width: 200px;">
            <div class="input-group input-group-sm">
              <input type="text" class="form-control" />
              <span class="input-group-btn">
                <button class="btn btn-primary" type="button"><i class="icon-search"></i></button>
              </span>
            </div>
          </div>
          <?php if ($logged_in): ?>
            <?php print l('<i class="icon-user"></i>', 'admin/workbench', array('query' => drupal_get_destination(), 'attributes' => array('class' => 'nav-user btn btn-primary'), 'html' => TRUE)); ?>
          <?php else: ?>
            <?php print l('<i class="icon-user"></i>', 'user', array('query' => drupal_get_destination(), 'attributes' => array('class' => 'nav-user btn btn-primary'), 'html' => TRUE)); ?>
          <?php endif; ?>
        </nav>
    </div>
</div>
<div id="greenbar" class="">
    <div class="container">
      <?php //print dguk_get_sub_menu() ?>
      <ul class="subnav subnav-data">
        <li><a class="" href="/data/search">Datasets</a></li>
        <li><a class="" href="/data/map-based-search">Map Search</a></li>
        <li><a class="" href="/odug">Data Requests</a></li>
        <li><a class="" href="/publisher">Publishers</a></li>
        <li><a href="/organogram/cabinet-office">Organogram: Public Roles &amp; Salaries</a></li>
        <li><a class="" href="/data/openspending-browse">OpenSpending Browser</a></li>
        <li><a class="" href="/data/openspending-report/index">OpenSpending Reports</a></li>
        <li><a class="" href="/data/site-usage">Site Analytics</a></li>
      </ul>
      <ul class="subnav subnav-apps">
        <li><a href="/apps">Browse Apps</a></li>
        <li><a href="/search/everything/?f[0]=bundle%3Aapps">Search Apps</a></li>
        <li><a href="/node/add/apps">Add Your App</a></li>
      </ul>

      <ul class="subnav subnav-interact">
        <li><a class="" href="/location">Location</a></li>
        <li><a class="" href="/linked-data">Linked Data</a></li>
        <li><a href="/blog">All Blogs</a></li>
        <li><a href="/forum">All Forums</a></li>
      </ul>
    </div>
</div>
<div role="main" id="main-content" class="container">
  <div class="container">
    <?php  print $breadcrumb; ?>
    <?php if($page['highlighted'] OR $messages): ?>
        <div class="drupal-messages">
            <?php print render($page['highlighted']); ?>
            <?php print $messages; ?>
        </div>
    <?php endif; ?>
  </div>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
      <h1><?php print $title; ?></h1>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($action_links): ?>
      <ul class="action-links"><?php print render($action_links); ?></ul>
  <?php endif; ?>

  <?php if (isset($tabs['#primary'][0]) || isset($tabs['#secondary'][0])): ?>
      <nav class="tabs"><?php print render($tabs); ?></nav>
  <?php endif; ?>
  <div class="row">
    <div class="col-md-12">
      <?php print render($page['content_pre']); ?>

      <?php print render($page['content']); ?>

      <?php print render($page['content_post']); ?>
    </div>
  </div>
</div><!--/main-->

        <?php if ($page['sidebar_first']): ?>
            <div class="sidebar-first" id="sidebar1">
                <?php print render($page['sidebar_first']); ?>
            </div>
        <?php endif; ?>

        <?php if ($page['sidebar_second']): ?>
            <div class="sidebar-second" id="sidebar2">
                <?php print render($page['sidebar_second']); ?>
            </div>
        <?php endif; ?>
        <div class="clearfix"></div>
    </div><!--/page-->



</div><!--/.content-container-->

<div class="footer">
  <footer role="contentinfo" class="container">
    <?php
      // Print the combined footer menu.
      print dguk_get_footer_menu();
    ?>
    <?php
      // Print anything else in this region.
      print render($page['footer']);
    ?>
  </footer>
</div> <!-- /footer -->
