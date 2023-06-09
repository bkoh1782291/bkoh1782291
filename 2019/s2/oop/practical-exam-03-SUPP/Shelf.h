#ifndef SHELF_H
#define SHELF_H

#include "Music_box.h"

class Shelf: public Music_box {
   public:
   	Shelf(); // default constructor
   	Shelf(int width); //constructor for shelf with given width in

   	int get_width(); //return the width of the shelf in centimetre

  //returns the number of Music boxes currently on the shelf
    
    int get_number_of_music_boxes();

//  return a dynamic array of the the music boxes currently on the shelf
    Music_box *get_contents();

// returns true and adds music box to shelf to shelf if there is sufficient space
// otherwise returns false

    bool add_music_box(Music_box a_music_box);

    ~Shelf();

    Music_box *array_h;

    int width_h;
    int current_width_h;
    int number;

  };

  #endif//Shelf_h       



