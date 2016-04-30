#!/bin/bash
#
# For all files in current folder, get their last modified date, create a new folder 
# named with that date, and move the file there, appending the date in front of the filename.

for f in *; do
    dir=$(stat -f%Sm -t%Y-%m-%d "$f")
    echo $f '->' $dir
    [ -d "$dir" ] || mkdir "$dir"
    mv "$f" "$dir"/"$dir"_"$f"
done
