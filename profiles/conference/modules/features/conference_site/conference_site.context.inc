<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function conference_site_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'conference_site-front';
  $context->description = '';
  $context->tag = 'Front page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-conference_spotlight-block_1' => array(
          'module' => 'views',
          'delta' => 'conference_spotlight-block_1',
          'region' => 'content',
          'weight' => 0,
        ),
        'views-feature_news-block_3' => array(
          'module' => 'views',
          'delta' => 'feature_news-block_3',
          'region' => 'content',
          'weight' => 1,
        ),
        'conference_profile-registration' => array(
          'module' => 'conference_profile',
          'delta' => 'registration',
          'region' => 'left',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front page');

  $export['conference_site-front'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'conference_site-navigation';
  $context->description = '';
  $context->tag = 'Sitewide context';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~node/*/edit' => '~node/*/edit',
        '~node/*/delete' => '~node/*/delete',
        '~node/add/*' => '~node/add/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-primary-links' => array(
          'module' => 'menu',
          'delta' => 'primary-links',
          'region' => 'left',
          'weight' => 0,
        ),
        'views-443d9d9c2f41027f0b191b6294ae88fd' => array(
          'module' => 'views',
          'delta' => '443d9d9c2f41027f0b191b6294ae88fd',
          'region' => 'left',
          'weight' => 1,
        ),
      ),
      'layout' => 'sidebar',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide context');

  $export['conference_site-navigation'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'conference_site-sitewide';
  $context->description = '';
  $context->tag = 'Sitewide context';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'conference_site-conference_footer' => array(
          'module' => 'conference_site',
          'delta' => 'conference_footer',
          'region' => 'footer',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide context');

  $export['conference_site-sitewide'] = $context;
  return $export;
}
