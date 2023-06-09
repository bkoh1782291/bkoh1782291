#!/bin/bash

g++ -o scheduler scheduler.cpp
g++ -o baseline baseline.cpp
g++ -o compute_stats compute_stats.cpp

echo
echo "baseline 1"
./baseline data_1111.txt output_1111.txt
./compute_stats data_1111.txt output_1111.txt

echo "scheduler 1"
./scheduler data_1111.txt output_1111.txt
./compute_stats data_1111.txt output_1111.txt

echo
echo "baseline 2"
./baseline data_2222.txt output_2222.txt
./compute_stats data_2222.txt output_2222.txt

echo "scheduler 2"
./scheduler data_2222.txt output_2222.txt
./compute_stats data_2222.txt output_2222.txt

echo
echo "baseline 3"
./baseline data_3333.txt output_3333.txt
./compute_stats data_3333.txt output_3333.txt

echo "scheduler 3"
./scheduler data_3333.txt output_3333.txt
./compute_stats data_3333.txt output_3333.txt