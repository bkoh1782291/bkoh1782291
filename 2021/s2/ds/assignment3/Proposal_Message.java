/*
	-------------------------------------------
	| Brian Koh Lit Yang					  |
	| a1782291								  |
	-------------------------------------------
	Implementation for proposal messages
	Stores memberID, proposerID, current accepted value
	and paxos message type in objects.
*/

import java.io.Serializable;
import java.util.Random;

public class Proposal_Message implements Serializable {
	private int MemberID;
	private int ProposerID;
	private Object value;
	private String type = "";

	// default constructor for each proposal message
	public Proposal_Message(int MemberID, int ProposerID, Object value, String type) {
		this.MemberID = MemberID;
		this.ProposerID = ProposerID;
		this.value = value;
		this.type = type;
	}

	// first instance of a proposal message
	public Proposal_Message(int MemberID) {
		this.MemberID = MemberID;
		this.ProposerID = 0; // set ProposerID = 0 when first new Proposal
		this.value = MemberID;
	}

	// function for creating a unique proposal id for each proposer
	public void unique_proposal_id() {
		int ran = new Random().nextInt(100 + 1);
		this.ProposerID = ran * 88;
	}

	// a simple way to print proposalMSG object in a nice format
	public String getProposalMSG() {
		return " " + type + "(Unique ID : " + Integer.toString(getProposerID()) + ", Value : " + getValue() + ")";
	}

	public int getProposerID() {
		return ProposerID;
	}

	public int getMemberID() {
		return MemberID;
	}

	public Object getValue() {
		return value;
	}

	public void setValue(Object value) {
		this.value = value;
	}

	public String getType() {
		return type;
	}

	// function for comparing proposal messages
	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null || getClass() != obj.getClass()) {
			return false;
		}
		Proposal_Message other = (Proposal_Message) obj;
		if (MemberID != other.MemberID || ProposerID != other.ProposerID)
		{
			return false;
		}
		if (value == null) {
			return other.value == null;
		} else {
			if (other.value == null)
				return false;
			else {
				return (int) value == (int) other.value;
			}
		}
	}
}

/*
 * https://stackoverflow.com/questions/363681/how-do-i-generate-random-integers-within-a-specific-range-in-java
 */