#include <iostream>
#include <vector>
#include "Set.h"
#include <cctype>
#include <algorithm>

using namespace std;

Set::Set()
{
  
}

void Set::addElement(int n)
{
       intvec.push_back(n);
}
    

void Set::removeElement(int n)
{
  
    vector<int>::iterator iter =
    find(intvec.begin(),intvec.end(),n);
    
    if(iter != intvec.end())
        intvec.erase(iter);
    
}
   
double Set::returnAverage()
{
    if (intvec.empty())
    {
        return -1;
    }
    else
    {
    double sum = 0 ;
  
    for (int i = 0; i < intvec.size(); i++){
      
        sum = sum + intvec[i];
    }
    
    //for(vector<int>::iterator iter = intvec.begin();
    //                          iter != intvec.end();
    //                          iter++)
    //{
    //    sum += *iter;
    //    index++;
    //}
   
 
    double average = sum/intvec.size();
    return average;
    }
}
int Set::returnMaximum()

{
   if (intvec.empty())
      {
          return -1;
      }
    else
    {
    vector<int> vec2;
    vec2 = intvec;
    
    vector<int>::iterator max = vec2.begin();
    for(vector<int>::iterator iter = vec2.begin();
                              iter != vec2.end();
                              iter++)
    {
       if(*max < *iter)
       {
           *max = *iter;
       }
    }
    
    return *max;
    }
}

int Set::returnMinimum()
{
    if (intvec.empty())
    {
           return -1;
    }
    else
    {
    vector<int> vec2;
    vec2 = intvec;
    vector<int>::iterator min = vec2.begin();
    for(vector<int>::iterator iter = vec2.begin();
                              iter != vec2.end();
                              iter++)
    {
       if(*min > *iter)
       {
           *min = *iter;
       }
    }
    
    return *min;
    }
}
    
void Set::show()
{
	for(vector<int>::size_type ix = 0; ix < intvec.size();++ix)
	{
		cout<<intvec[ix]<<" ";
	} 
}

Set::~Set()
 {

 }
