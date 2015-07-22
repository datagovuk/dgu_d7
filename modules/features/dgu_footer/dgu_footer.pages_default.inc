<?php
/**
 * @file
 * dgu_footer.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_footer_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'accessibility';
  $page->task = 'page';
  $page->admin_title = 'Accessibility';
  $page->admin_description = '';
  $page->path = 'accessibility-statement';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Accessibility',
    'name' => 'menu-footer',
    'weight' => '2',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_accessibility_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'accessibility';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'accessibility',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Data.gov.uk is committed to making this website accessible to all users, regardless of circumstances. We are actively working to increase the accessibility and usability of the site; if you have any questions or suggestions regarding the accessibility of this site, or if you have difficulty using any part of it, please <a href="/contact">contact us</a>.</p><p><strong>Standards compliance</strong> We are working towards ensuring that all pages on this site comply with priority 2 guidelines of the <a href="http://www.w3.org/WAI/intro/wcag.php">W3C Web Content Accessibility Guidelines</a>. Whilst data.gov.uk strives to adhere to the accepted guidelines and standards for accessibility and usability, it is not always possible to do so in all areas of the website. We are continually seeking out solutions that will bring all areas of the site up to the same level of overall accessibility.  <strong>How do I make the text bigger so that it is easier for me to read?</strong> Some users might find screen text easier to read by increasing the size at which text is displayed. To do this you should simply adjust your browser’s settings.</p><ul><li>Using Internet Explorer, go to View &gt; Text size &gt; and select the size you want</li> <li>Using Firefox, go to the View menu, select Zoom and then either Increase Ctrl + +, Decrease Ctrl + – or Normal Ctrl + 0.</li> <li>Using Opera, View &gt; Zoom &gt; and select the size you want</li></ul><p><strong>What are PDFs and how do I read them?</strong> PDF stands for Portable Document File. You need a plug-in called Adobe Acrobat Reader to view these files which you can download for free from <a href="http://www.adobe.com/products/acrobat/readstep.html">Adobe’s website</a>.  Users who have concerns about accessibility should visit <a href="http://access.adobe.com/">Adobe’s accessibility website</a>. Recent versions of Acrobat Reader have a Read Out Loud facility, which can be found under the View menu.  <strong>How can I view a Word file if I don’t have Word software?</strong> A free Word viewer is available from Microsoft at the <a href="http://www.microsoft.com/downloads/search.aspx?displaylang=en&amp;categoryid=9">Microsoft Download Center</a>. You’ll find Word, Excel and PowerPoint viewers here too. Open source versions of similar software can be accessed at http://www.openoffice.org/  <strong>Accessibility software</strong></p> <ol><li><a href="http://www.freedomscientific.com/fs_downloads/jaws.asp">JAWS</a> is a screen reader for Windows. A time-limited, downloadable demo is available.</li> <li><a href="http://lynx.browser.org/">Lynx</a> is a free text-only web browser for blind users with refreshable Braille displays.</li> <li><a href="http://www.opera.com/">Opera</a> is a visual browser with many accessibility-related features, including text zooming, user stylesheets and image toggle. A free downloadable version is available. It is compatible with Windows, Macintosh, Linux, and several other operating systems.</li></ol><p><strong>Accessibility services</strong></p> <ol><li><a href="http://validator.w3.org/">HTML Validator</a> is a free service for checking web pages conform to published HTML standards.</li> <li><a href="http://www.delorie.com/web/wpbcv.html">Web Page Backward Compatibility Viewer</a> is a tool for viewing your web pages without a variety of modern browser features.</li> <li><a href="http://www.delorie.com/web/lynxview.html">Lynx Viewer</a> is a free service for viewing what your web pages would look like in Lynx.</li></ol><p>Please note that these links are placed here only for your convenience only and not as an endorsement of either product or software.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['accessibility'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'code_of_conduct';
  $page->task = 'page';
  $page->admin_title = 'Code of conduct';
  $page->admin_description = '';
  $page->path = 'code-conduct';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Code of conduct',
    'name' => 'menu-footer',
    'weight' => '1',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_code_of_conduct_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'code_of_conduct';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'code-conduct',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>The data is provided to you the developers for you to develop <a href="http://www.data.gov.uk/apps">applications</a> which will make the world a better place, providing more or improved utility for the general public based on public sector datasets. We are here to help you do the great things we know you’re itching to do, but, as part of this being a trusted space in which we work together, there are some basic rules.</p><p>&nbsp;</p> <p>You are <strong>encouraged to:</strong></p> <ul><li>use provided live sources for the datasets as your primary data source, where possible – much of the data provided is dynamic and fluid (although in many cases over an annual or longer period of time), and basing your application on the keys in the data we are providing will ensure that your application is as up to date as possible;</li> <li>where using our data feeds, please if possible cache the data over a short period of time to reduce load both on your application and our servers;</li> <li>where you cannot use our live sources as the primary data source, please still use the keys contained within the data as the primary or foreign keys within your application, as this will enable you to migrate as simply as possible to up-to-date data and information when it is made available;</li> <li>where using your own long-term caches of our data, please refresh the data within your application in a timely manner when a new set of the data is made available;</li> <li>engage with us when something’s wrong – point out any inconsistencies in the data you find, make suggestions about how to improve the service, request new data sources to be added, and tell us about what you have built so we can help you to promote it!</li></ul> <p>You <strong>should:</strong></p> <ul><li>refer back to and cite the origin or source of the data when using it;</li> <li>clearly state where possible about which data is derived from official sources, which is from other sources, and which data is from any calculation within or outwith your app.</li></ul><p>&nbsp;</p> <p>You <strong>must not:</strong></p> <ul><li>make an application that pretends to be an official government service;</li> <li>present the data in a misleading or incorrect manner or to misrepresent or change the data;</li> <li>use this site for party political purposes, as the site paid for with public money so it is not appropriate to engage in party-political activity here;</li> <li>use these materials in or to support a criminal or illicit activity;</li> <li>use these materials on an application to inflame or make comments that are racist, sexist or homophobic, or which promote or incite violence or illegal activity.</li></ul><p><br /> <a name="participation"></a><strong>Participation Guidelines</strong></p> <p>When posting comments about ideas or applications, or posting to the site forum, please observe our site participation guidelines:</p> <ul><li>Be respectful of other users of this site</li> <li>Stay on topic and do not upload content that is unrelated to the purpose of this site. Do not use language that is offensive, inflammatory or provocative (this includes swearing and obscene or vulgar comments)</li> <li>Do not select a user name that is offensive, inflammatory or provocative</li> <li>Do not break the law (this includes libel, condoning illegal activity and contempt of court)</li> <li>In the course of using the community areas of this site, please do not post personal information – addresses, phone numbers, email addresses or other online contact details – relating either to you or other individuals</li> <li>Do not register more than one user account per person</li> <li>Do not impersonate or falsely claim to represent a person or an organisation. Do not attempt to log on using another user’s account</li> <li>Do not make any commercial endorsement or promotion of any product, service or publication not relevant to the discussion</li> <li>Do not post in a language other than English</li></ul> <p>If you are aged 16 or under, please get your parent’s/guardian’s permission before participating. Users without this consent are not allowed to participate or provide us with personal information.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['middle'][0] = 'new-2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['code_of_conduct'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'cookies_policy';
  $page->task = 'page';
  $page->admin_title = 'Cookies policy';
  $page->admin_description = '';
  $page->path = 'cookies-policy';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Cookies policy',
    'name' => 'menu-footer',
    'weight' => '3',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_cookies_policy_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'cookies_policy';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'cookies-policy',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p><strong>Cookies and data.gov.uk</strong><br><br>On data.gov.uk, we are using cookies in order to provide you with specific online services directly related to our remit. You need to accept the terms and conditions the first time you visit the site from your computer in order to access services that require cookies, but information on the specific types of cookies we operate are provided below.<br><br>Why do we use cookies?: Cookies allow the local temporary storage* of details regarding your specific information and preferences when visiting our site, whether it is accessing&nbsp; the data- upload services you need to, or contributing to online debates or forums. There are also cookies that collect information on your site usage in order that we can continually improve our online content provision. We do not however collect data on individual visitors web visits, only summary statistics.<br><br>* The duration of a cookie is set by a website creator but cookies can be deleted locally after web browsing sessions.<br><br>Data.gov.uk follows guidelines set out by the Information Commissioner\'s Office for alerting our site visitors to the presence of cookies.</p><p><br>A list of our cookie types:<br><br><strong>1.Data Publisher Login cookie</strong><br><br>Purpose: This login is for those who publish meta-data on data.gov.uk, if you have these user rights they would have been granted by a nominated person from the relevant government department or agency. You need this cookie enabled at least each time you upload data.<br><br>These cookies are necessary to log in as a Data Publisher. They link to a user account that contains the details provided by the user, which in turn links to the meta-data that is published by a department.These permissions allow the user to make catalogue edits, to access data they have can amend&nbsp; for their particular department only.<br><br>Cookie name: auth_tkt<br><br>Duration of Cookie: 2 years unless you select the option to ‘remember me’ after a browser session.<br><br><strong>2.General login for the ‘Participate’ section</strong><br><br>Purpose: This cookie is necessary to post comments to online forums and blogs and to submit your data ideas to us about apps and data. A user\'s cookie identifies the user against his or her account stored on the data.gov.uk web server. The account contains the details provided by the user and activity in the Social Hub, that are limited to a username, password, email address.<br><br>Cookie name:SESS&lt;hexadecimal code&gt; SSL_SESS&lt;hexademical code&gt;<br><br>Duration of Cookie: 2 days</p><p><strong>3. Map Preview tool</strong><br><br>The map preview tool is for use with web mapping datasets (called WMS datasets or ‘web mapping service datasets’) and allows you to collect datasets in an online basket and then preview these visually with a mapping display tool on the website. A temporary cookie is created from the moment&nbsp; you select a dataset to add&nbsp; to the online basket from a dataset search result listing, to when these are previewed using the mapping tool.<br><br>Cookie name: ckan<br><br>Duration of Cookie: This cookie disappears when you close your browser or empty the dataset list on the search results listing page.<br><br>See the search and preview map tool at: www.data.gov.uk/data/map-based-search<br><br><strong>4. Google analytics</strong><br><br>Purpose: These cookies are used to collect information about how visitors use our site. We use the information to compile internal reports and to help us improve the site. The cookies collect information in an anonymous form, including the number of visitors to the site, where visitors have come to the site from and the pages they visited.<br><br>Find out more about privacy at Google: http://www.google.co.uk/intl/en/analytics/privacyoverview.html<br><br>Cookie names: _utma _utmb _utmc _utmz _unam<br><br>Duration of Cookie: Up to 2 years</p><p><strong>5. CMS settings</strong></p><p>Purpose: These cookies are used to remember display preferences.</p><p>&nbsp;</p><p>Cookie name: Drupal.toolbar.collapsed</p><p>Duration of Cookie: Persistant (100 years)</p><p>&nbsp;</p><p>Cookie name: Drupal.tableDrag.showWeight</p><p>Duration of Cookie: 1 year<br>&nbsp;</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['middle'][0] = 'new-3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['cookies_policy'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'faq';
  $page->task = 'page';
  $page->admin_title = 'FAQ';
  $page->admin_description = '';
  $page->path = 'faq';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'FAQ',
    'name' => 'menu-footer',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_faq_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'faq';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'faq',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>1. <a href="#q1">What is the project doing?</a><br>2. <a href="q2">What is the status of this site?</a><br>3. <a href="#q3">Will personal information be at risk?</a><br>4. <a href="#q4">What is a mashup?</a><br>5. <a href="#q5">What is Linked Data and how does it fit into the Semantic Web?</a><br>6. <a href="#q6">How can people submit applications and visualisations?</a><br>7. <a href="#q8">How can people use data.gov.uk?</a><br>8. <a href="#q9">How were the datasets in data.gov.uk selected?</a><br>9. <a href="#q10">Why is a particular dataset not available yet, and when will it be?</a><br>10. <a href="#q11">Why is a particular dataset not available through an API yet, and when will it be?</a><br>11. <a href="#q12">How can people make contact with the project?</a><br>12. <a href="#q13">Is there a place for developers to discuss ideas, applications and using the data?</a><br>13. <a href="#q14">Will more public data become available in the future?</a><br>14. <a href="#q15">What are the commercial use rights if people have commercial ideas?</a><br>15. <a href="#q16">Under what licence is the data available?</a><br>16. <a href="#q17">Are there any “do”s and “don’t”s?</a></p><p>&nbsp;</p><p>&nbsp;</p><h2><a name="q1"><strong>Q. What is the project doing?</strong></a></h2><p>&nbsp;</p><p>A. The government is opening up its data for other people to re-use. This is only about non-personal, non-sensitive data – information like the list of schools, crime rates or the performance of your council.</p><p>To make sure that we do this properly and work with the web, this work is being overseen by the Transparency Board.</p><p>This preview site is the first step in creating a network of re-useable government data.</p><p>&nbsp;</p><h2><a name="q2"><strong>Q. What is the status of this site?</strong></a></h2><p>&nbsp;</p><p>A. Data.gov.uk launched publicly with a beta version in January 2010. Since then we have launched a number of enhancements which you can read about via the blog. Developments are continuing across the site so do check back regularly and of course please tell us what you <a href="http://www.data.gov.uk/contact">think</a></p><p>&nbsp;</p><h2><a name="q3"><strong>Q. Will personal information be at risk?</strong></a></h2><p>&nbsp;</p><p>A. The data we publish here, and on related websites, will not identify or provide ways to identify individuals, unless that information is already published (like head teachers of schools).</p><p>&nbsp;</p><h2><a name="q4"><strong>Q. What is a mashup?</strong></a></h2><p>&nbsp;</p><p>A. A mashup is a web page or, more usually, a web application that combines data or code from two or more sources. It provides information or functionality beyond that designed or envisaged by the original producers of the data. The attraction of data mashing lies in the ease and speed with which new web applications can be launched with limited resources. People also create visualisations – pictures that show the data in clear, imaginative ways and tell a story about the underlying information.</p><p>For example, a mashup combining data sources such as school addresses and school league tables to display the results using a mapping tool could show where high-achieving schools are. This would be of interest to parents of school-age children who are considering moving house.</p><p>We expect that new and exciting mashups will be the main product of collaboration through this website: be inventive and make things.</p><p>&nbsp;</p><h2><a name="q5"></a><a name="whatisthesemanticweb"><strong>Q. What is Linked Data and how does it fit into the Semantic Web?</strong></a></h2><p>&nbsp;</p><p>A. The Semantic Web is an evolution of the World Wide Web that, rather than just linking from one document to another, focuses on their meaning in relation to each other. Linked Data is a set of technologies to achieve this for data, creating a web of data. You can check progress on our linked data work by visiting the blogs, the<a href="http://data.gov.uk/linked-data"> linked data section</a>&nbsp;or you can follow the <a href="http://@UKGovLD">UK Linked Data Working Group</a> on twitter for up to date news on developments</p><p><span style="line-height:1.538em">While the technical details are complicated, and very well explained by resources like </span><a href="http://www.jenitennison.com/blog/" style="line-height: 1.538em;">Jeni Tennison’s practitioner’s blog</a><span style="line-height:1.538em"> </span><span style="line-height:1.538em">the important thing is how it enables people to exchange links to information and the context for that information. For example, you might point to Bartholomew School, and it will have attributes such as “head teacher”, and be part of the collection “All schools in Oxfordshire”.</span></p><p>&nbsp;</p><h2><a name="q6"><strong>Q. How can people submit applications and visualisations?</strong></a></h2><p>&nbsp;</p><p>A. Go to the <a href="/apps/">Apps page</a>, where you’ll find information on all applications and visualisations that people have submitted so far, a link for submitting your own application and facilities for joining in discussions.</p><p>&nbsp;</p><h2><a name="q8"><strong>Q. How can people use data.gov.uk?</strong></a></h2><p>&nbsp;</p><p>&nbsp;</p><p>A. Data.gov.uk uses a search engine to offer several ways of finding the data you want. You can view all the datasets to see everything that is currently available, or search by keyword, category, themes, file format or department/agency. Each dataset provides guidance on accessing its data.&nbsp;</p><p>&nbsp;</p><h2><a name="q9"><strong>Q. How were the datasets in data.gov.uk selected?</strong></a></h2><p>&nbsp;</p><p>A. Excluding personal and sensitive information, all information created by public sector bodies is, in principle, available for re-use. In the past, different approaches were adopted by local and regional authorities and individual agencies. The government is now widely encouraging all previously inaccessible public information to be made accessible through this website. For more details on what is being prioritised you should have a look at the <a href="http://data.gov.uk/blog/bringing-national-information-infrastructure-life">National Information Infrastructure</a>&nbsp;or check the <a href="http://data.gov.uk/odug">data request section</a>&nbsp;of the site.</p><p>&nbsp;</p><h2><a name="q10"><strong>Q. Why is a particular dataset not available yet, and when will it be?</strong></a></h2><p>&nbsp;</p><p>A. Given the vast volumes of data, it will be some time before everything can be made available. If there are particular datasets that you believe should be made available more quickly, please use the <a href="http://data.gov.uk/odug">data request process</a>.</p><p>You can also see a list of&nbsp;<a href="http://data.gov.uk/data/search?unpublished=true">unpublished datasets</a>,&nbsp;these are datasets that departments know they have but that have not been made public yet.</p><p>&nbsp;</p><h2><a name="q11"><strong>Q. Why is a particular dataset not available through an API yet, and when will it be?</strong></a></h2><p>&nbsp;</p><p>A. The W3C guidance on <a href="http://www.w3.org/TR/gov-data/">opening up government data</a> suggests that data should be published in its original raw format so that it’s available for re-use as soon as possible. Over time, we will covert datasets to use Linked Data standards, including access through a SPARQL end-point; this will provide an API for easy re-use. The site does have catalogue (metadata) APIs and more information can be found <a href="http://data.gov.uk/data/api">here</a>.</p><p>&nbsp;</p><h2><strong><a name="q12"><strong>Q. How can people make contact with the project?</strong></a></strong></h2><p>&nbsp;</p><p>A. We will provide developer community members who register through our Google Group with project updates. You can also follow the <a href="https://twitter.com/DataGovUK" target="_blank">project team on Twitter</a> and by reading the&nbsp;<a href="/blog/">blogs page</a>. To keep up with the latest progress and developments, check the posts on the <a href="/apps">apps page</a> and discussion boards.</p><p>&nbsp;</p><h2><strong><a name="q13"><strong>Q. Is there a place for developers to discuss ideas, applications and using of the data?</strong></a></strong></h2><p>&nbsp;</p><p>A. Yes, the <a href="/forum/">Discussion forum</a> is for that purpose. We realise that you’ll want to ask us and each other questions and we’ll try and help as best we can. There is also a wiki where you can work together to share techniques, ideas, problems and tools, using data from the UK Government and other sources to help people understand and get more from their area, issues of interest, and the world we live in.</p><p>&nbsp;</p><h2><strong><a name="q14"><strong>Q. Will more public data become available in the future?</strong></a></strong></h2><p>&nbsp;</p><p>A. Yes, this is just the start. As the project matures, more data will flow on to the site.</p><p>&nbsp;</p><h2><strong><a name="q15"><strong>Q. What are the commercial use rights if people have commercial ideas?</strong></a></strong></h2><p>&nbsp;</p><p>A. The Open Government Licence enables you to use all our data for commercial purposes. We are delighted that you see a commercial opportunity in using our data.</p><p>&nbsp;</p><h2><strong><a name="q16"><strong>Q. Under what licence is the data available?</strong></a></strong></h2><p>&nbsp;</p><p>A. In general, the data is licensed under the Open Government Licence. You can read more details on what that means on our <a href="/terms-and-conditions/">licence page</a>.</p><p>&nbsp;</p><h2><strong><a name="q17"><strong>Q. Are there any “do”s and “don’t”s?</strong></a></strong></h2><p>&nbsp;</p><p>A. We have a simple <a href="/code-conduct/">code of conduct</a> relating to your use of the data in your application. It covers how to relate your application data to the data we provide, and simple common-sense usage of the data.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['middle'][0] = 'new-4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-4';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faq'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'moderation_policy';
  $page->task = 'page';
  $page->admin_title = 'Moderation policy';
  $page->admin_description = '';
  $page->path = 'moderation-policy';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Moderation policy',
    'name' => 'menu-footer',
    'weight' => '5',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_moderation_policy_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'moderation_policy';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'moderation-policy',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p><strong>Moderation policy</strong></p><p><span>This moderation policy sets out the timescales, methods and terms within which&nbsp;<a href="http://data.gov.uk/" target="_blank">data.gov.uk</a>&nbsp;operates. This ensures that all user generated online content is suitable and in the context&nbsp; of the&nbsp;<a href="http://data.gov.uk/" target="_blank">data.gov.uk</a>&nbsp;service.</span></p><p><strong>Making postings:&nbsp;</strong><span>Comments added to the site by registered, logged-in members will appear on the site without moderation. We use \'Captcha\' software on all our web forms except the login page in order to prevent and reduce the amount of unsolicited postings that some users attempt to upload.</span></p><p><span>We sometimes use moderation management software to aid in the prevention of \'Spam\' appearing on this website and to flag-up unsuitable content.</span></p><p><span>Comments added to the site by unregistered or non logged-in users will not appear until they have been moderated.</span></p><p><span>Ideas and applications submitted are always moderated before appearing on the site within 3- 5 days of being submitted.</span></p><p><strong>Moderation frequency:</strong>&nbsp;The&nbsp;<a href="http://data.gov.uk/" target="_blank">Data.gov.uk</a>. Comments added over the weekend or bank holidays will be moderated on the next available working day.</p><p><strong>Ad-hoc online events:</strong>&nbsp;If there are any \'featured\' online feedback events that require more frequent moderation e.g. an online consultation that occurs within a specific time period; we will make moderation frequency for that speciifc activity.</p><p><strong>Content editing after approval:</strong>The&nbsp;<a href="http://data.gov.uk/" target="_blank">Data.gov.uk</a>&nbsp;Team will occasionally edit submitted content before it appears on the site. This editing is limited to&nbsp; improving clarity of any idea and removing typos, finally optimising any images that accompany an app.</p><p>We will not change the substance or meaning of any contribution.</p><p><strong>Content not published?:</strong>If your submission to the site does not appear on the site, or is removed, it means that the&nbsp;<a href="http://data.gov.uk/" target="_blank">Data.gov.uk</a>&nbsp;team feel that the contribution does not comply with thecode of conduct&nbsp;of the site.</p><p>Where possible and in response to any requests, we will explain why your contribution did not fit with the guidelines, with suggestions of how the content could be re-phrased so that it can appear on the site.</p><p><strong>Send moderation queries by email to:</strong><span>&nbsp;<a href="mailto:team@data.gov.uk" target="_blank">team@data.gov.uk</a></span></p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['middle'][0] = 'new-5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['moderation_policy'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'privacy';
  $page->task = 'page';
  $page->admin_title = 'Privacy';
  $page->admin_description = '';
  $page->path = 'privacy';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Privacy',
    'name' => 'menu-footer',
    'weight' => '4',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_privacy_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'privacy';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'privacy',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p><strong>Your personal data</strong></p> <p>From time to time, you may be asked to submit personal information about yourself (e.g. name and e-mail address) in order to receive or use services on our website. Such services include e-mail updates, website feedback, or suggesting an idea / application.</p> <p>By entering your details in the fields requested, you enable the Crown/Government (Cabinet Office) and its service providers to provide you with the services you select. Any personal information you provide to us will only be used by us, our agents and service providers, and will not be disclosed unless we are obliged or permitted to by law to do so.</p> <p>If you post or send offensive, inappropriate or objectionable content anywhere on this site, we may use whatever information about you is available to us to stop such behaviour.</p> <p>We will hold your personal information on our systems for as long as you use the service you have requested, and remove it in the event that the purpose has been met or when you no longer wish to continue your subscription.</p><p><strong>Accessibility statement</strong></p> <p>This website is run by a team drawn from Cabinet Office, The National Archives and Central Office of Information. It is our intention that the website is usable and accessible to all users. This website\'s objective is to conform to the Guidelines for (UK Government Websites), which supports Web Content Accessibility Guidelines of the World Wide Web Consortium. A full <a href="https://www.data.gov.uk/accessibility-statement">accessibility statement</a> is now available.</p><p><strong>Feedback</strong></p> <p>We very much welcome and actively encourage your feedback on this site. The site is being developed in a phased approach so we encourage you to provide feedback to ensure that future iterations meet your needs. This project is seen by us as a collaborative one between government and yourselves so do get in touch and help shape future direction.</p> <p>We will not pass on any of your personal information when dealing with your enquiry, unless you have given us permission to do so. Once we have replied to you, we keep a record of your message for audit purposes.</p><p><strong>The Data Protection Act</strong></p> <p>Under the Data Protection Act 1998, we have a legal duty to protect any information we collect from you. We use leading technologies and encryption software to safeguard your data, and keep strict security standards to prevent any unauthorised access to it.</p> <p>We will not pass on your personal details to any third party without your permission.</p> <p>If you wish to see our records of any correspondence you have sent to us, or if you have a query or complaint about this privacy policy or about the site, you can contact us using the contact us form.</p><p><strong>Changes to this privacy policy</strong></p> <p>If this privacy policy changes in any way, we will place an updated version on this page. Regularly reviewing this page ensures you are always aware of what information we collect, how we use it and under what circumstances, if any, we will share it with other parties.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['middle'][0] = 'new-6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['privacy'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'terms_and_conditions';
  $page->task = 'page';
  $page->admin_title = 'Terms and conditions';
  $page->admin_description = '';
  $page->path = 'terms-and-conditions';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Terms and conditions',
    'name' => 'menu-footer',
    'weight' => '8',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_terms_and_conditions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'terms_and_conditions';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'terms-and-conditions',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p><img alt="" src="/sites/default/files/ogl-symbol.jpg" style="float:right"></p><p>The data and information available through <a href="http://data.gov.uk">data.gov.uk</a> are available under terms described in the “licence” or "constraints" field of individual dataset records (meta-data). Except where otherwise noted this is the <a href="http://www.nationalarchives.gov.uk/doc/open-government-licence/version/3/" rel="license">Open Government Licence</a>.</p><p>All dataset records (meta-data) published on <a href="http://data.gov.uk/">data.gov.uk</a> are licensed under the <a href="http://www.nationalarchives.gov.uk/doc/open-government-licence/version/3/" rel="license">Open Government Licence</a>.</p><p><strong>Information you submit</strong></p><p>We want the information on this site to be open and as easy to re-use as possible. When you submit information to this site we will work on the basis, unless you clearly state otherwise alongside your work, that you are granting the Crown a non-exclusive, irrevocable right to use and pass on all public information that you submit (for example descriptions of your ideas and screenshots of your apps) as well as the right to allow the re-use of that information. This is so that we can place the contents of this site under the same permissive licence terms as above. Your ideas and applications remain your own.</p><p>The accuracy of information from any third party sites published on data.gov.uk is the responsibility of those sites.</p><p><strong>Traffic limits</strong><br><br>Automatic requesting of the web content is subject to the rules in&nbsp;<a href="http://data.gov.uk/robots.txt" target="_blank">http://data.gov.uk/robots.txt</a>. To maintain a good service for all, API&nbsp;users must ensure that a request is not sent until a response is&nbsp;received for the previous one (i.e. no concurrency), up to a maximum&nbsp;of 5 requests per second. We reserve the right to block users that&nbsp;go outside of these limits.</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['middle'][0] = 'new-7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['terms_and_conditions'] = $page;

  return $pages;

}
