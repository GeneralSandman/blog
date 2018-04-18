#!/bin/sh

source="$1.cc"
filename="$1.html"

touch $filename
echo "<xmp>" >> $filename

cat $source >> $filename

echo "</xmp>" >> $filename

