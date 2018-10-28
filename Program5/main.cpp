#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]) {

    UtPod t;

    song s1("John Legend", "All of Me", 4);
    int result = t.addSong(s1);

    song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);

    song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);

    song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);

    song s5("Avicii", "Levels", 241);
    result = t.addSong(s5);

    song s6("Avicii", "Wake Me Up", 8);
    result = t.addSong(s6);

    song s7("Coldplay","Something Just Like This",  10);
    result = t.addSong(s7);

    song s8("Post Malone","Congratulations",2);
    result = t.addSong(s8);

    song s9("Imagine Dragons","Tiptoe",3);
    result = t.addSong(s9);

    song s10("Imagine Dragons","Radioactive", 11);
    result = t.addSong(s10);

    song s11("Imagine Dragons","I Bet My Life", 4);
    result = t.addSong(s11);

    song s12("Imagine Dragons","Radioactive", 15);
    result = t.addSong(s12);

    song s13("Imagine Dragons","Radioactive", 3);
    result = t.addSong(s13);
    t.showSongList();

    song s14("Post Malone","White Iverson",17);
    result = t.addSong(s14);


    cout << "Remaining Memory = " << t.getRemainingMemory();
    cout << "\n";
    cout << "\n";

    cout << "Number of Songs = " << t.getNumSongs();
    cout << "\n";
    cout << "\n";

    t.shuffle();
    cout << "after shuffle1 \n";
    t.showSongList();
    cout << "\n";
    cout << "memory = " << t.getRemainingMemory();
    cout << "\n";

    cout << "Number of Songs = " << t.getNumSongs();
    cout << "\n";
    cout << "\n";

    t.sortSongList();
    cout << "after sorting \n";
    t.showSongList();


    result = t.removeSong(s2);

    result = t.removeSong(s3);
    cout << "after s2 and s3 removed \n";
    t.showSongList();

    cout << "Remaining Memory = " << t.getRemainingMemory();
    cout << "\n";
    cout << "\n";
    cout << "Number of Songs = " << t.getNumSongs();
    cout << "\n";
    cout << "\n";

    t.shuffle();
    cout << "after shuffle2 \n";
    t.showSongList();
    cout << "\n";

    t.sortSongList();
    cout << "after sorting \n";
    t.showSongList();
    return 0;
}