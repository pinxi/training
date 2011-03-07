<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function conference_workshop_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_flag_default_flags().
 */
function conference_workshop_flag_default_flags() {
  $flags = array();
  // Exported flag: "Subscription".
  $flags['subscription'] = array(
    'content_type' => 'node',
    'title' => 'Subscription',
    'global' => '0',
    'types' => array(
      '0' => 'workshop',
    ),
    'flag_short' => 'Subscribe',
    'flag_long' => '[flag-subscription-count] people have subscribed.',
    'flag_message' => '',
    'unflag_short' => 'Unsubscribe',
    'unflag_long' => '[flag-subscription-count] people have subscribed.',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        '0' => 2,
      ),
      'unflag' => array(
        '0' => 2,
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'conference_workshop',
    'locked' => array(
      '0' => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implementation of hook_node_info().
 */
function conference_workshop_node_info() {
  $items = array(
    'workshop' => array(
      'name' => t('Workshop'),
      'module' => 'features',
      'description' => t('Workshop content type.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function conference_workshop_views_api() {
  return array(
    'api' => '2',
  );
}
