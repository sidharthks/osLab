#!/bin/bash

read -p "Enter the numbers separated by spaces: " numbers
read -p "Enter A to sort in ascending or D to sort in desceding " order

if [ "$order" = "A" ] || [ "$order" = "a" ]; then
        sorted=$(echo "$numbers" | tr ' ' '\n' | sort -n | tr '\n' ' ')
elif [ "$order" = "D" ] || [ "$order" = "d" ]; then
        sorted=$(echo "$numbers" | tr ' ' '\n' | sort -r | tr '\n' ' ')
else
        echo "invalid input"
        exit 1
fi

echo "Sorted numbers: "
echo "$sorted"