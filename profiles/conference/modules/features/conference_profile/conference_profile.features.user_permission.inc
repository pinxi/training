<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function conference_profile_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit own profile content
  $permissions['edit own profile content'] = array(
    'name' => 'edit own profile content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: use views exporter
  $permissions['use views exporter'] = array(
    'name' => 'use views exporter',
    'roles' => array(
      '0' => 'editor',
    ),
  );

  return $permissions;
}
