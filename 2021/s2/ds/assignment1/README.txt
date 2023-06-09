Brian Koh Lit Yang
a1782291
Distributed Systems Assignment 1


------- script compilation/execution: --------

Terminal 1:
$ ./rmi_script.sh

Terminal 2:
$ ./test_script.sh
or
$ ./multi_test.sh


------- manual compilation/execution: --------

$ javac -d assignment1 *.java
$ rmiregistry -J-Djava.class.path=assignment1
$ java -classpath assignment1 SorterServer
$ java -classpath assignment1 SorterClient <input>.txt
$ diff -cs output.txt <input_comp>.txt


----------------- NOTE ------------------
NOTE: to test different parts, comment off/on sections of script.
NOTE: Delay pop function call is commented out, to test it, just un-comment it.
NOTE: multi_test.sh is used to simulate multiple clients in the system.



