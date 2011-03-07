<?php
// $Id: inline.api.php,v 1.1 2009/08/08 06:32:40 sun Exp $

/**
 * @file
 * Inline API documentation.
 */

/**
 * Implementation of hook_inline_info().
 *
 * @return
 *   An associative array of inline tags provided by this module, keyed by tag
 *   name with the following properties:
 *   - callback: (optional) The inline callback function name. Defaults to
 *     MODULENAME_TAGNAME_inline().
 *   - file: (optional) The include file where callback function resides.
 *   - path: (optional) The path of the include file. Defaults to the module's
 *     directory.
 */
function hook_inline_info() {
  $info['node'] = array(
    'file' => 'inline.node.inc',
  );
  if (module_exists('upload')) {
    $info['upload'] = array(
      'file' => 'inline.upload.inc',
    );
  }
  return $info;
}

