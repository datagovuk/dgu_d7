<?php

class MigrateVotes extends DrupalMigration{
    private $source_type = '';
    public function __construct($arguments){
        $arguments['source_version'] = 6;
        parent::__construct($arguments);
        $this->source_type = 'node';
        if (!empty($arguments['source_type'])) {
            $this->source_type = $arguments['source_type'];
        }

        if (!empty($arguments['user_migration'])) {
            $user_migration = $arguments['user_migration'];
            $this->dependencies[] = $user_migration;
        }
        $content_source = 'node';
        if (!empty($arguments['content_source'])) {
            $content_source = $arguments['content_source'];
            $this->dependencies[] = $content_source;
        }
        if (!array_key_exists('description', $arguments)){
            $arguments['description'] = '';
        }

        $this->source = new MigrateSourceSQL($this->query(),  $this->sourceFields, NULL, $this->sourceOptions);
        $this->destination = new MigrateDestinationD7Votes();
        $this->map = new MigrateSQLMap($this->machineName,
            array(
                'vote_id' => array('type' => 'int',
                    'unsigned' => TRUE,
                    'not null' => TRUE,
                    'description' => 'Vote Id',
                    'alias' => 'v',
                ),
            ),
            MigrateDestinationComment::getKeySchema()
        );
        $this->addFieldMapping("vote_id", "vote_id");
        $this->addFieldMapping("entity_type", "content_type");
        $this->addFieldMapping("entity_id", "content_id")->sourceMigration($content_source);
        $this->addFieldMapping("value", "value");
        $this->addFieldMapping("value_type", "value_type");
        $this->addFieldMapping("tag", "tag");
        $this->addFieldMapping("uid", "uid");
        $this->addFieldMapping("timestamp", "timestamp");
        $this->addFieldMapping("vote_source", "vote_source");

    }

    public function query(){
        $query = Database::getConnection('default', $this->sourceConnection)
            ->select('votingapi_vote', 'v')
            ->fields('v', array('vote_id', 'content_type', 'content_id', 'value', 'value_type', 'tag', 'uid', 'timestamp', 'vote_source'))
            ->orderBy('vote_id');
        $query->leftJoin('node', 'n', 'n.nid = v.content_id');
        $query->condition('n.type', $this->source_type);
        return $query;
    }

}

class MigrateDestinationD7Votes extends MigrateDestination {
    static public function getKeySchema() {
        return array(
            'vote_id' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'description' => 'Vote ID',
            ),
        );
    }

    public function __toString() {
        $output = t('Voting API Votes');
        return $output;
    }

    public function fields(){
        $fields = array();
        $fields["vote_id"] = t("vote_id");
        $fields["entity_type"] = t("entity_type");
        $fields["entity_id"] = t("entity_id");
        $fields["value"] = t("value");
        $fields["value_type"] = t("value_type");
        $fields["tag"] = t("tag");
        $fields["uid"] = t("uid");
        $fields["timestamp"] = t("timestamp");
        $fields["vote_source"] = t("vote_source");
        return $fields;
    }

    public function complete($object, $row){
        votingapi_recalculate_results($object->entity_type, $object->entity_id, TRUE);
    }

    public function rollback(array $key){
        db_delete('votingapi_vote')
            ->condition('vote_id', $key['destid1'])
            ->execute();
    }

    public function import(stdClass $object, stdClass $row){
        $updating = FALSE;
        drupal_write_record('votingapi_vote', $object);
        $this->complete($object, $row);
        if (isset($object->vote_id) && $object->vote_id > 0) {
            $return = array($object->vote_id);
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
}
