<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function conference_profile_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function conference_profile_node_info() {
  $items = array(
    'profile' => array(
      'name' => t('Profile'),
      'module' => 'features',
      'description' => t('A user profile built as content.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function conference_profile_rules_defaults() {
  return array(
    'rules' => array(
      'conference_profile_1' => array(
        '#type' => 'rule',
        '#set' => 'event_user_insert',
        '#label' => 'conference_profile_user_creation',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'conference_profile',
        ),
        '#status' => 'default',
        '#conditions' => array(),
        '#actions' => array(
          '0' => array(
            '#weight' => -3,
            '#info' => array(
              'label' => 'Load registered user\'s Profile',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User, whose profile should be loaded',
                ),
              ),
              'new variables' => array(
                'profile_node' => array(
                  'type' => 'node',
                  'label' => 'Content Profile',
                ),
              ),
              'module' => 'Content Profile',
            ),
            '#name' => 'content_profile_action_load',
            '#settings' => array(
              'type' => 'profile',
              '#argument map' => array(
                'user' => 'account',
                'profile_node' => 'profile_node',
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#weight' => -2,
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#settings' => array(
              'from' => 'info@bolognaexperts.net',
              'subject' => 'You have been successfully registered for the HER [conference-city] Seminar 2011 website',
              'message' => 'We are happy to inform you that you are successfully registered for the HER [conference-city] Seminar 2011 website.

You may also log in and check your registration data by clicking on this link and providing your email and password:

http://[conference-url].bolognaexperts.net/user

If you are attending the seminar you will find a hotel registration form and relevant instructions on:

http://[conference-url].bolognaexperts.net/page/hotel-booking-and-visa

Please fill out this form and send it before the deadlines stated in the same page.

For further information, do not hesitate and contact us.

Best regards,

The UNICA/Brussels Education Services Consortium',
              '#argument map' => array(
                'user' => 'account',
              ),
            ),
            '#type' => 'action',
          ),
          '4' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to an arbitrary mail address',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
                '3' => 'to',
              ),
            ),
            '#name' => 'rules_action_mail',
            '#settings' => array(
              'to' => 'info@bolognaexperts.net',
              'from' => '',
              'subject' => '[HER3] New registration for [profile_node:title-raw]',
              'message' => 'New registration details:

Name: [profile_node:title-raw]
City: [profile_node:field_profile_city-raw]
Country: [profile_node:field_profile_country-raw]
Manage at: [profile_node:node-url]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'profile_node',
                  ),
                  'message' => array(
                    '0' => 'profile_node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '2' => array(
            '#weight' => 1,
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#name' => 'rules_action_drupal_message',
            '#settings' => array(
              'message' => 'Welcome [profile_node:title-raw], thank you for registering to the seminar! Please complete you registration by specifying the information requested. ',
              'error' => 0,
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'profile_node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '3' => array(
            '#weight' => 2,
            '#info' => array(
              'label' => 'Page redirect',
              'module' => 'System',
              'eval input' => array(
                '0' => 'path',
                '1' => 'query',
                '2' => 'fragment',
              ),
            ),
            '#name' => 'rules_action_drupal_goto',
            '#settings' => array(
              'path' => 'node/[profile_node:nid]/edit',
              'query' => '',
              'fragment' => '',
              'force' => 1,
              'immediate' => 0,
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'path' => array(
                    '0' => 'profile_node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'conference_profile_2' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'conference_profile_profile_update',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'conference_profile',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Updated content is Profile',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'profile' => 'profile',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'path' => '<front>',
              'query' => '',
              'fragment' => '',
              'force' => 1,
              'immediate' => 0,
            ),
            '#name' => 'rules_action_drupal_goto',
            '#info' => array(
              'label' => 'Page redirect',
              'module' => 'System',
              'eval input' => array(
                '0' => 'path',
                '1' => 'query',
                '2' => 'fragment',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function conference_profile_views_api() {
  return array(
    'api' => '2',
  );
}
