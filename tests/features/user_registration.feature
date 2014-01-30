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
    When I click "I want to create an account"
    And I wait 1 second
    And I fill in "Username " with random text
    And I fill in "E-mail address" with a random address
    And I fill in "Confirm password" with random text
    And I fill in "Password" with random text
    And I press "Create new account"
    And I break
    Then I should see "Thanks for registering with data.gov.uk - to complete registration - you will soon get an email to verify the email you supplied."
