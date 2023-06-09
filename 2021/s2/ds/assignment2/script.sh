#!/bin/bash

kill -9 $(lsof -t -i:4567)

echo "compiling java files....."
javac *.java
echo "compilation done"

echo "starting server....."
gnome-terminal --tab --title=AggregationServer -- bash -c 'java AggregationServer 1234 ;bash'

echo "starting content server........"
gnome-terminal --tab --title=ContentServer1 -- bash -c 'java ContentServer example_feed.txt ;bash'

echo "starting client server........"
gnome-terminal --tab --title=ClientServer -- bash -c 'java GETClient ;bash'
