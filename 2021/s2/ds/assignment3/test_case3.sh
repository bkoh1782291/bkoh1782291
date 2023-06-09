#!/bin/bash

kill -9 $(lsof -t -i:4567)

echo "compiling java files....."
javac *.java
echo "compilation done"

echo "starting PAXOS....."
gnome-terminal --tab --title=Paxos_Server -- bash -c 'java Council_Election 3 9 ;bash'