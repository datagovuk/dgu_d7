<?php



class CKANDatsetMigration extends DrupalMigration {
    protected $source_type;

    /**
     * Constructor for CommentMigration
     * $arguments should contain the following elements:
     *  - user_migration: The machine name of the migration to use as the source for user id's.
     *  - default_uid: user id to use if not specified.
     *
     * @param array $arguments
     * @throws MigrateException
     */
    function __construct($arguments){


        if (!empty($arguments['source_type'])) {
            $this->source_type = $arguments['source_type'];
        }

        if (!empty($arguments['user_migration'])) {
            $user_migration = $arguments['user_migration'];
            $this->dependencies[] = $user_migration;
        }
        if (!array_key_exists('description', $arguments)){
            $arguments['description'] = '';
        }
        parent::__construct($arguments);
        $this->source = new MigrateSourceSQL($this->query(),  $this->sourceFields, NULL, $this->sourceOptions);
        $this->destination = new MigrateDestinationCKANDataset('ckan_dataset');
        $this->map = new MigrateSQLMap($this->machineName,
            array(
                'nid' => array('type' => 'int',
                    'unsigned' => TRUE,
                    'not null' => TRUE,
                    'description' => 'Source ckan node id',
                    'alias' => 'n',
                ),
            ),
            MigrateDestinationComment::getKeySchema()
        );
        // Setup  mappings.
        $this->addSimpleMappings(array('title', 'status', 'ckan_id'));

        if (isset($arguments['default_uid'])) {
            $default_uid = $arguments['default_uid'];
        }
        else {
            $default_uid = 1;
        }

        if (isset($user_migration)) {
            $this->addFieldMapping('uid', 'uid')
                ->sourceMigration($user_migration)
                ->defaultValue($default_uid);
        }
        else {
            $this->addFieldMapping('uid')
                ->defaultValue($default_uid);
        }
    }

    /**
     * Implementation of DrupalCommentMigration::query().
     *
     * We join to {node} so that we can use separate comment migration classes
     * for each associated node type.
     *
     * @return SelectQueryInterface
     */
    protected function query() {
        $query = Database::getConnection('default', $this->sourceConnection)
            ->select('ckan_package', 'cp')
            ->distinct()
            ->fields('cp', array('ckan_id', 'ckan_name', 'ckan_version', 'ckan_url'))
            ->condition('type', $this->sourceType)
            ->orderBy('changed');
        $query->innerJoin('node', 'n', 'n.vid=cp.vid');
        $query->fields('n', array('nid', 'vid', 'language', 'title',
            'uid', 'status', 'created', 'changed', 'comment', 'promote',
            'moderate', 'sticky', 'tnid', 'translate'));
        $query->innerJoin('node_revisions', 'nr', 'n.vid=nr.vid');
        $query->fields('nr', array('body', 'teaser', 'format'));
        $query->groupBy('cp.ckan_id');
        // Pick up simple CCK fields
        $cck_table = 'content_type_' . $this->sourceType;
        if (Database::getConnection('default', $this->sourceConnection)
            ->schema()->tableExists($cck_table)) {
            $query->leftJoin($cck_table, 'f', 'n.vid=f.vid');
            // The main column for the field should be rendered with
            // the field name, not the column name (e.g., field_foo rather
            // than field_foo_value).
            $field_info = $this->version->getSourceFieldInfo();
            foreach ($field_info as $field_name => $info) {
                if (isset($info['columns']) && !$info['multiple'] && $info['db_storage']) {
                    $i = 0;
                    foreach ($info['columns'] as $display_name => $column_name) {
                        if ($i++ == 0) {
                            $query->addField('f', $column_name, $field_name);
                        }
                        else {
                            // The database API won't allow colons in column aliases, so we
                            // will accept the default alias, and fix up the field names later.
                            // Remember how to translate the field names.
                            $clean_name = str_replace(':', '_', $display_name);
                            $this->fixFieldNames[$clean_name] = $display_name;
                            $query->addField('f', $column_name);
                        }
                    }
                }
            }
        }
        return $query;
    }

}

class MigrateDestinationCKANDataset extends MigrateDestinationEntity{
    /**
     * Basic initialization
     *
     * @param string $bundle
     *  A.k.a. the content type (page, article, etc.) of the ... comment?.
     * @param array $options
     *  Options applied to comments.
     */
    public function __construct($bundle, array $options = array()) {
        parent::__construct('ckan_dataset', $bundle, $options);
    }

    /**
     * Returns a list of fields available to be mapped for ckan dataset entities
     *
     * @param Migration $migration
     *  Optionally, the migration containing this destination.
     * @return array
     *  Keys: machine names of the fields (to be passed to addFieldMapping)
     *  Values: Human-friendly descriptions of the fields.
     */
    public function fields($migration = NULL) {
        $fields = array();
        $fields['id'] = t('CKAN Dataset Id');
        $fields['ckan_id'] = t('CKAN UUID');
        $fields['publisher_id'] = t("CKAN Publisher Id");
        $fields['title'] = t('Title');
        $fields['name'] = t('Name');
        $fields['data'] = t('Data');
        $fields['created'] = t('The date and time when the comment was created.');
        $fields['changed'] = t('The date and time when the comment was last changed');
        $fields['status'] = t('Status of reply.');

        // Then add in anything provided by handlers
        $fields += migrate_handler_invoke_all('Entity', 'fields', $this->entityType, $this->bundle, $migration);
        $fields += migrate_handler_invoke_all('Reply', 'fields', $this->entityType, $this->bundle, $migration);

        return $fields;
    }

    static public function getKeySchema() {
        return array(
            'id' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'description' => 'ID of reply entity',
            ),
        );
    }

    /**
     * Import a single ckan entity.
     *
     * @param $ckan_dataset
     *  CKAN Dataset object to build. Prefilled with any fields mapped in the Migration.
     * @param $row
     *  Raw source data object - passed through to prepare/complete handlers.
     * @return array
     *  Array of key fields (id only in this case) of the ckan dataset that was saved if
     *  successful. FALSE on failure.
     */
    public function import(stdClass $ckan_dataset, stdClass $row) {
        $migration = Migration::currentMigration();
        // In Drupal 6 status=0 means published, ckan dataset status=0 means unpublished
        $ckan_dataset->status = !$ckan_dataset->status;
        // Updating previously-migrated content?
        if (isset($row->migrate_map_destid1)) {
            if (isset($ckan_dataset->id)) {
                if ($ckan_dataset->id != $row->migrate_map_destid1) {
                    throw new MigrateException(t("Incoming id !id and map destination nid !destid1 don't match",
                        array('!id' => $ckan_dataset->id, '!destid1' => $row->migrate_map_destid1)));
                }
            }
            else {
                $ckan_dataset->id = $row->migrate_map_destid1;
            }
        }
        // Fix up timestamps
        if (isset($ckan_dataset->created)) {
            $ckan_dataset->created = MigrationBase::timestamp($ckan_dataset->created);
        }
        if (isset($ckan_dataset->changed)) {
            $ckan_dataset->changed = MigrationBase::timestamp($ckan_dataset->changed);
        }

        if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
            if (!isset($ckan_dataset->id)) {
                throw new MigrateException(t('System-of-record is DESTINATION, but no destination id provided'));
            }
            $rawdataset = $ckan_dataset;
            $old_dataset = entity_load('ckan_dataset', $ckan_dataset->id);
            if (empty($old_dataset)) {
                throw new MigrateException(t('System-of-record is DESTINATION, but ckan_dataset !id does not exist', array('!id' => $ckan_dataset->id)));
            }
            if (!isset($ckan_dataset->created)) {
                $ckan_dataset->created = $old_dataset->created;
            }
            if (!isset($ckan_dataset->changed)) {
                $ckan_dataset->changed = $old_dataset->changed;
            }
            $this->prepare($ckan_dataset, $row);
            foreach ($rawdataset as $field => $value) {
                $old_dataset->$field = $ckan_dataset->$field;
            }
            $ckan_dataset = $old_dataset;
        }
        else {
            // Set some default properties.
            $defaults = array(
                'bundle' => $this->bundle,
                'status' => 1,
            );
            foreach ($defaults as $field => $value) {
                if (!isset($ckan_dataset->$field)) {
                    $ckan_dataset->$field = $value;
                }
            }

            $this->prepare($ckan_dataset, $row);
        }

        if (isset($ckan_dataset->id) && $ckan_dataset->id) {
            $updating = TRUE;
        }
        else {
            $updating = FALSE;
        }

        migrate_instrument_start('ckan_dataset_save');
        $ckanDataset = new CKANDataset((array) $ckan_dataset);
        ckan_dataset_save($ckanDataset);
        migrate_instrument_stop('ckan_dataset_save');
        $this->complete($ckanDataset, $row);
        if (isset($ckanDataset->id) && $ckanDataset->id > 0) {
            $return = array($ckanDataset->id);
            if ($updating) {
                $this->numUpdated++;
            }
            else {
                $this->numCreated++;
            }
        }
        else {
            $return = FALSE;
        }
        return $return;
    }

    public function bulkRollback(array $ids){

    }


}
