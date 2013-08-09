<?php
/**
 */

class MigratePathRedirect extends DrupalMigration{
    public function __construct($arguments){
        $arguments['source_version'] = 6;
        parent::__construct($arguments);
        if (!array_key_exists('description', $arguments)){
            $arguments['description'] = '';
        }
        if (!empty($arguments['content_tables'])) {
            $tables = $arguments['content_tables'];
        }

        $this->source = new MigrateSourceSQL($this->query(),  $this->sourceFields, NULL, $this->sourceOptions);
        $this->destination = new MigrateDestinationRedirect($this->sourceConnection, $tables);
        $this->map = new MigrateSQLMap($this->machineName,
            array(
                'rid' => array('type' => 'int',
                    'unsigned' => TRUE,
                    'not null' => TRUE,
                    'description' => 'Redirect Id',
                    'alias' => 'r',
                ),
            ),
            MigrateDestinationComment::getKeySchema()
        );
        $this->addFieldMapping("rid", "rid");
        $this->addFieldMapping("source", "source");
        $this->addFieldMapping("redirect", "redirect");
        $this->addFieldMapping("query", NULL);
        $this->addFieldMapping("fragment", NULL);
        $this->addFieldMapping("language", "language");
        $this->addFieldMapping("status_code", "type");
        $this->addFieldMapping("last_used", "access");

        //add some defaults
        $this->addFieldMapping('source_options')->defaultValue('');
        $this->addFieldMapping('redirect_options')->defaultValue('');
        $this->addFieldMapping('uid')->defaultValue(0);


    }

    public function query(){
        $query = Database::getConnection('default', $this->sourceConnection)
            ->select('path_redirect', 'p')
            ->fields('p', array('rid', 'source', 'redirect', 'query', 'fragment', 'language', 'type', 'last_used'))
            ->orderBy('rid');
        return $query;
    }

}

class MigrateDestinationRedirect extends MigrateDestination {

    private $sourceConnection;

    private $tables;

    public function __construct($connection, $tables){
        $this->sourceConnection = $connection;
        $this->tables = $tables;
    }

    static public function getKeySchema() {
        return array(
            'rid' => array(
                'type' => 'int',
                'unsigned' => TRUE,
                'description' => 'Redirect ID',
            ),
        );
    }

    public function __toString() {
        $output = t('Redirect');
        return $output;
    }

    public function fields(){
        $fields = array();
        $fields["rid"] = t("rid");
        $fields["hash"] = t("hash");
        $fields["type"] = t("type");
        $fields["uid"] = t("uid");
        $fields["source"] = t("source");
        $fields["source_options"] = t("source_options");
        $fields["redirect"] = t("redirect");
        $fields["redirect_options"] = t("redirect_options");
        $fields["language"] = t("language");
        $fields["status_code"] = t("status_code");
        $fields["count"] = t("count");
        $fields["access"] = t("access");
        return $fields;
    }

    public function complete($object, $row){

    }

    public function rollback(array $key){
        db_delete('redirect')
            ->condition('rid', $key['destid1'])
            ->execute();
        entity_get_controller('redirect')->resetCache();
    }

    public function import(stdClass $object, stdClass $row){
        $updating = FALSE;
        //always make this insert a redirect.
        $object->rid = 0;
        //Add entity bundle type
        $object->type = 'redirect';
        $this->rewriteRedirect($object);
        redirect_save($object);
        $this->complete($object, $row);
        if (isset($object->rid) && $object->rid > 0) {
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

    /**
     * @param $source_nid
     * @return mixed
     */
    public function GetDestinationNid($source_nid, $table)
    {
        $dest_nid = FALSE;
        $query = Database::getConnection('default')
            ->select($table, '_temp')
            ->condition('sourceid1', $source_nid)
            ->fields('_temp', array('destid1'))
            ->execute();
        if ($query->rowCount() > 0) {
            $dest_nid = $query->fetchField(0);
        }

        return $dest_nid;
    }

    /**
     * @param stdClass $object
     */
    public function rewriteRedirect(stdClass $object)
    {
        $matches = array();
        preg_match('/(\w+)\/([0-9]*)\/(\w+)/', $object->redirect, $matches);
        if (!empty($matches)) {
            if ($matches[1] == 'node'){
                $source_nid = $matches[2];
                $query = Database::getConnection('default', $this->sourceConnection)
                    ->select('node', 'n')
                    ->condition('nid', $source_nid)
                    ->fields('n', array('type'))
                    ->execute();
                if ($query->rowCount() == 0){
                    throw new Exception('Source node %n is not found', $source_nid);
                }
                $type = $query->fetchField(0);
                $table = $this->tables[$type]['table'];
                $dest_nid = $this->getDestinationNid($source_nid, $table);
                if (!empty($dest_nid)) {
                    $url = $this->tables[$type]['url'] . '/' . $dest_nid;
                    if (count($matches) == 4) {
                        $url = $url . '/' . $matches[3];
                    }
                    $object->redirect = $url;
                }
            } elseif ($matches[1] == 'taxonomy'){
                throw new exception('not yet implemented');
            }
        }
    }
}
