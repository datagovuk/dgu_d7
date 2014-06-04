
@javascript
Feature: Create a Library Resource and search for library resources
  In order to easily find and create a library resource
  As a site user
  I should be able to search from a library search page from where I can also create a Library Resource

  @anon @search
  Scenario: View the library landing page and check default search result sort by option
    Given I am on the homepage
    And I click "Interact"
    When I follow "Library"
    Then I should be on "/library"
    And "Library" item in "Interact" subnav should be active
    And "Last updated" option in "Sort by:" should be selected
    And "Author" option in "Sort by:" should be disabled
    And "Relevance" option in "Sort by:" should be disabled
    And I should see the following <breadcrumbs>
      | Library |

  @anon @search
  Scenario: Use search box on Library landing page with and without a keyword to check the error message and solr sort.
    Given I am on "/library"
    And I should see the following <breadcrumbs>
      | Library |
    And I click search icon
    Then I should be on "/search/everything/?f[0]=bundle%3Aresource"
    And "Relevance" option in "Sort by:" should be disabled
    And "Content type" option in "Sort by:" should be disabled
    And "Last updated" option in "Sort by:" should be selected
    And I should see "Please enter some keywords to refine your search further."
    And I should see "DOCUMENT TYPE" pane in "first" column in "first" row
    And I should see "CATEGORY" pane in "first" column in "first" row
    And I should see "SECTOR" pane in "first" column in "first" row
    And I should see "TAGS" pane in "first" column in "first" row
    When I fill in "Search library resources..." with "data"
    And I click search icon
    Then I should be on "/search/everything/data?f[0]=bundle%3Aresource&solrsort=score"
    And I should see the following <breadcrumbs>
      | Search |
    And "Relevance" option in "Sort by:" should be selected
    And "Content type" option in "Sort by:" should be disabled
    And there should be "10" search results on the page
    And I should see "CONTENT TYPE" pane in "first" column in "first" row
    And I should see "CATEGORY" pane in "first" column in "first" row
    And I should see "DOCUMENT TYPE" pane in "first" column in "first" row
    And I should see "SECTOR" pane in "first" column in "first" row
    And I should see "TAGS" pane in "first" column in "first" row

  

#TODO use editor role instead of adminsitrator
