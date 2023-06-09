#!/bin/bash

echo "starting server....."
gnome-terminal --tab --title=Server -- bash -c 'java -classpath assignment1 SorterServer ;bash'


# ######################### ascending test ######################
# echo "starting client....."
# gnome-terminal --tab --title=Client -- bash -c 'sleep 2; java -classpath assignment1 SorterClient ascending.txt ;bash'

# echo "output terminal opened...."
# gnome-terminal --tab --title=Output -- bash -c 'sleep 5; diff -cs output.txt ascending_comp.txt ;bash'


# ######################## descending test ######################
# echo "starting client....."
# gnome-terminal --tab --title=Client -- bash -c 'sleep 2; java -classpath assignment1 SorterClient descending.txt ;bash'

# echo "output terminal opened...."
# gnome-terminal --tab --title=Output -- bash -c 'sleep 5; diff -sc output.txt descending_comp.txt ;bash'


# ######################## min value test ######################
# echo "starting client....."
# gnome-terminal --tab --title=Client -- bash -c 'sleep 2; java -classpath assignment1 SorterClient min.txt ;bash'

# echo "output terminal opened...."
# gnome-terminal --tab --title=Output -- bash -c 'sleep 5; diff -sc output.txt min_comp.txt ;bash'


######################## max value test ######################
echo "starting client....."
gnome-terminal --tab --title=Client -- bash -c 'sleep 2; java -classpath assignment1 SorterClient max.txt ;bash'

echo "output terminal opened...."
gnome-terminal --tab --title=Output -- bash -c 'sleep 5; diff -sc output.txt max_comp.txt ;bash'