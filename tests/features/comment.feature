@javascript
Feature: Make comments as a regular site user
  In order to participate
  As a site user
  I should be able to make comments

  @anon
  Scenario: Make sure that comments can not be posted by anonymous users
    Given I am on "/forum"
    And I wait until the page loads
    When I click "title" field in row "1" of "panel_pane_latest_forum" view
    And I wait until the page loads
    Then I should see the link "Login to make a comment"

  @api
  Scenario: Create new comment and reply to this comment
    Given there is a test page with "test-page" path
    And that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    And I visit "/test-page"
    And I wait until the page loads
    And I should see the following <breadcrumbs>
      | Test page |
    When I follow "Add new comment"
    And I wait until the page loads
    And I fill in "Subject" with "Test subject"
    And I type "Test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    And I press "Submit"
    And I wait until the page loads
    Then I should be on "/test-page"
    And I should see the success message "Comment was successfully created."
    And I should see the heading "Comments"
    And I should see "Test subject"
    And I should see the link "test_user"
    And I should see "Test comment"
    And I should see the link "Reply"
    And I should see the link "Edit"
    Given that the user "test_second_user" is not registered
    And I am not logged in
    And I am logged in as a user "test_second_user" with the "authenticated user" role
    And I visit "/test-page"
    And I wait until the page loads
    And I should see the link "Reply"
    And I should not see the link "Edit"
    When I follow "Reply"
    And I wait until the page loads
    And I fill in "Subject" with "Reply subject"
    And I type "Test reply" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    And I press "Submit"
    And I wait until the page loads
    Then I should be on "/test-page"
    And I should see the success message "Comment was successfully created."
    And I should see "Reply subject"
    And I should see the link "test_second_user"
    And I should see "Test reply"
    And I should see the link "Reply"
    And I should see the link "Edit"
    When I click "Collapse all comments"
    And I wait until the page loads
    Then I should not see the link "Collapse all comments"
    And I should see the link "Expand all comments"
    And I should not see "Test comment"
    And I should not see "Test reply"
