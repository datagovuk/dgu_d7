@javascript @anon @wip
Feature: Register an account on data.gov.uk with valid username and email
  In order to start using additional features of the site
  As any user
  I should be able to register on the site

  Background:
    Given I am on the homepage
    And I am not logged in
    And I follow login link
    And I wait until the page loads

  Scenario: Register to the site
    Then I should see "You are not logged in."
    And I should see the following <links>
    | links                       |
    | I have an account           |
    | I want to create an account |
    | Request new password        |
    And I should see the following <texts>
    | texts                      |
    | Username or e-mail address |
    | Password                   |

  Scenario: Create an account
    When I follow "I want to create an account"
    And I wait 1 second
    And I wait until the page loads
    And I fill in "Username " with "user"
    #And I fill in "Username " with random text
    And I break
    And I press "Create new account"
    Then I should see "A welcome message with further instructions has been sent to your e-mail address."
