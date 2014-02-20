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
     * @BeforeFeature
     */
    public static function prepare(FeatureEvent $event)
    {
        //$cmd = 'drush @standards.test ev \'$query = new EntityFieldQuery(); $result = $query->entityCondition("entity_type", "node")->propertyCondition("title", "Test ", "STARTS_WITH")->execute(); if (isset($result["node"])) {$nids = array_keys($result["node"]); foreach ($nids as $nid) {node_delete($nid);}}\'';
        //shell_exec($cmd);
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
   * Determine if the a user is already logged in.
   * Override DrupalContext::loggedIn() because we display logout link in the dropdown.
   */
  public function loggedIn() {
    $session = $this->getSession();
    $session->visit($this->locatePath('/'));
    $user_icon = $session->getPage()->find('css','#dgu-nav a.nav-user');
    if(empty($user_icon)) {
      throw new Exception("User icon on the top black bar not found");
    }
    $user_icon->click();
    $dropdown = $session->getPage()->find('css','#dgu-nav ul.dgu-user-dropdown');
    // If a user dropdown is found, we are logged in.
    return $dropdown;
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
   * @Given /^I am logged in as a user "([^"]*)" with the "([^"]*)" role$/
   */
  public function iAmLoggedInAsAUserWithTheRole($user_name, $role) {
    if (isset($user_name)) {

      // Check if a user with this role is already logged in.
      if ($this->loggedIn() && $this->user && isset($this->user->role) && $this->user->role == $role) {
        return TRUE;
      }
      elseif (isset($this->users[$user_name])) {
        // Set previously used credentials as current.
        $this->user = $this->users[$user_name];
        // Login.
        $this->login();
        return TRUE;
      }

      // Create user.
      $user = (object) array(
        'name' => $user_name,
        'pass' => Random::name(16),
        'role' => $role,
      );
      $user->mail = $this->getMailAddress($user_name);

      // Create a new user.
      $this->getDriver()->userCreate($user);

      $this->users[$user_name] = $this->user = $user;

      if ($role == 'authenticated user') {
        // Nothing to do.
      }
      else {
        $this->getDriver()->userAddRole($user, $role);
      }

      // Login.
      $this->login();

      return TRUE;
    }
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
   * @Given /^I click RSS icon in "([^"]*)" column in "([^"]*)" row$/
   */
  public function iClickRssIconInColumnInRow($column, $row) {

    $row = $this->getSession()->getPage()->find('css', '.panel-display .row-' . $row);
    if (empty($row)) {
      throw new Exception(ucfirst($row) . ' row not found');
    }

    $column = $row->find('css', '.panel-col-' . $column);
    if (empty($column)) {
      throw new Exception(ucfirst($column) . ' column not found in '. ucfirst($row) . ' row');
    }

    $rss_icons = $column->findAll('css', '.rss-icon');
    if (empty($rss_icons)) {
      throw new Exception('No RSS icons found in the ' . $column . ' column in '. ucfirst($row) . ' row');
    }
    foreach ($rss_icons as $rss_icon) {
      if (!$rss_icon->isVisible()) {
        throw new Exception('RSS icon found in ' . ucfirst($column) . ' column in '. ucfirst($row) . ' row but it\'s not visible');
      }
      $rss_icon->click();
      return;
    }
    throw new Exception('RSS icon found in the ' . $column . ' column but it\'s not visible');
  }

  /**
   * @Given /^I click search icon$/
   */
  public function iClickSearchIcon() {

    $search_icons = $this->getSession()->getPage()->findAll('css', '#dgu-search-form .btn-default');
    if (empty($search_icons)) {
      throw new Exception('No search icons found');
    }
    foreach ($search_icons as $search_icon) {
      if (!$search_icon->isVisible()) {
        throw new Exception('Search icon found but it\'s not visible');
      }
      $search_icon->click();
      return;
    }

  }

  /**
   * @Given /^search result counter should contain "([^"]*)"$/
   */
  public function searchResultCounterShouldContain($string) {
    $search_counters = $this->getSession()->getPage()->findAll('css', '.result-count-footer');
    if (empty($search_counters)) {
      throw new Exception('Search counter not found');
    }
    foreach ($search_counters as $search_counter) {
      if (!$search_counter->isVisible()) {
        throw new Exception('Search counter found but it\'s not visible');
      }
      elseif ($search_counter->getText() != $string) {
        throw new Exception('Search counter found but it contains "' . $search_counter->getText() . '" not "' . $string . '"');
      }
      return;
    }
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
   * @Given /^I should see "([^"]*)" block in "([^"]*)" column in "([^"]*)" row$/
   */
  public function iShouldSeeBlockInColumnInRow($block_title, $column, $row) {

    $row = $this->getSession()->getPage()->find('css', '.panel-display .row-' . $row);
    if (empty($row)) {
      throw new Exception(ucfirst($row) . ' row not found');
    }

    $column = $row->find('css', '.panel-col-' . $column);
    if (empty($column)) {
      throw new Exception(ucfirst($column) . ' column not found in '. ucfirst($row) . ' row');
    }

    $h2 = $column->findAll('css', '.block h2');
    if (empty($h2)) {
      throw new Exception('No blocks were found in the ' . $column . ' column in '. ucfirst($row) . ' row');
    }
    foreach ($h2 as $text) {
      if (trim($text->getText()) == $block_title) {
        if(!$text->isVisible()) {
          throw new Exception('Block "' . $block_title . '" found in ' . ucfirst($column) . ' column in '. ucfirst($row) . ' row but it\'s not visible');
        }
        return;
      }
    }
    throw new Exception('The block "' . $block_title . '" was not found in the ' . $column . ' column in '. ucfirst($row) . ' row');
  }

    /**
     * @Given /^I should see "([^"]*)" pane in "([^"]*)" column in "([^"]*)" row$/
     */
    public function iShouldSeePaneInColumnInRow($pane_title, $column, $row) {

    $row = $this->getSession()->getPage()->find('css', '.panel-display .row-' . $row);
    if (empty($row)) {
      throw new Exception(ucfirst($row) . ' row not found');
    }

    $column = $row->find('css', '.panel-col-' . $column);
    if (empty($column)) {
      throw new Exception(ucfirst($column) . ' column not found in '. ucfirst($row) . ' row');
    }

    $h2 = $column->findAll('css', '.panel-pane h2');
    if (empty($h2)) {
      throw new Exception('No panel panes were found in the ' . $column . ' column in '. ucfirst($row) . ' row');
    }
    foreach ($h2 as $text) {
        $a = $text->getText();
      if (trim($text->getText()) == $pane_title) {
        if(!$text->isVisible()) {
          throw new Exception('Pane "' . $pane_title . '" found in ' . ucfirst($column) . ' column in '. ucfirst($row) . ' row but it\'s not visible');
        }
        return;
      }
    }
    throw new Exception('Panel pane "' . $pane_title . '" was not found in the ' . $column . ' column in '. ucfirst($row) . ' row');
  }


  /**
   * @Then /^I should see a message about created draft "([^"]*)"$/
   */
  public function iShouldSeeAMessageAboutCreatedDraft($content_type) {
    return $this->assertSuccessMessage("Your draft $content_type has been created. Login to your profile to update it. You can submit this now or later");
  }

  /**
   * @Then /^I should see a message about "([^"]*)" being submitted for moderation$/
   */
  public function iShouldSeeAMessageAboutBeingSubmittedForModeration($content_type) {
    return $this->assertSuccessMessage("Your $content_type has been updated and submitted for moderation. Login to your profile to update it. You can submit this now or later");
  }


  /**
   * Function to check if the field specified is outlined in red or not
   *
   * @Given /^the field "([^"]*)" should be outlined in red$/
   *
   * @param string $field
   *   The form field label to be checked.
   */
  public function theFieldShouldBeOutlinedInRed($field) {
    $page = $this->getSession()->getPage();
    // get the object of the field
    $formField = $page->findField($field);
    if (empty($formField)) {
      throw new Exception('The page does not have the field with label "' . $field . '"');
    }
    // get the 'class' attribute of the field
    $class = $formField->getAttribute("class");
    // we get one or more classes with space separated. Split them using space
    $class = explode(" ", $class);
    // if the field has 'error' class, then the field will be outlined with red
    if (!in_array("error", $class)) {
      throw new Exception('The field "' . $field . '" is not outlined with red');
    }
  }

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
   * @Given /^"([^"]*)" option in "([^"]*)" should be selected$/
   */
  public function optionInShouldBeSelected($option_key, $label) {

    $page = $this->getSession()->getPage();

    $select = $page->find('xpath', "//label[contains(., '$label')]/following-sibling::select");

    if ($select) {
      $dom = new domDocument;
      $dom->loadHTML($select->getHtml());
      $options = $dom->getElementsByTagName('option');
      foreach ($options as $option) {
        if($option->getAttribute('selected') && $option->nodeValue == $option_key) {
          return;
        }
      }

    }

    throw new ElementNotFoundException(
      $this->getSession(), 'select option', 'value|text', $option_key
    );

  }

  /**
   * @Then /^I (?:|should )see page title "(?P<title>[^"]*)"$/
   */
  public function assertPageTitle($title) {
    $results = $this->getSession()->getPage()->findAll('css', 'h1.page-header');
    foreach ($results as $result) {
      if ($result->getText() == $title) {
        return;
      }
    }
    throw new \Exception(sprintf("The text '%s' was not found in page title on the page %s", $title, $this->getSession()->getCurrentUrl()));
  }

  /**
   * @Then /^I (?:|should )see node title "(?P<title>[^"]*)"$/
   */
  public function assertNodeTitle($title) {
    $results = $this->getSession()->getPage()->findAll('css', 'article.node h2.node-title');
    foreach ($results as $result) {
      if ($result->getText() == $title) {
        return;
      }
    }
    if (count($results)) {
      throw new \Exception(sprintf("The text '%s' was not found in node title on the page %s", $title, $this->getSession()->getCurrentUrl()));
    }
    else {
      throw new \Exception(sprintf("Node title missing on the page %s", $title, $this->getSession()->getCurrentUrl()));
    }
  }
  /**
   * @Given /^I have an image "([^"]*)" x "([^"]*)" pixels titled "([^"]*)" located in "([^"]*)" folder$/
   */

  public function iHaveAnImageTitledLocatedInFolder($width, $height, $title, $path) {
    $image = @imagecreatetruecolor($width, $height) or die('Cannot Initialize new GD image stream');
    $color = array(
      imagecolorallocate($image,rand(100, 150),rand(100, 150),rand(100, 150)),
      imagecolorallocate($image,rand(50, 100),rand(50, 100),rand(50, 100)),
    );

    for ($y = 0; $y < $height / 5; $y++) {
      $i=$y % 2;
      for ($x = 0; $x < $width / 5; $x++) {
        imagefilledrectangle($image, $x*5, $y*5, $x*5 + 5, $y*5 + 5, $color[++$i % 2]);
      }
    }

    imagestring($image, 5, $width/2 - strlen($title) * 4.5 , $height/2 - 15, $title, imagecolorallocate($image, 255, 255, 255));
    imagepng($image, $path . '/' . $title . '.png');
    imagedestroy($image);
  }


  /**
   * @Given /^TEST$/
   */
  public function test() {


  }


  /**
   * @Given /^I submit "([^"]*)" titled "([^"]*)" for moderation$/
   */
  public function iSubmitTitledForModeration($content_type, $title) {
    return array (
      new Given("I follow \"profile\""),
      new Given("I follow \"$title\""),
      new Given("I wait until the page loads"),
      new Given("I follow \"Edit draft\""),
      new Given("I press \"Submit for moderation\""),
      new Given("I should see a message about \"$content_type\" being submitted for moderation"),
      new Given("I follow \"profile\""),
      new Given("I should see the link \"$title\""),
      new Given("I follow \"My Drafts\""),
      new Given("I wait until the page loads"),
      new Given("I should see the link \"$title\""),
      new Given("I should see \"Needs review\""),
      new Given("I should see the link \"Draft\""),
    );
  }

  /**
   * @Given /^user with "([^"]*)" role moderates "([^"]*)" authored by "([^"]*)"$/
   */
  public function userWithRoleModeratesAuthoredBy($role, $title, $author) {
    return array (
      new Given("that the user \"test_moderator\" is not registered"),
      new Given("I am logged in as a user \"test_moderator\" with the \"$role\" role"),
      new Given("I visit \"/admin/workbench\""),
      new Given("I follow \"Needs Review\""),
      new Given("I wait until the page loads"),
      new Given("I follow \"$title\""),
      new Given("I wait until the page loads"),
      new Given("I follow \"Moderate\""),
      new Given("I wait until the page loads"),
      new Given("I should see \"Currently there is no published revision of this node.\""),
      new Given("I should see \"Created by test_user.\""),
      new Given("I should see \"Edited by $author.\""),
      new Given("I should see the link \"$author\" in the \"content\" region"),
      new Given("I should not see the link \"test_moderator\" in the \"content\" region"),
      new Given("\"Published\" option in \"Moderation state\" should be selected"),
      new Given("I press \"Apply\""),
      new Given("I wait until the page loads"),
      new Given("I should see \"This is the published revision.\""),
      new Given("I should see the link \"Unpublish\" in the \"content\" region"),
      new Given("I should see the link \"test_moderator\" in the \"content\" region"),
      new Given("I follow \"View\""),
      new Given("I should see \"Revision state: Published\""),
      new Given("I should see \"Current draft: Yes\""),
      new Given("I should see the link \"Unpublish this revision\" in the \"main_content\" region"),
    );
  }

  /**
   * @Then /^I should see "([^"]*)" in All content tab but not in My edits or My drafts tabs$/
   */
  public function iShouldSeeInAllContentTabButNotInMyEditsOrMyDraftsTabs($title) {
    return array (
      new Given("I visit \"/admin/workbench/content/edited\""),
      new Given("I should not see the link \"$title\""),
      new Given("I visit \"/admin/workbench/drafts\""),
      new Given("I should not see the link \"$title\""),
      new Given("I visit \"/admin/workbench/content/all\""),
      new Given("I follow \"$title\""),
      new Given("I should see the link \"New draft\""),
      new Given("I should see the link \"Add new comment\""),
      new Given("I should see \"View published\""),
    );
  }
}
