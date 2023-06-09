/*
	-------------------------------------------
	| Brian Koh Lit Yang					  |
	| a1782291								  |
	-------------------------------------------
	Suburbs Council Election, holds the election for the current council president
	In the base election case, there will be 9 members in the council elections and
	three of the council members want to run as president. The other 6 members will
	be voting for either one of the council members. If a majority vote is achieved,
	(n+1)/2, the council member will be elected as president.

	implement Member Profiles
	M1 - immediate
	M2 - late
	M3 - medium or never
	M4 to M9 have variable response times immediate; medium; late; never
*/

import java.lang.reflect.Member;
import java.util.ArrayList;

public class Council_Election {

    // protected static Council_Members M1, M2, M3, M4, M5, M6, M7, M8, M9;
    protected static ArrayList<Council_Members> MemberList = new ArrayList<>();

	// starting the election process for MemberList members
    public void election_start(int n) {

		// creating n members in a council [1]
		for (int i = 1; i < n+1; i++)
		{
			Council_Members temp = new Council_Members(i, 1000+i);
			MemberList.add(temp);
		}

        for (int i = 0; i < MemberList.size(); i++)
		{
			Council_Members member = MemberList.get(i);
            member.nodes = MemberList.size();
            member.majority_votes = MemberList.size() / 2 + 1;
        }

		System.out.println(" ------------------------------------ Starting Council Election ----------------------------------------\n ");

        for (int i = 0; i < MemberList.size(); i++)
		{
			Council_Members member = MemberList.get(i);

			new Thread(() -> {
				try{
					member.connecting();
				}
				catch (Exception e) {
					e.printStackTrace();
					System.out.println("Error in creating Threads ! ---- <Election.java> " );
				}
			}).start();
        }
    }

    protected void propose(Council_Members a_member) {
        new Thread(() -> {
			try{
				System.out.println("M" + a_member.MemberID + " will send a proposal to all other members .................\n");
				a_member.prepare();
			}
			catch (Exception e) {
				e.printStackTrace();
				System.out.println("Error in sending proposal messages ! ---- <Election.java> " );
			}
        }).start();
    }

	// function to simulate offline members in council election
	public void member_offline(){

		java.util.Random random = new java.util.Random();
		int m_id = random.nextInt(2);

		Council_Members m2 = MemberList.get(1);
		Council_Members m3 = MemberList.get(2);

		if (m_id == 0){
			m2.if_member_offline = true;
		}
		else if (m_id == 1){
			m3.if_member_offline = true;
		}
		else { // both go offline
			m2.if_member_offline = true;
			m3.if_member_offline = true;
		}
	}

	// function to simulate response speeds based on proposer profiles
	public void member_response_profiles(){

		// m1 will always respond immediately
		MemberList.get(0).response_profile = "immediate";

		java.util.Random random = new java.util.Random();
		int random_int = random.nextInt(10);

		// m2 will respond either immediately, will be late or sometimes offline
		if (random_int > 0 && random_int < 4)
		{
			MemberList.get(1).response_profile = "immediate";
		}
		else if ( random_int > 4 && random_int < 8)
		{
			MemberList.get(1).response_profile = "late";
		}
		else if (random_int > 8 && random_int < 10)
		{
			MemberList.get(1).if_member_offline = true;
		}
		else { MemberList.get(1).response_profile = "immediate"; }

		// m3 will respond in medium fashion or never
		java.util.Random random2 = new java.util.Random();
		int random_int2 = random2.nextInt(10);
		if (random_int2 > 0 && random_int2 < 7)
		{
			MemberList.get(2).response_profile = "medium";
		}
		else if (random_int2 > 7 && random_int2 < 10)
		{
			MemberList.get(2).if_member_offline = true;
		}
		else { MemberList.get(2).response_profile = "immediate"; }

		// response for other members M4 - M(n)
		for (int i = 3; i < MemberList.size(); i++)
		{
			java.util.Random random3 = new java.util.Random();
			int random_int3 = random3.nextInt(10);
			if (random_int3 > 0 && random_int3 < 3)
			{
				MemberList.get(i).response_profile = "immediate";
			}
			else if (random_int3 > 3 && random_int3 < 6)
			{
				MemberList.get(i).response_profile = "medium";
			}
			else if ( random_int3 > 6 && random_int3 < 10)
			{
				MemberList.get(i).response_profile = "late";
			}
			else { MemberList.get(i).response_profile = "immediate"; }
		}
	}

	public static void main(String[] args)
	{
		int n_members = 9;

		if (args.length > 1){
			n_members = Integer.parseInt(args[1]);
		}

		if (args.length == 0){
			System.out.println("\n -------------------------------- Please specify election case for Paxos Algorithm ! -------------------------------- ");
			System.out.println(" Avaliable Test Cases :");
			System.out.println(" Test Case 1 : Normal Paxos Election, proposers send messages at the same time.");
			System.out.println(" Test Case 2 : Normal Paxos Election, but proposers send messages sequentially.\n");
		}

		/* if all proposers send message at the same time */
		if (args[0].equals("1"))
		{
			System.out.println("\n |Test Case 1 Selected| ");
			System.out.println(" |Proposers are M1, M2 and M3| ");
			System.out.println(" |Propose Messages sent at the same time.| \n");

			Council_Election election = new Council_Election();

			election.election_start(n_members);
			election.propose(MemberList.get(0));
			election.propose(MemberList.get(1));
			election.propose(MemberList.get(2));
		}
		/* if all proposers send message sequentially */
		else if (args[0].equals("2"))
		{
			System.out.println("\n |Test Case 2 Selected| ");
			System.out.println(" |Proposers are M1, M2 and M3.| ");
			System.out.println(" |Propose Messages sent sequentially.|");
			System.out.println(" |Threads have a 10ms sleep time before next execution.| \n");

			Council_Election election = new Council_Election();
			election.election_start(n_members);
			election.propose(MemberList.get(0));
			try{
				Thread.sleep(10);
			}
			catch (Exception e){
				e.printStackTrace();
				System.out.println("Thread sleep() fail !");
			}
			election.propose(MemberList.get(1));
			try{
				Thread.sleep(10);
			}
			catch (Exception e){
				e.printStackTrace();
				System.out.println("Thread sleep() fail !");
			}
			election.propose(MemberList.get(2));
		}
		/* offline node simulation */
		else if (args[0].equals("3"))
		{
			System.out.println("\n |Test Case 3 Selected| ");
			System.out.println(" |Proposers are M1, M2 and M3.| ");
			System.out.println(" |Propose Messages sent at the same time.|");
			System.out.println(" |Simulating offline nodes for Paxos ..... ");
			System.out.println(" |Node M2 or M3, or both M2 and M3 will randomly be offline !");

			Council_Election election = new Council_Election();

			election.election_start(n_members);
			election.propose(MemberList.get(0));
			election.propose(MemberList.get(1));
			election.propose(MemberList.get(2));

			election.member_offline();
		}
		/* random response times from members simulation */
		else if (args[0].equals("4"))
		{
			System.out.println("\n |Test Case 4 Selected| ");
			System.out.println(" |Proposers are M1, M2 and M3.| ");
			System.out.println(" |Propose Messages sent at the same time.|");
			System.out.println(" |Adding simulation of varied responding times from all council members!");

			Council_Election election = new Council_Election();

			election.election_start(n_members);
			election.propose(MemberList.get(0));
			election.propose(MemberList.get(1));
			election.propose(MemberList.get(2));

			election.member_response_profiles();
		}
		/* random response times from members simulation and offline simulation */
		else if (args[0].equals("5"))
		{
			System.out.println("\n |Test Case 5 Selected| ");
			System.out.println(" |Proposers are M1, M2 and M3.| ");
			System.out.println(" |Propose Messages sent at the same time.|");
			System.out.println(" |Adding simulation of varied responding times from all council members !");
			System.out.println(" |Including the chance that both M2 or M3 will randomly be offline !");

			Council_Election election = new Council_Election();

			election.election_start(n_members);
			election.propose(MemberList.get(0));
			election.propose(MemberList.get(1));
			election.propose(MemberList.get(2));

			election.member_offline();
			election.member_response_profiles();
		}
		else {
			System.out.println("\n -------------------------------- Please specify election case for Paxos Algorithm ! -------------------------------- ");
			System.out.println(" Avaliable Test Cases :");
			System.out.println(" Test Case 1 : Normal Paxos Election, proposers send messages at the same time.");
			System.out.println(" Test Case 2 : Normal Paxos Election, but proposers send messages sequentially.\n");
		}
    }
}


/*
	https://stackoverflow.com/questions/1815955/java-for-loop-to-create-n-amount-of-object
	https://www.codejava.net/java-core/the-java-language/java-8-lambda-runnable-example
*/