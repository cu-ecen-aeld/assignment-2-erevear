#!/bin/bash

filesdir=$1
searchstr=$2

if [ -z $filesdir ] || [ -z $searchstr ]
then
	echo "please provide both a directory and search string"
	exit 1
fi

if ! [ -d $filesdir ]
then
	echo "first argument should be a directory"
	exit 1
fi

filecount=$(find $filesdir -type f | wc -l)

linecount=$(grep -r $searchstr $filesdir | wc -l)

echo "The number of files are $filecount and the number of matching lines are $linecount"
