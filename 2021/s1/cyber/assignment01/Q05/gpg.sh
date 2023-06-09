#!/bin/bash

# try all word in words.txt
for word in $(cat words.txt); do 

  # try to decrypt with word
  echo "${word}" | gpg --passphrase-fd 0 -q --batch --allow-multiple-messages --no-tty  --output the_decrypted_file -d ~/a1782291/2021/s1/cyber/assignment01/Q05/secret.txt.gpg;

  # if decrypt is successfull; stop
  if [ $? -eq 0 ]; then

    echo "GPG passphrase is: ${word}";
    exit 0;

  fi

done;

exit 1;
