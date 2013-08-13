<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <link rel="stylesheet" href="/assets/css/datagovuk.min.css" />
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
<div class="footer">
    <footer class="container">
        <ul class="links">
            <li><a href="/faq">FAQ</a></li>
            <li><a href="/moderation-policy">Moderation</a></li>
            <li><a href="/code-conduct">Code of conduct</a></li>
            <li><a href="/accessibility-statement">Accessibility</a></li>
            <li><a href="/cookies-policy">Cookies</a></li>
            <li><a href="/privacy">Privacy</a></li>
            <li><a href="/search/apachesolr_search/transparency%20board%20minutes">Transparency Board Minutes</a></li>
            <li><a href="/contact">Contact us</a></li>
            <li><a href="/terms-and-conditions">Terms &amp; Conditions</a></li>
        </ul>
    </footer>
</div> <!-- /footer -->
</body>
</html>
