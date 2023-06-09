#include "Heap.h"
using namespace std; 

Heap::Heap(int *a, int l){
	// passing in pointer array and length
	arrsize = l;
	temparray = a;
	buildHeap();
}

void Heap::buildHeap(){

    for (int i = arrsize / 2 - 1; i >= 0; i--){
        siftDown(i); 
    }
}

void Heap::siftDown(int i){

	int left = 2*i + 1;
	int right = 2*i + 2;
	//int largerChild;

	int numb;

	if ( left <= arrsize){
		if (right >= arrsize || temparray[left] <= temparray[right]){
			numb = left;
		}
		else{
			numb = right;
		}

		if (temparray[i] > temparray[numb]){
			int temp = temparray[i];
			temparray[i] = temparray[numb];
			temparray[numb] = temp;
			siftDown(numb);
		}
	}
}

int Heap::deleteMin(){

	int min = -1;
	if(arrsize > 0){
		min = temparray[0];
		temparray[0] = temparray[arrsize-1];
		arrsize--;
		siftDown(0);
	}

	return min;
}