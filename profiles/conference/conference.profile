<?php
/**
 * Conference Template Installation Profile
 * @author Nuvole
 */

/**
 * Implementation of hook_profile_details().
 */
function conference_profile_details() {
  return array(
    'name' => 'Conference template',
    'description' => 'Conference template installation profile.',
  );
}

/**
 * Implementation of hook_profile_modules().
 */
function conference_profile_modules() {

  $modules = array(
    // Core
    'block',
    'comment',
    'menu',
    'node',
    'openid',
    'path',
    'search',
    'system',
    'taxonomy',
    'trigger',
    'upload',
    'user',
    );
  return $modules;
}

function _conference_profile_modules() {
  return array(
    // Contrib
    'admin',
    'captcha',
    'content',
    'content_copy',
    'content_profile',
    'content_profile_registration',
    'context',
    'context_ui',
    'context_layouts',
    'ctools',
    'date_api',
    'date_timezone',
    'date',
    'date_popup',
    'diff',
    'email',
    'features',
    'filefield',
    'filter',
    'help',
    'imageapi',
    'imageapi_gd',
    'imageapi_imagemagick',
    'imagecache',
    'imagecache_ui',
    'imagefield',
    'jquery_ui',
    'lightbox2',
    'link',
    'markdown',
    'nodereference',
    'number',
    'openlayers',
    'openlayers_cck',
    'openlayers_geocoder',
    'openlayers_ui',
    'openlayers_views',
    'optionwidgets',
    'pathauto',
    'pathfilter',
    'recaptcha',
    'rules_admin',
    'strongarm',
    'text',
    'token',
    'transliteration',
    'views',
    'views_bulk_operations',
    'views_export',
    'views_ui',
    'views_slideshow',

    // Devel
    'schema',
    'backup_migrate',

    // Features
    'conference_site',
  );
}

/**
 * Implementation of hook_profile_task_list().
 */
function conference_profile_task_list() {

  $tasks['template-modules-batch'] = st('Install modules');
  $tasks['template-configure-batch'] = st('Configure platform');
  return $tasks;
}

/**
 * Implementation of hook_profile_tasks().
 */
function conference_profile_tasks(&$task, $url) {
  global $profile, $install_locale;

  // Just in case some of the future tasks adds some output
  $output = '';
  $batch = array();

  if ($task == 'profile') {
    // If we reach here, means no language install, move on to the next task
    $task = 'template-modules';
  }


  // We are running a batch task for this profile so basically do nothing and return page
  if (in_array($task, array('template-modules-batch', 'template-configure-batch'))) {
    include_once 'includes/batch.inc';
    $output = _batch_page();
  }

  // Install some more modules and maybe localization helpers too
  if ($task == 'template-modules') {
    $modules = _conference_profile_modules();
    $files = module_rebuild_cache();
    // Create batch
    foreach ($modules as $module) {
      $batch['operations'][] = array('_install_module_batch', array($module, $files[$module]->info['name']));
    }
    $batch['finished'] = '_conference_profile_batch_finished';
    $batch['title'] = st('Installing @drupal', array('@drupal' => drupal_install_profile_name()));
    $batch['error_message'] = st('The installation has encountered an error.');

    // Start a batch, switch to 'template-modules-batch' task. We need to
    // set the variable here, because batch_process() redirects.
    variable_set('install_task', 'template-modules-batch');
    batch_set($batch);
    batch_process($url, $url);
    // Jut for cli installs. We'll never reach here on interactive installs.
    return;
  }

  // Run additional configuration tasks
  // @todo Review all the cache/rebuild options at the end, some of them may not be needed
  // @todo Review for localization, the time zone cannot be set that way either
  if ($task == 'template-configure') {
    $batch['title'] = st('Configuring @drupal', array('@drupal' => drupal_install_profile_name()));
    $batch['operations'][] = array('_conference_template_configure', array());
    $batch['operations'][] = array('_conference_template_configure_check', array());
    $batch['finished'] = '_conference_template_configure_finished';
    variable_set('install_task', 'template-configure-batch');
    batch_set($batch);
    batch_process($url, $url);
    // Jut for cli installs. We'll never reach here on interactive installs.
    return;
  }

  return $output;
}

/**
 * Finished callback for the modules install batch.
 *
 * Advance installer task to language import.
 */
function _conference_profile_batch_finished($success, $results) {
  variable_set('install_task', 'template-configure');
}



/**
 * Configuration. First stage.
 */
function _conference_template_configure() {
  global $install_locale;

  // Set time zone
  // @TODO: This is not sufficient. We either need to display a message or
  // derive a default date API location.
  $tz_offset = date('Z');
  variable_set('date_default_timezone', $tz_offset);
}

/**
 * Configuration. Second stage.
 */
function _conference_template_configure_check() {
  // This isn't actually necessary as there are no node_access() entries,
  // but we run it to prevent the "rebuild node access" message from being
  // shown on install.
  node_access_rebuild();

  // Rebuild key tables/caches
  drupal_flush_all_caches();

  // Set default theme. This must happen after drupal_flush_all_caches(), which
  // will run system_theme_data() without detecting themes in the install
  // profile directory.
  _conference_system_theme_data();
  db_query("UPDATE {blocks} SET status = 0, region = ''"); // disable all DB blocks
  db_query("UPDATE {system} SET status = 0 WHERE type = 'theme' and name ='%s'", 'garland');
  db_query("UPDATE {system} SET status = 0 WHERE type = 'theme' and name ='%s'", 'ginkgo');
  variable_set('theme_default', 'conference');

  // Enable caching, CSS and JS compression
  // variable_set('cache', 1);
  // variable_set('preprocess_css', 1);
  // variable_set('preprocess_js', 1);

  // In Aegir install processes, we need to init strongarm manually as a
  // separate page load isn't available to do this for us.
  if (function_exists('strongarm_init')) {
    strongarm_init();
  }

  // Revert key components that are overridden by others on install.
  // Note that this comes after all other processes have run, as some cache
  // clears/rebuilds actually set variables or other settings that would count
  // as overrides. See `og_node_type()`.
  // Revert key components that are overridden by others on install.
  // Note that this comes after all other processes have run, as some cache
  // clears/rebuilds actually set variables or other settings that would count
  // as overrides. See `og_node_type()`.
  $revert = array(
    'conference_site'         => array('user_permission', 'variable', 'filter', 'user_role'),
    'conference_organizers'   => array('user_permission', 'variable', 'user_role'),
    'conference_profile'      => array('user_permission', 'variable', 'user_role'),
    'conference_program'      => array('user_permission', 'variable', 'user_role'),
    'conference_site'         => array('user_permission', 'variable', 'user_role'),
    'conference_spotlight'    => array('user_permission', 'variable', 'user_role'),
    'feature_site'            => array('user_permission', 'variable', 'user_role'),
  );
  features_revert($revert);
  drupal_flush_all_caches();
}

/**
 * Finish configuration batch
 *
 * @todo Handle error condition
 */
function _conference_template_configure_finished($success, $results) {
  variable_set('conference_install', 1);
  variable_set('install_task', 'finished');
}


/**
 * Alter some forms implementing hooks in system module namespace
 * This is a trick for hooks to get called, otherwise we cannot alter forms
 */

/**
 * @TODO: This might be impolite/too aggressive. We should at least check that
 * other install profiles are not present to ensure we don't collide with a
 * similar form alter in their profile.
 */
function system_form_install_select_profile_form_alter(&$form, $form_state) {
  foreach($form['profile'] as $key => $element) {
    $form['profile'][$key]['#value'] = 'conference';
  }
}

/**
 * Set English as default language.
 *
 * If no language selected, the installation crashes. I guess English should be the default
 * but it isn't in the default install. @todo research, core bug?
 */
function system_form_install_select_locale_form_alter(&$form, $form_state) {
  $form['locale']['en']['#value'] = 'en';
}

/**
 * Alter the install profile configuration form and provide timezone location options.
 */
function system_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['site_name']['#default_value'] = 'conference';
  $form['site_information']['site_mail']['#default_value'] = 'admin@'. $_SERVER['HTTP_HOST'];
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'admin@'. $_SERVER['HTTP_HOST'];
  $form['server_settings']['update_status_module']['#default_value'][0] = 0;

  if (function_exists('date_timezone_names') && function_exists('date_timezone_update_site')) {
    $form['server_settings']['date_default_timezone']['#access'] = FALSE;
    $form['server_settings']['#element_validate'] = array('date_timezone_update_site');
    $form['server_settings']['date_default_timezone_name'] = array(
      '#type' => 'select',
      '#title' => t('Default time zone'),
      '#default_value' => NULL,
      '#options' => date_timezone_names(FALSE, TRUE),
      '#description' => t('Select the default site time zone. If in doubt, choose the timezone that is closest to your location which has the same rules for daylight saving time.'),
      '#required' => TRUE,
    );
  }
}

/**
 * Reimplementation of system_theme_data(). The core function's static cache
 * is populated during install prior to active install profile awareness.
 * This workaround makes enabling themes in profiles/[profile]/themes possible.
 */
function _conference_system_theme_data() {
  global $profile;
  $profile = 'conference';

  $themes = drupal_system_listing('\.info$', 'themes');
  $engines = drupal_system_listing('\.engine$', 'themes/engines');

  $defaults = system_theme_default();

  $sub_themes = array();
  foreach ($themes as $key => $theme) {
    $themes[$key]->info = drupal_parse_info_file($theme->filename) + $defaults;

    if (!empty($themes[$key]->info['base theme'])) {
      $sub_themes[] = $key;
    }

    $engine = $themes[$key]->info['engine'];
    if (isset($engines[$engine])) {
      $themes[$key]->owner = $engines[$engine]->filename;
      $themes[$key]->prefix = $engines[$engine]->name;
      $themes[$key]->template = TRUE;
    }

    // Give the stylesheets proper path information.
    $pathed_stylesheets = array();
    foreach ($themes[$key]->info['stylesheets'] as $media => $stylesheets) {
      foreach ($stylesheets as $stylesheet) {
        $pathed_stylesheets[$media][$stylesheet] = dirname($themes[$key]->filename) .'/'. $stylesheet;
      }
    }
    $themes[$key]->info['stylesheets'] = $pathed_stylesheets;

    // Give the scripts proper path information.
    $scripts = array();
    foreach ($themes[$key]->info['scripts'] as $script) {
      $scripts[$script] = dirname($themes[$key]->filename) .'/'. $script;
    }
    $themes[$key]->info['scripts'] = $scripts;

    // Give the screenshot proper path information.
    if (!empty($themes[$key]->info['screenshot'])) {
      $themes[$key]->info['screenshot'] = dirname($themes[$key]->filename) .'/'. $themes[$key]->info['screenshot'];
    }
  }

  foreach ($sub_themes as $key) {
    $themes[$key]->base_themes = system_find_base_themes($themes, $key);
    // Don't proceed if there was a problem with the root base theme.
    if (!current($themes[$key]->base_themes)) {
      continue;
    }
    $base_key = key($themes[$key]->base_themes);
    foreach (array_keys($themes[$key]->base_themes) as $base_theme) {
      $themes[$base_theme]->sub_themes[$key] = $themes[$key]->info['name'];
    }
    // Copy the 'owner' and 'engine' over if the top level theme uses a
    // theme engine.
    if (isset($themes[$base_key]->owner)) {
      if (isset($themes[$base_key]->info['engine'])) {
        $themes[$key]->info['engine'] = $themes[$base_key]->info['engine'];
        $themes[$key]->owner = $themes[$base_key]->owner;
        $themes[$key]->prefix = $themes[$base_key]->prefix;
      }
      else {
        $themes[$key]->prefix = $key;
      }
    }
  }

  // Extract current files from database.
  system_get_files_database($themes, 'theme');
  db_query("DELETE FROM {system} WHERE type = 'theme'");
  foreach ($themes as $theme) {
    $theme->owner = !isset($theme->owner) ? '' : $theme->owner;
    db_query("INSERT INTO {system} (name, owner, info, type, filename, status, throttle, bootstrap) VALUES ('%s', '%s', '%s', '%s', '%s', %d, %d, %d)", $theme->name, $theme->owner, serialize($theme->info), 'theme', $theme->filename, isset($theme->status) ? $theme->status : 0, 0, 0);
  }
}







