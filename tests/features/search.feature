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
    And there should be "10" search results on the page

  @anon @search
  Scenario: Use search box on Search content landing page without a keyword
    Given I am on the homepage
    And I click "Interact"
    When I follow "Search content"
    And I wait until the page loads
    And I click search icon
    Then I should be on "/search/everything/"
    And "Relevance" option in "Sort by:" should be disabled
    And "Last updated" option in "Sort by:" should be selected
    And I should see "Please enter some keywords to refine your search further."

  @anon @search
  Scenario: Use search box on Search content landing page with a keyword
    Given I am on the homepage
    And I click "Interact"
    When I follow "Search content"
    And I wait until the page loads
    When I fill in "Search content..." with "data"
    And I click search icon
    Then I should be on "/search/everything/data?solrsort=score"
    And "Relevance" option in "Sort by:" should be selected
    And there should be "10" search results on the page

  @anon @search
  Scenario: Search for content from the Search content landing page using the content type facet link after the user has selected 'Content type' sort.
    Given I am on the homepage
    And I click "Interact"
    And I follow "Search content"
    And I wait until the page loads
    When I click search icon
    And I wait until the page loads
    Then I should be on "/search/everything/"
    And "Search content" item in "Interact" subnav should be active
    And I should see "Please enter some keywords to refine your search further"
    And I should see the following <breadcrumbs>
      | Search |
    And "Last updated" option in "Sort by:" should be selected
    And there should be "10" search results on the page
    And pager should match "^1 2 3 … »$"
    And I should see "CONTENT TYPE" pane in "first" column in "first" row
    When I follow "/search/everything/?solrsort=bundle%20asc"
    And I wait until the page loads
    Then "Content type" option in "Sort by:" should be selected
    When I follow "Dataset Request"
    And I wait until the page loads
    And "Content type" option in "Sort by:" should be disabled
    And "Last updated" option in "Sort by:" should be selected
    And I should see the following <breadcrumbs>
      | Data requests |
      | Search |

  @anon @search
  Scenario: View Search Library landing page
    Given I am on the homepage
    And I click "Interact"
    When I follow "Library"
    Then I should be on "/library"
    And "Library" item in "Interact" subnav should be active
    And "Relevance" option in "Sort by:" should be disabled
    And "Last updated" option in "Sort by:" should be selected
    And I should see the following <breadcrumbs>
      | Library |

  @anon @search
  Scenario: Use search box on Library landing page without a keyword
    Given I am on the homepage
    And I click "Interact"
    When I follow "Library"
    And I wait until the page loads
    And I click search icon
    Then I should be on "/search/everything/?f[0]=bundle%3Aresource"
    And "Relevance" option in "Sort by:" should be disabled
    And "Content type" option in "Sort by:" should be disabled
    And "Last updated" option in "Sort by:" should be selected
    And I should see "Please enter some keywords to refine your search further."
    And I should see the following <breadcrumbs>
      | Library |

  @anon @search
  Scenario: Use search box on Library landing page with a keyword
    Given I am on the homepage
    And I click "Interact"
    When I follow "Search content"
    And I wait until the page loads
    When I fill in "Search content..." with "data"
    And I click search icon
    Then I should be on "/search/everything/data?f[0]=bundle%3Aresource&solrsort=score"
    And "Relevance" option in "Sort by:" should be selected
    And there should be "10" search results on the page
