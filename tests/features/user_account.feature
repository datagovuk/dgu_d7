@javascript @anon
Feature: Register an account on data.gov.uk with valid username and email
  In order to start using additional features of the site
  As any user
  I should be able to register on the site

  Background:
    Given I am on the homepage
    And I am not logged in
    And I follow "Log in"
    And I wait until the page loads

  Scenario: Login form
    Then I should not see "You are not logged in."
    And I should see the following <links>
    | links                       |
    | I have an account           |
    | I want to create an account |
    | Request new password        |
    And I should see the following <texts>
    | texts                      |
    | Username or e-mail address |
    | Password                   |

  Scenario: Registration form
    When I click "I want to create an account"
    Then I should not see "You are not logged in."
    And I should see the following <texts>
      | texts                      |
      | Username                   |
      | E-mail address             |
      | Password                   |
      | Confirm password           |
    When I fill in "Password" with "a"
    Then I should see the following <texts>
      | texts                           |
      | To make your password stronger: |
      | Make it at least 6 characters   |
      | Add uppercase letters           |
      | Add numbers                     |
      | Add punctuation                 |
    When I fill in "Password" with "A"
    Then I should not see "Add uppercase letters"
    When I fill in "Password" with "1"
    Then I should not see "Add numbers"
    When I fill in "Password" with "."
    Then I should not see "Add punctuation"
    When I fill in "Password" with "123456"
    Then I should not see "Make it at least 6 characters"
    When I fill in "Password" with "aaaA1."
    Then I should not see "To make your password stronger"
    When I fill in "Confirm password" with "a"
    Then I should see "Passwords match: no"
    When I fill in "Confirm password" with "aaaA1."
    Then I should see "Passwords match: yes"

  @api @email
  Scenario: Create an account, message for unverified users, email verification
    # Create an account.
    Given that the user "test_user" is not registered
    When I click "I want to create an account"
    And I fill in "Username " with "test_user"
    And I fill in "E-mail address" with "test_user" address
    And I fill in "Password" with "Password1"
    And I fill in "Confirm password" with "Password1"
    And I press "Create new account"
    Then I should see "Thanks for registering with data.gov.uk - to complete registration - you will soon get an email to verify the email you supplied."
    And I should not be logged in
    # Message for unverified users.
    Given I am on the homepage
    And I follow "Log in"
    And I log in as the "test_user" with the password "Password1"
    Then I should see "You will now receive an email to verify your email address. In order to activate your data.gov.uk account just follow the simple step requested in this email."
    And I should see "tab to add more detail to your profile."
    And I should see "validation e-mail."
    # Email verification.
    Given the "test_user" user received an email 'Account details for test_user at data.gov.uk'
    When user "test_user" clicks link containing "user/validate" in mail 'Account details for test_user at data.gov.uk'
    Then I should be on "/user"
    And I should see "You have successfully validated your e-mail address."
    # Password reset using user name.
    Given I am not logged in
    And I go to "/user"
    And I fill in "Username " with "test_user"
    And I fill in "Password" with "invalid"
    And I press "Log in"
    Then I should see "Sorry, unrecognized username or password"
    And I fill in "Password" with "invalid"
    And I press "Log in"
    And I fill in "Password" with "invalid"
    And I press "Log in"
    And I fill in "Password" with "invalid"
    And I press "Log in"
    And I fill in "Password" with "invalid"
    And I press "Log in"
    And I fill in "Password" with "invalid"
    And I press "Log in"
    And I wait until the page loads
    And I should see "Sorry, there have been more than 5 failed login attempts for this account. It is temporarily blocked. Try again after one hour or request a new password."
    When I follow "Request new password"
    And I wait until the page loads
    And I fill in "Username or e-mail address" with "test_user"
    And I press "E-mail new password"
    And I wait 3 seconds
    And the "test_user" user received an email 'Replacement login information for test_user at data.gov.uk'
    And I should see "Further instructions have been sent to your e-mail address."
    And user "test_user" clicks link containing "user/reset" in mail 'Replacement login information for test_user at data.gov.uk'
    And I wait until the page loads
    Then I should see "Reset password"
    And I should see "Click on this button to log in to the site and change your password."
    And I should see "This login can be used only once."
    When I press "Log in"
    Then I should see "You have just used your one-time login link. It is no longer necessary to use this link to log in. Please change your password."
    # Password reset using emails address.
    Given I am not logged in
    And I go to "/user"
    And I follow "Request new password"
    And I wait until the page loads
    And I fill in "Username or e-mail address" with "test_user" address
    And I press "E-mail new password"
    And I wait 3 seconds
    Then the "test_user" user received an email 'Replacement login information for test_user at data.gov.uk'
    And I should see "Further instructions have been sent to your e-mail address."
    When user "test_user" clicks link containing "user/reset" in mail 'Replacement login information for test_user at data.gov.uk'
    And I wait until the page loads
    Then I should see "Reset password"
    And I should see "Click on this button to log in to the site and change your password."
    And I should see "This login can be used only once."
    When I press "Log in"
    Then I should see "You have just used your one-time login link. It is no longer necessary to use this link to log in. Please change your password."

  @api
  Scenario: Authenticated user profile
    Given that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    And I am on the homepage
    And I follow "test_user"
    And I wait until the page loads
    Then I should be on "/user"
    And I should see the following <links>
      | links                       |
      | My profile                  |
      | View                        |
      | Edit                        |
      | Manage my content           |
      | Create content              |
    And I should not see the following <links>
      | links                       |
      | File list                   |
      | Offensive content           |
      | Offensive replies           |
      | Needs review                |
    And I should see "Member for"
    Given I have an image "500" x "400" pixels titled "Test user picture" located in "/tmp/" folder
    And I follow "Edit"
    And I attach the file "/tmp/Test user picture.png" to "files[field_avatar_und_0]"
    When I press "Upload"
    And I wait until the page loads
    Then I should see "Click on the image and drag to mark how the image will be cropped"
    #Then I should see an "field_avatar_und_0_remove_button" element
