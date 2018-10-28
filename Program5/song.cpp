//
// Created by Naris on 10/23/2018.
//

#include "song.h"
using namespace std;

song::song()
{
    title = "";
    artist = "";
    memory = minmem;
}

song::song(string name)
{
    title = name;
    artist = "";
    memory = minmem;
}

song::song(string _artist, string _name, int _memory)
{
    artist = _artist;
    title = _name;
    memory = _memory;
}

string song ::getTitle() const
{
    return title;
};

string song ::getArtist() const
{
    return artist;
};

int song ::getMemory() const
{
    return memory;
};


void song::setTitle(string _title)
{
    title = _title;
};

void song::setArtist(string _artist)
{
    artist =_artist;
};

void song::setMemory(int _memory)
{
    memory =_memory;
};