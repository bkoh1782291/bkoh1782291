/*
	-------------------------------------------
	| Brian Koh Lit Yang					  |
	| a1782291								  |
	-------------------------------------------
	Class file for Socket implementation
*/

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Random;

public class Sockets
{
	public static Socket getSocket(int memberID, Object outOBJ) throws Exception
	{
		Proposal_Message pid = (Proposal_Message) outOBJ;
		Socket socket = null;

		// generate unique random port number
		int port = memberID * 1234;

		// create a new socket
		try {
			// System.out.println("========================= new socket opened ! =========================");
			socket = new Socket("127.0.0.1", port);
		}
		catch (Exception e) { //  if fail retry connection to Members
			for (int i =0 ; i < 3; i ++)
			{
				System.out.println("------------------> " + pid + " Connection to M" + memberID
									+ " failed. Attempting to reconnect " + i
									+ "times ............. ");
			Thread.sleep(1000);
			}
		}
		return socket;
	}

	// function to receive proposal message from incoming socket objects
	public static Proposal_Message receive_message(Socket socket)
	{
		ObjectInputStream ois;
		Proposal_Message inPID = null;

		if (socket.isConnected() == true)
		{
			try {
				ois = new ObjectInputStream(socket.getInputStream());
				inPID = (Proposal_Message) ois.readObject();
			} catch (Exception e) {
				System.out.println("Failed to receive in coming message");
			}
		}
		return inPID;
	}

	// function to write to member files to update the current accepted value to all members
	public static void update_members(int memberID, Object outOBJ)
	{
		Proposal_Message pid = (Proposal_Message) outOBJ;
		try {
			Socket socket = getSocket(memberID, outOBJ);
			if (socket.isConnected() == true)
			{
				ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
				oos.writeObject(outOBJ);
				oos.flush();
			}
		} catch (Exception e) {
			System.out.println("Failed to send " + pid.getProposalMSG());
		}
	}
}

/*
 * https://www.baeldung.com/java-write-to-file
 * https://www.programiz.com/java-programming/objectoutputstream
 */