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
    And I should see the link "See Dashboard"
    And view "latest_dataset_requests" view should have "5" rows
    And pager in "latest_dataset_requests" view should match "^1 2 3 … »$"
    And I should see "ODUG OVERVIEW" pane in "first" column in "second" row
    And I should see "PROGRESS ON REQUESTS" pane in "last" column in "second" row
    And I should see "ODUG MEMBERS" pane in "last" column in "second" row
    And I should see "USEFUL LINKS" pane in "last" column in "second" row
    And I should see "Login to request new data"
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
    And I should see "Request new data"
    When I follow "Request new data"
    Then I should be on "/node/add/dataset-request"
    And I should see "Create a dataset request"
    And I should see the following <breadcrumbs>
      |  Add content               |
      |  Create a dataset request  |
    And I should see "WHO ARE YOU?"
    And I should see "WHAT DATA WOULD YOU LIKE RELEASED?"
    And I should see "HAVE YOU FACED CHALLENGES IN ACCESSING THIS DATA?"
    And I should see "WHAT DO YOU PLAN TO DO WITH THE DATA?"
    And I should see "PLEASE DESCRIBE THE BENEFITS OF USING DATA IN THIS WAY."
    And I should see "ARE YOU ABLE TO PROVIDE ESTIMATES OF THE ECONOMIC OR FINANCIAL BENEFIT OF DATA RELEASE?"
    #Check we cannot see hidden fields
    And I should not see "Notes"
    And I should not see "Outcome"
    And I should not see "Status"
    # Fill out new dataset request form
    When I fill in "Your name" with "My name"
    And I fill in "Your e-mail" with "test@data.gov.uk"
    And I select the radio button "Private Individual"
    And I select the radio button "Request is public."
    And I fill in "Dataset name *" with "My Dataset request name"
    And I fill in "Data set description" with "My Dataset request description"
    And I fill in "Data holder" with "The Data holder"
    And I check the box "Finance"
    And I select the radio button "Yes" with the id "edit-field-barriers-attempted-und-1"
    And I wait 2 seconds
    And I select the radio button "Data is not published" with the id "edit-field-issue-type-und-data-is-not-published"
    And I select the radio button "Other" with the id "edit-field-barriers-reason-und-9"
    And I fill in "Further detail" with "Further details about my dataset request barriers"
    And I check the box "Business Use"
    And I fill in "Further detail" with "Further details of my dataset request"
    And I fill in "Benefits overview" with "The benefits overview of my dataset request"
    And I select the radio button "Yes" with the id "edit-field-barriers-attempted-und-1"
    And I select the radio button "No" with the id "edit-field-provide-estimates-und-0"
    And I press "Save draft"
    And I wait until the page loads
    Then I should see the following <breadcrumbs>
      |  Data Requests            |
      |  My Dataset request name  |
    And I should see "Your draft Dataset Request has been created. You can update it in My Drafts section."
    When I submit "Dataset Request" titled "My Dataset request name" for moderation
    #Moderate newly created dataset request
    And user with "moderator" role moderates "My Dataset request name" authored by "test_user"
    And the cache has been cleared
    And I visit "/data-request"
    And I wait until the page loads
    Then "title" field in row "1" of "latest_dataset_requests" view should match "^My Dataset request name$"
    And "name" field in row "1" of "latest_dataset_requests" view should match "^Submitted by test_user$"
    And "created" field in row "1" of "latest_dataset_requests" view should match "^\d* min \d* sec ago|\d* sec ago$"

  @anon
  Scenario: View ODUG blogs page
    Given I am not logged in
    And I am on "/data-request"
    When I follow "ODUG Blogs"
    Then I should be on "/data-request/blogs"
    And I should see the following <breadcrumbs>
      |  Data Requests |
      |  ODUG Blogs    |
    And I should see the link "Login to request new data"
    And I should see the link "See Dashboard"
    And I should see "ODUG OVERVIEW" pane in "first" column in "second" row
    And I should see "PROGRESS ON REQUESTS" pane in "last" column in "second" row
    And I should see "ODUG MEMBERS" pane in "last" column in "second" row
    And I should see "USEFUL LINKS" pane in "last" column in "second" row
    And search result counter should match "^\d* Dataset requests \+ \d* confidential requests$"
    And view "blogs_odug" view should have "6" rows
    And "title" field in row "1" of "blogs_odug" view should match "\w*"
    And "name" field in row "1" of "blogs_odug" view should match "^Created by"
    And row "1" of "blogs_odug" view should match "\d* comments? \d* \w* \d* \w* ago$|No comments so far$"
    And pager in "blogs_odug" view should match "^1 2 3 … »|1 2 3 »$"

  @anon
  Scenario: View ODUG minutes page
    Given I am not logged in
    And I am on "/data-request"
    When I follow "ODUG Minutes"
    Then I should see the following <breadcrumbs>
      |  Data Requests |
      |  ODUG Minutes    |
    And I should be on "/data-request/minutes"
    And I should see the link "Login to request new data"
    And I should see the link "See Dashboard"
    And I should see "ODUG OVERVIEW" pane in "first" column in "second" row
    And I should see "PROGRESS ON REQUESTS" pane in "last" column in "second" row
    And I should see "ODUG MEMBERS" pane in "last" column in "second" row
    And I should see "USEFUL LINKS" pane in "last" column in "second" row
    And search result counter should match "^\d* Dataset requests \+ \d* confidential requests$"
    And view "default" view should have "6" rows
    And "title" field in row "1" of "default" view should match "\w*$"
    And "field-resource-file" field in row "1" of "default" view should match "^Resources: Minutes of Open Data User Group \w* \d*.odt$"
    And pager in "default" view should match "^1 2 3 … »|1 2 3 »$"

  @anon
  Scenario: View the data requests RSS
    Given I am on "/data-request"
    And I wait until the page loads
    And I click RSS icon in "first" column in "second" row
    Then I should be on "/odug/rss.xml"
