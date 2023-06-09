/*
    Brian Koh Lit Yang
    a1782291
    Computer Networking and Applications Assignment 3
    usage : make
    ./PoisonedReverse < [textfile]

    test case:
    X
    Y
    Z

    X Z 50
    X Y 4
    Y Z 1

    X Y 60
*/

#include <iostream>
#include <iterator>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

struct node
{
    int origin;
    int destination;
    int distance;
    string from;
};

// hash map to convert routers into individual indexes
// reference : https://en.cppreference.com/w/cpp/container/map
map<string, int> table;

// function for getting rid of spaces
vector<string> space_removal(string input)
{
    vector<string> values;
    stringstream sstream(input);
    string word;

    while (sstream >> std::skipws >> word)
    {
        values.push_back(word);
    }

    return values;
}

/*
Distance vector function

calculates the total distance vector between nodes and updates the
cost matrix table based on whether there are changes with the previous state.

input :
        vector string of routers
        2d matrix vector string of updated states
        router_size
        vector string of current states
*/
void dv(vector<string> routers, vector<string> links, vector<vector<string>> updated_links)
{

    int n = routers.size();
    int link_table[n][n];
    node updated_table[n][n];
    long int inf = 10000000;

    // initializing both tables for current state and updated states
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                link_table[i][j] = 0;
                updated_table[i][j].distance = 0;
            }
            else
            {
                link_table[i][j] = -100;
                updated_table[i][j].distance = inf;
            }
        }
    }

    // initialize table for link edges
    for (int i = 0; i < links.size(); i++)
    {
        vector<string> updates = space_removal(links[i]);
        link_table[table[updates[0]]][table[updates[1]]] = stoi(updates[2]);
        link_table[table[updates[1]]][table[updates[0]]] = stoi(updates[2]);
    }

    // main distance vector algorithm
    vector<node> result;
    int i, j, k, x, y, t = 0;

    for (i = 0; i < updated_links.size() + 1; i++)
    {
        while (t == 0 || !result.empty())
        {
            result.clear();
            for (j = 0; j < routers.size(); j++)
            {
                // printing out first line of output
                cout << "router " << routers[j] << " at t=" << t << endl;

                for (k = 0; k < routers.size(); k++)
                {
                    if (routers[k] != routers[j])
                    {
                        cout << "\t" << routers[k];
                    }
                }
                cout << endl;
                for (x = 0; x < routers.size(); x++)
                {
                    int min = inf;
                    node new_update;
                    if (routers[x] != routers[j])
                    {
                        // printing out second line of output
                        cout << routers[x] << "\t";
                        for (y = 0; y < routers.size(); y++)
                        {
                            if (routers[y] != routers[j])
                            {
                                if (link_table[table[routers[j]]][table[routers[y]]] == -100)
                                {
                                    cout << "-"
                                        << "\t";
                                    continue;
                                }
                                if (updated_table[table[routers[y]]][table[routers[x]]].distance >= inf)
                                {
                                    cout << "INF"
                                         << "\t";
                                    continue;
                                }
                                // calculating and print total distance
                                // distance(j, y) + min (y , x)
                                int total_dist = link_table[table[routers[j]]][table[routers[y]]] + updated_table[table[routers[y]]][table[routers[x]]].distance;

                                /* ***************poisoned reverse additional code*************** */
                                // check if router.via equals to router start
                                if (updated_table[table[routers[y]]][table[routers[x]]].from == routers[j])
                                {
                                    total_dist = inf;
                                    cout << "INF" << "\t";
                                }
                                else
                                {
                                    cout << total_dist << "\t";
                                }
                                /* **************************************************************** */

                                if (total_dist < min)
                                {
                                    // update node information
                                    min = total_dist;
                                    new_update.origin = table[routers[j]];
                                    new_update.destination = table[routers[x]];
                                    new_update.distance = total_dist;
                                    new_update.from = routers[y];
                                }
                            }
                        }
                        cout << endl;
                        // checks if table is updated
                        if (min != updated_table[table[routers[j]]][table[routers[x]]].distance)
                        {
                            result.push_back(new_update);
                        }
                    }
                }
                cout << endl;
            }
            // increment t after running all router scenarios
            t++;
            for (j = 0; j < result.size(); j++)
            {
                updated_table[result[j].origin][result[j].destination].distance = result[j].distance;
                updated_table[result[j].origin][result[j].destination].from = result[j].from;
            }
        }
        for (j = 0; j < routers.size(); j++)
        {
            for (k = 0; k < routers.size(); k++)
            {
                if (j != k)
                {
                    // printing router pattern
                    cout << "router " << routers[j] << ": " << routers[k] << " is " << updated_table[j][k].distance << " routing through " << updated_table[j][k].from << endl;
                }
            }
        }
        cout << endl;
        if (i < updated_links.size())
        {
            for (j = 0; j < updated_links[i].size(); j++)
            {
                vector<string> updates = space_removal(updated_links[i][j]);
                if (updates[2] != "-1")
                {
                    link_table[table[updates[0]]][table[updates[1]]] = stoi(updates[2]);
                    link_table[table[updates[1]]][table[updates[0]]] = stoi(updates[2]);
                }
                else
                {
                    link_table[table[updates[0]]][table[updates[1]]] = -100;
                    link_table[table[updates[1]]][table[updates[0]]] = -100;
                }
            }
            node a;
            result.push_back(a);
        }
    }
}

int main(int argc, char **argv)
{
    // getting input for routers
    vector<string> routers;
    string input1;

    // getline method for multi-line input
    // reference : https://www.geeksforgeeks.org/how-to-use-getline-in-c-when-there-are-black-lines-in-input/
    while (getline(cin, input1))
    {
        if (input1.empty())
        {
            break;
        }
        routers.push_back(input1);
    }

    // fill out hash table
    for (int i = 0; i < routers.size(); i++)
    {
        table.insert(pair<string, int>(routers[i], i));
    }

    // taking input for current states
    vector<string> links;
    string input2;

    while (getline(cin, input2))
    {
        if (input2.empty())
        {
            break;
        }
        links.push_back(input2);
    }

    // taking input for 2d array for updated edge values
    vector<vector<string>> updated_links;
    vector<string> link;
    string input3;

    while (getline(cin, input3))
    {
        if (input3.empty())
        {
            break;
        }
        else
        {
            link.push_back(input3);
            while (getline(cin, input3))
            {
                if (input3.empty())
                {
                    break;
                }
                else
                {
                    link.push_back(input3);
                }
            }
            updated_links.push_back(link);
            link.clear();
        }
    }

    // call distance vector function
    dv(routers, links, updated_links);

    return 0;
}
