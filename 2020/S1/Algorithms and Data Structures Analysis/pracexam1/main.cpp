#include <iostream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <cctype>
#include "Set.h"

using namespace std;

	//takes numbers and outputs average, max and min
	//after the largest number is taken out

//  The main function takes as input a collection of numbers 
//	(one line of characters, containing only integers)
//	outputs the average, maximum, and minimum  of the given set of numbers 
//	after the removal of the largest number. 
//	The main function has to use the above defined methods to produce the output.

//	The main function should read the input, 
//	construct an empty and add all numbers of the input to the set. 
//	Afterwards, it should remove the largest number from the set.
	
int main(){

	
		std::string input;

		getline(cin, input);
		stringstream str_strm;

		str_strm << input;
		string temp_str;
		int temp_int;
		int n[10];
		int i = 0;
		int j = 0;

		while(!str_strm.eof()) {
			str_strm >> temp_str;

		if(stringstream(temp_str) >> temp_int) {
			//cout << temp_int << " ";
				n[i] = temp_int;
			i++;
			j++;
		}
			temp_str = "";
		}

		//input validation
		//only accepts numbers
		for(int i =0; i <j; i++){
			if (!((n[i] >= 'a' && n[i]<='z') || (n[i] >= 'A' && n[i]<='Z')))
        	{
          		break;
        	}
		}

		//sorting the array again for duplicates

		int p = 0;

		for(i = 0; i<j; i++){
			for(p = 0; p<i ; p++){

				if(n[i] == n[p]){
				j--;
					for(int k=i; k<j; k++){
						n[k] = n[k+1];
					}
				i--;
				}
			}
		}

		unsigned int count = 0;
		
		for(int i =0; i < j; i++){
			if(n[i] != 0){
				count++; 
			}
		}

		Set *numbs = new Set();

		// adding and removing elements that already exist
		for(unsigned int i =0; i < count; i++){
			numbs->addElement(n[i]);
		}

		numbs->findMaximum();

		numbs->removeElement();

		double Avg = numbs->returnAverage();

		std::cout << Avg << " ";

		std::cout << numbs->returnMaximum() << " ";

		std::cout << numbs->returnMinimum() << std::endl;
	

}

