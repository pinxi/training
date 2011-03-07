<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function conference_workshop_user_default_permissions() {
  $permissions = array();

  // Exported permission: create workshop content
  $permissions['create workshop content'] = array(
    'name' => 'create workshop content',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  // Exported permission: delete any workshop content
  $permissions['delete any workshop content'] = array(
    'name' => 'delete any workshop content',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  // Exported permission: delete own workshop content
  $permissions['delete own workshop content'] = array(
    'name' => 'delete own workshop content',
    'roles' => array(),
  );

  // Exported permission: edit any workshop content
  $permissions['edit any workshop content'] = array(
    'name' => 'edit any workshop content',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  // Exported permission: edit own workshop content
  $permissions['edit own workshop content'] = array(
    'name' => 'edit own workshop content',
    'roles' => array(),
  );

  return $permissions;
}
