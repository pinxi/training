<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function conference_program_user_default_permissions() {
  $permissions = array();

  // Exported permission: create activity content
  $permissions['create activity content'] = array(
    'name' => 'create activity content',
    'roles' => array(),
  );

  // Exported permission: delete any activity content
  $permissions['delete any activity content'] = array(
    'name' => 'delete any activity content',
    'roles' => array(),
  );

  // Exported permission: edit any activity content
  $permissions['edit any activity content'] = array(
    'name' => 'edit any activity content',
    'roles' => array(),
  );

  return $permissions;
}
