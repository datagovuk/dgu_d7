@javascript
Feature: Subscribe to content updates
  In order to follow content
  As a user
  I should be able to subscribe to content and receive email notifications

  @api
  Scenario: Subscribe user to a blog and test notifications about comment and blog update
    # Create a blog
    Given that the user "test_editor" is not registered
    And I am logged in as a user "test_editor" with the "editor" role
    And user "test_editor" created "blog" titled "Test blog"
    # Subscribe to this blog by test_user
    And that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    And the cache has been cleared
    And I visit "/blog"
    And I wait until the page loads
    And I click "Test blog"
    And I wait until the page loads
    And I should not see "Unsubscribe"
    When I click "Subscribe"
    And I wait 1 second
    Then I should see the link "Unsubscribe"
    Given I am logged in as a user "test_editor" with the "editor" role
    And I visit "/user"
    And I wait until the page loads
    And I click "Test blog"
    And I wait until the page loads
    And I click "Edit"
    And I wait until the page loads
    And I fill in "Title" with "Amended test blog"
    And I click "Publishing options"
    And I wait 1 second
    And I select "Published" from "Moderation state"
    When I press "Save"
    And I wait until the page loads
    Then I should see "Amended test blog"
    And I break
    # test_editor isn't subscribed
    And I should see the link "Subscribe"
    And the "test_user" user received an email 'Blog entry "Test blog" has been updated by test_editor'
    And I follow "Add new comment"
    And I fill in "Subject" with "Test subject"
    And I type "Test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    When I press "Submit"
    Then the "test_user" user received an email 'User test_editor posted a comment on Blog entry "Amended test blog"'
    Given I am logged in as a user "test_user" with the "authenticated user" role
    When user "test_user" clicks link containing "/blog/" in mail 'User test_editor posted a comment on Blog entry "Amended test blog"'
    And I wait until the page loads
    Then I should see the following <breadcrumbs>
      | Blog              |
      | Amended test blog |
    When user "test_user" clicks link containing "/message-subscribe" in mail 'Blog entry "Test blog" has been updated by test_editor'
    Then I should see the following <breadcrumbs>
      | My subscriptions |
    And I should see the link "Amended test blog"
    And I should see the link "Unsubscribe"
    When user "test_user" clicks link containing "/edit" in mail 'Blog entry "Test blog" has been updated by test_editor'
    Then I should see the following <breadcrumbs>
      | test_user |
      | Edit      |
    And I click "My subscriptions"
    And I should see the link "Amended test blog"
    When I click "Unsubscribe"
    And I wait 1 second
    Then I should not see "Unsubscribe"
    And I should see the link "Subscribe"
    And the cache has been cleared
    And I visit "/blog"
    And I wait until the page loads
    And I click "Amended test blog"
    And I wait until the page loads
    And I should not see "Unsubscribe"
    And I should see the link "Subscribe"

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
