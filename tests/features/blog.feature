@javascript
Feature: Create blogs as a blogger
  In order to discuss a topic
  As a blogger
  I should be able to create blogs

  @anon
  Scenario: View latest blogs page
    Given I am on the homepage
    And I click "Interact"
    When I follow "All Blogs"
    Then I should be on "/blog"
    And "All Blogs" item in "Interact" subnav should be active
    And I should see the following <breadcrumbs>
      | Blog         |
      | Latest Blogs |
    And view "latest_blog_posts" view should have "6" rows
    And I should see the link "See all"
    And view "frequent_bloggers" view should have "15" rows
    And search result counter should match "^\d* Blogs$"
    And I should see "FREQUENT BLOGGERS" pane in "last" column in "second" row

  @anon
  Scenario: View most popular blogs page
    Given I am on "/blog"
    And I follow "Most popular Blogs"
    And I should be on "/blog/popular"
    And "All Blogs" item in "Interact" subnav should be active
    And I should see the following <breadcrumbs>
      | Blog               |
      | Most popular Blogs |
    And view "most_popular_blog_posts" view should have "6" rows
    And row "1" of "most_popular_blog_posts" view should match "\d* comments Last \d* \w* \d* \w* ago$"
    And pager in "most_popular_blog_posts" view should match "^1 2 3 … »$"
    And view "frequent_bloggers" view should have "15" rows
    And I should see "FREQUENT BLOGGERS" pane in "last" column in "second" row
    And search result counter should match "^\d* Blogs$"

  @anon
  Scenario: View the blog RSS
    Given I am on "/blog"
    And I wait until the page loads
    And I click RSS icon in "first" column in "second" row
    Then I should be on "/blog/rss.xml"

  @anon @search
  Scenario: View search blog page and perform a search with and without a keyword checking the solr sort.
    Given I am on the homepage
    And I click "Interact"
    And I follow "All Blogs"
    And I wait until the page loads
    When I click search icon
    And I wait until the page loads
    Then I should be on "/search/everything/?f[0]=bundle%3Ablog"
    And "All Blogs" item in "Interact" subnav should be active
    And I should see "Please enter some keywords to refine your search further."
    And I should see the following <breadcrumbs>
      | Blog   |
      | Search |
    And search result counter should match "^\d* Blogs$"
    And "Last updated" option in "Sort by:" should be selected
    And there should be "10" search results on the page
    And pager should match "^1 2 3 … »$"
    And I should see "CONTENT TYPE" pane in "first" column in "first" row
    And I should see "CATEGORY" pane in "first" column in "first" row
    And I should see "SECTOR" pane in "first" column in "first" row
    And I should not see "TAGS" pane in "first" column in "first" row
    When I click "Blog entry"
    And I wait until the page loads
    Then I should be on "/search/everything/"
    And "Search content" item in "Interact" subnav should be active
    And I should see the following <breadcrumbs>
      | Search |
    And search result counter should match "^\d* Content results"
    And "Last updated" option in "Sort by:" should be selected
    And "Author" option in "Sort by:" should be disabled
    And "Relevance" option in "Sort by:" should be disabled
    And there should be "10" search results on the page
    When I fill in "Search content..." with "blog"
    And I click search icon
    Then I should be on "/search/everything/blog?solrsort=score"
    And "Relevance" option in "Sort by:" should be selected
    And "Author" option in "Sort by:" should be disabled
    When I click "Blog entry"
    And I wait until the page loads
    Then I should be on "/search/everything/blog?f[0]=bundle%3Ablog"
    And search result counter should match "^\d* Blogs"
    And "All Blogs" item in "Interact" subnav should be active
    And "Content type" option in "Sort by:" should be disabled

  @api
  Scenario: Create a new blogs entry with empty required fields
    Given I am logged in as a user with the "blogger" role
    And I visit "/node/add/blog"
    When I press "Save"
    Then I should see "Title field is required"
    And the field "Title" should be outlined in red

  @api
  Scenario: Create a new blog entry and comment on it and test notification about new content
    Given that the user "test_user" is not registered
    And that the user "test_subscriber_new_blog" is not registered
    And that the user "test_subscriber_updates_comments" is not registered
    And that the user "test_non_subscriber" is not registered
    And I am logged in as a user "test_non_subscriber" with the "authenticated user" role
    And I am logged in as a user "test_subscriber_new_blog" with the "authenticated user" role
    When I visit "/user"
    And I wait until the page loads
    And I follow "My subscriptions"
    And I wait until the page loads
    And I click "Auto subscribe"
    And I wait until the page loads
    And I check "Blog entry"
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
    And I check "Blog entry"
    And I wait 1 second
    And I check "Automatically subscribe to updates and comments"
    And I wait 1 second
    And I press "Save"
    And I wait until the page loads
    And I am logged in as a user "test_user" with the "blogger" role
    And I visit "/node/add/blog"
    And I wait until the page loads
    And I should see the following <breadcrumbs>
      | Add content       |
      | Create Blog entry |
    When I fill in "Title" with "Test blog"
    And I type "Test body" in the "edit-body-und-0-value" WYSIWYG editor
    And I press "Save draft"
    And I wait until the page loads
    Then I should see a message about created draft "Blog entry"
    And I should be on "/blog/test-blog"
    And I should see node title "Test blog"
    And I should see "Test body"
    When I submit "Blog entry" titled "Test blog" for moderation
    And user with "moderator" role moderates "Test blog" authored by "test_user"
    And the "test_user" user have not received an email 'Blog entry "Test blog" has been created '
    And the "test_non_subscriber" user have not received an email 'Blog entry "Test blog" has been created '
    And the "test_subscriber_new_blog" user received an email 'Blog entry "Test blog" has been created '
    And the "test_subscriber_updates_comments" user received an email 'Blog entry "Test blog" has been created '
    When I am logged in as a user "test_user" with the "authenticated user" role
    Then I should see "Test blog" in My content and All content tabs but not in My drafts tab
    Given the cache has been cleared
    When I visit "/blog"
    Then "title" field in row "1" of "latest_blog_posts" view should match "^Test blog$"
    And "name" field in row "1" of "latest_blog_posts" view should match "^Created by test_user (\d* min \d* sec|\d* min|\d* sec) ago$"
    And avatar in row "1" of "latest_blog_posts" view should link to "/users/testuser"
    And row "1" of "latest_blog_posts" view should match "No comments so far$"
    When I click "title" field in row "1" of "latest_blog_posts" view
    Then I should be on "/blog/test-blog"
    And I should see the link "Subscribe"
    # Testing comments as different user
    Given that the user "test_commenting_user" is not registered
    And I am logged in as a user "test_commenting_user" with the "authenticated user" role
    And I visit "/blog/test-blog"
    And I wait until the page loads
    When I follow "Add new comment"
    And I should see the following <breadcrumbs>
      | Blogs     |
      | Test blog |
      | Comment   |
    # TODO test how blog teaser above comment should be rendered
    And I fill in "Subject" with "Test subject"
    And I type "Test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    And I press "Submit"
    And I wait until the page loads
    Then I should be on "/blog/test-blog"
    And I should see the success message "Comment was successfully created."
    And I should see "Test blog"
    And I should see "Test body"
    And I should see the heading "Comments"
    And I should see "Test subject"
    And I should see "Test comment"
    And I should see the link "Reply"
    Given the cache has been cleared
    When I visit "/blog"
    Then row "1" of "latest_blog_posts" view should match "\d* comment \d* sec ago$"
    And the "test_subscriber_updates_comments" user received an email 'User test_commenting_user posted a comment on Blog entry "Test blog" '
    And the "test_subscriber_new_blog" user have not received an email 'User test_commenting_user posted a comment on Blog entry "Test blog" '
    And the "test_non_subscriber" user have not received an email 'User test_commenting_user posted a comment on Blog entry "Test blog" '
    And the "test_user" user have not received an email 'User test_commenting_user posted a comment on Blog entry "Test blog" '

  @api
  Scenario: Subscribe user to existing blog and test notifications about comment and blog update
    # Create a blog
    Given that the user "test_editor" is not registered
    And I am logged in as a user "test_editor" with the "editor" role
    And user "test_editor" created "blog" titled "Test blog"
    # Subscribe to this blog by test_user
    And that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    And the cache has been cleared
    And I visit "/blog"
    And I wait until the page loads
    And I click "Test blog"
    And I wait until the page loads
    And I should not see "Unsubscribe"
    When I click "Subscribe"
    And I wait 1 second
    Then I should see the link "Unsubscribe"
    Given I am logged in as a user "test_editor" with the "editor" role
    And I visit "/user"
    And I wait until the page loads
    And I click "Test blog"
    And I wait until the page loads
    And I click "Edit"
    And I wait until the page loads
    And I fill in "Title" with "Amended test blog"
    And I click "Publishing options"
    And I wait 1 second
    And I select "Published" from "Moderation state"
    When I press "Save"
    And I wait until the page loads
    Then I should see "Amended test blog"
    # test_editor isn't subscribed
    And I should see the link "Subscribe"
    And the "test_user" user received an email 'Blog entry "Test blog" has been updated'
    And I follow "Add new comment"
    And I fill in "Subject" with "Test subject"
    And I type "Test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    When I press "Submit"
    Then the "test_user" user received an email 'User test_editor posted a comment on Blog entry "Amended test blog"'
    Given I am logged in as a user "test_user" with the "authenticated user" role
    When user "test_user" clicks link containing "/blog/" in mail 'User test_editor posted a comment on Blog entry "Amended test blog"'
    And I wait until the page loads
    Then I should see the following <breadcrumbs>
      | Blog              |
      | Amended test blog |
    When user "test_user" clicks link matching ".*\/subscriptions$" in mail 'Blog entry "Test blog" has been updated'
    Then I should see the following <breadcrumbs>
      | My subscriptions |
    And I should see the link "Amended test blog"
    And I should see "Blog entry"
    And I should see the link "Unsubscribe"
    When user "test_user" clicks link containing "/subscriptions/delivery" in mail 'Blog entry "Test blog" has been updated'
    Then I should see the following <breadcrumbs>
      | My subscriptions          |
      | Delivery of notifications |
    And I click "My subscriptions"
    And I should see the link "Amended test blog"
    When I click "Unsubscribe"
    And I wait 1 second
    Then I should not see "Unsubscribe"
    And I should see the link "Subscribe"
    And the cache has been cleared
    And I visit "/blog"
    And I wait until the page loads
    And I click "Amended test blog"
    And I wait until the page loads
    And I should not see "Unsubscribe"
    And I should see the link "Subscribe"
