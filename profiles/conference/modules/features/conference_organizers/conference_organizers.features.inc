<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function conference_organizers_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function conference_organizers_imagecache_default_presets() {
  $items = array(
    'organizer-m' => array(
      'presetname' => 'organizer-m',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '192',
            'height' => '192',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'organizer-s' => array(
      'presetname' => 'organizer-s',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '128',
            'height' => '128',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function conference_organizers_node_info() {
  $items = array(
    'organizer' => array(
      'name' => t('Organizer'),
      'module' => 'features',
      'description' => t('Conference organizer.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Short description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function conference_organizers_views_api() {
  return array(
    'api' => '2',
  );
}
