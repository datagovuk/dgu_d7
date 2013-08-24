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
</body>
</html>
