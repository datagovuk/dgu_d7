@javascript
Feature: Submit new app as a regular site user
In order to inform how open data is used
As a site user
I should be able to submit a new app

  @anon
  Scenario: View apps landing page
    Given I am on the homepage
    And I click "Apps"
    When I follow "Browse Apps"
    And I wait until the page loads
    Then I should be on "/apps"
    And I should see "LATEST APPS" pane in "first" column in "third" row
    And I should see "TOP RATED APPS" pane in "last" column in "third" row

  @anon
  Scenario: View latest apps RSS
    Given I am on "/apps"
    And I wait until the page loads
    And I click RSS icon in "first" column in "third" row
    Then I should be on "/apps/latest/rss.xml"

  @anon
  Scenario: View top rated apps RSS
    Given I am on "/apps"
    And I wait until the page loads
    And I click RSS icon in "last" column in "third" row
    Then I should be on "/apps/top/rss.xml"

  @anon @search
  Scenario: View search apps page
    Given I am on the homepage
    And I click "Apps"
    When I follow "Search apps"
    And I wait until the page loads
    Then I should be on "/search/everything/?f[0]=bundle%3Aapp"
    And "Last updated" option in "Sort by:" should be selected
    And I should see "FILTER BY CONTENT TYPE:" pane in "first" column in "second" row
    And I should see "FILTER BY SECTOR:" pane in "first" column in "second" row
    And I should see "FILTER BY TAGS:" pane in "first" column in "second" row
    And I should see "FILTER BY TAGS:" pane in "first" column in "second" row

    #remove discrepancy - use 'apps' or 'Apps' in both links
  @anon @search
  Scenario: Use search box on Apps landing page
    Given I am on the homepage
    And I click "Apps"
    When I follow "Browse Apps"
    And I wait until the page loads
    When I fill in "Search Apps..." with "data"
    And I click search icon
    Then I should be on "/search/everything/data?f[0]=bundle%3Aapp&solrsort=score"
    And "Relevance" option in "Sort by:" should be selected

  @anon @search
  Scenario: Use search box on Apps landing page
    Given I am on the homepage
    And I click "Apps"
    When I follow "Browse Apps"
    And I wait until the page loads
    And I click search icon
    Then I should be on "/search/everything/?f[0]=bundle%3Aapp"
    And "Last updated" option in "Sort by:" should be selected
    And search result counter should contain "Apps"
    When I fill in "Search Apps..." with "data"
    And I click search icon
    Then "Relevance" option in "Sort by:" should be selected
    And search result counter should contain "Apps"

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
    And I should see page title "Apps"
    And I should see node title "TEST APP"
    And I should see "Developed by here"
    And I should see the link "test.co.uk"
    When I submit "App" titled "Test app" for moderation
    And user with "moderator" role moderates "Test app" authored by "test_user"
    When I am logged in as a user "test_user" with the "authenticated user" role
    Then I should see "Test app" in My content and All content tabs but not in My drafts tab
