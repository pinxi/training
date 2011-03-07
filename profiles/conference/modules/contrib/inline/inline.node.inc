<?php
// $Id: inline.node.inc,v 1.4 2009/08/12 05:54:36 sun Exp $

/**
 * @file
 * Allows to embed nodes into content.
 */

/**
 * Implementation of hook_TAGNAME_inline().
 *
 * @param $op
 *   The current operation performed.
 * @param $macro
 *   An inline macro object containing user supplied values, passed by reference.
 */
function inline_node_inline($op, &$macro) {
  switch ($op) {
    case 'args':
      // Return an array of available/required tag arguments.
      $args = array(
        'nid' => array(
          '#title' => t('Node id'),
          '#description' => t('A node id to embed.'),
          '#type' => 'int',
          '#default_value' => 0,
        ),
      );
      return $args;

    case 'prepare':
      // Load a node object if valid nid is given.
      if (!empty($macro->params['nid'])) {
        $node = node_load($macro->params['nid']);
        if (node_access('view', $node)) {
          $macro->node['node'] = $node;
        }
      }
      return;

    case 'render':
      // Return a rendered representation to replace a tag.
      if (!isset($macro->node['node'])) {
        return;
      }
      $node = node_build_content($macro->node['node'], FALSE, TRUE);
      return drupal_render($node->content);
  }
}

