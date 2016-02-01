<?php
/**
 * @file
 * dgu_blog.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dgu_blog_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Blog entry',
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
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'blog' => 'blog',
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
  $display->title = 'Blogs';
  $display->uuid = '13e9b250-e74d-4d6e-84bb-c5e35782a285';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-20f6ddf3-a910-46a2-b1a3-a3f3f0aabf71';
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
    $pane->uuid = '20f6ddf3-a910-46a2-b1a3-a3f3f0aabf71';
    $display->content['new-20f6ddf3-a910-46a2-b1a3-a3f3f0aabf71'] = $pane;
    $display->panels['left'][0] = 'new-20f6ddf3-a910-46a2-b1a3-a3f3f0aabf71';
    $pane = new stdClass();
    $pane->pid = 'new-d31e4ffb-2822-4f35-8b36-346a25c61906';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'blogs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'blogs_same_author',
      'context' => array(
        0 => '',
        1 => '',
      ),
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
    $pane->uuid = 'd31e4ffb-2822-4f35-8b36-346a25c61906';
    $display->content['new-d31e4ffb-2822-4f35-8b36-346a25c61906'] = $pane;
    $display->panels['right'][0] = 'new-d31e4ffb-2822-4f35-8b36-346a25c61906';
    $pane = new stdClass();
    $pane->pid = 'new-e9a6bce9-49c1-4453-97a8-addc6885e8fb';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e9a6bce9-49c1-4453-97a8-addc6885e8fb';
    $display->content['new-e9a6bce9-49c1-4453-97a8-addc6885e8fb'] = $pane;
    $display->panels['right'][1] = 'new-e9a6bce9-49c1-4453-97a8-addc6885e8fb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dgu_blog_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'blog';
  $page->task = 'page';
  $page->admin_title = 'Blog';
  $page->admin_description = 'Blog landing page';
  $page->path = 'blog';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Blogs',
    'name' => 'main-menu',
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
  $handler->name = 'page_blog_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'blog';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'blog',
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
    ),
  );
  $display->cache = array();
  $display->title = 'Blogs';
  $display->uuid = '5e74926c-9c9e-4b7e-ac0d-2231d42cb080';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8938fa1b-e8ab-47ed-8e2e-96a4dc16f421';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-blog-tabs';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8938fa1b-e8ab-47ed-8e2e-96a4dc16f421';
    $display->content['new-8938fa1b-e8ab-47ed-8e2e-96a4dc16f421'] = $pane;
    $display->panels['left'][0] = 'new-8938fa1b-e8ab-47ed-8e2e-96a4dc16f421';
    $pane = new stdClass();
    $pane->pid = 'new-b28168dc-f187-46d8-88de-7859a426898f';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'blogs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'latest_blog_posts',
      'override_title' => 1,
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
    $pane->uuid = 'b28168dc-f187-46d8-88de-7859a426898f';
    $display->content['new-b28168dc-f187-46d8-88de-7859a426898f'] = $pane;
    $display->panels['left'][1] = 'new-b28168dc-f187-46d8-88de-7859a426898f';
    $pane = new stdClass();
    $pane->pid = 'new-abf033fe-c8d8-49f7-81e0-5ff73be0aa90';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'frequent_bloggers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '15',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'frequent_bloggers',
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
    $pane->uuid = 'abf033fe-c8d8-49f7-81e0-5ff73be0aa90';
    $display->content['new-abf033fe-c8d8-49f7-81e0-5ff73be0aa90'] = $pane;
    $display->panels['right'][0] = 'new-abf033fe-c8d8-49f7-81e0-5ff73be0aa90';
    $pane = new stdClass();
    $pane->pid = 'new-aca88316-eff9-4a6e-abc1-2a3209fb9872';
    $pane->panel = 'top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'blog',
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
    $pane->uuid = 'aca88316-eff9-4a6e-abc1-2a3209fb9872';
    $display->content['new-aca88316-eff9-4a6e-abc1-2a3209fb9872'] = $pane;
    $display->panels['top'][0] = 'new-aca88316-eff9-4a6e-abc1-2a3209fb9872';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['blog'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'most_popular_blog_posts';
  $page->task = 'page';
  $page->admin_title = 'Most popular blog posts';
  $page->admin_description = 'Blog landing page';
  $page->path = 'blog/popular';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Blogs',
    'name' => 'main-menu',
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
  $handler->name = 'page_most_popular_blog_posts_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'most_popular_blog_posts';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'blog',
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
    ),
  );
  $display->cache = array();
  $display->title = 'Blogs';
  $display->uuid = '06e35e93-1e17-4641-a0ed-5aa4ce9e95b4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7a19dbe1-59c7-4056-a1af-85ad43f11783';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-blog-tabs';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7a19dbe1-59c7-4056-a1af-85ad43f11783';
    $display->content['new-7a19dbe1-59c7-4056-a1af-85ad43f11783'] = $pane;
    $display->panels['left'][0] = 'new-7a19dbe1-59c7-4056-a1af-85ad43f11783';
    $pane = new stdClass();
    $pane->pid = 'new-e507a05b-4a76-444e-b10a-d45f10fecb1a';
    $pane->panel = 'left';
    $pane->type = 'views';
    $pane->subtype = 'blogs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '6',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'most_popular_blog_posts',
      'override_title' => 1,
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
    $pane->uuid = 'e507a05b-4a76-444e-b10a-d45f10fecb1a';
    $display->content['new-e507a05b-4a76-444e-b10a-d45f10fecb1a'] = $pane;
    $display->panels['left'][1] = 'new-e507a05b-4a76-444e-b10a-d45f10fecb1a';
    $pane = new stdClass();
    $pane->pid = 'new-0620f32c-3f67-4dd3-94e4-5dbc9e66f8bb';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'frequent_bloggers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '15',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'frequent_bloggers',
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
    $pane->uuid = '0620f32c-3f67-4dd3-94e4-5dbc9e66f8bb';
    $display->content['new-0620f32c-3f67-4dd3-94e4-5dbc9e66f8bb'] = $pane;
    $display->panels['right'][0] = 'new-0620f32c-3f67-4dd3-94e4-5dbc9e66f8bb';
    $pane = new stdClass();
    $pane->pid = 'new-e7bf57b9-1f56-4618-b628-eaa1ab800f1c';
    $pane->panel = 'top';
    $pane->type = 'dgu_search_form';
    $pane->subtype = 'dgu_search_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_override' => NULL,
      'title_override_text' => NULL,
      'content_type' => 'blog',
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
    $pane->uuid = 'e7bf57b9-1f56-4618-b628-eaa1ab800f1c';
    $display->content['new-e7bf57b9-1f56-4618-b628-eaa1ab800f1c'] = $pane;
    $display->panels['top'][0] = 'new-e7bf57b9-1f56-4618-b628-eaa1ab800f1c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['most_popular_blog_posts'] = $page;

  return $pages;

}
