<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function conference_workshop_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'conference_workshop-profile';
  $context->description = '';
  $context->tag = 'Profile page';
  $context->conditions = array();
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Profile page');

  $export['conference_workshop-profile'] = $context;
  return $export;
}
