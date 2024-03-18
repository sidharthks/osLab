#!/bin/bash
if [ $# -ne 1 ]; then
        echo "Usage: $0 <number>"
        exit 1
fi

factorial(){
        if [ $1 -eq 0 ]; then
                echo 1
        else
                echo $(( $1 * $(factorial $(( $1 - 1 ))) ))
        fi
}
result=$(factorial $1)
echo "Factorial of $1 is $result"