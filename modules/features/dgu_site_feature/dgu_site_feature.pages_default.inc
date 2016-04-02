<?php
/**
 * @file
 * dgu_site_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgu_site_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_8';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 8;
  $handler->conf = array(
    'title' => 'About pages',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'page' => 'page',
              'article' => 'article',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'about/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'About';
  $display->uuid = '21795b88-d3db-4869-89ff-f7edbd794a09';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e5cda200-f233-47f5-a8b8-1fd60634df54';
    $pane->panel = 'left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e5cda200-f233-47f5-a8b8-1fd60634df54';
    $display->content['new-e5cda200-f233-47f5-a8b8-1fd60634df54'] = $pane;
    $display->panels['left'][0] = 'new-e5cda200-f233-47f5-a8b8-1fd60634df54';
    $pane = new stdClass();
    $pane->pid = 'new-aa9ebb85-44e8-4cef-960b-de9f59a48b6d';
    $pane->panel = 'right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'what_s_data_gov_uk_all_about_';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'aa9ebb85-44e8-4cef-960b-de9f59a48b6d';
    $display->content['new-aa9ebb85-44e8-4cef-960b-de9f59a48b6d'] = $pane;
    $display->panels['right'][0] = 'new-aa9ebb85-44e8-4cef-960b-de9f59a48b6d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e5cda200-f233-47f5-a8b8-1fd60634df54';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_8'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_site_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'about_us';
  $page->task = 'page';
  $page->admin_title = 'About';
  $page->admin_description = 'About us page.';
  $page->path = 'about/!string';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'About',
    'name' => 'menu-footer',
    'weight' => '100',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'string' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_about_us_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'about_us';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'about-us',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_string_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol';
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
  $display->uuid = 'f46532cb-4095-4c12-8731-5174db7aaae0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bb54077c-a694-4f13-bea5-bff6a08c8583';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p><strong>What&#39;s data.gov.uk all about?</strong></p>

<p>The Government is releasing public data to become more transparent&nbsp;and foster&nbsp;innovation. Some of this data was available before, but data.gov.uk brings it together in one searchable website. Making this data easily available means it will be easier for people to make decisions and suggestions about government policies based on detailed information. Hear more about the Government&#39;s Transparency agenda from the Prime Minister in <a href="https://www.youtube.com/watch?v=0stXV_fWWtU" target="_blank">this video</a>.</p>

<p><strong>What&#39;s available?</strong></p>

<p>There are datasets available from all central government departments and a number of other public sector bodies and local authorities. Is data just public information? Not really. From data.gov.uk, you can access the raw data driving government forward. This can then be used by people to build useful applications that help society, or investigate how effective policy changes have been over time.</p>

<p>General public information - such as how to find out if you are entitled to tax credits, or how to tax your car - can be found at <a href="http://gov.uk/" target="_blank">gov.uk</a>.</p>

<p><strong>How can I use the data?</strong></p>

<p>You can use the data in all sorts of ways. This may be simply to analyse trends over time from one policy area, or to compare how different parts of government go about their work. Technical users will be able to create useful applications out of the raw data files, which can then be used by everyone.</p>

<p><strong>How can I add my organisation&#39;s data?</strong></p>

<p>data.gov.uk provides a mini-site of&nbsp;guidance for publishers, including step-by-step process for including your data on data.gov.uk. Please see:</p>

<p><a href="http://guidance.data.gov.uk/" target="_blank">http://guidance.data.gov.uk/</a></p>

<p><strong style="line-height: 1.6em;">Who is involved in the project?</strong></p>

<p>Data.gov.uk is a key part of the Government&#39;s work on Transparency and Data. The data.gov.uk implementation is being led by the Data team in the Cabinet Office, working across government departments to ensure that data is released in a timely and accessible way.</p>

<p>This work is being supported by Sir Tim-Berners Lee &amp; Professor Nigel Shadbolt. There are a number of technical partners involved in the project to date. These include the <a href="http://ckan.org/" target="_blank">CKAN</a>, which&nbsp;runs the catalogue at data.gov.uk/data as well as a growing number of open data registries around the world. It is a project originally created by the Open Knowledge Foundation to make it easy to find, share and reuse open content and data. The CKAN software provides a web interface, programmer&#39;s API, feeds notifying of changes, and a browsable history of all changes. The API is documented here:&nbsp;<a href="http://data.gov.uk/data/metadata-api-docs">http://data.gov.uk/datametadata-api-docs</a>.</p>

<p><strong>How can I get involved?</strong></p>

<p>There are a number of ways of getting involved in the project, dependent on your background or interest. For example:</p>

<ul>
	<li>Applications: have you built something cool with our data? Share it with us through the Apps page. You never know who might get excited!</li>
	<li>Visualisations: one of the challenges is making data come to life. Have you found a great way of displaying our data? Does it combine with other data to give a new insight? Show us your talent?&nbsp;You can see some of the visualisations create by the data.gov.uk team and the code used to create them&nbsp;<a href="http://data.gov.uk/data/viz/social-investment-and-foundations">here</a> and <a href="http://data.gov.uk/data/viz/investment-readiness-programme">here</a>.</li>
	<li>Comments and feedback: You can provide comments on datasets and blogs&nbsp;as well as give feedback on the potential impact of a&nbsp;dataset.</li>
</ul>

<p><strong>Working with data</strong></p>

<p>If you wish to get involved in working with data you can check<a href="http://data.gov.uk/blog/simple-intro-open-data"> this</a> very brief primer, you can also check out organisations such as the <a href="http://theodi.org/">Open Data Institute</a> and the <a href="https://okfn.org/">Open Knowledge Foundation</a>.</p>

<p>&nbsp;</p>

<p><strong>To find out technical details about the setup of data.gov.uk go <a href="/about/technical-details">here</a>.</strong></p>

<p>&nbsp;</p>
',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bb54077c-a694-4f13-bea5-bff6a08c8583';
    $display->content['new-bb54077c-a694-4f13-bea5-bff6a08c8583'] = $pane;
    $display->panels['left'][0] = 'new-bb54077c-a694-4f13-bea5-bff6a08c8583';
    $pane = new stdClass();
    $pane->pid = 'new-ad015cf4-c2b8-48ba-8de2-02370cd56278';
    $pane->panel = 'right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'what_s_data_gov_uk_all_about_';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ad015cf4-c2b8-48ba-8de2-02370cd56278';
    $display->content['new-ad015cf4-c2b8-48ba-8de2-02370cd56278'] = $pane;
    $display->panels['right'][0] = 'new-ad015cf4-c2b8-48ba-8de2-02370cd56278';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bb54077c-a694-4f13-bea5-bff6a08c8583';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about_us'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'data';
  $page->task = 'page';
  $page->admin_title = 'Data';
  $page->admin_description = 'Place holder for CKAN data page ';
  $page->path = 'data';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Data',
    'name' => 'main-menu',
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
  $handler->name = 'page_data_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'data';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'data',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol';
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
  $display->uuid = 'e921f861-ba2a-483d-9451-0967e85e5c23';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5bcf3084-fd72-4845-b918-89f31ff9ef49';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'ckan_datasets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '50',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'ckan_dataset_admin_page',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5bcf3084-fd72-4845-b918-89f31ff9ef49';
    $display->content['new-5bcf3084-fd72-4845-b918-89f31ff9ef49'] = $pane;
    $display->panels['left'][0] = 'new-5bcf3084-fd72-4845-b918-89f31ff9ef49';
    $pane = new stdClass();
    $pane->pid = 'new-93e3243c-a6ce-4b52-b243-c48c083f7dd5';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'ckan_publishers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '50',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'ckan_publisher_admin_page',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '93e3243c-a6ce-4b52-b243-c48c083f7dd5';
    $display->content['new-93e3243c-a6ce-4b52-b243-c48c083f7dd5'] = $pane;
    $display->panels['left'][1] = 'new-93e3243c-a6ce-4b52-b243-c48c083f7dd5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5bcf3084-fd72-4845-b918-89f31ff9ef49';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['data'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'help';
  $page->task = 'page';
  $page->admin_title = 'Help';
  $page->admin_description = 'Help page with interactive site tours. ';
  $page->path = 'help';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Help',
    'name' => 'management',
    'weight' => '1000',
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
  $handler->name = 'page_help_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'help';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'help-page',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol_stacked_50_50';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Help';
  $display->uuid = 'cf391d27-73f0-4519-8ad1-3775778a9209';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-125d7a0e-f836-4b36-8ef1-210847b57424';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Follow the links on the right hand side to start a guided tutorial for our site.</p>
',
      'format' => 'filtered_html',
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
    $pane->uuid = '125d7a0e-f836-4b36-8ef1-210847b57424';
    $display->content['new-125d7a0e-f836-4b36-8ef1-210847b57424'] = $pane;
    $display->panels['left'][0] = 'new-125d7a0e-f836-4b36-8ef1-210847b57424';
    $pane = new stdClass();
    $pane->pid = 'new-7cccb247-7388-4957-9844-aec7611eb523';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'dgu_user-dgu_user_help';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7cccb247-7388-4957-9844-aec7611eb523';
    $display->content['new-7cccb247-7388-4957-9844-aec7611eb523'] = $pane;
    $display->panels['right'][0] = 'new-7cccb247-7388-4957-9844-aec7611eb523';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7cccb247-7388-4957-9844-aec7611eb523';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['help'] = $page;

  return $pages;

}
