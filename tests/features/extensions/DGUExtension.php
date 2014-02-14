<?php

namespace DGU;

use \Behat\Behat\Extension\Extension;
use \Symfony\Component\DependencyInjection\ContainerBuilder;

use \Behat\Behat\Context\Initializer\InitializerInterface;
use \Behat\Behat\Context\ContextInterface;
use \Behat\Mink\Mink;

class DGUExtension extends Extension
{
    public function load(array $config, ContainerBuilder $container)
    {
        $loader = new \Symfony\Component\DependencyInjection\Loader\XmlFileLoader(
            $container,
            new \Symfony\Component\Config\FileLocator(__DIR__)
        );
        $loader->load('services.xml');
    }
}

class MinkAwareInitializer implements InitializerInterface
{
    private $mink;

    public function __construct(Mink $mink)
    {
        $this->mink = $mink;
    }

    public function supports(ContextInterface $context)
    {
        // in real life you should use interface for that
        return method_exists($context, 'setMink');
    }

    public function initialize(ContextInterface $context)
    {
        $context->setMink($this->mink);
    }
}

/**
 * Derived from Mink session to override constructor to instantiate DGUDocumentElement DocumentElement.
 * To be able to override DocumentElement::find() (Element::find())
 */
class DGUSession extends \Behat\Mink\Session
{
    private $page;

    /**
     * Initializes session.
     *
     * @param DriverInterface  $driver
     * @param SelectorsHandler $selectorsHandler
     */
    public function __construct(\Behat\Mink\Driver\DriverInterface $driver, \Behat\Mink\Selector\SelectorsHandler $selectorsHandler = null)
    {
        parent::__construct($driver, $selectorsHandler);
        $this->page = new DGUDocumentElement($this);
    }
    /**
     * Returns page element.
     *
     * @return DocumentElement
     */
    public function getPage()
    {
        return $this->page;
    }
}


/**
 * Derived from DocumentElement to override find() method.
 * To manipulate only visible elements.
 */
class DGUDocumentElement extends \Behat\Mink\Element\DocumentElement
{
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
}

return new DGUExtension();