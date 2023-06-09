
#ifndef SET_H
#define SET_H

#include <vector>
#include <cctype>

class Set
{
public:

    Set();
    ~Set();

    void addElement(int n);
    void removeElement(int n);

    double returnAverage();
    int returnMaximum();
    int returnMinimum();

    void show();

private:
	  std::vector<int> intvec;
};



#endif 
