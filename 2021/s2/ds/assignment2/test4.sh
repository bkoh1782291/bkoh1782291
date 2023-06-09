#!/bin/bash
# TEST 4 ---Test if a client can get aggregated feed is correct after editing textfile

# killing default port
kill -9 $(lsof -t -i:4567)

echo "compiling java files....."
javac *.java
echo "compilation done"

echo "running test4 - feed aggregation after edits"
echo "starting ATOM server....."
gnome-terminal --tab --title=AggregationServer -- bash -c 'java AggregationServer ;bash'

echo "starting content server1........"
gnome-terminal --tab --title=ContentServer-1 -- bash -c 'java ContentServer example_feed.txt ;bash'

echo "starting client server1........"
gnome-terminal --tab --title=ClientServer-1 -- bash -c 'java GETClient ;bash'

echo "starting content server2........"
gnome-terminal --tab --title=ContentServer-2 -- bash -c 'java ContentServer example_feed.txt ;bash'

echo "starting client server2........"
gnome-terminal --tab --title=ClientServer-2 -- bash -c 'java GETClient ;bash'
