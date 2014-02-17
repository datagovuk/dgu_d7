@javascript
Feature: Create new forum topic as a site user
  In order to discuss a topic
  As a site user
  I should be able to post a new forum topic

  @anon
  Scenario: View the forum categories page
    Given I am on the homepage
    And I click "Interact"
    When I follow "All Forums"
    Then I should be on "/forum"
    And I should see "FORUM CATEGORIES" pane in "single" column in "first" row
    And I should not see "Create new Forum topic"

  @anon
  Scenario: View the forum RSS
    Given I am on "/forum"
    And I wait until the page loads
    And I click RSS icon in "single" column in "first" row
    Then I should be on "/forum/rss.xml"

  Scenario: View the forum category page
    Given I am on "/forum"
    When I follow "General discussion"
    And I should be on "/forum/general-discussion"
    And I should see "FORUM CATEGORIES" pane in "last" column in "first" row
    And I should see "SEARCH FORUM POSTS" pane in "last" column in "first" row

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
    Given I am logged in as a user with the "authenticated user" role
    And I visit "/forum"
    And I create "Test forum" forum topic in "General discussion" category

