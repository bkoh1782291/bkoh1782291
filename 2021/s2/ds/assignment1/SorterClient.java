// Brian Koh Lit Yang
// a1782291

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.io.*;
import java.util.*; //importing the stack class
import java.util.ArrayList;

public class SorterClient {
	private SorterClient() {
	}

	public static void main(String[] args) {
		try {
			// Getting the registry
			Registry registry = LocateRegistry.getRegistry(1234);

			// Looking up the registry for the remote object
			Sorter stub = (Sorter) registry.lookup("Sorter");

			/* -------------------------------- reading input ------------------------------------- */
			// reading input from text file using buffer
			File file = new File(args[0]);

			BufferedReader br = new BufferedReader(new FileReader(file));

			String st;
			ArrayList<String> input_array = new ArrayList<String>();
			ArrayList<String> output_array = new ArrayList<String>();

			while ((st = br.readLine()) != null) {
				System.out.println(st);
				input_array.add(st);
			}

			br.close(); // close the buffer

			// collecting operator from input
			String operator = input_array.get(0);
			input_array.remove(0);

			/* ------------------------------ calling methods ------------------------------------*/

			// Calling the remote methods using the obtained object
			// pushing values into stack
			for (int i = 0; i < input_array.size(); i++) {
				stub.pushValue(Integer.parseInt(input_array.get(i)));
			}

			// stub out a specific push Operation
			// and pop out value
			try {
				stub.pushOperator(operator);
			} catch (Exception e) {
				System.err.println("####### ERROR: invalid push operation ########");
			}

			/* ---------------------------------- writing to output ------------------------------- */
			// write output to output file
			try {

				// capturing returned stack and
				// converting it to string for output
				Stack<String> returned_stack = stub.return_stack();

				if (returned_stack.size() > 1) {
					for (int i = returned_stack.size() - 1; i >= 0; i--) {
						output_array.add(returned_stack.get(i));
					}
				} else if (returned_stack.size() == 1) {
					output_array.add(returned_stack.get(0));
				}

				String St = "returned stack: " + output_array;

				BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));

				output.write(St);

				// stubbing out pop function
				int pop_res = stub.pop();
				System.out.println("\npop operation: [ " + pop_res + " ]");

				// stubbing out isEmpty function
				boolean empty = stub.isEmpty();
				System.out.println("isEmpty check? : [ " + empty + " ]");

				// // stubbing out delayPop
				// int delay_pop_res = stub.delayPop(2000);
				// System.out.println("Delay pop operation: [ " + delay_pop_res + " ]\n");

				System.out.print("output written to output.txt. \n");

				output.close(); // close buffer

			} catch (IOException e) {
				System.out.print(e.getMessage());
			}

			System.out.println("Remote method invoked\n");
		} catch (Exception e) {
			System.err.println("Client exception: " + e.toString());
			e.printStackTrace();
		}
	}
}