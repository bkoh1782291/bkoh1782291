/*
	-------------------------------------------
	| Brian Koh Lit Yang					  |
	| a1782291								  |
	-------------------------------------------
*/

import java.io.*;
import java.util.*;

public class PrintResults extends Council_Members{

	PrintResults(int MID, int port) {
        super(MID, port);
    }

	/*
		function for declaring final proposed member as president
		checks and declares if the paxos algorithm is valid or not
		write to member text files for consistent storage
	*/
	public static void print_result(int nodes) throws IOException {
		String output = "";
		LinkedList<String> check = new LinkedList<>();
		for (int i = 1; i <= nodes; i++)
		{
			String content = FileReading.readLocalData("M" + i + ".txt");
			if (!content.isEmpty())
			{
				check.add(content);
				output += "M" + i + ": Agreed President is Member" + ": " + content;
			} else
			{
				output += "M" + i + ": N/A ( Is possibly offline. Please check"
						+ "  response status at the beginning )\n";
			}
		}

		// check if paxos algorithm is successful
		boolean res = false;
		for (int i = 0; i < check.size() - 1; i++)
		{
			if (!check.get(i).equals(check.get(i + 1)))
			{
				res = false;
			}
			if (check.get(i).equals(check.get(i + 1)))
			{
				res = true;
			}
		}
		// declaring that the Paxos algorithm is finished
		if (res == true)
		{
			System.out.println("\n\n=============================== " + "Output: " + "Test Result : << PAXOS PASS >> " + "=================================\n" + output);
		} else if (res == false){
			System.out.println("\n\n=============================== " + "Output: " + "Test Result : << PAXOS FAIL >> " + "==================================\n" + output);
		}

		// exit program
		System.exit(1);
	}
}
