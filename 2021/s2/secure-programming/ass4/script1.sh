#!/bin/bash
clang -g -fsanitize=address driver.c spalloc.c

cp a.out fuzzed_dir/default/crashes
cd fuzzed_dir/default/crashes
for file in *
do
	./a.out $file
done
rm a.out