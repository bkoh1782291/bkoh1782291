#ifndef TEAM_H
#define	TEAM_H

#include <iostream>
#include <string>
#include "Person.h"
#include "Coach.h"
#include "Player.h"

using namespace std;

class Team{
private:                       
	Person **Teams; 
	int number_of_players;                     
public:
	
	Team();                 /* creates a team object containing 5 team members as an array; 
							   the first and the last elements of the array are coaches, 
							   the rest of the elements are players
							*/

	Person **get_team();  // returns the array of the five team members
	int get_number_of_players();
	~Team();
};

#endif