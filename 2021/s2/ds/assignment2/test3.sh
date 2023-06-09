#!/bin/bash
# TEST 3 ---Test if a client can get aggregated feed in order of GET requests.

# killing default port
kill -9 $(lsof -t -i:4567)

echo "compiling java files....."
javac *.java
echo "compilation done"

echo "starting ATOM server....."
gnome-terminal --tab --title=AggregationServer -- bash -c 'java AggregationServer ;bash'

echo "starting content server1........"
gnome-terminal --tab --title=ContentServer-1 -- bash -c 'echo test2; sleep 1; java ContentServer example_feed.txt ;bash'

echo "starting client server1........"
gnome-terminal --tab --title=ClientServer-1 -- bash -c 'echo test2; sleep 1; java GETClient ;bash'

echo "starting content server2........"
gnome-terminal --tab --title=ContentServer-2 -- bash -c 'echo test2; sleep 1; java ContentServer example_feed2.txt ;bash'

echo "starting client server2........"
gnome-terminal --tab --title=ClientServer-2 -- bash -c 'echo test2; sleep 1; java GETClient ;bash'
