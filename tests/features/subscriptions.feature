@javascript
Feature: Subscribe to content updates
  In order to follow content
  As a user
  I should be able to subscribe to content and receive email notifications

  @api
  Scenario: Subscribe user to a blog and test email digest
    # Create a blog
    Given that the user "test_editor" is not registered
    And I am logged in as a user "test_editor" with the "editor" role
    And user "test_editor" created "blog" titled "Test blog"
    And the cache has been cleared
    # Set daily notifications for test_daily_subscriber and subscribe to Test blog
    And that the user "test_daily_subscriber" is not registered
    And I am logged in as a user "test_daily_subscriber" with the "authenticated user" role
    And I visit "/user"
    And I wait until the page loads
    And I follow "Edit"
    And I wait until the page loads
    And I select "Daily" from "Notification frequency"
    And I press "Save"
    And I visit "/blog"
    And I wait until the page loads
    And I click "Test blog"
    And I wait until the page loads
    When I click "Subscribe"
    And I wait 1 second
    # Set weekly notifications for test_daily_subscriber and subscribe to Test blog
    And that the user "test_weekly_subscriber" is not registered
    And I am logged in as a user "test_weekly_subscriber" with the "authenticated user" role
    And I visit "/user"
    And I wait until the page loads
    And I follow "Edit"
    And I wait until the page loads
    And I select "Weekly" from "Notification frequency"
    And I press "Save"
    And I visit "/blog"
    And I wait until the page loads
    And I click "Test blog"
    And I wait until the page loads
    When I click "Subscribe"
    And I wait 1 second
    # Comment on Test blog to triger notifications
    Given I am logged in as a user "test_editor" with the "editor" role
    And I visit "/user"
    And I wait until the page loads
    And I click "Test blog"
    And I wait until the page loads
    And I follow "Add new comment"
    And I fill in "Subject" with "Test subject"
    And I type "Test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    When I press "Submit"
    And I wait until the page loads
    Then the "test_daily_subscriber" user have not received an email 'data.gov.uk Message Digest'
    And the "test_weekly_subscriber" user have not received an email 'data.gov.uk Message Digest'
    # Set digest last run to 2 days ago to trigger daily notifications
    When I set digest last run to 2 days ago
    And I run cron
    Then the "test_daily_subscriber" user received an email 'data.gov.uk Message Digest'
    And the "test_weekly_subscriber" user have not received an email 'data.gov.uk Message Digest'
    When I set digest last run to 10 days ago
    And I run cron
    Then the "test_daily_subscriber" user have not received an email 'data.gov.uk Message Digest'
    And the "test_weekly_subscriber" user received an email 'data.gov.uk Message Digest'
