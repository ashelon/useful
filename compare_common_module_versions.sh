#!/bin/bash

if [ $# -eq 0 ]
  then
    echo "This script can check for all the versions of common Drupal modules across several websites."
    echo "If you want to know which version the admanager has, try ./compare.sh /var/www admanager"
    echo "No arguments supplied. I need <path> <search_string>"
  exit 1
fi


FOLDERS="$(find $1 -name $2)"
for eachFolder in $FOLDERS
do
	echo "========== $eachFolder"
	cat $eachFolder/$2.info | grep version
done
