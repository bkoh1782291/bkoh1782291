#!/bin/bash
# TEST 5 ---Test if a content server will try to reconnect ATOM server for 3 times.

# killing default port
kill -9 $(lsof -t -i:4567)

echo "running test 5 - reconnection test"
echo "compiling java files....."
javac *.java
echo "compilation done"

echo "starting content server1........"
gnome-terminal --tab --title=ContentServer-1 -- bash -c 'java ContentServer example_feed.txt ;bash'

sleep 9;
echo "starting content server2........"
gnome-terminal --tab --title=ContentServer-2 -- bash -c 'java ContentServer example_feed2.txt ;bash'

echo "starting ATOM server....."
gnome-terminal --tab --title=AggregationServer -- bash -c 'java AggregationServer ;bash'
