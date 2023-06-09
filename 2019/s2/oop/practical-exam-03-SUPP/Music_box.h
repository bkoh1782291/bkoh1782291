#ifndef MUSIC_BOX_H
#define MUSIC_BOX_H

#include <string>
using namespace std;

class Music_box
{
   public:
     Music_box();       //a default constructor
     Music_box(string songname, int width); 
     string get_song(); //return the name of the sone
     int get_width(); //return the width in centimetres of the music
     ~Music_box();   //A default destructor

     string song_h;
     int width_h;
};

#endif//MUSIC_BOX_H

