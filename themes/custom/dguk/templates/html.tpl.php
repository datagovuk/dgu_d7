<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <link rel="stylesheet" href="/assets/css/datagovuk.min.css" />
    <script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.3/jquery.min.js"></script>
    <script>window.jQuery || document.write('<script src="/assets/js/jquery-1.8.3.min.js"><\/script>')</script>
    <script src="/assets/js/vendor.min.js"></script>
    <?php print $scripts; ?>
    <!-- HTML5 element support for IE6-8 -->
    <!--[if lt IE 9]>
    <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
    <![endif]-->
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
<a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
<?php print $page_top; //stuff from modules always render first ?>
<?php print $page; // uses the page.tpl ?>
<?php print $page_bottom; //stuff from modules always render last ?>

<!-- Drupal class shim  ::  TODO update core Drupal install to set these correctly -->
<script>
  window.$ = window.jQuery;
  $(function() {
    $('.page').addClass('row-fluid');
    $('#main-content').addClass('span9');
    $('#sidebar1').addClass('span3');
    $('.breadcrumb').remove();

    $('#main-content > article').addClass('boxed');

    $('.panel-2col .panel-col-first').addClass('span8').removeClass('panel-col-first');
    $('.panel-2col .panel-col-last').addClass('span4').removeClass('panel-col-last');
    $('.panel-2col').addClass('row-fluid').removeClass('panel-2col');

    $('.panel-3col-33 .panel-col-first').addClass('span4').removeClass('panel-col-first');
    $('.panel-3col-33 .panel-col').addClass('span4').removeClass('panel-col');
    $('.panel-3col-33 .panel-col-last').addClass('span4').removeClass('panel-col-last');
    $('.panel-3col-33').addClass('row-fluid').removeClass('panel-3col-33');

  });
</script>

</body>
</html>
