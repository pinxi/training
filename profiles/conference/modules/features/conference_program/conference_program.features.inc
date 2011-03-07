<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function conference_program_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function conference_program_node_info() {
  $items = array(
    'activity' => array(
      'name' => t('Activity'),
      'module' => 'features',
      'description' => t('An activity in the conference program, such as a session or a workshop.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function conference_program_views_api() {
  return array(
    'api' => '2',
  );
}
