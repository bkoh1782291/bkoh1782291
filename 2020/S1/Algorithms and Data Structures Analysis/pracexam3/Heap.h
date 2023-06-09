#ifndef HEAP_H
#define HEAP_H

class Heap
{
	int *temparray;
	int arrsize;
public:

	//default constructor
	Heap(int *a, int l);

	//sifting down 
	void siftDown(int i);

	//build the heap
	void buildHeap();

	//return and deleteMin
	int deleteMin();
};

#endif