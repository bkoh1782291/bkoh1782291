#!/bin/bash

echo "starting server....."
gnome-terminal --tab --title=Server -- bash -c 'java -classpath assignment1 SorterServer ;bash'
sleep 2

######################### ascending test ######################
echo "starting client....."
gnome-terminal --tab --title=Client -- bash -c 'sleep 2; java -classpath assignment1 SorterClient ascending.txt ;bash'
sleep 4
echo "output terminal opened...."
gnome-terminal --tab --title=Output -- bash -c 'sleep 5; diff -cs output.txt ascending_comp.txt ;bash'
sleep 4

######################## descending test ######################
echo "starting client....."
gnome-terminal --tab --title=Client -- bash -c 'sleep 2; java -classpath assignment1 SorterClient descending.txt ;bash'
sleep 2
echo "output terminal opened...."
gnome-terminal --tab --title=Output -- bash -c 'sleep 8; diff -sc output.txt descending_comp.txt ;bash'
sleep 6

# ######################## min value test ######################
echo "starting client....."
gnome-terminal --tab --title=Client -- bash -c 'sleep 2; java -classpath assignment1 SorterClient min.txt ;bash'
sleep 4
echo "output terminal opened...."
gnome-terminal --tab --title=Output -- bash -c 'sleep 5; diff -sc output.txt min_comp.txt ;bash'
sleep 4

######################## max value test ######################
echo "starting client....."
gnome-terminal --tab --title=Client -- bash -c 'sleep 2; java -classpath assignment1 SorterClient max.txt ;bash'
sleep 4
echo "output terminal opened...."
gnome-terminal --tab --title=Output -- bash -c 'sleep 5; diff -sc output.txt max_comp.txt ;bash'
sleep 4