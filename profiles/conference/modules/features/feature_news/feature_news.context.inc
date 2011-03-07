<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function feature_news_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'feature_news_list';
  $context->description = '';
  $context->tag = 'Node list';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news' => 'news',
        'news/*' => 'news/*',
      ),
    ),
    'views' => array(
      'values' => array(
        'feature_news:page_1' => 'feature_news:page_1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-feature_news-block_1' => array(
          'module' => 'views',
          'delta' => 'feature_news-block_1',
          'region' => 'right',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Node list');

  $export['feature_news_list'] = $context;
  return $export;
}
