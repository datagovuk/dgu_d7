<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
  <head>
    <!-- IE=edge tells IE8 not to be tempted to use IE7 compatibility/quirks modes.
          chrome=IE7 tells IE7 to use the Chrome Frame if available - good for Flex machines.
          Should be the first meta tag in the body. -->
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=IE7" />
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <link rel="stylesheet" href="/assets/css/datagovuk.min.css" />
    <link rel="stylesheet" href="/assets/css/dgu-drupal.min.css" />
    <script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.3/jquery.min.js"></script>
    <script>
      //<![CDATA[
      window.jQuery || document.write('<script src="/assets/js/jquery-1.8.3.min.js"><\/script>')
      // ]]>
    </script>
    <script src="/assets/js/vendor.min.js"></script>
    <script src="/assets/js/dgu-drupal.min.js"></script>
    <script src="/assets/js/dgu-shared.min.js"></script>
    <?php print $scripts; ?>
    <!-- HTML5 element support for IE6-8 -->
    <!--[if lt IE 9]>
    <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->
    <!-- IE hacks -->
    <!-- font-awesome ie7 shim -->
    <!--[if IE 7]>
      <link rel="stylesheet" media="all" href="/assets/css/font-awesome-ie7.min.css" />
    <![endif]-->
    <!--[if lt IE 9]>
      <link href="/assets/css/dgu-ie7.css" rel="stylesheet" />
    <![endif]-->
  </head>
  <body class="<?php print $classes; ?>" <?php print $attributes;?>>
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
    <?php print $page_top; //stuff from modules always render first ?>
    <?php print $page; // uses the page.tpl ?>
    <?php print $page_bottom; //stuff from modules always render last ?>
  </body>
</html>
