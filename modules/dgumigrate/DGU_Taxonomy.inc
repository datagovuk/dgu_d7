<?php

/**
 * @file
 * Import CKAN dataset packages to Drupal 7.
 */

abstract class DGUMigration extends DynamicMigration {
  public function __construct() {
    parent::__construct();
  }
}

abstract class DGUTaxonomyMigration extends DGUMigration {
  static function createVocabIfNotExists($name, $description){
    $vid = db_query("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = '{$name}'")->fetchField();
    if (!taxonomy_vocabulary_load($vid)){
      taxonomy_vocabulary_save((object) array(
        'name' => $description,
        'machine_name' => $name,
      ));
    }
  }

  public function __construct($name, $description, $source_vid) {
    parent::__construct();
    $this->description = t("Migrate $name vocabulary from D6 to D7");
    $this->createVocabIfNotExists($name, $description);
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'tid' => array('type' => 'int',
                          'unsigned' => TRUE,
                          'not null' => TRUE,
                        ),
        ),
        MigrateDestinationTerm::getKeySchema()
    );
    
    $query = db_select('term_data', 'td', array('target' => 'd6source'))
             ->fields('td', array('tid', 'name', 'description'))
             ->condition('vid', $source_vid);
   	error_log($query->countQuery());
    $this->source = new MigrateSourceSQL($query);

    $this->destination = new MigrateDestinationTerm($name);
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('description', 'description');
  }
}

class DGUCategoryMigration extends DGUTaxonomyMigration {
  public function __construct() {
    parent::__construct("category", "Categories", 4);
  }
}

class DGUSectorMigration extends DGUTaxonomyMigration {
  public function __construct() {
    parent::__construct("sector", "Sectors", 13);
  }
}


class DGUDocTypeMigration extends DGUTaxonomyMigration {
  public function __construct() {
    parent::__construct("document_type", "Document Types", 21);
  }
}

class DGUNationMigration extends DGUTaxonomyMigration {
	public function __construct() {
		parent::__construct("nation", "Nation", 8);
	}
}

class DGUPublicBodyMigration extends DGUTaxonomyMigration {
	public function __construct() {
		parent::__construct("public_body", "Public Body", 7);
	}
}

class DGUTagsMigration extends DGUTaxonomyMigration {
	public function __construct() {
		parent::__construct("tags", "Tags", 6);
	}
}