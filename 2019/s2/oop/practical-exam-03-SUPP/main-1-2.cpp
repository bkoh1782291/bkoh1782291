#include <iostream>
#include <string>

#include "Music_box.h"
#include "Shelf.h"

using namespace std;

int main(){
  Music_box A = Music_box();
  Music_box B = Music_box("B",2);
  Music_box C = Music_box("C",1);

  Shelf Ex = Shelf(3);

  cout<<"The Shelf width is "<<Ex.get_width()<<endl;

  if(Ex.add_music_box(A) == true)
  {
  	  cout<<"The "<<A.get_song()<<" Finished."<<endl;
  }
  else
  {
      cout<<"The "<<A.get_song()<<" failed"<<endl;
  }

  cout<<"The number of muisc boxes is"<<Ex.get_number_of_music_boxes()<<endl;

if(Ex.add_music_box(B) == true)
  {
  	  cout<<"The "<<B.get_song()<<" Finished."<<endl;
  }
  else
  {
      cout<<"The "<<B.get_song()<<" failed"<<endl;
  }

  cout<<"The number of muisc boxes is"<<Ex.get_number_of_music_boxes()<<endl;

  if(Ex.add_music_box(C) == true)
  {
  	  cout<<"The "<<C.get_song()<<" Finished."<<endl;
  }
  else
  {
      cout<<"The "<<C.get_song()<<" failed"<<endl;
  }

  cout<<"The number of muisc boxes is"<<Ex.get_number_of_music_boxes()<<endl;

 cout <<Ex.get_contents()<<endl;

  return 0;
}
