// Brian Koh Lit Yang
// a1782291
// Sorter Remote interface that calls the Sorter Object class

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.*; //importing the stack class

// Creating Remote interface for our application
public interface Sorter extends Remote {

	// takes value as input and pushes it onto the stack.
	public void pushValue(int val) throws RemoteException;

	// push function that contains one of the four operators as input
	// ("ascending", "descending", "max", "min")
	// 1. for ascending operation - push all the popped values in the descending order;
	// 2. for descending - push all the popped values in ascending order;
	// 3. for max - push the max value;
	// 4. for min - push the min value of all the popped values.
	public void pushOperator(String operator) throws RemoteException;

	// removes an operator on the stack
	public int pop() throws RemoteException;

	// checks if the stack is empty
	public boolean isEmpty() throws RemoteException;

	// // delays a pop operation on the stack with miliseconds as input
	public int delayPop(int milis) throws RemoteException;

	// function to return print stack
	public Stack<String> return_stack() throws RemoteException;
}