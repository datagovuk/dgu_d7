@javascript
Feature: Sync datasets from CKAN to Drupal

  @api
  Scenario: Subscribe to dataset comemnts and updates
    Given that dataset with titled "Test dataset" with name "test-dataset" published by "cabinet-office" exists and has no resources
    And that the user "test_user" is not registered
    And that the user "test_user_updates" is not registered
    And that the user "test_user_comments" is not registered
    And I am logged in as a user "test_user" with the "CKAN sysadmin" role
    # test if new user won't receive notification
    And that the dataset with name "test-dataset" doesn't exist in Drupal
    When I visit "/ckan_dataset/test-dataset"
    Then I should see "The requested page could not be found."
    When I synchronise dataset with name "test-dataset"
    And I visit "/ckan_dataset/test-dataset"
    Then I should see the link "Test dataset"
    And I should see "Published by"
    And the "test_user" user have not received an email 'Dataset "Test dataset" has been created '
    # setting 3 different dataset notifications configurations for 3 differnet users
    When I visit "/user"
    And I wait until the page loads
    And I follow "My subscriptions"
    And I wait until the page loads
    And I click "Auto subscribe"
    And I wait until the page loads
    And I check "Dataset"
    And I wait 1 second
    And I press "Save"
    And I wait until the page loads
    Given I am logged in as a user "test_user_comments" with the "authenticated user" role
    And I visit "/user"
    And I wait until the page loads
    And I follow "My subscriptions"
    And I wait until the page loads
    And I click "Auto subscribe"
    And I wait until the page loads
    And I check "Dataset"
    And I wait 1 second
    When I check "Automatically subscribe to comments on datasets"
    And I wait 1 second
    And I press "Save"
    And I wait until the page loads
    Given I am logged in as a user "test_user_updates" with the "authenticated user" role
    And I visit "/user"
    And I wait until the page loads
    And I follow "My subscriptions"
    And I wait until the page loads
    And I click "Auto subscribe"
    And I wait until the page loads
    And I check "Dataset"
    And I wait 1 second
    When I check "Automatically subscribe to dataset updates"
    And I wait 1 second
    And I press "Save"
    And I wait until the page loads
    # all 3 users should receive emails about new dataset
    And I synchronise dataset with name "test-dataset"
    And that the dataset with name "test-dataset" doesn't exist in Drupal
    And I synchronise dataset with name "test-dataset"
    Then the "test_user" user received an email 'Dataset "Test dataset" has been created '
    And the "test_user_updates" user received an email 'Dataset "Test dataset" has been created '
    And the "test_user_comments" user received an email 'You have been subscribed to comments on new dataset "Test dataset" '
    # all 3 users shouldn't receive emails about new dataset on next sync
    When I synchronise dataset with name "test-dataset"
    Then the "test_user" user have not received an email 'Dataset "Test dataset" has been created '
    And the "test_user_updates" user have not received an email 'Dataset "Test dataset" has been created '
    And the "test_user_comments" user have not received an email 'You have been subscribed to comments on new dataset "Test dataset" '
    # only "test_user_updates" user should be notified about dataset update
    When I attach "http://data.gov.uk/assets/img/ideas.png" resource to "test-dataset" dataset
    And I synchronise dataset with name "test-dataset"
    Then the "test_user_updates" user received an email 'Dataset "Test dataset" has been updated '
    And the "test_user" user have not received an email 'Dataset "Test dataset" has been updated '
    And the "test_user_comments" user have not received an email 'Dataset "Test dataset" has been updated '
    # all 3 users shouldn't receive emails about new dataset on next sync if resources are the same
    And I synchronise dataset with name "test-dataset"
    Then the "test_user" user have not received an email 'Dataset "Test dataset" has been updated '
    And the "test_user_updates" user have not received an email 'Dataset "Test dataset" has been updated '
    And the "test_user_comments" user have not received an email 'Dataset "Test dataset" has been updated '
    When I attach "http://data.gov.uk/assets/img/apps.png" resource to "test-dataset" dataset
    # only "test_user_updates" user should be notified about dataset update when new resource attached
    And I synchronise dataset with name "test-dataset"
    Then the "test_user_updates" user received an email 'Dataset "Test dataset" has been updated '
    And the "test_user" user have not received an email 'Dataset "Test dataset" has been updated '
    And the "test_user_comments" user have not received an email 'Dataset "Test dataset" has been updated '
    When I open comment form for dataset with name "test-dataset"
    And I follow "Add reply"
    And I wait until the page loads
    And I fill in "Subject" with "Test subject"
    And I type "Test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    And I press "Submit"
    And I wait 5 second
    Then I should see the link "test_user_updates"
    # disabled in CKAN... ?
    #And I should see "Test subject"
    And the "test_user_comments" user received an email 'User test_user_updates posted a comment on dataset "Test dataset" '
    And the "test_user_updates" user have not received an email 'User test_user_updates posted a comment on dataset "Test dataset" '
    And the "test_user" user have not received an email 'User test_user_updates posted a comment on dataset "Test dataset" '
