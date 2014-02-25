<?php
  global $user;
  if (in_array('data publisher', array_values($user->roles))) {
    $user = user_load($user->uid);
  }
?>

<div id="blackbar" class="<?php print ($user->uid == 1 || in_array('data publisher', array_values($user->roles))) ? 'with' : 'without' ?>-publisher">
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
          $data_menu = dguk_get_data_menu();
          $apps_menu = dguk_get_apps_menu($secondary_menu);
          $interact_menu = dguk_get_interact_menu($main_menu);
          $active = 1;
          if(strpos($data_menu, 'subnav-data active')) {
            $active = 2;
          }
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
          <div class="text-links">
            <a href="/" title="" class="trigger-subnav nav-home <?php if($active == 1) print 'active'; ?>">Home</a>
            <a href="/data" class="trigger-subnav nav-data <?php if($active == 2) print 'active'; ?>">Data</a>
            <a href="/apps" class="trigger-subnav nav-apps <?php if($active == 3) print 'active'; ?>">Apps</a>
            <a href="/interact" class="trigger-subnav nav-interact <?php if($active == 4) print 'active'; ?>">Interact</a>
          </div>
          <div class="nav-search" style="width: 200px;">
            <form class="input-group input-group-sm" action="/data/search">
              <input type="text" class="form-control" name="q" placeholder="Search for data...">
              <span class="input-group-btn">
                <button type="submit" class="btn btn-primary"><i class="icon-search"></i></button>
              </span>
            </form>
          </div>
          <?php if ($logged_in): ?>
            <span class="dropdown">
              <a class="nav-user btn btn-primary dropdown-button" data-toggle="dropdown" href="#"><i class="icon-user"></i></a>
              <ul class="dropdown-menu dgu-user-dropdown" role="menu" aria-labelledby="dLabel">
                <li><a href="/admin/workbench"><i class="icon-user"></i>&nbsp; <?php print $user->name?>'s profile</a></li>
                <li><a href="/user/logout"><i class="icon-signout"></i>&nbsp; Log out</a></li>
              </ul>
            </span>
          <?php else: ?>
            <?php print l('<i class="icon-user"></i>', 'user', array('query' => drupal_get_destination(), 'attributes' => array('class' => array('nav-user', 'btn-default', 'btn', 'btn-primary')), 'html' => TRUE)); ?>
          <?php endif; ?>

          <?php if ($user->uid == 1 || in_array('data publisher', array_values($user->roles))): ?>
            <span class="dropdown">
              <a class="nav-publisher btn btn-info dropdown-button" data-toggle="dropdown" href="#"><i class="icon-lock"></i></a>
              <ul class="dropdown-menu dgu-user-dropdown" role="menu" aria-labelledby="dLabel">
                <li role="presentation" class="dropdown-header">Tools</li>
                <li><a href="/dataset/new">Add a Dataset</a></li>
                <li><a href="/harvest">Dataset Harvesting</a></li>
                <li role="presentation" class="dropdown-header">My publishers</li>
                <?php if (!empty($user->field_publishers)) foreach ($user->field_publishers[LANGUAGE_NONE] as $publisher_ref): ?>

                  <?php $publisher = entity_load_single('ckan_publisher', $publisher_ref['target_id']); ?>

                  <li><a href="/publisher/<?php print $publisher->name?>"><?php print $publisher->title?></a></li>
                <?php endforeach; ?>
              </ul>
            </span>
          <?php endif; ?>


        </nav>
    </div>
</div>
<div id="greenbar" class="">
    <div class="container">
      <?php print $data_menu; ?>
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
    <div class="drupal-messages">
        <?php if($page['highlighted']): ?>
          <?php print render($page['highlighted']); ?>
        <?php endif; ?>
        <?php if($messages): ?>
          <div id="messages" ><?php print $messages; ?></div>
        <?php endif; ?>
    </div>
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
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
