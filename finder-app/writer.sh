#!/bin/bash

writefile=$1
writestr=$2


if [ -z $writefile ] || [ -z $writestr ]
then
	echo "please provide both a filename and an input string"
	exit 1
fi

mkdir -p $(dirname "$writefile") && touch $writefile

if [ -e $writefile ]
	then echo $writestr > $writefile
else
	echo "can't write file"
	exit 1
fi