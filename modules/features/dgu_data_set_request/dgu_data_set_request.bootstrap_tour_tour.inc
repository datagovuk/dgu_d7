<?php
/**
 * @file
 * dgu_data_set_request.bootstrap_tour_tour.inc
 */

/**
 * Implements hook_default_bootstrap_tour().
 */
function dgu_data_set_request_default_bootstrap_tour() {
  $export = array();

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'data_request_administration';
  $bootstrap_tour->title = 'Data request administration';
  $bootstrap_tour->roles = '3,10';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'Data request adminisration tour';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.nav-user',
      'path' => 'help',
      'placement' => 'left',
      'title' => 'User account',
      'content' => '<p>To access the data requests administration functions please go to the user account page.</p>

<p>At this stage all new data requests should be already moderated.</p>

<p><a href="/user?tour=content_moderation">Play content moderation tour</a></p>
',
      'format' => 'filtered_html',
    ),
    1 => array(
      'selector' => 'a[href="/admin/workbench"]',
      'path' => 'user',
      'placement' => 'bottom',
      'title' => 'Manage my content',
      'content' => '<p>Next please click &#39;Manage my content&#39; tab.</p>
',
      'format' => 'filtered_html',
    ),
    2 => array(
      'selector' => 'a[href="/admin/workbench/content/data-requests"]',
      'path' => 'admin/workbench',
      'placement' => 'bottom',
      'title' => 'List of all data requests',
      'content' => '<p>Then click &#39;Data Requests&#39;&nbsp;tab to access the data requests administration page.</p>
',
      'format' => 'filtered_html',
    ),
    3 => array(
      'selector' => '.view-data-requests-administration .views-table',
      'path' => 'admin/workbench/content/data-requests',
      'placement' => 'top',
      'title' => 'List of all data request',
      'content' => '<p>This contains a list of all active and closed&nbsp;data requests for all publishers and Relationship Managers, you can narow down nubmer of requests displayed using filters above.</p>
',
      'format' => 'filtered_html',
    ),
    4 => array(
      'selector' => '#edit-title',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Title filter',
      'content' => '<p>You can search through the titles, entering any string contained in the title to perform the search.<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    5 => array(
      'selector' => '#edit-field-review-status-value',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Status filter',
      'content' => '<p>You can also flter requests by their status.&nbsp; In order to do that please select the status filter from the drop down list.</p>
',
      'format' => 'filtered_html',
    ),
    6 => array(
      'selector' => '#edit-field-publication-preference-value',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Publication preference filter',
      'content' => '<p>You can also filter by publication preference...<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    7 => array(
      'selector' => '#edit-field-review-outcome-value',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Outcome filter',
      'content' => '<p>... or by request&nbsp;outcome. Setting the outcome filter narrows down the results to only&nbsp;data requests with the status &#39;Closed&#39;, because the&nbsp;&#39;Outcome&#39; field is available only for closed requests.</p>
',
      'format' => 'filtered_html',
    ),
    8 => array(
      'selector' => '#edit-field-barriers-reason-value',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Issue filter',
      'content' => '<p>You can use &#39;issue&#39; filter in similar way to&nbsp;status and outcome filters.<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    9 => array(
      'selector' => '#edit-items-per-page',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Items per page',
      'content' => '<p>Here you can choose the number of&nbsp;data requests that will be displayed&nbsp;on the list per page.</p>
',
      'format' => 'filtered_html',
    ),
    10 => array(
      'selector' => '#edit-submit-data-requests-administration',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Apply button',
      'content' => '<p>Please don&#39;t forget to press &#39;Apply&#39; button to apply filters.<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    11 => array(
      'selector' => 'th.views-field-changed',
      'path' => '',
      'placement' => 'top',
      'title' => 'Default sort',
      'content' => '<p>By default the list is sorted&nbsp;by modification date.&nbsp;You can change this by clicking on other column labels.</p>
',
      'format' => 'filtered_html',
    ),
    12 => array(
      'selector' => '.views-row-first .views-field-title a',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Link to the data request',
      'content' => '<p>The title of the data request is the link to the data request view page.</p>
',
      'format' => 'filtered_html',
    ),
    13 => array(
      'selector' => '.views-row-first .views-field-edit-node a',
      'path' => '',
      'placement' => 'left',
      'title' => 'Edit link',
      'content' => '<p>This is the link to the data request edit page.</p>
',
      'format' => 'filtered_html',
    ),
    14 => array(
      'selector' => '.views-row-first .views-field-field-assignee a',
      'path' => '',
      'placement' => 'left',
      'title' => 'Link to user profile',
      'content' => '<p>Data request assignee is the link to data.gov.uk user profile.<br />
	&nbsp;</p>
',
      'format' => 'filtered_html',
    ),
    15 => array(
      'selector' => '.text-center .pagination',
      'path' => '',
      'placement' => 'top',
      'title' => 'Pager',
      'content' => '<p>You can&nbsp;navigate through all the data request pages here.</p>
',
      'format' => 'filtered_html',
    ),
    16 => array(
      'selector' => 'a[href="/admin/workbench/content/active"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Active Data requests',
      'content' => '<p>To manage data requests currently assigned to you please click &#39;Active Data requests&#39; tab.</p>
',
      'format' => 'filtered_html',
    ),
    17 => array(
      'selector' => '.view-data-requests-administration .view-content',
      'path' => 'admin/workbench/content/active',
      'placement' => 'top',
      'title' => 'Active Data requests',
      'content' => '<p>This is very similar list to &#39;Data requests&#39; just without &#39;Assignee&#39; column because they are all assigned to you.</p>
',
      'format' => 'filtered_html',
    ),
    18 => array(
      'selector' => '.view-data-requests-administration .view-filters form',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Fitlers',
      'content' => '<p>The filters&nbsp;work&nbsp;in the same way as&nbsp;on the data requests list.</p>
',
      'format' => 'filtered_html',
    ),
    19 => array(
      'selector' => 'a[href="/admin/workbench/content/edited"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'My Edits',
      'content' => '<p>You can find all requests you have edited (e.g. assigned to somebody else) here.</p>
',
      'format' => 'filtered_html',
    ),
    20 => array(
      'selector' => '.views-row-first .views-field-edit-node a',
      'path' => 'admin/workbench/content/data-requests',
      'placement' => 'left',
      'title' => 'Edit link',
      'content' => '<p>To edit a data request please click edit link.</p>
',
      'format' => 'filtered_html',
    ),
    21 => array(
      'selector' => '.tabs--primary a[href="/node/651/edit"]',
      'path' => 'node/651/edit',
      'placement' => 'bottom',
      'title' => 'Editing data request',
      'content' => '<p>You are now on the data request edit page.</p>
',
      'format' => 'filtered_html',
    ),
    22 => array(
      'selector' => '.tabs--primary a[href="/data-request/test-data"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Virew data request',
      'content' => '<p>Click &#39;View&#39; to switch to data request view page.</p>
',
      'format' => 'filtered_html',
    ),
    23 => array(
      'selector' => '.tabs--primary a[href="/node/651/moderation"]',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Moderation',
      'content' => '<p>Click &#39;Moderate&#39; to see the moderation history, unpublish or change the moderation state of the current revision.</p>
',
      'format' => 'filtered_html',
    ),
  );
  $export['data_request_administration'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'data_requests_practitioners_guide';
  $bootstrap_tour->title = 'Data requests practitioners guide';
  $bootstrap_tour->roles = '6';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = '';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.nav-user',
      'path' => 'help',
      'placement' => 'left',
      'title' => 'User account',
      'content' => '<p>To access data requests administration functions please go to user account page.</p>
',
      'format' => 'filtered_html',
    ),
    1 => array(
      'selector' => '.publishers-active-requests-link',
      'path' => 'user',
      'placement' => 'bottom',
      'title' => 'Publisher active data requests',
      'content' => '<p>As a practitioner, you can view all open data requests assigned to your publishers by clicking on this link.</p>
',
      'format' => 'filtered_html',
    ),
    2 => array(
      'selector' => 'th.views-field-changed',
      'path' => 'tour-redirect/publisher-active-data-request-url',
      'placement' => 'top',
      'title' => 'Sort data requests',
      'content' => '<p>You can sort the data requests by clicking on the title of the relevant column.</p>
',
      'format' => 'filtered_html',
    ),
    3 => array(
      'selector' => '#edit-title',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Filter data requests',
      'content' => '<p>Alternatively, if there are a large number of requests, you can filter by title, status, outcome (for closed requests), preference, issue, relationship manager, publisher, publisher assignee (ie the person to whom the request has been allocated) and number of items on the page.</p>
',
      'format' => 'filtered_html',
    ),
    4 => array(
      'selector' => '.views-submit-button input.btn',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Apply button',
      'content' => '<p>Click &lsquo;apply&rsquo; after choosing your filter criteria.</p>
',
      'format' => 'filtered_html',
    ),
    5 => array(
      'selector' => '.views-row-first .flag-subscribe-node',
      'path' => '',
      'placement' => 'left',
      'title' => 'Subscribe to alerts',
      'content' => '<p>You can choose whether to be subscribed to alerts when requests are updated. Click subscribe/unsubscribe to change your status.</p>
',
      'format' => 'filtered_html',
    ),
    6 => array(
      'selector' => '.views-row-first .views-field-title',
      'path' => '',
      'placement' => 'right',
      'title' => 'Choose data request to view',
      'content' => '<p>To view a specific data request, click the title of the relevant request.</p>
',
      'format' => 'filtered_html',
    ),
    7 => array(
      'selector' => 'article.node',
      'path' => 'tour-redirect/publisher-active-data-request',
      'placement' => 'top',
      'title' => 'View full detail and review updates',
      'content' => '<p>This page will show the full detail of the request, when it was submitted and who by, as well as the current status, Cabinet Office relationship manager and any review notes added to reflect progress.</p>
',
      'format' => 'filtered_html',
    ),
    8 => array(
      'selector' => '.field-name-field-review-comments form',
      'path' => '',
      'placement' => 'top',
      'title' => 'Updating the request',
      'content' => '<p>Review notes should be added to keep track of progress in reviewing a request.</p>

<p>Review notes are only visible to publishers and administrators. Nothing added here is published on data.gov.uk</p>

<p>A note should be added each time there is a change to keep practitioners and relationship managers informed of the status, and to enable updates to the public view when appropriate.</p>

<p>You should submit review notes to provide an update or to ask questions of the publisher assignee or Cabinet Office.</p>
',
      'format' => 'filtered_html',
    ),
    9 => array(
      'selector' => '.field-name-field-review-comments input.btn',
      'path' => '',
      'placement' => 'right',
      'title' => 'Submit review note',
      'content' => '<p>Once you&rsquo;ve added your notes, click this button to save it.</p>

<p>Each review note will automatically include the name of the person making the comment as well as the date.</p>

<p>An alert will be sent to all subscribers when changes are made to keep them aware of updates.</p>

<p>Relationship managers will change the status of the request as necessary based on the information provided in the review notes.</p>
',
      'format' => 'filtered_html',
    ),
  );
  $export['data_requests_practitioners_guide'] = $bootstrap_tour;

  $bootstrap_tour = new stdClass();
  $bootstrap_tour->disabled = FALSE; /* Edit this to true to make a default bootstrap_tour disabled initially */
  $bootstrap_tour->api_version = 1;
  $bootstrap_tour->name = 'data_requests_user_guide';
  $bootstrap_tour->title = 'Data requests user guide';
  $bootstrap_tour->roles = '6';
  $bootstrap_tour->autorun = 0;
  $bootstrap_tour->description = 'Data requests user guide for assignees';
  $bootstrap_tour->steps = array(
    0 => array(
      'selector' => '.nav-user',
      'path' => 'help',
      'placement' => 'left',
      'title' => 'User account',
      'content' => '<p>To access data requests administration functions please go to user account page.</p>
',
      'format' => 'filtered_html',
    ),
    1 => array(
      'selector' => '.view-data-requests-administration',
      'path' => 'user',
      'placement' => 'top',
      'title' => 'Active Data requests',
      'content' => '<p>The most recent data requests that have been assigned to you are shown here.</p>

<p>A maximum of 5 data requests will be displayed, if you want to see all data requests assigned to you can either click &quot;See all&quot; below or &quot;View these now&quot; in the green message bar above.</p>
',
      'format' => 'filtered_html',
    ),
    2 => array(
      'selector' => '.active-requests-link',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Alert about active data requests',
      'content' => '<p>When you log in, the current total of data requests assigned to you is displayed in the green message bar on the user account page.</p>

<p>There are links here for you to access a list of all data requests assigned to you and the data request user guide.</p>
',
      'format' => 'filtered_html',
    ),
    3 => array(
      'selector' => '.tabs--secondary a[href="/admin/workbench/content/active"]',
      'path' => 'admin/workbench/content/active',
      'placement' => 'bottom',
      'title' => 'Active data requests',
      'content' => '<p>Data requests that have not been closed and that are assigned to you are displayed here.</p>
',
      'format' => 'filtered_html',
    ),
    4 => array(
      'selector' => '.view-data-requests-administration th.views-field-changed a',
      'path' => '',
      'placement' => 'top',
      'title' => 'Sort data requests',
      'content' => '<p>You can sort your data requests by clicking on the title of the relevant column.</p>
',
      'format' => 'filtered_html',
    ),
    5 => array(
      'selector' => '.view-data-requests-administration #edit-title',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Filter data requests',
      'content' => '<p>Alternatively, if you have a large number of requests, you can filter by title, status, preference and number of items on the page.</p>
',
      'format' => 'filtered_html',
    ),
    6 => array(
      'selector' => '.view-data-requests-administration  .views-submit-button input.btn',
      'path' => '',
      'placement' => 'bottom',
      'title' => 'Apply button',
      'content' => '<p>Click &lsquo;apply&rsquo; after choosing your filter criteria.</p>
',
      'format' => 'filtered_html',
    ),
    7 => array(
      'selector' => '.view-data-requests-administration .views-row-first .views-field-title a',
      'path' => '',
      'placement' => 'right',
      'title' => 'Choose data request to edit',
      'content' => '<p>To edit a specific data request, click the title of the relevant request.</p>
',
      'format' => 'filtered_html',
    ),
    8 => array(
      'selector' => 'article.node',
      'path' => 'tour-redirect/active-data-request',
      'placement' => 'top',
      'title' => 'View full detail and edit request',
      'content' => '<p>This page will show the full detail of the request, when it was submitted and who by, as well as the current status and Cabinet Office relationship manager.</p>
',
      'format' => 'filtered_html',
    ),
    9 => array(
      'selector' => '.field-name-field-review-comments form',
      'path' => '',
      'placement' => 'top',
      'title' => 'Updating the request',
      'content' => '<p>Review notes should be added to keep track of progress in reviewing a request.</p>

<p>Review notes are only visible to publishers and administrators. Nothing added here is published on data.gov.uk</p>

<p>A note should be added each time there is a change to keep practitioners and relationship managers informed of the status, and to enable updates to the public view when appropriate.</p>
',
      'format' => 'filtered_html',
    ),
    10 => array(
      'selector' => '.field-name-field-review-comments input.btn',
      'path' => '',
      'placement' => 'right',
      'title' => 'Submit review note',
      'content' => '<p>Once you&rsquo;ve added your notes, click this button to save it.</p>

<p>Each review note will automatically include the name of the person making the comment as well as the date.</p>

<p>An alert will be sent to all subscribers when changes are made to keep them aware of updates.</p>

<p>Relationship managers will change the status of the request as necessary based on the information provided in the review notes.</p>
',
      'format' => 'filtered_html',
    ),
    11 => array(
      'selector' => 'article.node header a.username',
      'path' => '',
      'placement' => 'right',
      'title' => 'Requestor details',
      'content' => '<p>If you have a query about the request, you can contact them via their profile.</p>

<p>To access their profile, click on their username at the top of the request.</p>
',
      'format' => 'filtered_html',
    ),
    12 => array(
      'selector' => '.tabs--primary',
      'path' => 'tour-redirect/active-data-request-author',
      'placement' => 'right',
      'title' => 'Contact requestor',
      'content' => '<p>Click on the &lsquo;Contact&rsquo; tab to bring up a contact form.</p>
',
      'format' => 'filtered_html',
    ),
    13 => array(
      'selector' => 'form.contact-form',
      'path' => 'tour-redirect/active-data-request-author-contact',
      'placement' => 'top',
      'title' => 'Contact form',
      'content' => '<p>Complete the contact form ensuring you include a clear reference to the data request in the subject line as this will not automatically link to the data request.</p>

<p>The form will automatically fill in your name and email address from your profile but can be changed if necessary. The email address you include will be the one any responses are sent to so ensure it is correct.</p>
',
      'format' => 'filtered_html',
    ),
    14 => array(
      'selector' => 'form.contact-form #edit-submit',
      'path' => '',
      'placement' => 'right',
      'title' => 'Send message',
      'content' => '<p>Once the form is complete you can choose whether to have a copy of the message sent to you by ticking the box. Click &lsquo;Send message&rsquo; when you are done.</p>

<p>It is important to ensure you add a review note to the relevant request to reflect the action that has been taken.</p>
',
      'format' => 'filtered_html',
    ),
  );
  $export['data_requests_user_guide'] = $bootstrap_tour;

  return $export;
}
