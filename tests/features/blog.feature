@javascript
Feature: Create new forum topic as a site user
  In order to discuss a topic
  As a site user
  I should be able to post a new forum topic

  @anon
  Scenario: View latest blogs page
    Given I am on the homepage
    And I click "Interact"
    When I follow "All Blogs"
    Then I should be on "/blog"
    And I should see "FREQUENT BLOGGERS" pane in "last" column in "second" row
    And search result counter should contain "Blogs"

  @anon
  Scenario: View most popular blogs page
    Given I am on "/blog"
    And I follow "Most popular Blogs"
    And I should be on "/blog/popular"
    And I should see "FREQUENT BLOGGERS" pane in "last" column in "second" row
    And search result counter should contain "Blogs"

  @anon
  Scenario: View the blog RSS
    Given I am on "/blog"
    And I wait until the page loads
    And I click RSS icon in "first" column in "second" row
    Then I should be on "/blog/rss.xml"

  @api
  Scenario: Create a new blogs entry with empty required fields
    #todo - use blogger role
    Given I am logged in as a user with the "blogger" role
    And I visit "/node/add/blog"
    When I press "Save"
    Then I should see "Title field is required"
    And the field "Title" should be outlined in red

  @api
  Scenario: Create a new blog entry
    Given that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "blogger" role
    And I visit "/node/add/blog"
    And I fill in "Title" with "Test blog"
    When I press "Save draft"
    And I wait until the page loads
    Then I should see a message about created draft "Blog entry"
    And I should see node title "Test blog"
    When I submit "Blog entry" titled "Test blog" for moderation
    And user with "moderator" role moderates "Test blog" authored by "test_user"
    When I am logged in as a user "test_user" with the "authenticated user" role
    Then I should see "Test blog" in My content and All content tabs but not in My drafts tab





