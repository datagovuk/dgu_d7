@javascript
Feature: Create new forum topic as a site user
  In order to discuss a topic
  As a site user
  I should be able to post a new forum topic

  @anon
  Scenario: View the latest forum topics landing page as anonymous user
    Given I am on the homepage
    And I click "Interact"
    When I follow "All Forums"
    Then I should be on "/forum"
    And "All Forums" item in "Interact" subnav should be active
    And I should see the following <breadcrumbs>
      | Forum               |
      | Latest forum topics |
    And I should see the link "Login to take part in forums »"
    And search result counter should match "^\d* Forum topics$"
    And view "panel_pane_latest_forum" view should have "6" rows
    And I should see the link "See all"

  @anon
  Scenario: View the latest forum topics RSS
    Given I am on "/forum"
    And I wait until the page loads
    And I click RSS icon in "single" column in "first" row
    Then I should be on "/forum/rss.xml"

  @anon @api
  Scenario: View the most popular forum topics page as anonymous and authenticated users
    Given I am on "/forum"
    When I follow "Most popular topics"
    Then I should be on "/forum/popular"
    And I should see the following <breadcrumbs>
      | Forum               |
      | Most popular topics |
    And I should see the link "Login to take part in forums »"
    And search result counter should match "^\d* Forum topics$"
    And "title" field in row "1" of "panel_pane_most_popular_forum" view should match "^\w*"
    And  "name" field in row "1" of "panel_pane_most_popular_forum" view should match "^Created by \w*|\w* (\d* \w* \d* \w* ago|\d* \w* ago)"
    And  "taxonomy-forums" field in row "1" of "panel_pane_most_popular_forum" view should match "^Posted in \w*"
    And row "1" of "panel_pane_most_popular_forum" view should match "\d* replies Last \d* \w* \d* \w* ago$"
    And view "panel_pane_most_popular_forum" view should have "6" rows
    And pager in "panel_pane_most_popular_forum" view should match "^1 2 3 … »$"
    Given that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    And I am on "/forum/categories"
    Then I should see the link "Create new forum topic"

  @anon
  Scenario: View the most popular forum topics RSS
    Given I am on "/forum/popular"
    And I wait until the page loads
    And I click RSS icon in "single" column in "first" row
    Then I should be on "/forum/popular/rss.xml"

  @anon @api
  Scenario: View the forum categories page as anonymous and authenticated users
    Given I am on "/forum"
    When I follow "Forum categories"
    Then I should be on "/forum/categories"
    And I should see the following <breadcrumbs>
      | Forum      |
      | Categories |
    And search result counter should match "^\d* Forum topics$"
    And view "forum_categories_block" view should have "9" rows
    And row "1" of "forum_categories_block" view should match "^General discussion"
    And row "1" of "forum_categories_block" view should match "\d* topics \d* replies$"
    And I should see the link "Login to take part in forums »"
    Given that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    And I am on "/forum/categories"
    Then I should see the link "Create new forum topic"

  @anon @api
  Scenario: View a forum category page as anonymous and authenticated users
    Given I am on "/forum/categories"
    When I follow "General discussion"
    Then I should be on "/forum/general-discussion"
    And I should see the following <breadcrumbs>
      | Forum              |
      | Categories         |
      | General discussion |
    And search result counter should match "^\d* Forum topics$"
    And I should see "GENERAL DISCUSSION" pane in "first" column in "second" row
    And I should see "FORUM CATEGORIES" pane in "last" column in "second" row
    And row "1" of "block_1" view should match "^General Discussion \d* topics"
    And view "block_1" view should have "9" rows
    And view "panel_pane_category_forum" view should have "6" rows
    And "title" field in row "1" of "panel_pane_category_forum" view should match "^\w*"
    And  "name" field in row "1" of "panel_pane_category_forum" view should match "^Created by \w*|\w* (\d* \w* \d* \w* ago|\d* \w* ago)"
    And row "1" of "panel_pane_category_forum" view should match "\d* replies|reply \d* \w* \d* \w* ago|No replies so far$"
    And pager in "panel_pane_category_forum" view should match "^1 2 3 … »$"
    And I should see the link "Login to take part in forums »"
    Given that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    And I am on "/forum/categories"
    Then I should see the link "Create new forum topic"

  @api
  Scenario: Create a new forum topic with empty required fields
    Given I am logged in as a user with the "authenticated user" role
    And I visit "/forum"
    And I follow "Create new forum topic"
    When I press "Save"
    Then I should see "Subject field is required"
    And I should see "Forums field is required"
    And the field "Subject" should be outlined in red
    And the field "Forums" should be outlined in red

  @api
  Scenario: Create a new forum topic, test notifications
    Given that the user "test_user" is not registered
    And that the user "test_subscriber_new_forum" is not registered
    And that the user "test_subscriber_updates_comments" is not registered
    And that the user "test_non_subscriber" is not registered
    And I am logged in as a user "test_non_subscriber" with the "authenticated user" role
    And I am logged in as a user "test_subscriber_new_forum" with the "authenticated user" role
    When I visit "/user"
    And I wait until the page loads
    And I follow "My subscriptions"
    And I wait until the page loads
    And I click "Auto subscribe"
    And I wait until the page loads
    And I check "Forum topic"
    And I wait 1 second
    And I press "Save"
    And I wait until the page loads
    And I am logged in as a user "test_subscriber_updates_comments" with the "authenticated user" role
    When I visit "/user"
    And I wait until the page loads
    And I follow "My subscriptions"
    And I wait until the page loads
    And I click "Auto subscribe"
    And I wait until the page loads
    And I check "Forum topic"
    And I wait 1 second
    And I check "Automatically subscribe to updates and comments"
    And I wait 1 second
    And I press "Save"
    And I wait until the page loads
    And I am logged in as a user "test_user" with the "authenticated user" role
    And I visit "/forum"
    And I follow "Create new forum topic"
    And I fill in "Subject" with "Test forum topic"
    And I select "General discussion" from "Forums"
    When I press "Save draft"
    And I wait until the page loads
    Then I should see a message about created draft "Forum topic"
    And I should see node title "Test forum topic"
    When I submit "Forum topic" titled "Test forum topic" for moderation
    And user with "moderator" role moderates "Test forum topic" authored by "test_user"
    And the "test_user" user have not received an email 'Forum topic "Test forum topic" has been created '
    And the "test_non_subscriber" user have not received an email 'Forum topic "Test forum topic" has been created '
    And the "test_subscriber_new_forum" user received an email 'Forum topic "Test forum topic" has been created '
    And the "test_subscriber_updates_comments" user received an email 'Forum topic "Test forum topic" has been created '
    When I am logged in as a user "test_user" with the "authenticated user" role
    Then I should see "Test forum topic" in My content and All content tabs but not in My drafts tab
    # Comment on "Test forum topic" as "test_commenting_user"
    Given that the user "test_commenting_user" is not registered
    And I am logged in as a user "test_commenting_user" with the "authenticated user" role
    And I am on "/forum/general-discussion/test-forum-topic"
    And I should see the link "Subscribe"
    When I follow "Add new comment"
    And I wait until the page loads
    Then I should see the following <breadcrumbs>
      | Forum            |
      | Test forum topic |
      | Comment          |
    When I fill in "Subject" with "Test subject"
    And I type "Body content of test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    And I press "Submit"
    And I wait until the page loads
    Then I should be on "/forum/general-discussion/test-forum-topic"
    And I should see the success message "Comment was successfully created."
    And I should see "Test forum topic"
    And I should see the heading "Comments"
    And I should see "Test subject"
    And I should see "Body content of test comment"
    And I should see the link "Reply"
    And the "test_subscriber_updates_comments" user received an email 'User test_commenting_user posted a comment on Forum topic "Test forum topic" '
    And the "test_subscriber_new_forum" user have not received an email 'User test_commenting_user posted a comment on Forum topic "Test forum topic" '
    And the "test_non_subscriber" user have not received an email 'User test_commenting_user posted a comment on Forum topic "Test forum topic" '
    And the "test_user" user have not received an email 'User test_commenting_user posted a comment on Forum topic "Test forum topic" '
    # Clear the cache so the forum topic will show up on the forum landing page
    Given the cache has been cleared
    When I visit "/forum"
    And I wait until the page loads
    Then "title" field in row "1" of "panel_pane_latest_forum" view should match "^Test forum topic$"
    And avatar in row "1" of "panel_pane_latest_forum" view should link to "/users/testuser"
    And  "name" field in row "1" of "panel_pane_latest_forum" view should match "^Created by \w* (\d* \w* \d* \w* ago|\d* \w* ago)"
    And row "1" of "panel_pane_latest_forum" view should match "1 reply"
    When I click "title" field in row "1" of "panel_pane_latest_forum" view
    Then I should be on "/forum/general-discussion/test-forum-topic"
    #View the Test forum topic and check the author link
    When I follow "test_user" in the "main_content"
    And I wait until the page loads
    Then I should be on "/users/testuser"

  @anon @search
  Scenario: View search forum page with and without a keyword, check solr sort.
    Given I am on "/forum"
    When I click search icon
    Then I should be on "/search/everything/?f[0]=bundle%3Aforum"
    And I should see "Please enter some keywords to refine your search further."
    And I should see the following <breadcrumbs>
      | Forum  |
      | Search |
    And I should see "Please enter some keywords to refine your search further."
    And "All Forums" item in "Interact" subnav should be active
    And "Last updated" option in "Sort by:" should be selected
    And there should be "10" search results on the page
    And pager should match "^1 2 3 … »$"
    When I fill in "Search forum topics..." with "key"
    And I click search icon
    Then I should be on "/search/everything/key?f[0]=bundle%3Aforum"
    And search result counter should match "^\d* Forum topics"
    And "Relevance" option in "Sort by:" should be selected
    And I should see "CONTENT TYPE" pane in "first" column in "first" row
    And I should see "CATEGORY" pane in "first" column in "first" row
    And I should see "SECTOR" pane in "first" column in "first" row
    And I click "Forum topic"
    And I wait until the page loads
    Then I should be on "/search/everything/key?"
    And "Search content" item in "Interact" subnav should be active
    And I should see the following <breadcrumbs>
      | Search |
    And search result counter should match "^\d* Content results"
    And "Relevance" option in "Sort by:" should be selected
    And "Author" option in "Sort by:" should be disabled
    And there should be "10" search results on the page
    When I click "Forum topic"
    And I wait until the page loads
    Then I should be on "/search/everything/key?f[0]=bundle%3Aforum"
    And "All Forums" item in "Interact" subnav should be active
