@javascript
Feature: View latest apps landing page and submit a new app for moderation as a regular site user
  In order to inform how open data is used
  As a site user
  I should be able to search for apps which are published and submit a new App

  @anon
  Scenario: View latest apps landing page and check Top rated apps page
    Given I am on the homepage
    And I am not logged in
    And I click "Apps"
    And I wait until the page loads
    Then I should be on "/apps"
    And view "latest_apps" view should have "5" rows
    And I should see the link "See all"
    And I should see the link "Login to add your app »"
    And I should see the following <breadcrumbs>
      | Apps        |
      | Latest apps |
    And search result counter should match "^\d* Apps$"
    When I follow "Top rated apps"
    And I wait until the page loads
    Then I should be on "/apps/top"
    Then I should see the link "Login to add your app »"
    And I should see the following <breadcrumbs>
      | Apps           |
      | Top rated apps |
    And view "top_rated_apps" view should have "5" rows
    And search result counter should match "^\d* Apps$"
    And pager should match "^1 2 3 … »$"

  @anon
  Scenario: View latest apps RSS
    Given I am on "/apps"
    And I wait until the page loads
    And I click RSS icon in "first" column in "fourth" row
    Then I should be on "/apps/latest/rss.xml"

  @anon
  Scenario: View top rated apps RSS
    Given I am on "/apps/top"
    And I wait until the page loads
    And I click RSS icon in "first" column in "fourth" row
    Then I should be on "/apps/top/rss.xml"


  @anon @search
  Scenario: Use search box on latest apps landing page/search page with and without keyword checking if relevance sort is selected. Check error message and default sort
    Given I am on "/apps"
    And I click search icon
    And I wait until the page loads
    Then I should be on "/search/everything/?f[0]=bundle%3Aapp"
    And I should see "Please enter some keywords to refine your search further"
    And "Last updated" option in "Sort by:" should be selected
    When I fill in "Search apps..." with "data"
    And I click search icon
    And I wait until the page loads
    Then I should be on "/search/everything/data?f[0]=bundle%3Aapp&solrsort=score"
    And "Relevance" option in "Sort by:" should be selected
    And "Author" option in "Sort by:" should be disabled
    And "Content type" option in "Sort by:" should be disabled
    And I should see the following <breadcrumbs>
      | Apps   |
      | Search |
    And I should see "CONTENT TYPE" pane in "first" column in "first" row
    And I should see "CATEGORY" pane in "first" column in "first" row
    And I should see "SECTOR" pane in "first" column in "first" row
    And I should not see "TAGS" pane in "first" column in "first" row
    And there should be "10" search results on the page
    And pager should match "^1 2 3 … »$"

  @api
  Scenario: Create a new app as the "test_user", update it before submitting for moderation, test notifications
    Given that the user "test_user" is not registered
    And that the user "test_subscriber" is not registered
    And that the user "test_non_subscriber" is not registered
    And that the user "test_commenting_user" is not registered
    # Create these accounts to test if they receive emails.
    And I am logged in as a user "test_non_subscriber" with the "authenticated user" role
    And I am logged in as a user "test_subscriber" with the "authenticated user" role
#    When I visit "/user"
#    And I wait until the page loads
#    And I follow "My subscriptions"
#    And I wait until the page loads
#    And I click "Auto subscribe"
#    And I wait until the page loads
#    And I check "App"
#    And I wait 1 second
#    And I press "Save"
#    And I wait until the page loads
#    And I am logged in as a user "test_subscriber_updates_comments" with the "authenticated user" role
#
#    When I visit "/user"
#    And I wait until the page loads
#    And I follow "My subscriptions"
#    And I wait until the page loads
#    And I click "Auto subscribe"
#    And I wait until the page loads
#    And I check "App"
#    And I wait 1 second
#    And I check "Automatically subscribe to updates and comments"
#    And I wait 1 second
#    And I press "Save"
#    And I wait until the page loads

    And I am logged in as a user "test_user" with the "authenticated user" role
    When I visit "/apps"
    And I follow "Add your app"
    And I wait until the page loads
    Then I should see "Submit an app"
    And I should see "Name"
    And I should see "Description"
    Given I have an image "300" x "300" pixels titled "Test image" located in "/tmp/" folder
    And I attach the file "/tmp/Test image.png" to "files[field_screen_shots_und_0]"
    And I fill in "Name" with "Test app"
    And I type "Test App description text" in the "edit-body-und-0-value" WYSIWYG editor
    And I fill in "Title" with "Test app"
    And I fill in "URL" with "data.gov.uk"
    And I fill in "Developed by" with "Test developer"
    And I fill in "Submitter Name" with "Test submitter"
    And I fill in "Submitter e-mail" with "submitter@example.com"
    Given I have an image "370" x "370" pixels titled "Test image" located in "/tmp/" folder
    And I attach the file "/tmp/Test image.png" to "files[field_app_thumbnail_und_0]"
    And I select "Free" from "App charge"
    And I select "Health" from "Category"
    And I select "Other" from "Sector"
    When I press "Save draft"
    And I wait until the page loads
    Then I should see a message about created draft "App"
    And I should see node title "Test app"
    And I should see "Test developer"
    #App title is used as the hyperlink title so we check the link title then check if there is a link
    And I should see "App Link: Test app"
    And I should see the link "Test app"
    Then I should be on "/apps/test-app"
    And I should see the following <breadcrumbs>
      | Apps     |
      | Test app |
    And I should see "App charge: Free"
    And I should see "Health"
    And I should see "Apps submitted to data.gov.uk are currently approved for publication"
    And I should see the link "Flag as offensive"
    When I follow "Edit draft"
    And I wait until the page loads
    And I press "Save draft"
    And I wait until the page loads
    Then I should see " Your draft App has been updated. You can update it in My Drafts section."
    And I should see "Updated on"
    And I should see the link "Subscribe"
    And I submit "App" titled "Test app" for moderation
    # Moderate "Test app" as a "test_moderator"
    Given user with "moderator" role moderates "Test app" authored by "test_user"
    And the "test_user" user have not received an email 'App "Test app" has been created '
    And the "test_non_subscriber" user have not received an email 'App "Test app" has been created '
    And the "test_subscriber" user have not received an email 'App "Test app" has been created '
    # Clear the cache so the new app will show up on the latest apps landing page
    Given the cache has been cleared
    And I am logged in as a user "test_subscriber" with the "authenticated user" role
    When I visit "/apps"
    And I wait until the page loads
    Then "title" field in row "1" of "latest_apps" view should match "^Test app$"
    When I click "title" field in row "1" of "latest_apps" view
    Then I should be on "/apps/test-app"
    And I click "Subscribe"
    And I wait 1 second
    # Comment on "Test app" as "test_commenting_user"
    And I am logged in as a user "test_commenting_user" with the "authenticated user" role
    And I am on "/apps/test-app"
    When I follow "Add new comment"
    And I wait until the page loads
    Then I should see the following <breadcrumbs>
      | Apps     |
      | Test app |
      | Comment  |
    When I fill in "Subject" with "Test subject"
    And I type "Body content of test comment" in the "edit-field-reply-comment-und-0-value" WYSIWYG editor
    And I press "Submit"
    And I wait until the page loads
    Then I should be on "/apps/test-app"
    And I should see the success message "Comment was successfully created."
    And I should see "Test app"
    And I should see the heading "Comments"
    And I should see "Test subject"
    And I should see "Body content of test comment"
    And I should see the link "Reply"
    And the "test_subscriber" user received an email 'User test_commenting_user posted a comment on App "Test app" '
    And the "test_user" user have not received an email 'User test_commenting_user posted a comment on App "Test app" '
    And the "test_non_subscriber" user have not received an email 'User test_commenting_user posted a comment on App "Test app" '
    #View the Test App and check the author link
    Given I am on "/apps/test-app"
    When I follow "test_user" in the "main_content"
    And I wait until the page loads
    Then I should be on "/users/testuser"

#TODO Test presence of "More like this" block.
#TODO Test star ratings.
#TODO Test presence of screenshots and pop ups of app view page.
#TODO Solr Indexing - test presence of new app on search page and test "updated on" is displayed after an update.
#TODO Test app promo tiles (including adding an image and testing the link).
#TODO Test app thumbnails and ratings on landing page views.
