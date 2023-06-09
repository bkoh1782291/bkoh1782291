#!/bin/bash
afl-gcc driver.c spalloc.c -o testbinary
afl-fuzz -i input -o fuzzed_dir ./testbinary @@

# afl-fuzz -i input -o fuzzed_dir -S fuzzer02 ./testbinary @@
# afl-fuzz -i input -o fuzzed_dir -S fuzzer03 ./testbinary @@
# afl-fuzz -i input -o fuzzed_dir -S fuzzer04 ./testbinary @@
