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
                    <li class="nav-blog"><a href="/blog">Blogs</a></li>
                    <li class="nav-forum"><a href="/forum">Forum</a></li>
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

<div class="container content-container">

    <div class="page">
        <?php print $breadcrumb; ?>

        <?php if($page['highlighted'] OR $messages){ ?>
            <div class="drupal-messages">
                <?php print render($page['highlighted']); ?>
                <?php print $messages; ?>
            </div>
        <?php } ?>

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

    <footer role="contentinfo">
        <?php print render($page['footer']); ?>
    </footer>
</div><!--/.content-container-->

