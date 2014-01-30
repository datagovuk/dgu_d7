<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext;

use Behat\Behat\Event\SuiteEvent,
    Behat\Behat\Event\FeatureEvent,
    Behat\Behat\Event\ScenarioEvent,
    Behat\Behat\Event\StepEvent;

use Behat\Behat\Context\Step\Given,
    Behat\Behat\Context\Step\When,
    Behat\Behat\Context\Step\Then;

use Behat\Behat\Exception\PendingException;

use Behat\Mink\Exception\ElementException,
    Behat\Mink\Exception\ElementNotFoundException;

use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;

use Drupal\Component\Utility\Random;

/**
 * Some of our features need to run their scenarios sequentially
 * and we need a way to pass relevant data (like generated node id)
 * from one scenario to the next.  This class provides a simple
 * registry to pass data. This should be used only when absolutely
 * necessary as scenarios should be independent as often as possible.
 */
abstract class HackyDataRegistry {
  public static $data = array();
  public static function set($name, $value) {
    self::$data[$name] = $value;
  }
  public static function get($name) {
    $value = "";
    if (isset(self::$data[$name])) {
      $value = self::$data[$name];
    }
    if ($value === "") {
        $backtrace = debug_backtrace(FALSE, 2);
        $calling = $backtrace[1];
        if (array_key_exists('line', $calling) && array_key_exists('file', $calling)) {
            throw new PendingException(sprintf("Fix HackyDataRegistry accessing with unset key at %s:%d in %s.", $calling['file'], $calling['line'], $calling['function']));
        } else {
            // Disabled primarily for calls from AfterScenario for now due to too many errors.
            //throw new PendingException(sprintf("Fix HackyDataRegistry accessing with unset key in %s.", $calling['function']));
        }
    }
    return $value;
  }
  public static function keyExists($name) {
    if (isset(self::$data[$name])) {
      return TRUE;
    }
    return FALSE;
  }
}

class LocalDataRegistry {
  public $data = array();
  public function set($name, $value) {
    $this->data[$name] = $value;
  }
  public function get($name) {
    $value = "";
    if (isset($this->data[$name])) {
      $value = $this->data[$name];
    }
    return $value;
  }
}

// Require 3rd-party libraries here:
//
//   require_once 'PHPUnit/Autoload.php';
//   require_once 'PHPUnit/Framework/Assert/Functions.php';

/**
 * Features context.
 */
// class FeatureContext extends BehatContext
class FeatureContext extends Drupal\DrupalExtension\Context\DrupalContext
{
    /**
     * Initializes context.
     * Every scenario gets its own context object.
     *
     * @param array $parameters context parameters (set them up through behat.yml)
     */
    public function __construct(array $parameters)
    {
        // Initialize your context here
    }

    public function fillField($field, $value)
    {
      $locator = $this->fixStepArgument($field);
      $value = $this->fixStepArgument($value);
      $nodes = $this->getSession()->getPage()->findAll('named', array('field', $this->getSession()->getSelectorsHandler()->xpathLiteral($locator)));

      if (null === $nodes) {
        throw new ElementNotFoundException($this->getSession(), 'form field', 'id|name|label|value', $locator);
      }

      foreach ($nodes as $node) {
        if($node->isVisible()) {
          $xpath = $node->getXpath();
          try {
            $node->getSession()->getDriver()->setValue($xpath, $value);
          }
          catch (\Exception $exception) {
            throw new ElementException($node, $exception);
          }
          break;
        }
      }
    }


  /**
   * Hold the execution until the page is/resource are completely loaded OR timeout
   *
   * @Given /^I wait until the page (?:loads|is loaded)$/
   * @param object $callback
   *   The callback function that needs to be checked repeatedly
   */
  public function iWaitUntilThePageLoads($callback = null) {
    // Manual timeout in seconds
    $timeout = 60;
    // Default callback
    if (empty($callback)) {
      if ($this->getSession()->getDriver() instanceof Behat\Mink\Driver\GoutteDriver) {
        $callback = function($context) {
          // If the page is completely loaded and the footer text is found
          if(200 == $context->getSession()->getDriver()->getStatusCode()) {
            return true;
          }
          return false;
        };
      }
      else {
        // Convert $timeout value into milliseconds
        // document.readyState becomes 'complete' when the page is fully loaded
        $this->getSession()->wait($timeout*1000, "document.readyState == 'complete'");
        return;
      }
    }
    if (!is_callable($callback)) {
      throw new Exception('The given callback is invalid/doesn\'t exist');
    }
    // Try out the callback until $timeout is reached
    for ($i = 0, $limit = $timeout/2; $i < $limit; $i++) {
      if ($callback($this)) {
        return true;
      }
      // Try every 2 seconds
      sleep(2);
    }
    throw new Exception('The request is timed out');
  }


  /**
   * @Given /^I wait (\d+) second(?:s|)$/
   */
  public function iWaitSeconds($arg1) {
    sleep($arg1);
  }

  /**
   * @Given /^I follow login link$/
   */
  public function iFollowLoginLink() {
    $page = $this->getSession()->getPage();
    $link = $page->find('css','#dgu-nav a.nav-user');
    if(empty($link)) {
      throw new Exception("Login link on the top black bar not found");
    }
    $link->click();
  }






   /**
   * @Given /^I fill in "([^"]*)" with random text$/
   */
  public function iFillInWithRandomText($label) {
    // A @Tranform would be more elegant.
    $randomString = strtolower(Random::name(10));
    // Save this for later retrieval.
    HackyDataRegistry::set('random:' . $label, $randomString);
    $step = "I fill in \"$label\" with \"$randomString\"";
    return new Then($step);
  }

  /**
   * @Given /^I fill in "([^"]*)" with a random address$/
   */
  public function iFillInWithARandomAddress($label) {
    // A @Tranform would be more elegant.
    $randomString = strtolower(Random::name(10)) . "@example.com";
    // Save this for later retrieval.
    HackyDataRegistry::set('random:' . $label, $randomString);
    $step = "I fill in \"$label\" with \"$randomString\"";
    return new Then($step);
  }








   /**
   * @Given /^I should not see the following <texts>$/
   */
  public function iShouldNotSeeTheFollowingTexts(TableNode $table) {
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $text = $table[$key]['texts'];
      if(!$page->hasContent($text) === FALSE) {
        throw new Exception("The text '" . $text . "' was found");
      }
    }
  }

  /**
   * @Given /^I (?:should |)see the following <texts>$/
   */
  public function iShouldSeeTheFollowingTexts(TableNode $table) {
    $page = $this->getSession()->getPage();
    $messages = array();
    $failure_detected = FALSE;
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $text = $table[$key]['texts'];
      if($page->hasContent($text) === FALSE) {
        $messages[] = "FAILED: The text '" . $text . "' was not found";
        $failure_detected = TRUE;
      } else {
        $messages[] = "PASSED: '" . $text . "'";
      }
    }
    if ($failure_detected) {
      throw new Exception(implode("\n", $messages));
    }
  }

  /**
  * @Given /^I (?:should |)see the following <links>$/
  */
  public function iShouldSeeTheFollowingLinks(TableNode $table) {
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $link = $table[$key]['links'];
      $result = $page->findLink($link);
      if(empty($result)) {
        throw new Exception("The link '" . $link . "' was not found");
      }
    }
  }

  /**
   * @Given /^I should not see the following <links>$/
   */
  public function iShouldNotSeeTheFollowingLinks(TableNode $table) {
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $link = $table[$key]['links'];
      $result = $page->findLink($link);
      if(!empty($result)) {
        throw new Exception("The link '" . $link . "' was found");
      }
    }
  }

  /**
   * @Given /^I should see "([^"]*)" block in "([^"]*)" column$/
   */
  public function iShouldSeeBlockInColumn($block_title, $column) {
    $region = $this->getSession()->getPage()->find('region', $column);
    if (empty($region)) {
      throw new Exception(ucfirst($column) . ' column not found');
    }
    $h2 = $region->findAll('css', '.block h2');
    if (empty($h2)) {
      throw new Exception('No blocks were found in the ' . $column . ' column');
    }
    foreach ($h2 as $text) {
      if (trim($text->getText()) == $block_title) {
        return;
      }
    }
    throw new Exception('The block "' . $block_title . '" was not found in the ' . $column . ' column');
  }

  /**
   * @Given /^I should see "([^"]*)" pane in "([^"]*)" column$/
   */
  public function iShouldSeePaneInColumn($pane_title, $column) {
    $region = $this->getSession()->getPage()->find('region', $column);
    if (empty($region)) {
      throw new Exception(ucfirst($column) . ' column not found');
    }
    $h2 = $region->findAll('css', '.panel-pane h2');
    if (empty($h2)) {
      throw new Exception('No panel panes were found in the ' . $column . ' column');
    }
    foreach ($h2 as $text) {
      if (trim($text->getText()) == $pane_title) {
        return;
      }
    }
    throw new Exception('Panel pane "' . $pane_title . '" was not found in the ' . $column . ' column');
  }

//    print "\n";
//    print_r($text->getText());
//    print "\n";
//    die;

/*

    // If a logout link is found, we are logged in. While not perfect, this is
    // how Drupal SimpleTests currently work as well.
    $element = $session->getPage();
    return $element->findLink($this->getDrupalText('log_out'));





  @javascript
  Scenario: Comment login link
    Given I am not logged in
    And I am on "/meetings"
    And I click on the element with css selector "h1.article-title a"
    And I click "Login"
    Then I should be on "/user/login"

  @javascript
  Scenario: Logging in and out
    Given I am on "/user/login"
    And I fill in the following:
      | Username | admin |
      | Password | pass |
    When I press "Log in"
    Then I should see the link "Logout"

  @javascript
  Scenario: Logging out
    Given I am on "/user/login"
    And I fill in the following:
      | Username | admin |
      | Password | pass |
    When I press "Log in"
    And I click "Logout"
    Then I should not see the link "Logout"

  @javascript
  Scenario: Error messages
   Given I am on "/user"
   When I press "Log in"
   Then I should see the error message "Password field is required"
   And I should not see the error message "Sorry, unrecognized username or password"
   And I should see the following <error messages>
   | error messages             |
   | Username field is required |
   | Password field is required |
   And I should not see the following <error messages>
   | error messages                                                                |
   | Sorry, unrecognized username or password                                      |
   | Unable to send e-mail. Contact the site administrator if the problem persists |

 */
}
