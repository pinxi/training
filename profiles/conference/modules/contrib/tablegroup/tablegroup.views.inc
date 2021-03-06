<?php
// $Id: tablegroup.views.inc,v 1.1.2.1 2009/11/24 19:26:01 bec Exp $

/**
 * Implementation of hook_views_plugins().
 */
function tablegroup_views_plugins() {
  return array(
    'module' => 'tablegroup',
    'style' => array(
      'tablegroup' => array(
        'title' => t('Grouped Table'),
        'help' => t('Displays results as cells in a table, grouped by row and column.'),
        'handler' => 'tablegroup_plugin_style_tablegroup',
        'theme' => 'tablegroup_view_tablegroup',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}

function template_preprocess_tablegroup_view_tablegroup(&$variables) {
  $header = $variables['rows']['header'];
  array_unshift($header, '&nbsp;');

  $rows = $variables['rows']['rows'];
  foreach ($rows as $row_label => $row) {
    array_unshift($rows[$row_label], array('header' => TRUE, 'data' => $row_label));
  }

  $variables['table'] = theme('table', $header, $rows, array('class' => 'views-plugin-style-tablegroup'));
}
