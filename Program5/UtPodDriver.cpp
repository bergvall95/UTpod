#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    int num;
    cout << "Please enter the memory size of the UT Pod (0-512): ";
    cout << "\n";
    cin >> num;
    if(num < 1 || num >512){
        num = 512;
    }
    UtPod t(num);
    cout << "Adding default songs\n";
    song s1("John Legend", "All of Me", 4);
    int results = t.addSong(s1);
    cout << "Adding " << s1.getTitle() << " = " << results << "\n";

    song s2("Beatles", "Hey Jude2", 5);
    results = t.addSong(s2);
    cout << "Adding " << s2.getTitle() << " = " << results << "\n";

    song s3("Beatles", "Hey Jude3", 6);
    results = t.addSong(s3);
    cout << "Adding " << s3.getTitle() << " = " << results << "\n";

    song s4("Beatles", "Hey Jude4", 7);
    results = t.addSong(s4);
    cout << "Adding " << s4.getTitle() << " = " << results << "\n";

    song s5("Avicii", "Levels", 200);
    results = t.addSong(s5);
    cout << "Adding " << s5.getTitle() << " = " << results << "\n";

    song s6("Avicii", "Wake Me Up", 8);
    results = t.addSong(s6);
    cout << "Adding " << s6.getTitle() << " = " << results << "\n";

    song s7("Coldplay","Something Just Like This",  10);
    results = t.addSong(s7);
    cout << "Adding " << s7.getTitle() << " = " << results << "\n";

    song s8("Post Malone","Congratulations", 2);
    results = t.addSong(s8);
    cout << "Adding " << s8.getTitle() << " = " << results << "\n";

    song s9("Imagine Dragons","Tiptoe",3);
    results = t.addSong(s9);
    cout << "Adding " << s9.getTitle() << " = " << results << "\n";

    song s10("Imagine Dragons","Radioactive", 11);
    results = t.addSong(s10);
    cout << "Adding " << s10.getTitle() << " = " << results << "\n";

    song s11("Imagine Dragons","I Bet My Life", 4);
    results = t.addSong(s11);
    cout << "Adding " << s11.getTitle() << " = " << results << "\n";

    song s12("Imagine Dragons","Radioactive", 15);
    results = t.addSong(s12);
    cout << "Adding " << s12.getTitle() << " = " << results << "\n";

    song s13("Imagine Dragons","Radioactive", 3);
    results = t.addSong(s13);
    cout << "Adding " << s13.getTitle() << " = " << results << "\n";

    song s14("Post Malone","White Iverson", 17);
    results = t.addSong(s14);
    cout << "Adding " << s14.getTitle() << " = " << results << "\n";

    song s15("Toto","Africa", 13);
    results = t.addSong(s15);
    cout << "Adding " << s15.getTitle() << " = " << results << "\n";
    cout << "\n";

    cout << "After Sorting\n";
    cout << "\n";
    t.sortSongList();
    t.showSongList();

    cout << "After Shuffling\n";
    cout << "\n";
    t.shuffle();
    t.showSongList();

    song s16("Post Malone","Psycho", 8);
    results = t.addSong(s16);
    cout << "Adding " << s16.getTitle() << " = " << results << "\n";

    song s17("Avicii","Waiting For Love", 14);
    results = t.addSong(s17);
    cout << "Adding " << s17.getTitle() << " = " << results << "\n";

    song s18("Britney Spears","Toxic", 600);
    results = t.addSong(s18);
    cout << "Adding " << s18.getTitle() << " = " << results << "\n";

    cout << "\n";
    cout << "After Adding\n";
    cout << "\n";
    t.showSongList();

    song s19("Imagine Dragons","Radioactive", 15);
    results = t.removeSong(s19);
    cout << "Removing " << s19.getTitle() << " = " << results << "\n";

    song s20("Beatles", "Hey Jude3", 6);
    results = t.removeSong(s20);
    cout << "Removing " << s20.getTitle() << " = " << results << "\n";

    song s21("Linkin Park", "New Divide", 9);
    results = t.removeSong(s21);
    cout << "Removing " << s21.getTitle() << " = " << results << "\n";

    cout << "\n";
    cout << "After Removing\n";
    cout << "\n";
    t.showSongList();

    cout << "After Sorting\n";
    cout << "\n";
    t.sortSongList();
    t.showSongList();

    cout << "After Shuffling\n";
    cout << "\n";
    t.shuffle();
    t.showSongList();

    int x = t.getRemainingMemory();
    cout << "Remaining memory: "<< x << "\n";


    return 0;


}