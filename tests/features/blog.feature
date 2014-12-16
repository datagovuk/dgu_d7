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
    And I should see "TAGS" pane in "first" column in "first" row
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
  Scenario: Create a new blog entry and comment on it
    Given that the user "test_user" is not registered
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
    When I am logged in as a user "test_user" with the "authenticated user" role
    Then I should see "Test blog" in My content and All content tabs but not in My drafts tab
    Given the cache has been cleared
    When I visit "/blog"
    Then "title" field in row "1" of "latest_blog_posts" view should match "^Test blog$"
    And "name" field in row "1" of "latest_blog_posts" view should match "^Created by test_user (\d* min \d*|\d*) sec ago$"
    And avatar in row "1" of "latest_blog_posts" view should link to "/users/testuser"
    And row "1" of "latest_blog_posts" view should match "No comments so far$"
    When I click "title" field in row "1" of "latest_blog_posts" view
    Then I should be on "/blog/test-blog"
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

  @anon
  Scenario: Make sure that comments can not be posted by anonymous users
    Given I am on "/blog"
    And I wait until the page loads
    When I click "title" field in row "1" of "latest_blog_posts" view
    And I wait until the page loads
    Then I should see the link "Login to make a comment"
