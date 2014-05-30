@javascript
Feature: Search content as a site user
  In order for me to easily find content which I am searching for
  As a site user
  I should be able to search the content of the site.

  @anon @search
  Scenario: View Search content landing page
    Given I am on the homepage
    And I click "Interact"
    When I follow "Search content"
    Then I should be on "/search/everything"
    And "Search content" item in "Interact" subnav should be active
    And I should see the following <breadcrumbs>
      | Search |
    And "Last updated" option in "Sort by:" should be selected
    And "Author" option in "Sort by:" should be disabled
    And there should be "10" search results on the page
    And pager should match "^1 2 3 … »$"

  @anon @search
  Scenario: Use search box on Search content landing page without a keyword
    Given I am on "/search/everything/"
    And I click search icon
    Then I should be on "/search/everything/"
    And "Relevance" option in "Sort by:" should be disabled
    And "Last updated" option in "Sort by:" should be selected
    And I should see "Please enter some keywords to refine your search further."
    And there should be "10" search results on the page
    And pager should match "^1 2 3 … »$"

  @anon @search
  Scenario: Use search box on Search content landing page with a keyword
    Given I am on "/search/everything/"
    When I fill in "Search content..." with "data"
    And I click search icon
    Then I should be on "/search/everything/data?solrsort=score"
    And "Relevance" option in "Sort by:" should be selected
    And there should be "10" search results on the page
    And pager should match "^1 2 3 … »$"

  #TODO in search.feature we need to add a scenario for testing if keyword is preserved when a facet is un-/selected

  @anon @search
  Scenario: Search for content using the Page facet link after the 'Content type' sort by is selected .
    Given I am on "/search/everything/"
    When I select "Content type" from "search-results-sort"
    And I wait until the page loads
    Then "Content type" option in "Sort by:" should be selected
    When I follow "Page"
    And I wait until the page loads
    Then I should be on "/search/everything/?f[0]=bundle%3Apage"
    And "Search content" item in "Interact" subnav should be active
    And "Content type" option in "Sort by:" should be disabled
    And "Last updated" option in "Sort by:" should be selected
    And I should see the following <breadcrumbs>
      | Search |
    And I should see "CONTENT TYPE" pane in "first" column in "first" row
    And I should see "CATEGORY" pane in "first" column in "first" row
    And I should see "SECTOR" pane in "first" column in "first" row
    And I should see "TAGS" pane in "first" column in "first" row
    And there should be "10" search results on the page
    And search result counter should match "^\d* Pages"
    And pager should match "^1 2 3 … »$"
