#!/bin/bash

echo converting $1

sed -i 's/a/4/' $1
sed -i 's/e/3/' $1
sed -i 's/i/1/' $1
sed -i 's/o/0/' $1
