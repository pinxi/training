<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function conference_spotlight_user_default_permissions() {
  $permissions = array();

  // Exported permission: create spotlight content
  $permissions['create spotlight content'] = array(
    'name' => 'create spotlight content',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  // Exported permission: delete any spotlight content
  $permissions['delete any spotlight content'] = array(
    'name' => 'delete any spotlight content',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  // Exported permission: edit any spotlight content
  $permissions['edit any spotlight content'] = array(
    'name' => 'edit any spotlight content',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  return $permissions;
}
