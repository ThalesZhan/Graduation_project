#!/bin/bash
# get all filename in specified path
# first parameter should be the path of files, and second is the txt's name 


files=$(ls $1)
for filename in $files
do
   echo $filename >> $2.txt
done