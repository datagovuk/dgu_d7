@javascript
Feature: Request new data
  In order to unlock government data
  As a site user
  I should be able to request new data

  @anon
  Scenario: View latest data requests page as an anonymous user
    Given I am not logged in
    And I am on the homepage
    And I click "Data"
    When I follow "Data Requests"
    Then I should be on "/data-request"
    And I should see the following <breadcrumbs>
      | Data Requests         |
      | Latest data requests  |
    And "Data Requests" item in "Data" subnav should be active
    And I should see the link "Login to request new data"
    And view "latest_dataset_requests" view should have "5" rows
    And I should see the link "See all"
    And I should see "OPEN DATA USER GROUP" pane in "first" column in "second" row
    And I should see "ODUG MEMBERS" pane in "last" column in "second" row
    And I should see "USEFUL LINKS" pane in "last" column in "second" row
    And search result counter should match "^\d* Dataset requests \+ \d* confidential requests$"
    When I follow "Login to request new data"
    Then I should be on "/user/login?destination=/node/add/dataset-request"
    And I should see the following <breadcrumbs>
      | User account |
      | Login        |

  @api
  Scenario: View latest data requests page and create a Dataset request as an authenticated user
    Given that the user "test_user" is not registered
    And I am logged in as a user "test_user" with the "authenticated user" role
    And I am on "/data-request"
    When I follow "Request new data"
    Then I should be on "/node/add/dataset-request"
    And I should see "Create a dataset request"
    And I should see the following <breadcrumbs>
      | Add content              |
      | Create a dataset request |
    #Check we cannot see hidden fields
    And I should not see "Notes"
    And I should not see "Outcome"
    And I should not see "Status"
    When I press "Save draft"
    And I wait 1 second
    Then I should see "Data request title field is required."
    And I should see "Data request description field is required."
    And I should see "Data themes field is required."
    And I should see "Suggested use field is required."
    And I should see "Are you able to provide estimates of the economic or financial benefit of data release? field is required."
    And I should see "Publication preference field is required."
    And I should see "I request this data field is required."
    And I should not see "Organisation name field is required."
    And I should not see "Organisation type field is required."
    And the field "Data request title" should be outlined in red
    And the field "Data request description" should be outlined in red
    # Fill out new dataset request form
    And I fill in "Data request title" with "Test data request"
    And I fill in "Data request description" with "My Dataset request description"
    And I select the radio button "Request is public"
    And I select the radio button "On behalf of an Organisation"
    And I wait 2 seconds
    And I select the radio button "Start up"
    And I fill in "Organisation name" with "My organisation"
    And I check the box "Finance"
    And I select the radio button "Yes" with the id "edit-field-barriers-attempted-und-1"
    And I wait 1 second
    And I select the radio button "Other" with the id "edit-field-barriers-reason-und-9"
    And I check the box "Business Use"
    And I fill in "Benefits overview" with "The benefits overview of my dataset request"
    And I select the radio button "Yes" with the id "edit-field-barriers-attempted-und-1"
    And I select the radio button "No" with the id "edit-field-provide-estimates-und-0"
    And I fill in "Do you know who holds this data?" with "The Data holder"
    And I press "Save draft"
    And I wait until the page loads
    Then I should see the following <breadcrumbs>
      | Data Requests            |
      | Test data request |
    And I should see "Your draft Dataset Request has been created. You can update it in My Drafts section."
    And I should see "Please ensure your profile is up to date as we may use these details to contact you about your Dataset Request."
    When I submit "Dataset Request" titled "Test data request" for moderation
    # Moderate newly created dataset request
    And user with "moderator" role moderates "Test data request" authored by "test_user"
    And the cache has been cleared
    And I visit "/data-request"
    And I wait until the page loads
    Then "title" field in row "1" of "latest_dataset_requests" view should match "^Test data request$"
    And "name" field in row "1" of "latest_dataset_requests" view should match "^Submitted by test_user$"
    And "created" field in row "1" of "latest_dataset_requests" view should match "^\d* min \d* sec ago|\d* sec ago$"
    #
    # Test administration workflow
    #
    # Register test_subscriber
    And that the user "test_subscriber" is not registered
    And I am logged in as a user "test_subscriber" with the "authenticated user" role
    And I visit "/data-request"
    And I follow "Test data request"
    And I wait until the page loads
    When I click "Subscribe"
    And I wait 1 second
    Then I should see the link "Unsubscribe"
    # Register test_data_publisher user and assign it to "Academics" publisher
    Given that the user "test_data_publisher" is not registered
    And I am logged in as a user "test_data_publisher" with the "data publisher" role
    And user "test_data_publisher" belongs to "Academics" publisher
    And I am logged in as a user "test_data_publisher" with the "data publisher" role
    # Set weekly notifications for test_data_publisher
    And I visit "/user"
    And I wait until the page loads
    And I follow "My subscriptions"
    And I wait until the page loads
    And I follow "Delivery of notifications"
    And I wait until the page loads
    And I select the radio button "Weekly"
    And I press "Save"
    # Register test_data_request_manager user
    And that the user "test_data_request_manager" is not registered
    And I am logged in as a user "test_data_request_manager" with the "data request administrator" role
    # Set daily notifications for test_data_publisher
    And I visit "/user"
    And I wait until the page loads
    And I follow "My subscriptions"
    And I wait until the page loads
    And I follow "Delivery of notifications"
    And I select the radio button "Daily"
    And I press "Save"
    # Register test_data_request_admin user
    And that the user "test_data_request_admin" is not registered
    And I am logged in as a user "test_data_request_admin" with the "data request administrator" role
    And I am on "/admin/workbench"
    And I follow "Data requests"
    And I wait until the page loads
    And I follow "Test data request"
    And I wait until the page loads
    And I follow "Edit"
    And I wait until the page loads
    And I select "test_data_request_manager" from "Relationship manager"
    When I press "Save"
    And I wait until the page loads
    # Subscriber shouldn't be notified because it can't see this change, "Relationship manager" is a backend field which shouldn't be visible to normal users
    Then the "test_subscriber" user have not received an email 'Data request "Test data request" has been updated by test_data_request_admin '
    Given I am not logged in
    And I am logged in as a user "test_data_request_manager" with the "data request administrator" role
    When I visit "/admin/workbench"
    And I follow "My Data requests"
    And I wait until the page loads
    And I follow "Test data request"
    And I follow "Edit"
    And I wait until the page loads
    And I select the radio button "Escalated to data holder"
    And I wait 2 seconds
    And I select the radio button "Academics"
    And I wait 2 seconds
    And I select the radio button "test_data_publisher"
    And I press "Save"
    And I wait until the page loads
    Then I should see "Add review note"
    Given I visit "/admin/workbench"
    And I wait until the page loads
    When I follow "My Data requests"
    And I wait until the page loads
    Then I should see "Test data request"
    When I follow "My Edits"
    And I wait until the page loads
    Then I should see "Test data request"
    Given I am not logged in
    # Log in as test_data_publisher
    And I am logged in as a user "test_data_publisher" with the "data publisher" role
    When I visit "/admin/workbench"
    And I wait until the page loads
    And I follow "Active Data requests"
    And I wait until the page loads
    And I follow "Test data request"
    Then I should see "Add review note"
    # Set digest last run to 2 days ago to trigger daily notifications
    And I set digest last run to 2 days ago
    And I run cron
    Then the "test_data_request_manager" user received an email 'data.gov.uk Message Digest'
    # TODO - test summary of changes
    #Summary of changes:
    #Field "Publisher assignee" changed
    #from:
    #to: test_data_publisher
    And the "test_data_publisher" user have not received an email 'data.gov.uk Message Digest'
    And the "test_data_request_admin" user have not received an email 'data.gov.uk Message Digest'
    # Set digest last run to 10 days ago to trigger daily and weekly notifications
    When I set digest last run to 10 days ago
    And I run cron
    Then the "test_data_publisher" user received an email 'data.gov.uk Message Digest'
    And the "test_data_request_manager" user have not received an email 'data.gov.uk Message Digest'
    And the "test_data_request_admin" user have not received an email 'data.gov.uk Message Digest'
    # Test links in the email
    When user "test_data_publisher" clicks link containing "data-request/my-dataset-request-title" in mail 'data.gov.uk Message Digest'
    And I wait until the page loads
    Then I should be on "data-request/my-dataset-request-title"
    When user "test_data_publisher" clicks link containing "admin/workbench/content/active" in mail 'data.gov.uk Message Digest'
    And I wait until the page loads
    Then I should be on "admin/workbench/content/active"
    And I should see the link "Test data request"
    And I should see "Request is public"
    Then I should see the following <breadcrumbs>
      | Active Data requests |
    When user "test_data_publisher" clicks link containing "message-subscribe" in mail 'data.gov.uk Message Digest'
    And I wait until the page loads
    Then I should see the following <breadcrumbs>
      | My subscriptions |
    And I should see the link "Test data request"
    # Unsubscribe test_data_publisher from "Test data request"
    And I click "Unsubscribe"
    And I wait 2 seconds
    Then I should see the link "Subscribe"
    # Log in as test_data_request_manager and change relationship manager
    Given I am not logged in
    And I am logged in as a user "test_data_request_manager" with the "data request administrator" role
    And I visit "/admin/workbench"
    And I wait until the page loads
    And I follow "My Data requests"
    And I wait until the page loads
    When I follow "Test data request"
    And I wait until the page loads
    And I follow "Edit"
    And I wait until the page loads
    And I select "test_data_request_admin" from "Relationship manager"
    And I press "Save"
    Then the "test_data_request_admin" user received an email 'Data request "Test data request" has been assigned to you'
    And I should see "Add review note"
    Given I visit "/admin/workbench/content/my-data-requests"
    And I wait until the page loads
    Then I should not see "Test data request"
    When I follow "My Edits"
    And I wait until the page loads
    Then I should see "Test data request"
    # Set digest last run to 10 days ago to trigger daily and weekly notifications
    And I set digest last run to 10 days ago
    And I run cron
    Then the "test_data_request_manager" user received an email 'data.gov.uk Message Digest'
    And the "test_data_publisher" user have not received an email 'data.gov.uk Message Digest'
    And the "test_data_admin" user have not received an email 'data.gov.uk Message Digest'

  @anon
  Scenario: View ODUG minutes page
    Given I am not logged in
    And I am on "/data-request"
    When I follow "ODUG minutes"
    And I should be on "/library/?f[0]=im_field_document_type%3A90"
    And "Library" item in "Interact" subnav should be active
    And search result counter should match "^\d* Library resources$"

  @anon
  Scenario: View the data requests RSS
    Given I am on "/data-request"
    And I wait until the page loads
    And I click RSS icon in "first" column in "second" row
    Then I should be on "/odug/rss.xml"

  @anon @search
  Scenario: Use search box on dataset requests landing page with a keyword checking it is retained when using the facet link
    Given I am on "/data-request"
    When I fill in "Search dataset requests..." with "data"
    And I click search icon
    Then I should be on "/search/everything/data?f[0]=bundle%3Adataset_request&solrsort=score"
    And search result counter should match "^\d* Dataset requests$"
    And "Relevance" option in "Sort by:" should be selected
    And there should be "10" search results on the page
    And pager should match "^1 2 3 … »$"
    When I click "Dataset Request"
    Then I should be on "/search/everything/data?solrsort=score"
    And search result counter should match "^\d* Content results$"

  @anon @search
  Scenario: Use search box on dataset requests landing page without a keyword
    Given I am on "/data-request"
    And I click search icon
    Then I should be on "/search/everything/?f[0]=bundle%3Adataset_request"
    And search result counter should match "^\d* Dataset requests$"
    And "Author" option in "Sort by:" should be disabled
    And "Last updated" option in "Sort by:" should be selected
    And "Relevance" option in "Sort by:" should be disabled
    And "Content type" option in "Sort by:" should be disabled
    And I should see "Please enter some keywords to refine your search further."
    And there should be "10" search results on the page
    And pager should match "^1 2 3 … »$"

#TODO test private request access (node view and search index) for non admins
#TODO test presence of all fields on node view page