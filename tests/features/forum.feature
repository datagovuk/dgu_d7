@javascript
Feature: Create new forum topic as a site user
  In order to discuss a topic
  As a site user
  I should be able to post a new forum topic

  @anon
  Scenario: View the latest forum topics landing page
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

  @anon
  Scenario: View the latest forum topics RSS
    Given I am on "/forum"
    And I wait until the page loads
    And I click RSS icon in "single" column in "first" row
    Then I should be on "/forum/rss.xml"

  @anon
  Scenario: View the most popular forum topics page
    Given I am on "/forum"
    When I follow "Most popular topics"
    Then I should be on "/forum/popular"
    And I should see the following <breadcrumbs>
      | Forum               |
      | Most popular topics |
    And I should see the link "Login to take part in forums »"
    And search result counter should match "^\d* Forum topics$"

  @anon
  Scenario: View the most popular forum topics RSS
    Given I am on "/forum/popular"
    And I wait until the page loads
    And I click RSS icon in "single" column in "first" row
    Then I should be on "/forum/popular/rss.xml"

  @anon
  Scenario: View the forum categories page
    Given I am on "/forum"
    When I follow "Forum categories"
    Then I should be on "/forum/categories"
    And I should see the following <breadcrumbs>
      | Forum      |
      | Categories |
    And I should see the link "Login to take part in forums »"
    And search result counter should match "^\d* Forum topics$"

  @anon
  Scenario: View a forum category page
    Given I am on "/forum/categories"
    When I follow "General discussion"
    And I should be on "/forum/general-discussion"
    And I should see "GENERAL DISCUSSION" pane in "first" column in "second" row
    And I should see "FORUM CATEGORIES" pane in "last" column in "second" row

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
  Scenario: Create a new forum topic
    Given that the user "test_user" is not registered
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
    When I am logged in as a user "test_user" with the "authenticated user" role
    Then I should see "Test forum topic" in My content and All content tabs but not in My drafts tab
    # Comment on "Test forum topic" as "test_commenting_user"
    Given that the user "test_commenting_user" is not registered
    And I am logged in as a user "test_commenting_user" with the "authenticated user" role
    And I break
    And I am on "/forum/general-discussion/test-forum-topic"
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
