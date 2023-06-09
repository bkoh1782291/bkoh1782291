#include <iostream>
#include <string>
#include "Person.h"
#include "Coach.h"
#include "Player.h"
#include "Team.h"

using namespace std;

Team::Team(){
	Teams = new Person*[number_of_players];
	int i;

	//coach1
	for (int i = 0; i < 2 ; i++){
		Coach *team_ptr = new Coach();
		Teams[i] = team_ptr;
	}

	//player 2,3,4
	for (int i = 1; i < 4 ; i++){
			//string n, int sl, int *list, int m
		Player *team_ptr = new Player();
		Teams[i] = team_ptr;
	}
	
	for(int i = 4; i < 6; i++){
		Coach *team_ptr = new Coach();
		Teams[i] = team_ptr;
	}
}

int Team::get_number_of_players(){
	return number_of_players;
}

Person** Team::get_team(){
	return Teams;
}

Team::~Team(){

}