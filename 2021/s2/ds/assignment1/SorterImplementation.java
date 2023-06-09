// Brian Koh Lit Yang
// a1782291
// class to implement the sorter object

import java.util.*; //importing the stack class

// Implementing the remote interface
public class SorterImplementation implements Sorter {

	// implementation and initialisation of stack
	Stack<String> curr_stack = new Stack<>();

	// sanity check for object creation
	public void printMsg() {
		System.out.println("Creating Object");
	}

	/*
		function for push value operation
		input : value to push into stack
		output : returns nothing

	*/
	public void pushValue(int val) {
		String s = String.valueOf(val);
		curr_stack.push(s);
	}

	/*
	 	function that pushes values onto the stack depending on the operators given
		input : operator string
		output : returns nothing
	*/
	public void pushOperator(String operator) {

		// push operator onto the stack
		curr_stack.push(operator);
		String operation = curr_stack.pop();
		int sizeofstack = curr_stack.size();

		// pop stack values into new array
		int[] arr = new int[sizeofstack];

		// System.out.println("current stack size :" + curr_stack.size());

		try {
			for (int i = 0; i < sizeofstack; i++) {
				arr[i] = Integer.parseInt(curr_stack.pop());
			}
		} catch (Exception e) {
			System.err.println("######### Stack Pop Error ########");
		}

		// perform operations on the new array based on the case
		switch (operator) {
			case "ascending":
				for (int i = arr.length - 1; i >= 0; i--) {
					curr_stack.push(String.valueOf(arr[i]));
				}
				break;
			case "descending":
				for (int i = 0; i < arr.length; i++) {
					curr_stack.push(String.valueOf(arr[i]));
				}
				break;
			case "max":
				int max = 0;
				for (int i = 0; i < arr.length; i++) {
					if (arr[i] > max) {
						max = arr[i];
					}
				}
				curr_stack.push(String.valueOf(max));
				break;
			case "min":
				int min = 99999;
				for (int i = 0; i < arr.length; i++) {
					if (arr[i] < min) {
						min = arr[i];
					}
				}
				curr_stack.push(String.valueOf(min));
				break;
		}

		// print new stack after operations
		try {
			System.out.println("new stack: " + curr_stack);
		} catch (Exception e) {
			System.err.println("########### Stack Error ##########");
		}
	}

	/*
		function for pop operation for the stack
		input : nothing
		output : returns value popped
	*/
	public int pop() {
		int stack_val = Integer.parseInt(curr_stack.pop());
		System.out.println("\npop operation: [ " + stack_val + " ]");

		return stack_val;
	}

	/*
		function that checks if the stack is empty
		input : nothing
		output : returns bool value
	*/
	public boolean isEmpty() {
		System.out.println("isEmpty? ");
		if (curr_stack.isEmpty() == true) {
			System.out.print("True ");
			return true;
		} else {
			System.out.print("False ");
			return false;
		}
	}

	/*
		function to implement delayed pop
		input : time for delay
		output : returns value popped
	*/
	public int delayPop(int time) {
		System.out.println("\nDelayPop called : ");
		try {
			Thread.sleep(time);
		} catch (InterruptedException ex) {
			Thread.currentThread().interrupt();
		}
		int result = Integer.parseInt(curr_stack.pop());
		System.out.print("Delay pop operation: [ " + result + " ]");
		return result;
	}

	/*
		function to return stack to the client
		input : nothing
		output : returns current stack
	*/
	public Stack<String> return_stack() {
		return curr_stack;
	}

}