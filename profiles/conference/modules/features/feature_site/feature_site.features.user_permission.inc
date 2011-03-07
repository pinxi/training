<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function feature_site_user_default_permissions() {
  $permissions = array();

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
  );

  return $permissions;
}
