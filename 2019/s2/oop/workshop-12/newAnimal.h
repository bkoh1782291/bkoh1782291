#ifndef NEWANIMAL_H
#define NEWANIMAL_H

#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

class newAnimal: public animal{
  
public:

  virtual string get_name();
  int get_volume();
  int get_AnimalId();
  
  string name;
  int volume;
  int AnimalId;
  int id;
};

#endif //NEWANIMAL_H
