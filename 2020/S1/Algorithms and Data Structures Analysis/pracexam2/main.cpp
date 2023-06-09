#include <iostream>
#include "myF.h"
#include <cctype>
#include <sstream>
using namespace std;
 
int main(int argc, char** args) 
{
    string input;
    getline(cin,input);
    stringstream str_strm;
    str_strm << input;
    
    string temp_str;
    int temp_int;
    int *temparr;

    myF recur_solve;
    
    while(!str_strm.eof()){
        str_strm >> temp_str;
        if(stringstream(temp_str) >> temp_int){
            //if numbers less than or equal to 40
            if(temp_int <= 40){
                //normal recursion solve
                // temp_int carries the value into methods as int n
                cout << recur_solve.solve(temp_int) << " ";
            }
            else if (temp_int >40){
                //memoisation solve
                temparr = new int[temp_int];
                for (int i = 0; i <= temp_int; i++) {
                    temparr[i] = -1;
                }
                cout << recur_solve.solve_mem(temparr, temp_int) << " ";
                delete[] temparr;
            }
        }
        temp_str = "";
    }
    cout << endl;
}


