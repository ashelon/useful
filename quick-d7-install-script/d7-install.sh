#!/bin/bash

# Parameters 
##########################################################

dbHost="localhost"
dbName="natuur"
dbUser="natuur"
dbPassword="natuur"

siteName="Name of your website"
siteSlogan=""
siteLocale="be"

AdminUsername="admin"
AdminPassword="admin"
adminEmail="admin@example.com"

tempdir=`mktemp -d -t drupal-new`

##########################################################

clear
echo -e "////////////////////////////////////////////////////////////////////////////////////////////////////////"
echo -e "// This script will install Drupal 7 with useful standard modules and Zen to the current directory."
echo -e "// "
echo -e "// Make sure you have edited this script with the right parameters and downloaded Drupal 7."
echo -e "// "
echo -e "// Press enter to start. You might get some rsync errors, just ignore those."
read -p "////////////////////////////////////////////////////////////////////////////////////////////////////////"

# install core
sudo drush dl drupal --destination=$tempdir

# get drupal version dir name
tempdir_contents=`ls $tempdir`
drupal_dir=${tempdir_contents##*/}

# move drupal core files to current directory and delete tempdir.
sudo rsync -r $tempdir/$drupal_dir/ ./
sudo rm -rf $tempdir

#create directories
sudo mkdir sites/all/libraries sites/all/modules/contrib sites/all/modules/custom sites/all/modules/features

# download modules

sudo drush dl --destination=sites/all/modules/contrib \
ctools \
views \
libraries \
pathauto \
globalredirect \
date \
module_filter \
token \
less \
backup_migrate \
transliteration \
admin_menu \
features \
ckeditor \
options_element \
title \
link \
imce \
google_analytics \
file_entity \
entity \
entityreference

sudo drush dl --destination=sites/all/themes zen

sudo mkdir -p sites/default/files
sudo chmod 777 -R sites/default/files
sudo chmod 777 sites/default/files/settings.php

sudo chown -R www-data:www-data *
sudo chown -R www-data:www-data .*

# add Fancy install profile

echo -e "////////////////////////////////////////////////////"
echo -e "// Add the Base installation profile to /profiles now and strike any user to continue."
read -p "////////////////////////////////////////////////////"

# Download Drupal and install 
##########################################################
sudo drush site-install -y base --account-mail=$adminEmail --account-name=$AdminUsername --account-pass=$AdminPassword --site-name=$siteName --site-mail=$adminEmail --locale=$siteLocale --db-url=mysql://$dbUser:$dbPassword@$dbHost/$dbName;

echo -e "////////////////////////////////////////////////////"
echo -e "All done."
