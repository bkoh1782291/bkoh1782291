
#include <iostream>
#include <vector>
#include "Set.h"
#include <cctype>
#include <sstream>
using namespace std;
 
int main(int argc, char** args) 
{
    std::string input;
    getline(cin, input);
    stringstream str_strm;
    str_strm << input;

    string temp_str;
    int temp_int;

//create an array to store the covered input integer
    int array[10];
    int index = 0;
    
    while(!str_strm.eof())
     {
        str_strm >> temp_str;

        
        if(stringstream(temp_str) >> temp_int)  
        {
          //cout << temp_int << " ";
          array[index] = temp_int;	
          index++;
        }
        temp_str = "";
     }
    
//cout<<index<<endl;
    
  

    for(int i = 0; i < index; i++)
    {
        for(int j = 0; j<i ; j++)
        {

            if(array[i] == array[j])
              {
                index--;
                for(int t=i; t<index; t++){
                    array[t] = array[t+1];
                }
                i--;
            }
        }
    }

    unsigned int length = 0;
    
    for(int i =0; i < index; i++){
        if(array[i] != 0){
            length++;
        }
    }
    
    
    Set *A = new Set();
    for(unsigned int i =0; i < length; i++)
    {
        A->addElement(array[i]);
        
    }
    
    
    /*
    int maximum1 = A->returnMaximum();
    A->removeElement(maximum1);
    A->show();
    cout<<endl;
    
    double ave = A->returnAverage();
    cout<<"average: "<<ave<<endl;
    
    int maximum2 = A->returnMaximum();
    cout<<"maximum: "<<maximum2<<endl;
    
    int minimum = A->returnMinimum();
    cout<<"minimum: "<<minimum<<endl;
    */
    
    //find out the maximum number
    int maximum1 = A->returnMaximum();
   
    //remove the maximum number
    A->removeElement(maximum1);
    
    //find out the new maximum number after remove operation
    int maximum2 = A->returnMaximum();
    
    int minimum = A->returnMinimum();
    //find out the average value
    double ave = A->returnAverage();
    
    
    cout<< ave <<" "<< maximum2<<" "<<minimum<<endl;
    
    
    
     return 0;
}

