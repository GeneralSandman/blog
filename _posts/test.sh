#!/bin/bash

i=1
index=1

for month in 01 02 03 04 05 06
do
    for day in 01 02 03 04 05 06 07 08 09 10
    do
        filename="2017-$month-$day-Gain-Offers-$i.md"
        touch "$filename"
        cat "__model.md" >> "$filename" 
        i=`expr $i + $index`
    done
done