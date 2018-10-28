//
// Created by Naris on 10/23/2018.
//

#ifndef PROGRAM5_SONG_H
#define PROGRAM5_SONG_H

#include <string>

using namespace std;

class song {
private:
    string artist;
    string title;
    int memory;

    static const int minmem = 1;

public:
    song();
    song(string title);
    song(string artist, string title, int memory);

    string getTitle() const;

    string getArtist() const;

    int getMemory() const;

    void setTitle(string _title);

    void setArtist(string _artist);

    void setMemory(int _memory);
};


#endif //PROGRAM5_SONG_H
