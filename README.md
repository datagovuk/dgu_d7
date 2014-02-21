dgu_d7
======

Data.gov.uk Drupal 7 project


INSTALLATION
============

To use this drupal distribution, you will need to have a LAMP stack and a working drush installation.  Please see
https://drupal.org/requirements for detailed requirements. You can get drush and it's installation instructions from
here: https://github.com/drush-ops/drush

Once you have the requirements sorted out, you can install drupal with the following drush commands:

````bash
$ drush make distro.make /var/www/
$ drush --yes --verbose site-install dgu --db-url=mysql://user:pass@localhost/db_name --account-name=admin --account-pass=password  --site-name='something creative'
```

This will install drupal, download all the required modules and configure the system.  After this step completes
successfully, you should enable some modules:

````bash
$ drush --yes en dgu_site_feature  
$ drush --yes en composer_manager  
$ drush --yes en dgu_app dgu_blog dgu_consultation dgu_data_set dgu_data_set_request dgu_footer dgu_forum dgu_glossary dgu_idea dgu_library dgu_linked_data dgu_location dgu_organogram dgu_promo_items dgu_reply dgu_shared_fields dgu_user dgu_taxonomy ckan dgu_search dgu_services dgu_home_page
$ drush --yes en ckan
````

You will need to configure drupal with the url of your CKAN instance.  We use the following drush commands:
````bash
$ drush vset ckan_url 'http://data.gov.uk/api/';
$ drush vset ckan_apikey 'xxxxxxxxxxxxxxxxxxxxx';
````
You may also check and modify these settings in the admin menu: configuration->system->ckan.

We have also written some migration classes for migrating our existing Drupal 6 web site to version 7.  The order
that we run these tasks is important.  After installation, we run the following drush commands to migrate our web site:

````bash
$ drush migrate-import --group=User --debug  
$ drush migrate-import --group=Taxonomy  
$ drush migrate-import --group=Files --debug  
$ drush migrate-import --group=Datasets --debug  
$ drush migrate-import --group=Nodes --debug  
$ drush migrate-import --group=Paths --debug  
$ drush migrate-import --group=Comments --debug  
````

The migration depends on finding drupal variables to tell it where to look to find files and the data,
so, before you can run the migration, you will to add something like the following to your settings.php file:

````php
$conf['drupal6files'] = '/var/www/old_files';
$databases['d6source']['default'] = array(
    'driver' => 'mysql',
    'database' => 'drupal_d6',
    'username' => 'web',
    'password' => 'supersecret',
    'host' => 'localhost',
    'prefix' => '',
);
````

