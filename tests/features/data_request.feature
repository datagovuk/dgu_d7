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
    And the field "Data request title" should be outlined in red
    And the field "Data request description" should be outlined in red
    # Fill out new dataset request form
    And I fill in "Data request title" with "My Dataset request title"
    And I fill in "Data request description" with "My Dataset request description"
    And I select the radio button "Request is public."
    And I select the radio button "In behalf of an organisation"
    And I wait 1 second
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
      | My Dataset request title |
    And I should see "Your draft Dataset Request has been created. You can update it in My Drafts section."
    And I should see "Please ensure your profile is up to date as we may use these details to contact you about your Dataset Request."
    When I submit "Dataset Request" titled "My Dataset request title" for moderation
    #Moderate newly created dataset request
    And user with "moderator" role moderates "My Dataset request title" authored by "test_user"
    And the cache has been cleared
    And I visit "/data-request"
    And I wait until the page loads
    Then "title" field in row "1" of "latest_dataset_requests" view should match "^My Dataset request title$"
    And "name" field in row "1" of "latest_dataset_requests" view should match "^Submitted by test_user$"
    And "created" field in row "1" of "latest_dataset_requests" view should match "^\d* min \d* sec ago|\d* sec ago$"
    # Test administration workflow
    Given that the user "test_data_request_admin" is not registered
    And I am logged in as a user "test_data_request_admin" with the "data request administrator" role
    And I am on "/admin/workbench"
    And I follow "Data requests"
    And I wait until the page loads
    And I follow "My Dataset request title"
    And I wait until the page loads
    And I follow "Edit"
    And I wait until the page loads
    And I select "test_data_request_admin" from "Assignee"
    And I select the radio button "Academics"
    When I press "Save"
    And I wait until the page loads
    Then I should see the link "test_data_request_admin"
    And I should see the link "Academics"
    When I visit "/admin/workbench"
    And I follow "Active Data requests"
    And I wait until the page loads
    And I follow "My Dataset request title"
    And I wait until the page loads
    And I follow "Edit"
    And I wait until the page loads
    And I select "jamesashton" from "Assignee"
    And I press "Save"
    And I wait until the page loads
    Then I should see the link "jamesashton"
    When I visit "/admin/workbench"
    And I wait until the page loads
    And I follow "Active Data requests"
    Then I should not see "My Dataset request title"
    And I wait until the page loads
    When I follow "My Edits"
    Then I should see "My Dataset request title"
    Given I am not logged in
    And I am on "/user"
    And I log in as "jamesashton" user
    When I visit "/admin/workbench"
    And I wait until the page loads
    And I follow "Active Data requests"
    And I wait until the page loads
    And I follow "My Dataset request title"
    Then I should see "Add note"

  @anon
  Scenario: View ODUG blogs page
    Given I am not logged in
    And I am on "/data-request"
    When I follow "ODUG Blogs"
    Then I should be on "/data-request/blogs"
    And I should see the following <breadcrumbs>
      | Data Requests |
      | ODUG Blogs    |
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
      | Data Requests |
      | ODUG Minutes  |
    And I should be on "/data-request/minutes"
    And I should see the link "Login to request new data"
    And I should see the link "See Dashboard"
    And I should see "ODUG OVERVIEW" pane in "first" column in "second" row
    And I should see "PROGRESS ON REQUESTS" pane in "last" column in "second" row
    And I should see "ODUG MEMBERS" pane in "last" column in "second" row
    And I should see "USEFUL LINKS" pane in "last" column in "second" row
    And search result counter should match "^\d* Dataset requests \+ \d* confidential requests$"
    And view "odug_minutes_block" view should have "6" rows
    And "title" field in row "1" of "odug_minutes_block" view should match "\w*"
    And "field-resource-file" field in row "1" of "odug_minutes_block" view should match "^Resources:"
    And pager in "odug_minutes_block" view should match "^1 2 3 … »|1 2 3 »"

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
