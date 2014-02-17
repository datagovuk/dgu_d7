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

    #remove discrapancy - use 'apps' or 'Apps' in both links
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
