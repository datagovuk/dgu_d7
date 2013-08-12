<div id="blackbar">
    <div class="container">
        <div id="hm-government-link" class="retina-img">
            <img src="/assets/img/crown-and-text.png" alt="HM Government" />
        </div>
            <span class="ckan-logged-in" style="display: none;">
                <div id="login-or-signup">
                    You are logged-in as
                    <a href="${'/user' if ('dgu_drupal_auth' in config['ckan.plugins']) else h.url_for(controller='user',action='me')}">${c.userobj.fullname if (c.userobj and c.userobj.fullname) else c.user}</a>.
                    <a href="${'/logout' if ('dgu_drupal_auth' in config['ckan.plugins']) else h.url_for('/data/user/logout')}">Log out</a>.
                </div>
            </span>
            <span class="ckan-logged-out">
                <div id="login-or-signup">
                    <a href="${'/user' if ('dgu_drupal_auth' in config['ckan.plugins']) else h.url_for(controller='user',action='login')}">Log in</a>
                    or
                    <a href="${'/user/register' if ('dgu_drupal_auth' in config['ckan.plugins']) else h.url_for(controller='user',action='register')}">sign up</a>
                </div>
            </span>
    </div>
</div>
<div id="greenbar" class="">
    <div class="container">
        <a class="btn btn-inverse visible-phone" data-toggle="collapse" data-target=".main-nav-collapse">
            Nav &nbsp;<i class="icon-chevron-down icon-white"></i>
        </a>
        <a class="brand" href="#" rel="home">
            <div id="dgu-header" class="retina-img">
                <img src="/assets/img/dgu-header-cropped.png" alt="DATA.GOV.UK - Opening up Government" />
            </div>
        </a>
    </div>
    <div class="container">
        <div class="navbar navbar-inverse">
            <div class="main-nav-collapse">
                <ul id="dgu-nav" class="nav">
                    <li class="nav-home active"><a href="/">Home</a></li>
                    <li class="nav-data"><a href="/data">Data</a></li>
                    <li class="nav-participate"><a href="/participate">Participate</a></li>
                    <li class="nav-data-requests"><a href="/odug">Data Requests</a></li>
                    <li class="nav-apps"><a href="/apps">Apps</a></li>
                    <li class="nav-location"><a href="/location">Location</a></li>
                    <li class="nav-linked-data"><a href="/linked-data">Linked Data</a></li>
                    <li class="nav-library"><a href="/library">Library</a></li>
                    <li class="nav-about"><a href="/about-us">About</a></li>
                </ul>
            </div><!--/.main-nav-collapse -->
        </div>
    </div>
</div>


<header id="navbar" role="banner" class="navbar navbar-fixed-top">
    <div class="navbar-inner">
        <div class="container">
            <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
            <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
            </a>

            <?php if ($logo): ?>
                <a class="logo pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                </a>
            <?php endif; ?>

            <?php if ($site_name): ?>
                <h1 id="site-name">
                    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="brand"><?php print $site_name; ?></a>
                </h1>
            <?php endif; ?>

            <?php if ($primary_nav || $secondary_nav || !empty($page['navigation'])): ?>
                <div class="nav-collapse">
                    <nav role="navigation">
                        <?php if ($primary_nav): ?>
                            <?php print render($primary_nav); ?>
                        <?php endif; ?>
                        <?php if (!empty($page['navigation'])): ?>
                            <?php print render($page['navigation']); ?>
                        <?php endif; ?>
                        <?php if ($secondary_nav): ?>
                            <?php print render($secondary_nav); ?>
                        <?php endif; ?>
                    </nav>
                </div>
            <?php endif; ?>
        </div>
    </div>
</header>

<div class="container">

    <header role="banner" id="page-header">
        <?php if ( $site_slogan ): ?>
            <p class="lead"><?php print $site_slogan; ?></p>
        <?php endif; ?>

        <?php print render($page['header']); ?>
    </header> <!-- /#header -->

    <div class="row">

        <?php if ($page['sidebar_first']): ?>
            <aside class="span3" role="complementary">
                <?php print render($page['sidebar_first']); ?>
            </aside>  <!-- /#sidebar-first -->
        <?php endif; ?>

        <section class="<?php print _bootstrap_content_span($columns); ?>">
            <?php if ($page['highlighted']): ?>
                <div class="highlighted hero-unit"><?php print render($page['highlighted']); ?></div>
            <?php endif; ?>
            <?php if ($breadcrumb): print $breadcrumb; endif;?>
            <a id="main-content"></a>
            <?php print render($title_prefix); ?>
            <?php if ($title): ?>
                <h1 class="page-header"><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?>
            <?php print $messages; ?>
            <?php if ($tabs): ?>
                <?php print render($tabs); ?>
            <?php endif; ?>
            <?php if ($page['help']): ?>
                <div class="well"><?php print render($page['help']); ?></div>
            <?php endif; ?>
            <?php if ($action_links): ?>
                <ul class="action-links"><?php print render($action_links); ?></ul>
            <?php endif; ?>
            <?php print render($page['content']); ?>
        </section>

        <?php if ($page['sidebar_second']): ?>
            <aside class="span3" role="complementary">
                <?php print render($page['sidebar_second']); ?>
            </aside>  <!-- /#sidebar-second -->
        <?php endif; ?>

    </div>
    <footer class="footer container">
        <?php print render($page['footer']); ?>
    </footer>
</div>
