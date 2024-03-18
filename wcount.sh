#!/bin/bash

if [ $# -ne 2 ]; then
        echo "Usage: $0 <filename> <word> "
        exit 1
fi

if [ ! -f "$1" ]; then
        echo "Error: File $1 not found! "
        exit 1
fi

count=$(grep -o -w "$2" "$1" | wc -l)

echo "The word '$2' occurs $count times in the file '$1'"