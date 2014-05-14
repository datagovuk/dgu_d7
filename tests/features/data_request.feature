@javascript
Feature: Request new data
  In order to unlock government data
  As a site user
  I should be able to request new data

  @anon
  Scenario: View latest data requests page
    Given I am not logged in
    And I am on the homepage
    And I click "Data"
    When I follow "Data Requests"
    Then I should be on "/data-request"
    And I should see the link "Login to request new data"
    And I should see the link "See Dashboard"
    And I should see "ODUG OVERVIEW" pane in "first" column in "second" row
    And I should see "PROGRESS ON REQUESTS" pane in "last" column in "second" row
    And I should see "ODUG MEMBERS" pane in "last" column in "second" row
    And I should see "USEFUL LINKS" pane in "last" column in "second" row
    And search result counter should match "^\d* Dataset requests \+ \d* confidential requests$"

  @anon
  Scenario: View ODUG blogs page
    Given I am not logged in
    And I am on "/data-request"
    And I follow "ODUG Blogs"
    And I should be on "/data-request/blogs"
    And I should see the link "Login to request new data"
    And I should see the link "See Dashboard"
    And I should see "ODUG OVERVIEW" pane in "first" column in "second" row
    And I should see "PROGRESS ON REQUESTS" pane in "last" column in "second" row
    And I should see "ODUG MEMBERS" pane in "last" column in "second" row
    And I should see "USEFUL LINKS" pane in "last" column in "second" row
    And search result counter should match "^\d* Dataset requests \+ \d* confidential requests$"

  @anon
  Scenario: View ODUG minutes page
    Given I am not logged in
    And I am on "/data-request"
    And I follow "ODUG Minutes"
    And I should be on "/data-request/minutes"
    And I should see the link "Login to request new data"
    And I should see the link "See Dashboard"
    And I should see "ODUG OVERVIEW" pane in "first" column in "second" row
    And I should see "PROGRESS ON REQUESTS" pane in "last" column in "second" row
    And I should see "ODUG MEMBERS" pane in "last" column in "second" row
    And I should see "USEFUL LINKS" pane in "last" column in "second" row
    And search result counter should match "^\d* Dataset requests \+ \d* confidential requests$"

  @anon
  Scenario: View the data requests RSS
    Given I am on "/data-request"
    And I wait until the page loads
    And I click RSS icon in "first" column in "second" row
    Then I should be on "/odug/rss.xml"
