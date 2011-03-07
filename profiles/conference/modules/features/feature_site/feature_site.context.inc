<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function feature_site_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'feature_site_sitewide';
  $context->description = '';
  $context->tag = 'Sitewide context';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide context');

  $export['feature_site_sitewide'] = $context;
  return $export;
}
