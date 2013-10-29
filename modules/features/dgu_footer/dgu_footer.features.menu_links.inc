<?php
/**
 * @file
 * dgu_footer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dgu_footer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer:about
  $menu_links['menu-footer:about'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'About',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 100,
  );
  // Exported menu link: menu-footer:accessibility-statement
  $menu_links['menu-footer:accessibility-statement'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'accessibility-statement',
    'router_path' => 'accessibility-statement',
    'link_title' => 'Accessibility',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
  );
  // Exported menu link: menu-footer:code-conduct
  $menu_links['menu-footer:code-conduct'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'code-conduct',
    'router_path' => 'code-conduct',
    'link_title' => 'Code of conduct',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
  );
  // Exported menu link: menu-footer:contact
  $menu_links['menu-footer:contact'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 7,
  );
  // Exported menu link: menu-footer:cookies-policy
  $menu_links['menu-footer:cookies-policy'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'cookies-policy',
    'router_path' => 'cookies-policy',
    'link_title' => 'Cookies policy',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
  );
  // Exported menu link: menu-footer:faq
  $menu_links['menu-footer:faq'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'faq',
    'router_path' => 'faq',
    'link_title' => 'FAQ',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-footer:moderation-policy
  $menu_links['menu-footer:moderation-policy'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'moderation-policy',
    'router_path' => 'moderation-policy',
    'link_title' => 'Moderation policy',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
  );
  // Exported menu link: menu-footer:privacy
  $menu_links['menu-footer:privacy'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'privacy',
    'router_path' => 'privacy',
    'link_title' => 'Privacy',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
  );
  // Exported menu link: menu-footer:terms-and-conditions
  $menu_links['menu-footer:terms-and-conditions'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'terms-and-conditions',
    'router_path' => 'terms-and-conditions',
    'link_title' => 'Terms and conditions',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Accessibility');
  t('Code of conduct');
  t('Contact');
  t('Cookies policy');
  t('FAQ');
  t('Moderation policy');
  t('Privacy');
  t('Terms and conditions');


  return $menu_links;
}
