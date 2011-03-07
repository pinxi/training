<?php
// $Id: node.inc,v 1.1 2009/08/08 06:56:42 sun Exp $

/**
 * Implementation of hook_wysiwyg_plugin().
 */
function inline_node_plugin() {
  $plugins['node'] = array(
    'title' => t('Inline node'),
    'vendor url' => 'http://drupal.org/project/inline',
    'icon file' => 'node.png',
    'icon title' => t('Insert or update an embedded content'),
    'settings' => array(
      'dialog' => array(
        'url' => base_path() . 'index.php?q=wysiwyg/node',
        'width' => 700,
        'height' => 500,
      ),
    ),
    // @todo Use a more granular way to validate contents for input formats.
    #'extended_valid_elements' => array('img[class|src|border=0|alt|title|width|height|align|name|style]'),
  );
  return $plugins;
}

/**
 * Implementation of hook_wysiwyg_dialog().
 *
 * @see inline_node_plugin()
 */
function node_wysiwyg_dialog($instance) {
  drupal_set_title(t('Add or edit external content'));

  // Add dialog JavaScript.
  drupal_add_js(drupal_get_path('module', 'inline') . '/plugins/dialog.js');

  return drupal_get_form('inline_node_wysiwyg_dialog_form', $instance);
}

/**
 * Form builder function for node inline wysiwyg dialog form.
 *
 * @see node_wysiwyg_dialog()
 */
function inline_node_wysiwyg_dialog_form(&$form_state, $instance) {
  $form['nid'] = array(
    '#type' => 'select',
    '#title' => t('Content to embed'),
    '#options' => array(
      1 => 'foo bar',
    ),
    '#description' => t('The selected content will be inserted and embedded into your content.'),
  );
  // @todo Wrap this into 'actions'.
  $form['submit'] = array(
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
  );
  $form['submit'][] = array('#type' => 'submit', '#value' => t('Insert'));
  $form['submit'][] = array(
    '#type' => 'markup',
    '#value' => l(t('Cancel'), 'external', array('attributes' => array('class' => 'form-cancel'))),
  );
  return $form;
}

