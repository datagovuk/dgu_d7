# language: en
Feature: Search
  In order to find the data that is relevant to me
  I must enter my search term into the data search box 

  @important
  Scenario: Data Search
    Given I have entered search term into search box
    When I press search
    Then I can see the search results