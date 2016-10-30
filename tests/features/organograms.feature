@javascript
Feature: Upload organograms
  In order to
  As an administrator
  I should be able to upload organograms

  @anon
  Scenario: View organograms
    Given I am not logged in
    And I am on the homepage
    And I click "Data"
    When I follow "Organograms"
    Then I should be on "/organogram/cabinet-office"
    And I should see the following <breadcrumbs>
      | Organogram     |
      | Cabinet Office |
    And I should see "Public body"
    And I should see "Version"
    And I should see the link "Source data"

  @api
  Scenario: Edit organograms
    Given that the user "test_admin" is not registered
    And I am logged in as a user "test_admin" with the "administrator" role
    And I am on "/organogram/cabinet-office"
    When I follow "Edit"
    Then I should see the link "Guidance: Preparing the data"
    And I should see "Organogram publication"
    And I should see "31 Mar 2011"