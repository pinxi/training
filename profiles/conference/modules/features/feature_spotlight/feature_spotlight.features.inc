<?php

/**
 * Implementation of hook_imagecache_default_presets().
 */
function feature_spotlight_imagecache_default_presets() {
  $items = array(
    'spotlight-l' => array(
      'presetname' => 'spotlight-l',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '600',
            'height' => '220',
          ),
        ),
      ),
    ),
    'spotlight-portrait' => array(
      'presetname' => 'spotlight-portrait',
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
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function feature_spotlight_views_api() {
  return array(
    'api' => '2',
  );
}
