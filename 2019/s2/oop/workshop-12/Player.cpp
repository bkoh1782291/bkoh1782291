#include <iostream>
#include <string>
#include "Coach.h"
#include "Person.h"
#include "Player.h"

using namespace std;

int Player::nextID = 999;

Player::Player():Person("","Player",0)
{
	num_game = 0;
	personID = nextID++;

}

Player::Player(string n, int sl, int *list, int m):Person(n,"Player",sl)
{

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

int Player::get_salary(){
	if (serviceLength<15){
		return salary;
	} else {
		return salary*3;
	}
}

Player::~Player(){

}