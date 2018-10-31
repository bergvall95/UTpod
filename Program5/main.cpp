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
    if(num < 0 || num >512){
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

    song s8("Post Malone","Congratulations",2);
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

    song s14("Post Malone","White Iverson",17);
    results = t.addSong(s14);
    cout << "Adding " << s14.getTitle() << " = " << results << "\n";

    song s15("Toto","Africa", 13);
    results = t.addSong(s15);
    cout << "Adding " << s15.getTitle() << " = " << results << "\n";


    while(1) {
        int com;
        cout << "Please enter action (1 = add, 2 = remove, 3 = shuffle, 4 = sort, 5 = show, 6 = memory, or any other key = exit): ";
        cout << "\n";
        cin >> com;
        cout << "\n";
        if(com == 1){
            string art;
            string til;
            int s;
            cout << "Please enter artist: ";
            cout << "\n";
            cin.ignore();
            getline(cin, art);
            cout << "\n";
            cout << "Please enter title: ";
            cout << "\n";
            getline(cin, til);
            cout << "\n";
            cout << "Please enter size: ";
            cout << "\n";
            cin >> s;
            song n(art,til,s);
            results = t.addSong(n);
            cout << "Adding " << n.getTitle() << " = " << results << "\n";
        }
        else if(com == 2){
            string art;
            string til;
            int s;
            cout << "Please enter artist: ";
            cout << "\n";
            cin.ignore();
            getline(cin, art);
            cout << "\n";
            cout << "Please enter title: ";
            cout << "\n";
            getline(cin, til);
            cout << "\n";
            cout << "Please enter size: ";
            cout << "\n";
            cin >> s;
            cout << "\n";
            song n(art,til,s);
            results = t.removeSong(n);
            cout << "Deleting " << n.getTitle() << " = " << results << "\n";
        }
        else if(com == 3){
            t.shuffle();
        }

        else if(com == 4){
            t.sortSongList();
        }

        else if(com == 5){
            t.showSongList();
        }

        else if(com == 6){
            int x = t.getRemainingMemory();
            cout << "Remaining memory: "<< x << "\n";
        }

        else{
            break;
        }

    }

    return 0;
}