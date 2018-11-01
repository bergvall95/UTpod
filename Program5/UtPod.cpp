//
// Created by Naris on 10/23/2018.
//

#include "UtPod.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

UtPod::UtPod() { // blank constructor for allocating memory
    songs = NULL;
    memSize = MAX_MEMORY;

}

UtPod::UtPod(int size) { // constructor for actual ut pod
    songs = NULL;
    memSize = size;

}

int UtPod ::getRemainingMemory() {
    int sum = 0;
    SongNode *curr = songs;
    if(songs ==NULL) { // empty list becomes the new node
        return MAX_MEMORY;
    }

    while(1){
        sum = sum + curr -> s.getMemory();
        curr = curr -> next;
        if(curr == NULL){
            break;
        }

    }

    return memSize - sum;
}

int UtPod ::addSong(song const &s) { // add song function
    SongNode *temp = new SongNode;// temp song to add node
    temp -> s = s; // adding song
    temp -> next = NULL;// adding pointer to next
    SongNode *last = songs;

    if(getRemainingMemory()- s.getMemory() <= 0){ // checking remaining memory
        return NO_MEMORY;
    }
    if(songs ==NULL) { // special case for 0 songs
        songs = temp;
        return SUCCESS ;
    }



    while(last->next != NULL){ //navigating to add song to last part of UT pod
        last = last -> next;
    }
    last->next = temp;
    return  SUCCESS;
}

int UtPod ::removeSong(song const &s) { // removing song
    SongNode *temp = new SongNode; // temp song
    SongNode *check = songs; // works because in UT pod class
    SongNode *prev; // node for previous song
    if(songs ==NULL) { // if there are no songs, you cant find any
        return NOT_FOUND;
    }
    while(check != NULL){ // checking all songs
        string a = check -> s.getTitle(); // check for title
        string b = s.getTitle(); // checking for song to be removed's title
        string c = check -> s.getArtist();// check for artist
        string d = s.getArtist();// removed song's artist
        int m1 = check -> s.getMemory();// ^^
        int m2 = s.getMemory();
        if(a.compare(b) == 0 && c.compare(d) == 0 && m1 == m2){ // comparing strings
            temp = check->next;//incrementing temp
            if(check->next == NULL){// checking if at end of list.
                prev->next = NULL; // setting 2nd to last song's next to NULL
                delete(check); // actually deleting
                return SUCCESS;
            }
            else { // removing songs that arent at the end of the list
                check->s = temp->s;//checking song variables
                check->next = temp->next;// setting next
                delete(temp);// deleting song
                return SUCCESS;
            }
        }
        prev = check;//incrementing previous
        check = check -> next;// incrementing check

    }
    return  NOT_FOUND; // if the loop fails



}

void UtPod ::showSongList() { // showing song list

    SongNode *cur = songs;
    if(songs ==NULL) { // empty list becomes the new node
        cout << "No Songs";
        cout << "\n";
        return;
    }

    while(1){ // printing out formatted song
        cout << "Song: " << cur->s.getTitle();
        cout << "\n";
        cout << "Artist: " << cur->s.getArtist();
        cout << "\n";
        cout << "Size: " << cur->s.getMemory();
        cout << "\n";
        cout << "------------------------------------------------";
        cout << "\n";
        cur = cur -> next;
        if(cur == NULL){ // break if at the end of the list
            break;
        }

    }
    cout << "\n";

}

void UtPod ::shuffle() { // shuffling songs
    song n[getNumSongs()]; // array of songs
    int count = getNumSongs(); // counter for number of songs
    srand(time(NULL));// randomization seeded with current time (time will never be the same)
    SongNode *curr = songs;// setting pointer to beginning of songs
    if(songs ==NULL) { // empty list becomes the new node
        return;
    }

    while(1){

        while(1) {
            int x = rand() % getNumSongs(); // making sure random number will be within number of songs.
            string a = "";
            string b = n[x].getTitle(); // title of first randomized song
            if (a.compare(b) == 0) {
                n[x] = curr->s;
                break;
            }
        }
        curr = curr -> next;
        if(curr == NULL){
            break;
        }

    }

    SongNode *rep = songs;
    for(int i = 0; i<count; i++){
        rep->s = n[i];
        rep = rep->next;
    }


}

void UtPod ::sortSongList() { // sorting song list
    song n[getNumSongs()];
    int count = getNumSongs();
    SongNode *cur = songs; // setting pointer
    for (int i = 0; i < count; i++) {
        n[i] = cur->s; // copying array
        cur = cur->next;
    }
    for (int i = 0; i < count - 1; i++) { // checking artist name for all songs
        string a = n[i].getArtist();
        string b = n[i + 1].getArtist();
        if (b.compare(a) < 0) { // if a b
            song temp = n[i];//setting temp
            n[i] = n[i + 1];// swapping second song to first song
            n[i + 1] = temp; // swapping first  song into second song
            for (int j = i; j > 0; j--) { // swapping from i to beginning of array
                string c = n[j].getArtist();
                string d = n[j - 1].getArtist();
                if (c.compare(d) < 0) {
                    song temp2 = n[j - 1];
                    n[j - 1] = n[j];
                    n[j] = temp2;
                }
            }
        }
    }
    for (int i = 0; i < count - 1; i++) {
        string aa = n[i].getArtist();
        string bb = n[i + 1].getArtist();
        if (aa.compare(bb) == 0) { // if artists are the same  sort by title ( same algorithm but with step to check artist)
            string a = n[i].getTitle();
            string b = n[i + 1].getTitle();
            if (b.compare(a) < 0) {
                song temp = n[i];
                n[i] = n[i + 1];
                n[i + 1] = temp;
                for (int j = i; j > 0; j--) {
                    string cc = n[j].getArtist();
                    string dd = n[j - 1].getArtist();
                    if (cc.compare(dd) == 0) {
                        string c = n[j].getTitle();
                        string d = n[j - 1].getTitle();
                        if (c.compare(d) < 0) {
                            song temp2 = n[j - 1];
                            n[j - 1] = n[j];
                            n[j] = temp2;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < count - 1; i++) {
        string aa = n[i].getArtist();
        string bb = n[i + 1].getArtist();
        if (aa.compare(bb) == 0) {
            string aaa = n[i].getTitle();
            string bbb = n[i + 1].getTitle();
            if (aaa.compare(bbb) == 0) {// if artists and title are the same  sort by memory( same algorithm but with step to check artist and title)
                int a = n[i].getMemory();
                int b = n[i + 1].getMemory();
                if (b < a) {
                    song temp = n[i];
                    n[i] = n[i + 1];
                    n[i + 1] = temp;
                    for (int j = i; j > 0; j--) {
                        string cc = n[j].getArtist();
                        string dd = n[j - 1].getArtist();
                        if (cc.compare(dd) == 0) {
                            string ccc = n[j].getTitle();
                            string ddd = n[j - 1].getTitle();
                            if (ccc.compare(ddd) == 0) {// if artist and title are the same  sort by memory ( same algorithm but with step to check artist and title)
                                int c = n[j].getMemory();
                                int d = n[j - 1].getMemory();
                                if (c < d) {
                                    song temp2 = n[j - 1];
                                    n[j - 1] = n[j];
                                    n[j] = temp2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    SongNode *rep = songs;
    for (int i = 0; i < count; i++) {
        rep->s = n[i];
        rep = rep->next;
    }
}

void UtPod ::clearMemory() { // clearing all memory in the ut pod
    SongNode *temp = new SongNode;
    SongNode *check = songs;
    SongNode *prev;
    if(songs ==NULL) { // if no songs nothing to return.
        return;
    }
    while(check != NULL){ // delete until end of list
            temp = check->next;
            if(check->next == NULL){ // for end case
                prev->next = NULL;
                delete(check);
            }
            else { // for rest of cases
                check->s = temp->s;
                check->next = temp->next;
                delete(temp);
            }

            prev = check; // increments check
            check = check -> next;
        }
        songs = NULL;
}

UtPod::~UtPod(){ // deconstructor just calls clear memory and tries to print to show that nothing is there
    clearMemory();
    this->showSongList();

}






