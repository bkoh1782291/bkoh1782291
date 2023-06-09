#include "TruckDepot.h"
#include <cmath>
#include <iostream>

int TruckDepot::numTrucks(int pileSize, int truckCapacity){
    int result =-1;
    int pile1;
    int pile2;
 //   std::cout << "PileSize: " << pileSize << std::endl;
    
    if (pileSize<= truckCapacity){
        result =1;
    }
    else{
        if (pileSize %2 ==0){
            pile1=pileSize/2;
            pile2 =pileSize/2;
        }else{
            pile1=pileSize/2+1;
            pile2=pileSize/2;
        }
        
        result = numTrucks(pile1,truckCapacity) + numTrucks(pile2,truckCapacity);
    }
    std::cout<<"Number of Trucks for pileSize " << pileSize <<": " << result <<std::endl;
    return result;
}

int TruckDepot::numTrucks_mem(int pileSize, int truckCapacity, int** mem){
    int result =-1;
    int pile1;
    int pile2;
    if (mem[pileSize-1][truckCapacity-1]!=0){
        result =mem[pileSize-1][truckCapacity-1];
    }
    else{
    
    if (pileSize<= truckCapacity){
        result =1;
    }
    else{
        if (pileSize %2 ==0){
            pile1=pileSize/2;
            pile2 =pileSize/2;
        }else{
            pile1=pileSize/2+1;
            pile2=pileSize/2;
        }
        
        result = numTrucks_mem(pile1,truckCapacity,mem) + numTrucks_mem(pile2,truckCapacity,mem);
    }

        mem[pileSize-1][truckCapacity-1]=result;
    }
    
    std::cout<<"Number of Trucks for pileSize " << pileSize <<": " << result <<std::endl;
    return result;

}
