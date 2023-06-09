#include <iostream>
#include "myF.h"
#include <cctype>
#include <algorithm>

using namespace std;

myF::myF(){

}

int myF::solve(int n){
//recursion
    //diving the problem into smaller sub-problems until none is left
    // n must be positive integer
    // if n is between 0 and 10 return 1
    if(n>= 0 && n<=10){
        return 1;
    }
    //if n is even
    if(n%2 == 0 && n>10){
        return (solve(n/2) + solve(n-2) + solve(n-3));
    }
    //if n is odd 
    if(n%2 == 1 && n>10){
        return (solve ((n-1)/2) + solve(n-3) + solve(n-4));
    }

    return 0;
}

int myF::solve_mem(int *mem_array, int n){
//memoisation
//storing the obtained results of the recursive function into an array
    //so that it can be used again, speeds up process.    
    int i;
    for(i=0; i<=n; i++){
        if(mem_array[n] != -1){
            return mem_array[n];
        }
        // if n is between 0 and 10 return 1
        if(n>=0 && n<=10){
            mem_array[n] = 1;
        }
        //if n is even
        if(n %2 == 0 && n > 10){
            mem_array[n] = solve_mem(mem_array, n/2) + solve_mem(mem_array, n-2) + solve_mem(mem_array, n-3);
        }
        //if n is odd 
        else if(n %2 == 1 && n > 10){
            mem_array[n] = solve_mem(mem_array, (n-1)/2) + solve_mem(mem_array, n-3) + solve_mem(mem_array, n-4);
        }
    }   
    return mem_array[n];
}


myF::~myF(){

}
