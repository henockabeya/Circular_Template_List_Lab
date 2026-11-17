//
// Created by Henoc Kabeya on 11/14/26.
//

#ifndef CIRCULAR_TEMPLATE_LIST_LAB_SONG_H
#define CIRCULAR_TEMPLATE_LIST_LAB_SONG_H
#include <__fwd/string.h>
#include <iostream>
#include "Media.h"
#include <string>
using namespace std;

class Song: public Media {
    private:
    string artist;

    public:
    Song (const string& t, const string& a, int d): Media(t,d),artist(a){}
    string getArtist() const;
    string toString () const override;
    void play() const override;

};

#endif //CIRCULAR_TEMPLATE_LIST_LAB_SONG_H
