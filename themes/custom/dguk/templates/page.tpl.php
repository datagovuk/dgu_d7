<div id="blackbar">
    <div class="container">
        <div id="hm-government-link" class="retina-img">
            <img src="/assets/img/crown-and-text.png" alt="HM Government" />
        </div>
            <?php if ($logged_in): ?>
              <span class="ckan-logged-in">
                  <div id="login-or-signup">
                      You are logged-in as
                      <a href="/user"><? print $user->name; ?></a>.
                      <a href="/user/logout">Log out</a>.
                  </div>
              </span>
            <? else: ?>
              <span class="ckan-logged-out">
                  <div id="login-or-signup">
                      <a href="/user">Log in</a>
                      or
                      <a href="/user/register">sign up</a>
                  </div>
              </span>
            <? endif; ?>
    </div>
</div>
<div id="greenbar" class="">
    <div class="container">
        <a class="btn btn-inverse visible-phone" data-toggle="collapse" data-target=".main-nav-collapse">
            Nav &nbsp;<i class="icon-chevron-down icon-white"></i>
        </a>
        <a class="brand" href="/" rel="home">
            <div id="dgu-header" class="retina-img">
                <img src="/assets/img/dgu-header-cropped.png" alt="DATA.GOV.UK - Opening up Government" />
            </div>
        </a>
    </div>
    <div class="container">
      <?php print dguk_get_main_menu() ?>
    </div>
</div>

<div class="container content-container">

    <div class="page">
        <?php print $breadcrumb; ?>

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
