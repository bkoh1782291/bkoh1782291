README

--------------------------------------------- HOW TO RUN ---------------------------------------------------------

chmod +x test cases to be able to run scripts !

Manual compilation
	$ javac *.java
	$ java Council_Election <test_case> <number_of_members>

OR

Run script test_case
	$ ./test_case1.sh



Expected Behaviours:


-------------------------------------------------------------------------------------------------------------------
TEST CASE 1

all proposers send message at the same time with 9 members in a council
members 1,2,3 are proposers to be president

Expected output :
paxos algorithm will acheive consensus and will choose one of the three proposers to be president


-------------------------------------------------------------------------------------------------------------------
TEST CASE 2

all proposers send message sequentially with 9 members in a council
members 1,2,3 are proposers to be president

controlled with Thread.sleep();

Expected output :
paxos algorithm will acheive consensus and will choose M3 to be president, because he is the last
member to arrive


-------------------------------------------------------------------------------------------------------------------
TEST CASE 3

all proposers send message at the same time with 9 members in a council
members 1,2,3 are proposers to be president

Added simulation of either members 2 or/and 3 will go offline after proposing.

Expected output :
paxos algorithm will acheive consensus and will choose M3 to be president, because he is the last
member to arrive


-------------------------------------------------------------------------------------------------------------------
TEST CASE 4

all proposers send message at the same time with 9 members in a council
members 1,2,3 are proposers to be president

Added simulation of varied responding times from all council members

Expected output :
paxos algorithm will acheive consensus and will choose one of the three proposers to be president, but some members
will respond late, or never respond at all


-------------------------------------------------------------------------------------------------------------------
TEST CASE 5

all proposers send message at the same time with 9 members in a council
members 1,2,3 are proposers to be president

Expected output :
paxos algorithm will acheive consensus and will choose one of the three proposers to be president but m2 or m3 or both
m2 and m3 will go offline, and some members will respond late, or never respond at all.


-------------------------------------------------------------------------------------------------------------------
TEST CASE 6

all proposers send message at the same time with 20 members in a council
members 1,2,3 are proposers to be president

Expected output :
paxos algorithm will acheive consensus and will choose one of the three proposers to be president
