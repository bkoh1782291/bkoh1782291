#include "SortPerson.h"
#include "Person.h"
#include "Team.h"
#include "Coach.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

static void sort(Person **people, int n){
	int i,j;
	Person *k;

	for(i = 1; i <n; i++){
		k = people[i];
		j = i - 1;

		while (j >=0 && people[j]->get_personID() > k->get_personID())
		{
			people[j+1] = people[j];
			j = j-1;
		}
		people[j+1] =k;
	}
}