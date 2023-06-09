#!/bin/bash
i=1
x=0

while IFS= read -r line;
do
    ((x=x+1))
    cat test.txt | sed -n $i'p' test.txt | head -c $line
    echo 
    ((i=i+1))
done < "$1"
