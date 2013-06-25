# language: en
Feature: register
  In order to participate
  Users must create an account

  @important @creates-user
  Scenario: Register user
    Given I have entered test into the username box
    And I have entered "test@test.test" into the email box
    And I have entered "test@test.test" into the confirm email box
    And I have entered password into the password box
    And I have entered password into the confirm password box
    When I press Create new account button
    Then I can see registration confirmation message