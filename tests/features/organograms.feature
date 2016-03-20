@javascript
Feature: Upload organograms
  In order to
  As an administrator
  I should be able to upload organograms

  @api
  Scenario: Upload organograms
    Given I am on "/user"
    And I log in as "admin" user
    And I upload organograms

  @api
  Scenario: Validate organograms
    Given I am on "/user"
    And I log in as "admin" user
    And I validate organograms
