/*
	-------------------------------------------
	| Brian Koh Lit Yang					  |
	| a1782291								  |
	-------------------------------------------
	Member class, connects all of the members to each other, in a P2P fashion
	This file holds all of the stages of the Paxos algorithm
	Phase 1 - Prepare & Promise
	Phase 2 - Accept & Accepted
	Phase 3 - Final & print output
*/

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

public class Council_Members extends Sockets {

	public Socket socket;
	public ServerSocket server;

	public int MemberID;
	public int nodes;
	public int majority_votes;
	public int port;
	public int promised_proposer_id = -1;
	public int max_proposer_id = -1;
	public boolean paxos_complete = false;

	public Proposal_Message proposal_message;
	public Proposal_Message promised_msg = null;
	public Proposal_Message accepted_msg = null;
	public Proposal_Message final_proposal_message = null;
	public ArrayList<Proposal_Message> acceptors;

	public Object acceptedValue = null;
	public Object finalValue = null;

	public List<Integer> promisesReceived;
	public String path_to_file;

	public boolean if_member_offline = false;
	public String response_profile = "";


	/*
	 * default constructor for nodes M1 to M3 M1, M2, M3 will proposal for
	 * themselves, M4-M9 will randomly choose one from M1-M3 as proposal value
	 */
	Council_Members(int MemberID, int port) {
		this.MemberID = MemberID;
		this.proposal_message = new Proposal_Message(MemberID);
		this.path_to_file = "M" + MemberID + ".txt";
		this.port = MemberID * 1234;
	}

	/*
	 * Start of Member function, connects to all the other sockets and starts the
	 * paxos algorithm
	 */
	void connecting() {
		// create a new backup file at first connection and delete old backup
		File backup = new File(path_to_file);
		if (backup.exists()) backup.delete();

		// close previous connection if there is any
		try {
			if (socket != null) {
				socket.close();
				socket = null;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			FileReading.readLocalData(path_to_file);
			server = new ServerSocket(this.port);

			while (paxos_complete == false)
			{
				socket = server.accept();

				if (if_member_offline) {
					socket.close();
                    System.out.println("{ Error! } Member " + this.MemberID + " Is Offline !");
                    break;
                }

				// check if incoming response profiles are valid
				try {
					if (this.response_profile.equals("medium"))
					{
						Thread.sleep(100);
					}
					else if (this.response_profile.equals("late"))
					{
						Thread.sleep(500);
					}
					else if (this.response_profile.equals("never"))
					{
						socket.close();
						System.out.println(" -> M" + this.MemberID + "will go offline and never respond !");
						break;
					}
				}
				catch (Exception e) {
					System.out.println("106:Council_Members.java | Error in Server Socket Connection for M" + this.MemberID);
				}

				start_paxos(socket);
				if (paxos_complete == true) break;
			}
			if (this.MemberID == 1) { PrintResults.print_result(nodes); }
		} catch (Exception e) {
			System.out.println("Error in Server Socket Connection for M" + this.MemberID);
		}
	}

	/*
	 *	broadcasting function to broadcast messages to other nodes
	 */
	public void broadcast_message(Proposal_Message proposal_message, String message_type)
	{
		Proposal_Message toSendMSG = new Proposal_Message(this.MemberID, proposal_message.getProposerID(), proposal_message.getValue(), message_type);

		if (message_type.equals("Prepare"))
		{
			System.out.println("{ Phase 1a } for Member M" + this.MemberID + " Start Phase 1, " + "Broadcast"
					+ this.proposal_message.getProposalMSG() + " to all members ! \n");
		}
		else if (message_type.equals("Accept"))
		{
			System.out.println("{ Phase 2a } for Member M" + this.MemberID + " Start Phase 2 - Accept() " + " M" + this.MemberID
					+ " has Received Majority Promises ( " + promisesReceived.size() + " ) \n\n Send Accept Request "
					+ this.proposal_message.getProposalMSG() + " to all members ! \n");
		}
		for (int i = 1; i <= nodes; i++)
		{
			Sockets.update_members(i, toSendMSG);
		}
	}

	/*
	 * Phase 1a of paxos, send a prepare message
	 * Member to generate a proposal ID and send to acceptors (used in Election stage)
	 */
	public void prepare() {
		// clear all data that has received with earlier proposal(s) to restart a proposal
		this.promisesReceived = new ArrayList<>();
		this.acceptors = new ArrayList<>();
		this.proposal_message.unique_proposal_id(); // create unique PID = last digits time stamp + ID
		Proposal_Message toSendMSG = new Proposal_Message(this.MemberID, this.proposal_message.getProposerID(), null, "Prepare");
		broadcast_message(toSendMSG, "Prepare"); // send prepare(n) to all s include itself
	}

	public synchronized void start_paxos(Socket s) {
		try {
			Proposal_Message obj = receive_message(s);
			String returned = obj.getType();

			if (returned.equals("Prepare"))
			{
				// System.out.println("{Prepare} Message Received from M" + obj.getMemberID() + "!");
				Prepare_Message(obj);
			}
			else if (returned.equals("Promise"))
			{
				// System.out.println("{Promise} Message Received from M" + obj.getMemberID() + "!");
				Promise_Message(obj);
			}
			else if (returned.equals("Accept"))
			{
				// System.out.println("{Accept} Message Received from M" + obj.getMemberID() + "!");
				Accept_Message(obj);
			}
			else if (returned.equals("Accepted"))
			{
				// System.out.println("{Accepted} Message Received from M" + obj.getMemberID() + "!");
				Accepted_Message(obj);
			}
			else if (returned.equals("Final"))
			{
				// System.out.println("{Final} Message Received from M" + obj.getMemberID() + "!");
				try{
					if (paxos_complete) return;
					FileReading.write_toFile(obj.getValue(), this.path_to_file, this.MemberID);
					paxos_complete = true;
					// server.close();
				}
				catch (Exception e) {
					System.out.println(">> M" + this.MemberID + "Error in sending FINAL message !");
					e.printStackTrace();
				}
			}
			else {
				System.out.println(">> M" + this.MemberID + "Error:: Unknown MSG type!");
			}
		} catch (Exception e) {
			System.out.println(">> M" + this.MemberID + "Error:: in run accept");
			e.printStackTrace();
		}
	}

	/*
	 * phase 1b : acceptor compares received proposalID and max_proposer_id, if no
	 * maxPID exist, accept this proposalID as maxPID and accept value if proposalID > max,
	 * reply accepted ID and accepted value otherwise ignore this prepare message
	 */
	public void Prepare_Message(Proposal_Message prepareMSG) {
		int propose_to_member = prepareMSG.getMemberID();
		int proposerID = prepareMSG.getProposerID();

		try{
			// if next proposer ID is bigger than the current max
			if (proposerID > max_proposer_id)
			{
				// update maxPID
				max_proposer_id = proposerID;
				// create new promise message
				promised_msg = new Proposal_Message(MemberID, max_proposer_id, acceptedValue, "Promise");
				System.out.println("{ Phase 1b } Sending Promise Message M" +
									this.MemberID + " to -> M" + propose_to_member + '\n');
				Sockets.update_members(propose_to_member, promised_msg);
			}
			else if (proposerID == max_proposer_id)
			{
				System.out.println("Duplicate prepare message Found !");
				Sockets.update_members(propose_to_member, promised_msg);
			}
		}
		catch (Exception e) {
			System.out.println(">> M" + this.MemberID + "Error in receiving preparing message");
			e.printStackTrace();
		}
	}

	/*
	 * phase 2a : If a Proposer receives a majority_votes of Promises from Acceptors, it
	 * will set value to its proposal and send an Accept message (pid, V).
	 */
	public void Promise_Message(Proposal_Message received_message) {

		int acceptor_id = received_message.getMemberID();
		int received_proposer_id = received_message.getProposerID();
		Object receivedValue = received_message.getValue();

		try {
			// return if already received
			if (promisesReceived.contains(acceptor_id)) {
				System.out.println(" ------------------------- Duplicate promise found ! ------------------------- \n");
				return;
			}
			// add ID to promises received collection
			promisesReceived.add(acceptor_id);

			if (received_proposer_id > promised_proposer_id) {
				// update PID and accepted value
				promised_proposer_id = received_proposer_id;
				if (receivedValue != null) {
					this.proposal_message.setValue(receivedValue);
					System.out.println("{ Phase 1b } -> New MaxID ! Update Value on Proposer M" + this.MemberID + ", Set value to -> "
							+ this.proposal_message.getValue());
				} else {
					System.out.println("{ Phase 1b } -> New MaxID ! Update Value on Proposer M" + this.MemberID + " Set value to -> ("
							+ Integer.toString(promised_proposer_id) + ") from M" + acceptor_id + "\n");
				}
			}

			// if majority_votes n/2 + 1 reached, accept proposal
			if (promisesReceived.size() == majority_votes)
			{
				if (this.proposal_message.getValue() != null) {
					try {
						broadcast_message(this.proposal_message, "Accept");
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}
		}
		catch (Exception e) {
			System.out.println(">> M" + this.MemberID + "Error in receiving promise message");
			e.printStackTrace();
		}
	}

	/*
	 * Phase 2b : acceptor compare received pID and maxPID,
	 * if acceptPID = maxPID save to local backup
	 * otherwise return maxPID
	 */
	public void Accept_Message(Proposal_Message acceptRequestMSG) {

		if (acceptRequestMSG.getValue() == null) {
			System.out.println("Error ! No accept message found !" + acceptRequestMSG.getProposalMSG());
			return;
		}

		try{
			int propose_to_member = acceptRequestMSG.getMemberID();
			int proposerID = acceptRequestMSG.getProposerID();
			Object proposerValue = acceptRequestMSG.getValue();

			// if proposer id is gt current max id
			if (proposerID >= max_proposer_id)
			{
				// update current max id
				max_proposer_id = proposerID;
				System.out.println("{ Phase 2a } -> New Max ID ! Update Value on Proposer M"
									+ this.MemberID + " in accept stage with(PID: " + max_proposer_id + ")\n");
				acceptedValue = proposerValue;
				promised_msg = new Proposal_Message(MemberID, max_proposer_id, acceptedValue, "Promise"); // update promised_msg
				accepted_msg = new Proposal_Message(MemberID, max_proposer_id, acceptedValue, "Accepted"); // create accepted_msg
			}
			// return max_proposerID only to proposer because proposerID is smaller than maxPID
			else {
				accepted_msg = new Proposal_Message(MemberID, max_proposer_id, null, "Accepted");
			}
			System.out.println("{ Phase 2a } Accept Stage M" + MemberID
								+ " send message " + accepted_msg.getProposalMSG()
								+ " to M" + propose_to_member + "\n");
			Sockets.update_members(propose_to_member, accepted_msg); // send accepted MSG to proposer

		}
		catch (Exception e) {
			System.out.println(">> M" + this.MemberID + "Error in receiving Accept Message");
			e.printStackTrace();
		}
	}

	/*
	 * phase 3:
	 * must Accept (n, v) if not promised in Phase 1b || > maxPID register
	 * AcceptMSG.V -> acceptedValue & send AcceptedMSG to the Proposer (Learner)
	 * Else ignore message
	 */
	public void Accepted_Message(Proposal_Message accepted_msg) throws Exception {

		// if there is a proposal message
		if (final_proposal_message != null) return;

		int acceptor_id = accepted_msg.getMemberID();
		int acceptorPID = accepted_msg.getProposerID();

		try {
			// reset previous member id
			Proposal_Message previous_member_id = null;

			for (int i = 0; i < acceptors.size(); i++)
			{
				if (acceptor_id == acceptors.get(i).getMemberID())
				{
					previous_member_id = acceptors.get(i);
					break;
				}
			}

			// if duplicate msg or smaller PID means outdated MSG -> ignore
			if (previous_member_id != null && acceptorPID <= previous_member_id.getProposerID())
				return;
			acceptors.add(accepted_msg);
			System.out.println("{ Phase 2b } Accepted Stage for Proposer M" + this.MemberID
								+ ", received Accepted Message from M" + accepted_msg.getMemberID() + " -> "
								+ acceptedValue + " total number - " + acceptors.size() + '\n');

			// if consensus acheived by majority votes
			if (acceptors.size() == majority_votes)
			{
				System.out.println("==================| M" + this.MemberID
								+ " has received enough Accepted Messages ! Messages Recieved :["
								+ acceptors.size() + "] !\n");

				// check current proposer ID value in acceptors list
				int max = 0;
				int comp;
				for (int i = 0; i < acceptors.size(); i++)
				{
					if (acceptors.get(i) != null) {
						comp = acceptors.get(i).getProposerID();
						if (comp > max) {
							max = comp;
						}
						else { continue; }
					} else if (acceptors.get(i) == null) { continue; }
				}
				// if incoming pid is larger than current max value prepare phase 1
				if (max > this.proposal_message.getProposerID()) {
					System.out.println("Found larger PID from incoming accepted "+
									"message.......... \n" + "Generating a new Proposal ..........\n");
					// back into phase 1
					prepare(); // resend prepare message again
				}
				// learning phase
				else { // let all other nodes about the final consensus value
					System.out.println("\n{ Learning Phase } " + " M" + this.MemberID
							+ " has Received Majority Accepted ( " + promisesReceived.size()
							+ " )\n\n Sending Final Agreement to all Council Members..................\n");
					finalValue = promised_msg.getValue();
					final_proposal_message = new Proposal_Message(this.MemberID, proposal_message.getProposerID(), finalValue, "Final");
					acceptors.clear();

					// printing out final consensus output
					try{
					System.out.println("\n|==================== Consensus Acheived ! Agreement on Proposer M"
							+ final_proposal_message.getMemberID() + " is made ! =========================|\n");
							broadcast_message(final_proposal_message, "Final");
					}
					catch (Exception e)
					{
						System.out.println(">> M" + this.MemberID + "Error in sending FINAL Agreement !");
						e.printStackTrace();
					}
				}
			}
		}
		catch (Exception e) {
			System.out.println(">> M" + this.MemberID + "Error in receiving acceptance Message");
			e.printStackTrace();
		}
	}


}