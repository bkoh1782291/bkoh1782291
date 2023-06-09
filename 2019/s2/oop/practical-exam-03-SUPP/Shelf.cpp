#include "Music_box.h"
#include "Shelf.h"

Shelf::Shelf(){
    current_width_h = 0;
    width_h = 0;
    number = 0;

    array_h = new Music_box[width_h];

}

Shelf::Shelf(int width){
    current_width_h = 0;
    width_h = width;
    number = 0;

    array_h = new Music_box[width_h];

}

int Shelf::get_width(){
	return width_h;
}

int Shelf::get_number_of_music_boxes(){
    return number;
}

  Music_box* Shelf::get_contents(){
  	return array_h;
  }


  bool Shelf::add_music_box(Music_box a_music_box){
  	//bool check = false;
  	
  	if((current_width_h + a_music_box.get_width()) <= width_h){
  		array_h[number] = a_music_box;
  		number++;
        
  		current_width_h = current_width_h + a_music_box.get_width();
        return true;
  	}
  		return false;
  	
  }

  Shelf::~Shelf(){}
