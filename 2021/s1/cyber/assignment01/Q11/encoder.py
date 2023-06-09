#!/usr/bin/python3

import argparse
import os
import sys
import random

def mycrypto (filename):
    with open(filename, 'r') as f, open(filename + '.enc', 'w') as o:
        blob = f.read()
        for b in blob:
            key = random.randrange(255)
            # ord() function returns an integer representing the Unicode character
            # ^ operator is XOR operator
            # XOR, also known as "exclusive or", compares two binary numbers bitwise. If both bits are the same, XOR outputs 0.
            #If the bits are different, XOR outputs 1.
            #For instance, performing XOR on 6 and 3 (binary 110 and 011, respectively) results in 5 (binary 101).
            x = ord(b) ^ key
            o.write(chr(x))

def main():
    parser = argparse.ArgumentParser(description='Encrypt (?) a file')
    parser.add_argument('filename', metavar='filename', type=str, help='file to encrypt')
    parser.add_argument('--seed', metavar='seed',type=int,default=2021,help='seed')
    args = parser.parse_args()

    if not os.path.isfile(args.filename):
        print('The file  does not exist')
        sys.exit()

    random.seed(args.seed)
    mycrypto(args.filename)

if __name__== "__main__":
    main()
