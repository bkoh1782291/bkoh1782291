// a1767905, Ly, Jason
// a1769000, Mak, Ken
// a1782291, Koh, Brian
// group name: pls give me hd

#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

// std is a namespace: https://www.cplusplus.com/doc/oldtutorial/namespaces/
const int TIME_ALLOWANCE = 8; // allow to use up to this number of time slots at once
const int PRINT_LOG = 0;	  // print detailed execution trace

class Customer
{
public:
	std::string name;
	int priority;
	int age_priority = 10;
	int arrival_time;
	int slots_remaining; // how many time slots are still needed
	int playing_since;


	Customer(std::string par_name, int par_priority, int par_arrival_time, int par_slots_remaining)
	{
		name = par_name;
		priority = par_priority;
		arrival_time = par_arrival_time;
		slots_remaining = par_slots_remaining;
		playing_since = -1;
	}

	void decrement()
	{
		slots_remaining = slots_remaining - 1;
	}

	int get_age()
	{
		return age_priority;
	}
};

class Event
{
public:
	int event_time;
	int customer_id; // each event involes exactly one customer

	Event(int par_event_time, int par_customer_id)
	{
		event_time = par_event_time;
		customer_id = par_customer_id;
	}
};

void initialize_system(
	std::ifstream &in_file,
	std::deque<Event> &arrival_events,
	std::deque<Customer> &customers)
{
	std::string name;
	int priority, arrival_time, slots_requested;

	// read input file line by line
	// https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c
	int customer_id = 0;
	while (in_file >> name >> priority >> arrival_time >> slots_requested)
	{
		Customer customer_from_file(name, priority, arrival_time, slots_requested);
		customers.push_back(customer_from_file);

		// new customer arrival event
		Event arrival_event(arrival_time, customer_id);
		arrival_events.push_back(arrival_event);

		// check if current process has high priority

		customer_id++;
	}
}

void print_state(
	std::ofstream &out_file,
	int current_time,
	int current_id,
	const std::deque<Event> &arrival_events,
	const std::deque<int> &customer_queue)
{
	out_file << current_time << " " << current_id << '\n';
	if (PRINT_LOG == 0)
	{
		return;
	}
	std::cout << current_time << ", " << current_id << '\n';
	for (int i = 0; i < arrival_events.size(); i++)
	{
		std::cout << "\t" << arrival_events[i].event_time << ", " << arrival_events[i].customer_id << ", ";
	}
	std::cout << '\n';
	for (int i = 0; i < customer_queue.size(); i++)
	{
		std::cout << "\t" << customer_queue[i] << ", ";
	}
	std::cout << '\n';
}

// process command line arguments
// https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cerr << "Provide input and output file names." << std::endl;
		return -1;
	}
	std::ifstream in_file(argv[1]);
	std::ofstream out_file(argv[2]);
	if ((!in_file) || (!out_file))
	{
		std::cerr << "Cannot open one of the files." << std::endl;
		return -1;
	}

	// deque: https://www.geeksforgeeks.org/deque-cpp-stl/
	// vector: https://www.geeksforgeeks.org/vector-in-cpp-stl/
	std::deque<Event> arrival_events;	// new customer arrivals
	std::deque<Customer> customers;	// information about each customer
	std::vector<Customer> high_prior_q; // to store process id and burst time
	std::vector<Customer> low_prior_q;

	// read information from file, initialize events queue
	initialize_system(in_file, arrival_events, customers);

	int current_id = -1;   // who is using the machine now, -1 means nobody
	int time_out = -1;	   // time when current customer will be preempted
	std::deque<int> queue; // waiting queue

	int AGE_THRESHOLD = 1000;
	// step by step simulation of each time slot
	bool all_done = false;
	for (int current_time = 0; !all_done; current_time++)
	{

		//check if exisiting customers in low queue has been waiting too long
		for(int i = 0; i < low_prior_q.size(); i++){
			if(((current_time - low_prior_q[i].arrival_time)) > 30)
			{
				high_prior_q.push_back(low_prior_q[i]);
				low_prior_q.erase(low_prior_q.begin() + i);
			}
			// if((AGE_THRESHOLD - current_time - low_prior_q[i].arrival_time) == 0){
			//  	cout << current_time << " - " << low_prior_q[i].arrival_time << " = " << AGE_THRESHOLD - current_time - low_prior_q[i].arrival_time << endl;
			// }

		}
		//cout << endl;

		// welcome newly arrived customers
		while (!arrival_events.empty() && (current_time == customers[0].arrival_time))
        {
            // high priority customer
            if (customers[arrival_events[0].customer_id].priority == 0)
            {
                high_prior_q.push_back(customers[0]);
            }
            else // regular priority customer
            {
                low_prior_q.push_back(customers[0]);
            }
            customers.pop_front();
        }



		// if (arrival_events.empty() == false) {
		// 	arrival_events.pop_front();
		// }

		int min_BT;
		string min_id;
		int flag = 0;

		if (high_prior_q.size() > 0)
		{
			flag = 1;
			for (int i = 0; i < high_prior_q.size(); i++)
			{
				// find the smallest burst time in this vector
				if (i == 0)
				{
					min_BT = high_prior_q[0].slots_remaining;
					min_id = high_prior_q[0].name;
				}
				else if (high_prior_q[i].slots_remaining < min_BT)
				{
					min_BT = high_prior_q[i].slots_remaining;
					min_id = high_prior_q[i].name;
				}
			}
		}
		else if (low_prior_q.size() > 0)
		{
			flag = 2;
			for (int i = 0; i < low_prior_q.size(); i++)
			{
				// find the smallest burst time in this vector
				if (i == 0)
				{
					min_BT = low_prior_q[0].slots_remaining;
					min_id = low_prior_q[0].name;
				}
				else if (low_prior_q[i].slots_remaining < min_BT)
				{
					min_BT = low_prior_q[i].slots_remaining;
					min_id = low_prior_q[i].name;
				}
			}
		}
		else
		{
			min_id = "-1";
		}

		min_id.erase(remove(min_id.begin(), min_id.end(), 'c'), min_id.end());
		// cout << " min id : " << stoi(min_id) << endl;
		current_id = stoi(min_id);

		// cout << min_id << " |||| burst time is: " << to	_string(min_BT) << endl;
		// cout << "minimum/smallest element is: " << high_prior_q[i].name << endl;
		string temp_name;
		int temp_name2;
		if (current_id > -1)
		{
			// within the queue find the customer with the id equal to current_id
			if (flag == 1)
			{
				// iterate through high priority queue
				for (int i = 0; i < high_prior_q.size(); i++)
				{
					temp_name = high_prior_q[i].name;
					if (temp_name == "c00")
					{
						temp_name2 = 0;
					}
					else
					{
						temp_name.erase(remove(temp_name.begin(), temp_name.end(), 'c'), temp_name.end());
						temp_name2 = stoi(temp_name);
					}
					// decrease the burst time
					if (current_id == temp_name2)
					{
						//cout << "before sex" << high_prior_q[i].slots_remaining << endl;
						high_prior_q[i].decrement();
						if (high_prior_q[i].slots_remaining == 0){
								high_prior_q.erase(high_prior_q.begin() + i);
						}
						//cout << "after sex" << high_prior_q[i].slots_remaining << endl;
					}
				}
			}
			else
			{
				// iterate through low priority queue
				for (int i = 0; i < low_prior_q.size(); i++)
				{
					temp_name = low_prior_q[i].name;
					// temp_name.erase(remove(min_id.begin(), min_id.end(), 'c'), min_id.end());
					if (temp_name == "c00")
					{
						temp_name2 = 0;
					}
					else
					{
						temp_name.erase(remove(temp_name.begin(), temp_name.end(), 'c'), temp_name.end());
						temp_name2 = stoi(temp_name);
					}
					// decrease the burst time
					if (current_id == temp_name2)
					{
						//cout << "before sex" << low_prior_q[i].slots_remaining << endl;
						low_prior_q[i].decrement();
						if (low_prior_q[i].slots_remaining == 0){
								low_prior_q.erase(low_prior_q.begin() + i);
						}
						//cout << "after sex" << low_prior_q[i].slots_remaining << endl;
					}
				}
			}
		}


		print_state(out_file, current_time, current_id, arrival_events, queue);
		// exit loop when there are no new arrivals, no waiting and no playing customers
		all_done = (customers.empty() && (low_prior_q.size() == 0) && (high_prior_q.size() == 0) && current_id == -1);
	}

	return 0;
}