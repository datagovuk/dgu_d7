@javascript
Feature: View latest apps landing page and submit a new app for moderation as a regular site user
  In order to inform how open data is used
  As a site user
  I should be able to search for apps which are published and submit a new App

  @anon
  Scenario: View latest apps landing page and check Top rated apps page
    Given I am on the homepage
    And I am not logged in
    And I click "Apps"
    And I wait until the page loads
    Then I should be on "/apps"
    And view "latest_apps" view should have "5" rows
    And I should see the link "Login to add your app »"
    And I should see the following <breadcrumbs>
      | Apps        |
      | Latest apps |
    And search result counter should match "^\d* Apps$"
    And pager should match "^1 2 3 … »$"
    When I follow "Top rated apps"
    And I wait until the page loads
    Then I should be on "/apps/top"
    Then I should see the link "Login to add your app »"
    And I should see the following <breadcrumbs>
      | Apps           |
      | Top rated apps |
    And view "top_rated_apps" view should have "5" rows
    And search result counter should match "^\d* Apps$"
    And pager should match "^1 2 3 … »$"

  @anon
  Scenario: View latest apps RSS
    Given I am on "/apps"
    And I wait until the page loads
    And I click RSS icon in "first" column in "fourth" row
    Then I should be on "/apps/latest/rss.xml"

  @anon
  Scenario: View top rated apps RSS
    Given I am on "/apps/top"
    And I wait until the page loads
    And I click RSS icon in "first" column in "fourth" row
    Then I should be on "/apps/top/rss.xml"

  @anon @search
  Scenario: View search apps page
    Given I am on the homepage
    And I click "Apps"
    And I wait until the page loads
    When I click search icon
    And I wait until the page loads
    Then I should be on "/search/everything/?f[0]=bundle%3Aapp"
    And "Last updated" option in "Sort by:" should be selected
    And I should see "CONTENT TYPE" pane in "first" column in "first" row
    And I should see "SECTOR" pane in "first" column in "first" row
    And I should see "TAGS" pane in "first" column in "first" row
    And search result counter should match "^\d* Apps$"

  @anon @search
  Scenario: Use search box on Apps landing page
    Given I am on the homepage
    And I click "Apps"
    And I wait until the page loads
    When I fill in "Search apps..." with "data"
    And I click search icon
    Then I should be on "/search/everything/data?f[0]=bundle%3Aapp&solrsort=score"
    And "Relevance" option in "Sort by:" should be selected

  @anon @search
  Scenario: Use search box on Apps search page
    Given I am on the homepage
    And I click "Apps"
    And I wait until the page loads
    And I click search icon
    Then I should be on "/search/everything/?f[0]=bundle%3Aapp"
    And "Last updated" option in "Sort by:" should be selected
    And search result counter should match "^\d* Apps$"
    When I fill in "Search apps..." with "data"
    And I click search icon
    Then "Relevance" option in "Sort by:" should be selected
    And search result counter should match "^\d* Apps$"

  @api
  Scenario: Create a new app and test moderation workflow
    Given that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    And I visit "/apps"
    And I follow "Add your app"
    And I have an image "300" x "300" pixels titled "Test image" located in "/tmp/" folder
    And I attach the file "/tmp/Test image.png" to "files[field_screen_shots_und_0]"
    And I fill in "Name" with "Test app"
    And I fill in "URL" with "test.co.uk"
    And I fill in "Developed by" with "Developed by here"
    And I fill in "Submitter Name" with "Submitter Name here"
    And I fill in "Submitter e-mail" with "submitter@example.com"
    And I select "Free" from "App charge"
    And I select "Health" from "Category"
    And I select "Other" from "Sector"
    When I press "Save draft"
    And I wait until the page loads
    Then I should see a message about created draft "App"
    And I should see node title "Test app"
    And I should see "Developed by here"
    And I should see the link "test.co.uk"
    When I submit "App" titled "Test app" for moderation
    And user with "moderator" role moderates "Test app" authored by "test_user"
    When I am logged in as a user "test_user" with the "authenticated user" role
    Then I should see "Test app" in My content and All content tabs but not in My drafts tab
