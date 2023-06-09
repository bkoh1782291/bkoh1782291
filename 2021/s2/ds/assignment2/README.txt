README

To Run :

----------------------------------- Manual compilation ----------------------------------
compile files using javac AggregationServer.java PUTClient.java GETClient.java

Open terminal and run server first:
	$ java AggregationServer

Open another terminal and run content server :  (to test PUT request to send xml file to the ATOM server)
	$ java ContentServer example_feed.text

Open another terminal and run Client server :  (to test the retrival of xml file from GET request to the ATOM server)
	$ java GETClient


-----------------------------------------------------------------------------------------------
NOTE: Content Server and Clients require manual inputs to fire HTTP requests or exit requests.
-----------------------------------------------------------------------------------------------

Expected Behaviours:

-------------------------------------------------------------------------------------------------------------------
The ATOM server will start up and listen to socket connections on a specified port ( else default port 4567 )
	- if a specified port is needed, it must be entered into all 3 elements of the system.
	- ex. java AggregationServer 8080
		  java ContentServer example_feed.txt 8080
		  java GETClient 8080


-------------------------------------------------------------------------------------------------------------------
The content server will start up and reads in user input, PUT or exit
	- if a PUT request is entered:
									it will write convert the plaintext file into xml using the xmlparser
									then it will transfer it to the ATOM server through sockets
									and also export into a file called output.xml

	- if a exit request is entered:
									it will close the socket and end the connection to the ATOM server safely.

The xml content will also be written into a string and passed into the server through sockets.

the ATOM server should also display the xml content in the terminal, this shows that it recieves the xml content.


-------------------------------------------------------------------------------------------------------------------
The GETClient will server start up and read in user input, GET or exit
	- if a GET request is entered:
									the client will send a GET request to the ATOM server to retrive the xml
									after recieving it, it will parse the xml back into plain text,
									just like the example feed.

	- if a exit request is entered:
									it will close the socket and end the connection to the ATOM server safely.



________________________________________________________ TESTING ______________________________________________________

There are 5 test scripts that can be run on this system.
Please note that manual input is required.

# test1.sh
: a basic soundness test for the system
	- fires up one of each, one server, one content client and one get client
	- this test ensures that each of the elements of the system works in its most basic from
	- typing in "PUT" in the content server will send a PUT request to the ATOM server
		- transforms the example feed into xml
	- the server will send a hearbeat message every 12 seconds

	- typing in "GET" in the GETClient will recieve the xml
		- transforms the xml back into a feed and prints out in console
		- The transfered XML file is stored in the feed.xml file from ATOM server.

	STEPS:
		1. type PUT in the content server
		2. type GET in the GET client
		3. type exit in to check if content server exits properly
		4. Ctrl + C to kill GET client


# test2.sh
: Test for if multiple clients and multiple Content Servers can access an aggregation Server
	- this test will start up an ATOM server, two content clients and two GETclients.
	- the two content servers have two seperate example_feeds.
	- the user can add more as required.
	- if two PUT requests are made, there should be two seperate feeds stored in the queue.
	- the get request will retreive the feeds and print them in the terminal

	STEPS:
		1. type PUT in the content server
		2. type PUT in the content server
		3. type GET in the GET client
		4. type GET in the GET client
		5. check the output feeds


# test3.sh
: Test if a client can get aggregated feed in order of GET requests.
	- this test will start up an ATOM server, a set of content client and GETclient twice.
	- the two content clients will have two seperate feeds
	- this is to test that the aggregated feeds are correct and the queue implemented is working correctly

	STEPS:
		1. type PUT in the content server
		2. type GET in the GET client
		3. check the output feeds
		4. type PUT in the content server
		5. type GET in the GET client
		6. check the output feeds


# test4.sh
: Test if a client can get aggregated feed is correct after editing textfile
	- similar test to the previous test, but it is to check that the feed changes after editing the textfile.
	- the feed will change based on the example_feed edits

	STEPS:
		1. type PUT on ContentServer-1
		2. type GET on ClientServer-1
		3. edit example_feed.txt
		4. type PUT on ContentServer-2
		5. type GET on ClientServer-2


# test5.sh
: Test if a content server will try to reconnect ATOM server for 3 times.
	- this test will see if the ContentServer will attempt to reconnect to the ATOM server
	- the first content server will start before the ATOM server
	- it will try to reconnect every 6 seconds.
	- if successful, the content server will print out "connection successful!"

	STEPS:
		1. just run the script to see the effects

________________________________________________________ TESTING ______________________________________________________














