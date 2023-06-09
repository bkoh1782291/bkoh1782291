#!/bin/bash
# TEST 1 ------------- test for single client and single content server


# killing default port
kill -9 $(lsof -t -i:4567)

echo "compiling java files....."
javac *.java
echo "compilation done"

echo "starting ATOM server....."
gnome-terminal --tab --title=AggregationServer -- bash -c 'java AggregationServer ;bash'

echo "starting content server........"
gnome-terminal --tab --title=ContentServer1 -- bash -c 'echo test1; sleep 1; java ContentServer example_feed.txt; exec bash'

echo "starting client server........"
gnome-terminal --tab --title=ClientServer -- bash -c 'echo test1; sleep 1; java GETClient ;bash'
