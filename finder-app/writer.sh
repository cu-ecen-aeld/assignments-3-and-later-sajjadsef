#!/bin/bash

writefile=$1
writestr=$2

if [ -z "$writefile" ] || [ -z "$writestr" ]; then
    echo "Error, not all arguments are given"
    exit 1
fi

DIR=$(dirname $writefile)
mkdir -p $DIR
error=$(touch $writefile)


if [ "$error" > 0 ]; then
    echo "failed to create the file"
    exit 1
fi

echo $writestr > $writefile