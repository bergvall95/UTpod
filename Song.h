#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

 class Song{

     private:
	string title;
	string artist;
	int memory;

	static const int minmem = 1;

     public:
	Song();
