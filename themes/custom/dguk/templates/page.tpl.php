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
      <?php print dguk_get_sub_menu() ?>
    </div>
</div>
<div class="container">

    <div class="page">
        <?php  print $breadcrumb . $title; //issue #811: breadcrubms are temporarily removed ?>

        <?php if($page['highlighted'] OR $messages): ?>
            <div class="drupal-messages">
                <?php print render($page['highlighted']); ?>
                <?php print $messages; ?>
            </div>
        <?php endif; ?>

        <div role="main" id="main-content">

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

            <?php print render($page['content_pre']); ?>

            <?php print render($page['content']); ?>

            <?php print render($page['content_post']); ?>

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
