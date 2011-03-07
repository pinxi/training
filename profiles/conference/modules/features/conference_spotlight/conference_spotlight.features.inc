<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function conference_spotlight_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function conference_spotlight_imagecache_default_presets() {
  $items = array(
    'spotlight-m' => array(
      'presetname' => 'spotlight-m',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '350',
            'height' => '350',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'spotlight-wide' => array(
      'presetname' => 'spotlight-wide',
      'actions' => array(
        '0' => array(
          'weight' => '-10',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '700',
            'height' => '',
            'upscale' => 1,
          ),
        ),
        '1' => array(
          'weight' => '-9',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '700',
            'height' => '300',
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
function conference_spotlight_node_info() {
  $items = array(
    'spotlight' => array(
      'name' => t('Spotlight'),
      'module' => 'features',
      'description' => t('Spotlight banner'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function conference_spotlight_views_api() {
  return array(
    'api' => '2',
  );
}
