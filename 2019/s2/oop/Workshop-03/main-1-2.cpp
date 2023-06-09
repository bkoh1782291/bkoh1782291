#include <iostream>
#include <stdlib.h>

extern void print_class(std::string courses[4], std::string students[], int report_card[][4], int nstudents);

int main(int argc,char **argv)
{
	
	std::string courses[4] = {"Maths", "English", "Chemistry", "Programming"};

	std::string students[3] = {"A","B","C"};

	int report_card[3][4] = 
				{ 
				{83, 96, 56, 55},
				{45, 100, 67, 95},
				{39, 68, 57, 65}
				};

	int nstudents = 3;

	print_class(courses, students, report_card, nstudents);
	
}