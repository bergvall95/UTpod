//
// Created by Naris on 10/23/2018.
//

#include "UtPod.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

UtPod::UtPod() {
    songs = NULL;
    memSize = MAX_MEMORY;

}

UtPod::UtPod(int size) {
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

int UtPod ::addSong(song const &s) {
    SongNode *temp = new SongNode;
    temp -> s = s;
    temp -> next = NULL;
    SongNode *last = songs;

    if(getRemainingMemory()- s.getMemory() <= 0){
        return NO_MEMORY;
    }
    if(songs ==NULL) {
        songs = temp;
        return SUCCESS ;
    }



    while(last->next != NULL){
        last = last -> next;
    }
    last->next = temp;
    //free(temp);
    return  SUCCESS;
}

int UtPod ::removeSong(song const &s) {
    SongNode *temp = new SongNode;
    SongNode *check = songs;
    if(songs ==NULL) {
        return NOT_FOUND;
    }
    while(check->next != NULL){
        string a = check -> s.getTitle();
        string b = s.getTitle();
        string c = check -> s.getArtist();
        string d = s.getArtist();
        int m1 = check -> s.getMemory();
        int m2 = s.getMemory();
        if(a.compare(b) == 0 && c.compare(d) == 0 && m1 == m2){
            temp = check->next;
            check->s = temp->s;
            check->next = temp->next;
            free(temp);
            return SUCCESS;
        }
        check = check -> next;

    }
    return  NOT_FOUND;



}

void UtPod ::showSongList() {

    SongNode *cur = songs;
    if(songs ==NULL) { // empty list becomes the new node
        cout << "No Songs";
        return;
    }

    while(1){
        cout << "Song: " << cur->s.getTitle();
        cout << "\n";
        cout << "Artist: " << cur->s.getArtist();
        cout << "\n";
        cout << "Size: " << cur->s.getMemory();
        cout << "\n";
        cout << "------------------------------------------------";
        cout << "\n";
        cur = cur -> next;
        if(cur == NULL){
            break;
        }

    }
    cout << "\n";

}

void UtPod ::shuffle() {
    song n[getNumSongs()];
    int count = getNumSongs();
    srand(time(NULL));
    SongNode *curr = songs;
    if(songs ==NULL) { // empty list becomes the new node
        return;
    }

    while(1){

        while(1) {
            int x = rand() % getNumSongs();
            string a = "";
            string b = n[x].getTitle();
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

void UtPod ::sortSongList() {
    song n[getNumSongs()];
    int count = getNumSongs();
    SongNode *cur = songs;
    for (int i = 0; i < count; i++) {
        n[i] = cur->s;
        cur = cur->next;
    }
    for (int i = 0; i < count - 1; i++) {
        string a = n[i].getArtist();
        string b = n[i + 1].getArtist();
        if (b.compare(a) < 0) {
            song temp = n[i];
            n[i] = n[i + 1];
            n[i + 1] = temp;
            for (int j = i; j > 0; j--) {
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
        if (aa.compare(bb) == 0) {
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
            if (aaa.compare(bbb) == 0) {
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
                            if (ccc.compare(ddd) == 0) {
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

void UtPod ::clearMemory() {
    SongNode *check = songs;
    if(songs ==NULL) {
        return;
    }
    while(check->next != NULL){

        free(check);
        check = check -> next;

    }
    songs = NULL;
}
UtPod::~UtPod(){
    clearMemory();
    this->showSongList();

}






