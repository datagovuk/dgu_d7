<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
?>
<div class="profile clearfix"<?php print $attributes; ?>>
  <div class="avatar"><?php print render($user_profile['field_avatar']); ?></div>
  <div class="col-md-10 col-md-offset-2 col-sm-9 col-sm-offset-3">
      <dl class="clearfix">
        <dt><?php print t('First name'); ?></dt>
        <dd><?php print $first_name; ?></dd>
      </dl>
      <dl class="clearfix">
        <dt><?php print t('Surname'); ?></dt>
        <dd><?php print $surname; ?></dd>
      </dl>
    <?php if (user_access('moderate glossary')): ?>
      <dl class="clearfix">
        <dt><?php print t('Email'); ?></dt>
        <dd><?php print $user->mail; ?></dd>
      </dl>
    <?php endif; ?>
    <?php if($bio): ?>
      <dl class="clearfix">
        <dt><?php print t('Bio'); ?></dt>
        <dd><?php print $bio; ?></dd>
      </dl>
    <?php endif; ?>
      <dl class="clearfix">
        <dt><?php print t('History'); ?></dt>
        <dd><?php print t('Member for ') . render($user_profile['summary']['member_for']['#markup']); ?></dd>
      </dl>
    <?php if($twitter): ?>
      <dl class="clearfix">
        <dt><?php print t('Twitter'); ?></dt>
        <dd><?php print l('@' . $twitter, 'http://twitter.com/' . $twitter); ?></dd>
      </dl>
    <?php endif; ?>
    <?php if($job_title): ?>
      <dl class="clearfix">
        <dt><?php print t('Job title'); ?></dt>
        <dd><?php print $job_title; ?></dd>
      </dl>
    <?php endif; ?>
    <?php if($linkedin): ?>
      <dl class="clearfix">
        <dt><?php print t('LinkedIn'); ?></dt>
        <dd><?php print l($linkedin, $linkedin); ?></dd>
      </dl>
    <?php endif; ?>
    <?php if($facebook): ?>
      <dl class="clearfix">
        <dt><?php print t('Facebook'); ?></dt>
        <dd><?php print l($facebook, $facebook); ?></dd>
      </dl>
    <?php endif; ?>
  </div>
</div>
