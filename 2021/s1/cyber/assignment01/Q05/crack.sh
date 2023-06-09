#!/bin/bash

if [ "$#" != 2 ]; then
        echo "enter file and wordlist"
else

while IFS= read -r line; 
do
        gpg --batch --passphrase "$line" "$1" &> /dev/null
        if [ $? -eq 0 ]
       	then
               echo "SUCESS - $line"
               exit 0
        else
               echo "FAILED - $line"
	fi
done < "$2"
fi
