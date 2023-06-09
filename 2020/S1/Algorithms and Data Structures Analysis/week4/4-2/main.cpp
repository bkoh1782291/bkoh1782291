#include "TruckDepot.h"
#include<iostream>
using namespace std;



int main(void) {
    TruckDepot depot;
    int pileSize =100;
    int truckCapacity=2;
    int result;
    
    cout << "Run without Memoisation" << endl;
    result = depot.numTrucks(pileSize,truckCapacity);
    cout << "Run with Memoisation" << endl;
    
    int** mem = new int*[pileSize];
    for(int i = 0; i < pileSize; ++i){
        mem[i] = new int[truckCapacity];
    }
    
    
    result =depot.numTrucks_mem(pileSize,truckCapacity,mem);
  
}
