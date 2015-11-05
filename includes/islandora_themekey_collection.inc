<?php

/**
 * @file
 * Mapping functions for Islandora Themekey.
 */

/**
 * Themekey callback.
 *
 * Inspects the current object and its child pages, if any, to determine
 * what collection they are part of.
 *
 * @return array
 *   List of collection PIDs.
 */
function islandora_themekey_is_member_of_collection() {
  $parameters = array();
  // Get the PID, and if it appears to be an alias, get the
  // corrsponding PID.
  if (count(arg()) > 1) {
    module_load_include('inc', 'islandora', 'includes/utilities');
    $pid = arg(2);
    if (!islandora_is_valid_pid($pid)) {
      // Check the url_alias table to see if there's an entry there.
      $pid = drupal_get_normal_path(current_path());
    }
    $islandora_object = islandora_object_load($pid);

    // islandora:is_member_of_collection property.
    $collection_pids = array();
    if ($islandora_object) {
      $collections = $islandora_object->relationships->get(FEDORA_RELS_EXT_URI, 'isMemberOfCollection');
      // The root collection PID will be a member of 0 collections, so we need
      // to check for it.
      if (count($collections) > 0) {
        foreach ($collections as $collection) {
          $collection_pids[] = $collection['object']['value'];
        }
        return $collection_pids;
      }
      else {
        // If the object is a book page or a newspaper issue, query the RI
        // to get its ancestor collection.
        $object_cmodel_pids = $islandora_object->models;
        if ($object_cmodel_pids[0] == 'islandora:newspaperIssueCModel'
          || $object_cmodel_pids[0] == 'islandora:pageCModel') {
          $query = <<<EOQ
            select ?collection from <#ri> where {
              # Get the collection that book pages and newspaper issues belong to.
              <info:fedora/$pid> <fedora-rels-ext:isMemberOf> ?parent .
              ?parent <fedora-rels-ext:isMemberOfCollection> ?collection .
            }
EOQ;
          $connection = islandora_get_tuque_connection();
          $results = $connection->repository->ri->sparqlQuery($query, 1);
          foreach ($results as $result) {
            $collection_pids[] = $result['collection']['value'];
          }
          return $collection_pids;
        }
        // If the object is a newspaper page, query the RI to get the
        // its ancestor collection.
        if ($object_cmodel_pids[0] == 'islandora:newspaperPageCModel') {
          $query = <<<EOQ
            select ?collection from <#ri> where {
              # Get the collection that newspaper pages belong to.
              <info:fedora/$pid> <fedora-rels-ext:isMemberOf> ?issue .
              ?issue <fedora-rels-ext:isMemberOf> ?newspaper .
              ?newspaper <fedora-rels-ext:isMemberOfCollection> ?collection .
            }
EOQ;
          $connection = islandora_get_tuque_connection();
          $results = $connection->repository->ri->sparqlQuery($query, 1);
          foreach ($results as $result) {
            $collection_pids[] = $result['collection']['value'];
          }
          return $collection_pids;
        }
      }
    }
  }
  return NULL;
}
