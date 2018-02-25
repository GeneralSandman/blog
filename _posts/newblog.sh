#!/bin/bash

date=`date +%Y-%m-%d-`
filename="$date$1.md"

ls -l "$filename" >> /dev/null
res=$?
if [ $res==0 ]
then
    echo "exists this file"    
else
    echo "touch file $filename"
fi

touch "$filename"
res=$?
if [ res==0 ]
then
    cat "__model.md" >> "$filename"
else
    echo "create file failed"
fi
