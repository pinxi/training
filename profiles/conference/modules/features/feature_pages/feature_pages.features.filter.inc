<?php

/**
 * Implementation of hook_filter_default_formats().
 */
function feature_pages_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML
  $formats['Filtered HTML'] = array(
    'name' => 'Filtered HTML',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'editor',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'markdown',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-9',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '0',
        'weight' => '-8',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '-7',
      ),
      '4' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-6',
      ),
      '5' => array(
        'module' => 'inline',
        'delta' => '0',
        'weight' => '-5',
      ),
    ),
  );

  // Exported format: Full HTML
  $formats['Full HTML'] = array(
    'name' => 'Full HTML',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'editor',
    ),
    'filters' => array(
      '0' => array(
        'module' => 'markdown',
        'delta' => '0',
        'weight' => '-10',
      ),
      '1' => array(
        'module' => 'filter',
        'delta' => '2',
        'weight' => '-9',
      ),
      '2' => array(
        'module' => 'filter',
        'delta' => '1',
        'weight' => '-8',
      ),
      '3' => array(
        'module' => 'filter',
        'delta' => '3',
        'weight' => '-7',
      ),
      '4' => array(
        'module' => 'inline',
        'delta' => '0',
        'weight' => '-6',
      ),
    ),
  );

  return $formats;
}
