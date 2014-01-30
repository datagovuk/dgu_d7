@javascript @anon
Feature: About section
  In order to find out about data.gov.uk
  As any user
  I want to find information on an About page

  Scenario: Browse to the About page
    Given I am on the homepage
    When I follow "About"
    And I wait until the page loads
    Then I should see the heading "About"
    And I should see "WHAT'S DATA.GOV.UK ALL ABOUT?" pane in "last" column

  Scenario: Browse to Technical details page
    Given I am on "/about"
    When I follow "Technical details"
    And I wait until the page loads
    Then I should see the heading "About - Technical Details"
    And I should see the heading "Comments"
    And I should see "WHAT'S DATA.GOV.UK ALL ABOUT?" pane in "last" column
