#!/bin/bash
echo "To use the local Drush, run the following command in the active shell:"
echo "alias drush='php `pwd`/`dirname $0`/profiles/conference/libraries/drush/drush.php'"
echo "A local alias for Drush will be set. Then run 'drush status' within the Drupal tree to test."
