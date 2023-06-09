#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class animal{
protected:
  string name;
  int animalID;
  int id = 0;
  int volume;
public:
  animal(string n, int v);
  virtual string get_name() =0;
  int get_animalID();
  int get_volume();

  void set_name(string aName);
  void set_volume(int aVolume);

  virtual ~animal();

};



#endif