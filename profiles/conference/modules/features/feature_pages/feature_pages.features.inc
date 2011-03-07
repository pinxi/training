<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function feature_pages_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function feature_pages_imagecache_default_presets() {
  $items = array(
    'box-m' => array(
      'presetname' => 'box-m',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '192',
            'height' => '192',
          ),
        ),
      ),
    ),
    'box-s' => array(
      'presetname' => 'box-s',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '128',
            'height' => '128',
          ),
        ),
      ),
    ),
    'scale-m' => array(
      'presetname' => 'scale-m',
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
    'scale-s' => array(
      'presetname' => 'scale-s',
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
function feature_pages_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'module' => 'features',
      'description' => t('Static pages.'),
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
