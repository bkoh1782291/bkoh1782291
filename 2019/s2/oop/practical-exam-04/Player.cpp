#include <iostream>
#include <string>
#include "Person.h"
#include "Coach.h"
#include "Player.h"

using namespace std;

int Player::nextID = 1000;

Player::Player():Person("","coach",0){
	num_game = 0;
}

Player::Player(string n, int sl, int *list, int m):Person(n,"Coach",sl){
	num_game = m;
	personID = nextID++;
	list1 = list;
}

int Player::searchGame(int x){
	for(int i=0; i <num_game; i++){
		if(list1[i] == x){
			return i+1;
		}
	}
	return -1;
}

int Player::get_salary()
{
	if(serviceLength <20){
		return salary;
	} else {
		return salary*3;
	}
}

Player::~Player(){

}