<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function conference_organizers_user_default_permissions() {
  $permissions = array();

  // Exported permission: create organizer content
  $permissions['create organizer content'] = array(
    'name' => 'create organizer content',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  // Exported permission: delete any organizer content
  $permissions['delete any organizer content'] = array(
    'name' => 'delete any organizer content',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  // Exported permission: edit any organizer content
  $permissions['edit any organizer content'] = array(
    'name' => 'edit any organizer content',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  return $permissions;
}
