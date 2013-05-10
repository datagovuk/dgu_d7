# language: en
Feature: logon
  In order to avoid getting hacked
  Users must log in before seeing the admin menu

  @important
  Scenario: Admin user
    Given I have entered admin into the user box
    And I have entered pass into the password
    When I press login
    Then I can see the admin menu
