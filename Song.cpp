//////// Song.cpp////////*
Written by: Alex Bergvall and Naris 

#include "Song.h"

//////// Constructors//////*

using namespace std;

   Song::Song()
   {
      title = "";
      artist = "";
      memory = minmem;
   }

   Song::Song(string name)
   {
      this->title =name;
      artist = "";
      memory = minmem;
   }
   
   Song::Song(string _name, string _artist, int _memory)
   {
      title = _name;
      artist = _artist;
      memory = _memory;
   }

   
   string Song::getTitle()const
   {
   	return title; 
   }

   
   string Song::getArtist()const
   {
   	return artist; 
   }
 
   int Song::getMemory()const
   {
	return memory;
   }
   
