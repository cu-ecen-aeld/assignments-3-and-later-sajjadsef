#!/bin/sh

filesdir=$1
searchstr=$2

if [ -z "$filesdir" ] || [ -z "$searchstr" ]; then
    echo "Error, not all arguments are given"
    exit 1
fi

if [ -d "$filesdir" ]; then
    X=$(find $filesdir -type f | wc -l)
    Y=$(grep -rw $filesdir -e $searchstr | wc -l)
    echo "The number of files are $X and the number of matching lines are $Y"
else
    echo "Error, given directory does not exist"
    exit 1
fi

