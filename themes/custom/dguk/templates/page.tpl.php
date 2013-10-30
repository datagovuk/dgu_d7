<div id="blackbar">
    <div class="container">
        <a class="brand" href="/" rel="home">
          <!--
            <div id="dgu-header" class="retina-img">
                <img src="/assets/img/dgu-header-cropped.png" alt="DATA.GOV.UK - Opening up Government" />
            </div>
            -->
        </a>

        <?php
          // $main_menu is set to menu-interact and $secondary_menu is set to menu-apps
          // otherwise context doesn't work
          $interact_menu = dguk_get_interact_menu($main_menu);
          $apps_menu = dguk_get_apps_menu($secondary_menu);
          $active = 1;
          if(strpos($apps_menu, 'subnav-apps active')) {
            $active = 3;
          }
          if(strpos($interact_menu, 'subnav-interact active')) {
            $active = 4;
          }
        ?>

      <div class="chevron position<?php print $active;?>"></div>
        <nav id="dgu-nav">
          <?php //print dguk_get_main_menu($main_menu);?>

          <a href="/" title="" class="trigger-subnav nav-home <?php if($active == 1) print 'active'; ?>">Home</a>
          <a href="/data" class="trigger-subnav nav-data <?php if($active == 2) print 'active'; ?>">Data</a>
          <a href="/apps" class="trigger-subnav nav-apps <?php if($active == 3) print 'active'; ?>">Apps</a>
          <a href="/interact" class="trigger-subnav nav-interact <?php if($active == 4) print 'active'; ?>">Interact</a>


          <div class="nav-search" style="width: 200px;">
            <div class="input-group input-group-sm">
              <input type="text" class="form-control" />
              <span class="input-group-btn">
                <button class="btn-default btn btn-primary" type="button"><i class="icon-search"></i></button>
              </span>
            </div>
          </div>
          <?php if ($logged_in): ?>
            <?php print l('<i class="icon-user"></i>', 'admin/workbench', array('query' => drupal_get_destination(), 'attributes' => array('class' => array('nav-user', 'btn-default', 'btn', 'btn-primary')), 'html' => TRUE)); ?>
          <?php else: ?>
            <?php print l('<i class="icon-user"></i>', 'user', array('query' => drupal_get_destination(), 'attributes' => array('class' => array('nav-user', 'btn-default', 'btn', 'btn-primary')), 'html' => TRUE)); ?>
          <?php endif; ?>
        </nav>
    </div>
</div>
<div id="greenbar" class="">
    <div class="container">
      <ul class="subnav subnav-data">
        <li><a class="active" href="/data/search">Datasets</a></li>
        <li><a class="" href="/data/map-based-search">Map Search</a></li>
        <li><a class="" href="/odug">Data Requests</a></li>
        <li><a class="" href="/publisher">Publishers</a></li>
        <li><a href="/organogram/cabinet-office">Public Roles &amp; Salaries</a></li>
        <li><a class="" href="/data/openspending-browse">OpenSpending</a></li>
        <li><a class="" href="/data/openspending-report/index">Spend Reports</a></li>
        <li><a class="" href="/data/site-usage">Site Analytics</a></li>
      </ul>
      <?php print $apps_menu; ?>
      <?php print $interact_menu; ?>
    </div>
</div>
<div id="pre-content">
  <div class="container">
    <div class="row">
      <div class="col-md-12">
        <?php  print $breadcrumb; ?>
      </div>
    </div>
  </div>
</div>
<div role="main" id="main-content">
  <div class="container">
    <?php if($page['highlighted'] OR $messages): ?>
        <div class="drupal-messages">
            <?php print render($page['highlighted']); ?>
            <?php print $messages; ?>
        </div>
    <?php endif; ?>
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