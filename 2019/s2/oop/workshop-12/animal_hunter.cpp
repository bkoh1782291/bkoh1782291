#include <string>
#include <iostream>

using namespace std;

// class definition of a animal abstract class
class animal
{
protected:
  string name;
  int volume;
  int AnimalId;
  int id;
public:
  void set_values(string n,int v);
  virtual string get_name() =0;  // not implemented here
  ~animal();
};


// implementation of set values
void animal::set_values(string n,int v)
{
  name = n ;
  volume = v ;
  AnimalId = id;
}

animal::~animal()
{
        cout << "Destroyed the animal" << endl ;
}


class newAnimal: public animal
{
public:
  virtual string get_name();
  int get_volume();
  int get_AnimalId();
};

string newAnimal::get_name()
{
  return name;
}

int newAnimal::get_volume(){
  return volume;
}

int newAnimal::get_AnimalId(){
  id++;
  return id;
}

int main()
{
  newAnimal *animalA = new newAnimal();
  animalA->set_values("dog",10);
  cout << "The animal's ID is :" << animalA->get_AnimalId() << endl;
  cout << "The animal's name is: " << animalA->get_name() << endl;
  cout << "The animal's volume is: " << animalA->get_volume() << endl;
}
