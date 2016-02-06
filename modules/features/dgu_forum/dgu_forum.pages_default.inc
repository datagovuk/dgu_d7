<?php
/**
 * @file
 * dgu_forum.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgu_forum_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Forum topic',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'node-forum',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'forum' => 'forum',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
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
  $display->title = 'Forum';
  $display->uuid = '39ee9f12-dafd-444f-bdd4-f1a2cb892c43';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-13a5e1e5-e7d5-4c73-a330-7c0f0f8f7bcf';
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
    $pane->uuid = '13a5e1e5-e7d5-4c73-a330-7c0f0f8f7bcf';
    $display->content['new-13a5e1e5-e7d5-4c73-a330-7c0f0f8f7bcf'] = $pane;
    $display->panels['left'][0] = 'new-13a5e1e5-e7d5-4c73-a330-7c0f0f8f7bcf';
    $pane = new stdClass();
    $pane->pid = 'new-b96242b6-534c-4b38-b45e-ef4162bb4cc7';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'forum_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
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
    $pane->uuid = 'b96242b6-534c-4b38-b45e-ef4162bb4cc7';
    $display->content['new-b96242b6-534c-4b38-b45e-ef4162bb4cc7'] = $pane;
    $display->panels['right'][0] = 'new-b96242b6-534c-4b38-b45e-ef4162bb4cc7';
    $pane = new stdClass();
    $pane->pid = 'new-6cec87a2-e3de-4fed-a92f-3aac8446eee4';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'dgu_search-searchforum';
    $pane->shown = FALSE;
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6cec87a2-e3de-4fed-a92f-3aac8446eee4';
    $display->content['new-6cec87a2-e3de-4fed-a92f-3aac8446eee4'] = $pane;
    $display->panels['right'][1] = 'new-6cec87a2-e3de-4fed-a92f-3aac8446eee4';
    $pane = new stdClass();
    $pane->pid = 'new-17ff89c2-6778-4229-bb26-3c299fafcdca';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'apachesolr_search-mlt-001';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '17ff89c2-6778-4229-bb26-3c299fafcdca';
    $display->content['new-17ff89c2-6778-4229-bb26-3c299fafcdca'] = $pane;
    $display->panels['right'][2] = 'new-17ff89c2-6778-4229-bb26-3c299fafcdca';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-13a5e1e5-e7d5-4c73-a330-7c0f0f8f7bcf';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_forum_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'forum_categories';
  $page->task = 'page';
  $page->admin_title = 'Forum categories';
  $page->admin_description = 'Forum categories - top level forum landing page';
  $page->path = 'forum/categories';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Forum categories',
    'name' => 'main-menu',
    'weight' => '4',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Forum',
      'name' => 'main-menu',
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
  $handler->name = 'page_forum_categories_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'forum_categories';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'forum',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Forum';
  $display->uuid = '2db7a2ae-16e0-45d7-831b-6de21c27f6ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7af225f6-ec2b-46e6-9208-21c762ccb9cb';
    $pane->panel = 'middle';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'forum',
      'override_title' => 0,
      'override_title_text' => '',
      'show_counter' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7af225f6-ec2b-46e6-9208-21c762ccb9cb';
    $display->content['new-7af225f6-ec2b-46e6-9208-21c762ccb9cb'] = $pane;
    $display->panels['middle'][0] = 'new-7af225f6-ec2b-46e6-9208-21c762ccb9cb';
    $pane = new stdClass();
    $pane->pid = 'new-2e6a2d58-ceb9-4094-a30f-dc888ee93271';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-forum-tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'menu-tabs',
      'css_class' => 'tabs',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2e6a2d58-ceb9-4094-a30f-dc888ee93271';
    $display->content['new-2e6a2d58-ceb9-4094-a30f-dc888ee93271'] = $pane;
    $display->panels['middle'][1] = 'new-2e6a2d58-ceb9-4094-a30f-dc888ee93271';
    $pane = new stdClass();
    $pane->pid = 'new-3caebd32-3340-42bb-8226-2bfc247ba8d9';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'forum_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'forum_categories_block',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3caebd32-3340-42bb-8226-2bfc247ba8d9';
    $display->content['new-3caebd32-3340-42bb-8226-2bfc247ba8d9'] = $pane;
    $display->panels['middle'][2] = 'new-3caebd32-3340-42bb-8226-2bfc247ba8d9';
    $pane = new stdClass();
    $pane->pid = 'new-87d45a44-080e-4365-8e96-086405d572f1';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Login to take part in forums (for anonymous users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/user/login?destination=/forum">Login to take part in forums &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '87d45a44-080e-4365-8e96-086405d572f1';
    $display->content['new-87d45a44-080e-4365-8e96-086405d572f1'] = $pane;
    $display->panels['middle'][3] = 'new-87d45a44-080e-4365-8e96-086405d572f1';
    $pane = new stdClass();
    $pane->pid = 'new-0f0b0307-88c8-4820-a462-5bfa8040021c';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create forum content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Create new forum topic (for authenticated users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/node/add/forum">Create new forum topic &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '0f0b0307-88c8-4820-a462-5bfa8040021c';
    $display->content['new-0f0b0307-88c8-4820-a462-5bfa8040021c'] = $pane;
    $display->panels['middle'][4] = 'new-0f0b0307-88c8-4820-a462-5bfa8040021c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['forum_categories'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'forum_topics';
  $page->task = 'page';
  $page->admin_title = 'Forum topics';
  $page->admin_description = 'Forum topics in category';
  $page->path = 'forum/%term';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'term' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'term',
        'vids' => array(
          7 => '7',
          1 => 0,
          2 => 0,
          8 => 0,
          3 => 0,
          4 => 0,
          5 => 0,
          6 => 0,
        ),
        'breadcrumb' => 0,
        'transform' => 1,
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
  $handler->name = 'page_forum_topics_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'forum_topics';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'forum-category',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Forum';
  $display->uuid = '732c2569-b0f3-4eeb-9bf5-8bc8fab5a1ec';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-151ed439-636f-4e6b-9aa5-774839640888';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create forum content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Create new forum topic (for authenticated users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/node/add/forum">Create new forum topic »</a></p>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '151ed439-636f-4e6b-9aa5-774839640888';
    $display->content['new-151ed439-636f-4e6b-9aa5-774839640888'] = $pane;
    $display->panels['bottom'][0] = 'new-151ed439-636f-4e6b-9aa5-774839640888';
    $pane = new stdClass();
    $pane->pid = 'new-155b241f-5213-4b02-8d05-c7fff627a2df';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Login to take part in forums (for anonymous users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/user/login?destination=/forum">Login to take part in forums »</a></p>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '155b241f-5213-4b02-8d05-c7fff627a2df';
    $display->content['new-155b241f-5213-4b02-8d05-c7fff627a2df'] = $pane;
    $display->panels['bottom'][1] = 'new-155b241f-5213-4b02-8d05-c7fff627a2df';
    $pane = new stdClass();
    $pane->pid = 'new-5b1f0e83-a101-4a76-8817-26dbb08a6ef1';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'forum_topics-panel_pane_category_forum';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5b1f0e83-a101-4a76-8817-26dbb08a6ef1';
    $display->content['new-5b1f0e83-a101-4a76-8817-26dbb08a6ef1'] = $pane;
    $display->panels['left'][0] = 'new-5b1f0e83-a101-4a76-8817-26dbb08a6ef1';
    $pane = new stdClass();
    $pane->pid = 'new-b0770569-e2b7-4103-a7ac-e5f7d1416046';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'forum_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
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
    $pane->uuid = 'b0770569-e2b7-4103-a7ac-e5f7d1416046';
    $display->content['new-b0770569-e2b7-4103-a7ac-e5f7d1416046'] = $pane;
    $display->panels['right'][0] = 'new-b0770569-e2b7-4103-a7ac-e5f7d1416046';
    $pane = new stdClass();
    $pane->pid = 'new-b9a14eb3-0ba7-4784-8d29-2edd5359418f';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'dgu_search-searchforum';
    $pane->shown = FALSE;
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b9a14eb3-0ba7-4784-8d29-2edd5359418f';
    $display->content['new-b9a14eb3-0ba7-4784-8d29-2edd5359418f'] = $pane;
    $display->panels['right'][1] = 'new-b9a14eb3-0ba7-4784-8d29-2edd5359418f';
    $pane = new stdClass();
    $pane->pid = 'new-66eb1ade-93bb-43f8-83cc-1b813287c9cb';
    $pane->panel = 'top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'forum',
      'override_title' => 0,
      'override_title_text' => '',
      'show_counter' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '66eb1ade-93bb-43f8-83cc-1b813287c9cb';
    $display->content['new-66eb1ade-93bb-43f8-83cc-1b813287c9cb'] = $pane;
    $display->panels['top'][0] = 'new-66eb1ade-93bb-43f8-83cc-1b813287c9cb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['forum_topics'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'latest_forum_topics_';
  $page->task = 'page';
  $page->admin_title = 'Latest forum topics';
  $page->admin_description = 'Forum topics - top level forum landing page';
  $page->path = 'forum';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Forum',
    'name' => 'main-menu',
    'weight' => '4',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Forum',
      'name' => 'main-menu',
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
  $handler->name = 'page_latest_forum_topics__panel_context';
  $handler->task = 'page';
  $handler->subtask = 'latest_forum_topics_';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'forum',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Forum';
  $display->uuid = 'dadd3b68-5af4-4a4f-a18c-9cbfb8ab57f5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8e25c8b7-36bc-4eb3-91dd-2a559afd3f4c';
    $pane->panel = 'middle';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'forum',
      'override_title' => 0,
      'override_title_text' => '',
      'show_counter' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8e25c8b7-36bc-4eb3-91dd-2a559afd3f4c';
    $display->content['new-8e25c8b7-36bc-4eb3-91dd-2a559afd3f4c'] = $pane;
    $display->panels['middle'][0] = 'new-8e25c8b7-36bc-4eb3-91dd-2a559afd3f4c';
    $pane = new stdClass();
    $pane->pid = 'new-2dc99d3f-4b3f-46e6-96c0-a18a564cd817';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-forum-tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'menu-tabs',
      'css_class' => 'tabs',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2dc99d3f-4b3f-46e6-96c0-a18a564cd817';
    $display->content['new-2dc99d3f-4b3f-46e6-96c0-a18a564cd817'] = $pane;
    $display->panels['middle'][1] = 'new-2dc99d3f-4b3f-46e6-96c0-a18a564cd817';
    $pane = new stdClass();
    $pane->pid = 'new-72313024-ec90-47d0-aa8f-7a68c4babba7';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'forum_topics-panel_pane_latest_forum';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '72313024-ec90-47d0-aa8f-7a68c4babba7';
    $display->content['new-72313024-ec90-47d0-aa8f-7a68c4babba7'] = $pane;
    $display->panels['middle'][2] = 'new-72313024-ec90-47d0-aa8f-7a68c4babba7';
    $pane = new stdClass();
    $pane->pid = 'new-bf9946d8-3eae-4113-8f58-50d791078c74';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create forum content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Create new forum topic (for authenticated users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/node/add/forum">Create new forum topic &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'bf9946d8-3eae-4113-8f58-50d791078c74';
    $display->content['new-bf9946d8-3eae-4113-8f58-50d791078c74'] = $pane;
    $display->panels['middle'][3] = 'new-bf9946d8-3eae-4113-8f58-50d791078c74';
    $pane = new stdClass();
    $pane->pid = 'new-fd78fe99-a753-44dc-bc29-91609b3b8be2';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Login to take part in forums (for anonymous users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/user/login?destination=/forum">Login to take part in forums &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'fd78fe99-a753-44dc-bc29-91609b3b8be2';
    $display->content['new-fd78fe99-a753-44dc-bc29-91609b3b8be2'] = $pane;
    $display->panels['middle'][4] = 'new-fd78fe99-a753-44dc-bc29-91609b3b8be2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['latest_forum_topics_'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'most_popular_topics';
  $page->task = 'page';
  $page->admin_title = 'Most popular topics';
  $page->admin_description = 'Forum topics - top level forum landing page';
  $page->path = 'forum/popular';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Latest forum topics',
    'name' => 'main-menu',
    'weight' => '4',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Forum',
      'name' => 'main-menu',
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
  $handler->name = 'page_most_popular_topics_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'most_popular_topics';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'forum',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'dgu_onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Forum';
  $display->uuid = 'ae759d77-a812-4fb5-a9f8-6eb5e0d73484';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3dc37456-8860-478a-a42b-37e565312fed';
    $pane->panel = 'middle';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'forum',
      'override_title' => 0,
      'override_title_text' => '',
      'show_counter' => '1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3dc37456-8860-478a-a42b-37e565312fed';
    $display->content['new-3dc37456-8860-478a-a42b-37e565312fed'] = $pane;
    $display->panels['middle'][0] = 'new-3dc37456-8860-478a-a42b-37e565312fed';
    $pane = new stdClass();
    $pane->pid = 'new-56d4e8a8-21b5-4ec2-83e9-41066208a325';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-forum-tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'menu-tabs',
      'css_class' => 'tabs',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '56d4e8a8-21b5-4ec2-83e9-41066208a325';
    $display->content['new-56d4e8a8-21b5-4ec2-83e9-41066208a325'] = $pane;
    $display->panels['middle'][1] = 'new-56d4e8a8-21b5-4ec2-83e9-41066208a325';
    $pane = new stdClass();
    $pane->pid = 'new-187f7bde-6587-439b-8802-dd87d419abf7';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'forum_topics-panel_pane_most_popular_forum';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '187f7bde-6587-439b-8802-dd87d419abf7';
    $display->content['new-187f7bde-6587-439b-8802-dd87d419abf7'] = $pane;
    $display->panels['middle'][2] = 'new-187f7bde-6587-439b-8802-dd87d419abf7';
    $pane = new stdClass();
    $pane->pid = 'new-45fd9497-2247-4917-83f5-e701fc24722d';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create forum content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Create new forum topic (for authenticated users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/node/add/forum">Create new forum topic &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '45fd9497-2247-4917-83f5-e701fc24722d';
    $display->content['new-45fd9497-2247-4917-83f5-e701fc24722d'] = $pane;
    $display->panels['middle'][3] = 'new-45fd9497-2247-4917-83f5-e701fc24722d';
    $pane = new stdClass();
    $pane->pid = 'new-eaa21a77-c7b5-4d62-aa75-634fb15c234b';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Login to take part in forums (for anonymous users)',
      'title' => '',
      'body' => '<p class="text-center"><a href="/user/login?destination=/forum">Login to take part in forums &raquo;</a></p>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'unboxed',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'eaa21a77-c7b5-4d62-aa75-634fb15c234b';
    $display->content['new-eaa21a77-c7b5-4d62-aa75-634fb15c234b'] = $pane;
    $display->panels['middle'][4] = 'new-eaa21a77-c7b5-4d62-aa75-634fb15c234b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['most_popular_topics'] = $page;

  return $pages;

}
