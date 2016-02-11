Useful Drupal development tools
---------------------------------

*MODULE* contains a Drupal 7 module with frequently used functions such as 
* create a block
* create an admin form
* define a cron job
* execute remote API call
 
*base* contains a basic installation profile.
 
*quick-d7-install-script* contains a quick and dirty shell script that downloads and installs Drupal 7 with standard contrib modules.
 
*drush-make* does the same, but more elegantly with drush.

How do I get PHP Errors to display?
---------------------------------

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);
