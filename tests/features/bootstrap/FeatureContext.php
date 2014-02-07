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
    $this->dataRegistry = new LocalDataRegistry();
    if (isset($parameters['drupal_users'])) {
      $this->drupal_users = $parameters['drupal_users'];
    }
    if (isset($parameters['email'])) {
      $this->email = $parameters['email'];
    }
    $this->mailAddresses = array();
    $this->mailMessages = array();

  }

  /**
  * Override Element::find().
  *
  * To manipulate only visible elements
  */
  public function find($selector, $locator)
  {
      $items = $this->findAll($selector, $locator);

      if (count($items) && !method_exists(current($items), 'isVisible')) {
        return current($items);
      }

      foreach ($items as $item) {
        if ($item->isVisible()) {
          return $item;
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
   * @Given /^I should not be logged in$/
   */
  public function iShouldNotBeLoggedIn() {
    if ($this->loggedIn()) {
      return false;
    }
  }


  /**
   * Authenticates a user with password from configuration.
   *
   * @Given /^I am logged in as (?:|the )"([^"]*)"(?:| user)$/
   * @Given /^I log in as (?:|the )"([^"]*)"(?:| user)$/
   */
  public function iAmLoggedInAs($username) {
    $password = $this->drupal_users[$username];
    return $this->iAmLoggedInAsTheWithThePassword($username, $password);
  }

  /**
   * @Given /^I am logged in as the "([^"]*)" with the password "([^"]*)"$/
   * @Given /^I log in as the "([^"]*)" with the password "([^"]*)"$/
   */
  public function iAmLoggedInAsTheWithThePassword($username, $password) {
    return array (
      new Given("I fill in \"Username or e-mail address\" with \"$username\""),
      new Given("I fill in \"Password\" with \"$password\""),
      new Given("I press \"Log in\""),
    );
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


  //TODO - add class to rss link

  /**
   * @Given /^I follow RSS link$/
   */
  public function iFollowRSSLink() {
    $page = $this->getSession()->getPage();
    $link = $page->find('css','pane-forum-categories > a');
    if(empty($link)) {
      throw new Exception("RSS link not found");
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
 */



  /**
   * Return email address for given user role.
   */
  protected function getMailAddress($user) {

    if(empty($this->mailAddresses[$user])) {
      $this->mailAddresses[$user] = $this->email['username'] . '+' . str_replace('_', '.', $user) . '.'  . Random::name(8) . '@'. $this->email['host'];
    }

    return $this->mailAddresses[$user];
  }

  /**
   * @Given /^I fill in "([^"]*)" with "([^"]*)" address$/
   */
  public function iFillInWithAddress($label, $user) {
    $mail_address = $this->getMailAddress($user);
    $step = "I fill in \"$label\" with \"$mail_address\"";
    return new Then($step);
  }

//   /**
//   * Check that the mail is received.
//   *
//   * @Then /^ (?:(?:do|should) )?receive mail (titled )?"(?P<title>[^"]*)"$/
//   *
//   * @param $title
//   *   The email title to look for.
//   */
//  public function iShouldReceiveMail($title, $user) {
//    if (!function_exists('imap_open')) {
//      throw new \Exception('PHP imap not installed.');
//    }
//    $title = $this->fixStepArgument($title);
//
//    // Open the IMAP mailbox.
//    $mail_address = $this->getMailAddress('anonymous_user');
//    $mbox = imap_open( $this->email['mailbox'], $mail_address,  $this->email['password']);
//
//
//    $mail_creds = $this->getMailCreds();
//    $mbox = imap_open('{' . $mail_creds['imap'] . '/imap/ssl}INBOX', $mail_creds['user'], $mail_creds['pass']);
//    if ($mbox) {
//      $trials = 300;
//      for ($attempts = 0; $attempts++ < $wait; ) {
//        // Read all of the messages.
//        $all = imap_check($mbox);
//        if ($all->Nmsgs) {
//          foreach (imap_fetch_overview($mbox, "1:$all->Nmsgs") as $msg) {
//            if ($msg->to == $mail_creds['email'] && $msg->subject == $title) {
//              $msg->body['text'] = imap_fetchbody($mbox, $msg->msgno, 1);
//              $msg->body['html'] = imap_fetchbody($mbox, $msg->msgno, 2);
//              $this->mailMessages[] = $msg;
//              imap_delete($mbox, $msg->msgno);
//              break 2;
//            }
//          }
//        }
//
//        // Wait a second and try again.
//        usleep(1000000);
//        if ($affirmative && ($attempts % 60) == 1) {
//          print "    Waiting for mail to " . $mail_creds['email'] . "\n";
//        }
//      }
//
//      // Close the mailbox.
//      imap_close($mbox);
//
//      // Throw Exception when the message is not found.
//      if ($attempts >= $wait) {
//        if ($affirmative) {
//          throw new \Exception('Email "' . $title . '" not found.');
//        }
//      }
//      elseif (!$affirmative) {
//        throw new \Exception('Email "' . $title . '" received, and should not of been.');
//      }
//    }
//  }

  /**
   * @Given /^the "([^"]*)" user received an email "([^"]*)"$/
   */
  public function theUserReceivedAnEmail($user, $title) {

    $mail_address = $this->getMailAddress($user);
    $title = $this->fixStepArgument($title);

    $mbox = imap_open( $this->email['mailbox'], $mail_address,  $this->email['password']);

    $all = imap_check($mbox);

    $received = false;
    // Trying 30 times with one second pause
    for ($attempts = 0; $attempts++ < 30; ) {

      if ($all->Nmsgs) {
        foreach (imap_fetch_overview($mbox, "1:$all->Nmsgs") as $msg) {

          if ($msg->to == $mail_address && $msg->subject == $title) {
            $msg->body = imap_fetchbody($mbox, $msg->msgno, 1);
            // Consider if we start sending HTML emails.
            //$msg->body['html'] = imap_fetchbody($mbox, $msg->msgno, 2);
            $this->mailMessages[$user][] = $msg;
            imap_delete($mbox, $msg->msgno);
            $received = true;
            break 2;
          }
        }
      }
      sleep(1);
    }
    imap_close($mbox);
    // Throw Exception if message not found.
    if (!$received) {
      throw new \Exception('Email "' . $title . '" to "' . $mail_address . '" not received.');
    }
  }

  /**
   * @When /^user "([^"]*)" clicks link containing "(?P<link>[^"]*)" in mail(?: (?:titled )?"(?P<title>[^"]*)")?$/
   */
  public function userClickLinkContainingInMail($user, $link_substring, $title = NULL) {

    $link_substring = $this->fixStepArgument($link_substring);
    $title = $title ? $this->fixStepArgument($title) : NULL;

    foreach ($this->mailMessages[$user] as $msg) {
      if ($title && $msg->subject == $title) {

        if (!empty($msg->body)) {

          // Look for matching link text.
          $body = str_replace('\n', '', $msg->body);

          // Get all links.
          if (preg_match_all('/https?:\/\/.*/i', $body, $matches)) {
            $links = array_shift($matches);

            foreach ($links as $link) {
              if (strpos($link, $link_substring) !== false) {
                $this->getSession()->visit($link);
              }
            }
          }
        }
      }
    }
//    throw new \Exception('Email "' . $title . '" does not have a link with the text "' . $link_substring . '".');
//    throw new \Exception('Email "' . $title . '" not received.');
//    throw new \Exception('Email "' . $title . '" does not have any links.');
  }

  /**
   * @Given /^that the user "([^"]*)" is not registered$/
   */
  public function thatTheUserIsNotRegistered($user_name) {
    try {
      $this->getDriver()->drush('user-cancel', array($user_name), array('yes' => NULL, 'delete-content' => NULL));
    }
    catch (Exception $e) {
      if(strpos($e->getMessage(), "Could not find a user account with the name $user_name!") !== 0){
        // Print exception message if exception is different than expected
        print $e->getMessage();
      }
    }
  }

  /**
   * @Given /^TEST$/
   */
  public function test() {


  }




}
