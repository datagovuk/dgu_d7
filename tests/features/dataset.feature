@javascript
Feature: Sync datasets from CKAN to Drupal

  @api
  Scenario: Subscribe to dataset comemnts and updates
    Given that dataset with titled "Test dataset" with name "test-dataset" published by "cabinet-office" exists and has no resources
    And that the user "test_user" is not registered
    And that the user "test_publisher_subscriber" is not registered
    And that the user "test_update_subscriber" is not registered
    And that the user "test_comment_subscriber" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    # test if new user won't receive notification
    And that the dataset with name "test-dataset" doesn't exist in Drupal
    When I visit "/ckan_dataset/test-dataset"
    # Then I should see "The requested page could not be found."
    When I synchronise dataset with name "test-dataset"
    And I visit "/ckan_dataset/test-dataset"
    Then I should see the link "Test dataset"
    And I should see "Published by"
    And the "test_user" user has not received an email 'Dataset "Test dataset" has been created '
    # Subscribe to a publisher
    And I am logged in as a user "test_publisher_subscriber" with the "authenticated user" role
    When I visit "/user"
    And I wait until the page loads
    And I follow "My subscriptions"
    And I wait until the page loads
    And I follow "Publisher subscriptions"
    And I wait until the page loads
    And I check "Cabinet Office"
    And I press "Save"
    And I wait until the page loads
    Then I should see "Bulk dataset updates can couse sending hundreds of notifications. We strongly recommend changing your preference to daily or weekly digest."
    And I press "Change to daily digest"
    Then I should see "You have changed your notification frequency to digest_day digest."
    And I should see "Cabinet Office"
    When I follow "Delivery of notifications"
    And I wait until the page loads
    And I select the radio button "Immediately as they are triggered"
    And I press "Save"
    # create a new dataset in Drupal, only test_publisher_subscriber should be notified
    Given that the dataset with name "test-dataset" doesn't exist in Drupal
    When I synchronise dataset with name "test-dataset"
    Then the "test_publisher_subscriber" user received an email 'Dataset "Test dataset" has been created '
    And the "test_user" user has not received an email 'Dataset "Test dataset" has been created '
    And the "test_update_subscriber" user has not received an email 'Dataset "Test dataset" has been created '
    And the "test_comment_subscriber" user has not received an email 'Dataset "Test dataset" has been created '
    # nobody should be notified about a new dataset on next sync
    When I synchronise dataset with name "test-dataset"
    Then the "test_publisher_subscriber" user has not received an email 'Dataset "Test dataset" has been created '
    And the "test_user" user has not received an email 'Dataset "Test dataset" has been created '
    And the "test_update_subscriber" user has not received an email 'Dataset "Test dataset" has been created '
    And the "test_comment_subscriber" user has not received an email 'Dataset "Test dataset" has been created '
    Given I am logged in as a user "test_update_subscriber" with the "authenticated user" role
    And I get comments of dataset named "test-dataset"
    And I click "Subscribe to updates"
    Given I am logged in as a user "test_comment_subscriber" with the "authenticated user" role
    And I get comments of dataset named "test-dataset"
    And I click "Subscribe to comments"
    # only "test_user_updates" user should be notified about dataset update
    When I attach "http://data.gov.uk/assets/img/ideas.png" resource to "test-dataset" dataset
    And I synchronise dataset with name "test-dataset"
    Then the "test_update_subscriber" user received an email 'Dataset "Test dataset" has been updated '
    And the "test_publisher_subscriber" user received an email 'Dataset "Test dataset" has been updated '
    And the "test_user" user has not received an email 'Dataset "Test dataset" has been updated '
    And the "test_comment_subscriber" user has not received an email 'Dataset "Test dataset" has been updated '
    # all 3 users shouldn't receive emails about new dataset on next sync if resources are the same
    When I synchronise dataset with name "test-dataset"
    Then the "test_update_subscriber" user has not received an email 'Dataset "Test dataset" has been updated '
    And the "test_publisher_subscriber" user has not received an email 'Dataset "Test dataset" has been updated '
    And the "test_user" user has not received an email 'Dataset "Test dataset" has been updated '
    And the "test_comment_subscriber" user has not received an email 'Dataset "Test dataset" has been updated '
    # all 3 users shouldn't receive emails about new dataset on next sync if resources are the same
    # only "test_user_updates" user should be notified about dataset update when new resource attached
    When I open comment form for dataset with name "test-dataset"
    And I follow "Add reply"
    And I wait until the page loads
    And I fill in "Subject" with "Test subject"
    And I type "Test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    And I press "Submit"
    And I wait 5 second
    Then I should see the link "test_comment_subscriber"
    #And I should see "Test subject"
    And the "test_comment_subscriber" user received an email 'User test_user_updates posted a comment on dataset "Test dataset" '
    And the "test_update_subscriber" user has not received an email 'User test_user_updates posted a comment on dataset "Test dataset" '
    And the "test_user" user has not received an email 'User test_user_updates posted a comment on dataset "Test dataset" '
