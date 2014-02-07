@javascript @anon @wip @api
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

  @api
  Scenario: Create an account
    Given that the user "test_user" is not registered
    When I click "I want to create an account"
    And I fill in "Username " with "test_user"
    And I fill in "E-mail address" with "test_user" address
    And I fill in "Password" with "Password1"
    And I fill in "Confirm password" with "Password1"
    And I press "Create new account"
    Then I should see "Thanks for registering with data.gov.uk - to complete registration - you will soon get an email to verify the email you supplied."
    And I should not be logged in
    And I am on the homepage
    And I follow login link
    And I log in as the "test_user" with the password "Password1"
    Then I should see "You will now receive an email to verify your email address. In order to activate your data.gov.uk account just follow the simple step requested in this email."
    And I should see "tab to add more detail to your profile."
    And I should see "validation e-mail."
    Given the "test_user" user received an email "Account details for test_user at data.gov.uk"
    When user "test_user" clicks link containing "user/validate" in mail "Account details for test_user at data.gov.uk"
    Then I should be on "/admin/workbench"
    And I should see "You have successfully validated your e-mail address."


  Scenario: test
    And the "test_user" user received an email "Account details for test_user at data.gov.uk"
    And I break
    Given TEST