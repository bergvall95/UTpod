//
// Created by Naris on 10/23/2018.
//

#ifndef PROGRAM5_UTPOD_H
#define PROGRAM5_UTPOD_H
#include <string>
#include "song.h"

//UtPod class declaration
using namespace std;
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode

    {
        song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;


public:
    UtPod();
    explicit UtPod(int size);


    int addSong(song const &s);
    int removeSong(song const &s);
    void shuffle();
    void showSongList();
    void sortSongList();

    int getTotalMemory() {
        return memSize;
    }

    int getRemainingMemory();
    int getNumSongs();
    void clearMemory();
    ~UtPod();

};




#endif //PROGRAM5_UTPOD_H
