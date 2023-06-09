#include <string>

#include "Music_box.h"
using namespace std;

Music_box::Music_box(){
	song_h = "null";
    width_h = 0;
}

Music_box::Music_box(string songname , int width){
	song_h = songname;
    width_h = width;
}

string Music_box::get_song(){
	return song_h;
}

int Music_box::get_width(){
	return width_h;
}


Music_box::~Music_box(){}