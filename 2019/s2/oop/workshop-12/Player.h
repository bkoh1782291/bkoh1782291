#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player: public Person
{
public:
	Player();
	Player(string n, int sl, int *list, int m);
	int searchGame(int x);

	int get_salary();

	~Player();

protected: 
	static int nextID;
	int num_game;
	int *list1;
};

#endif