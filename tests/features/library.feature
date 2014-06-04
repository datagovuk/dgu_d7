
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

#TODO use editor role instead of adminsitrator
