//
// Created by Henoc Kabeya on 11/16/26.
//

#ifndef CIRCULAR_TEMPLATE_LIST_LAB_PODCATST_H
#define CIRCULAR_TEMPLATE_LIST_LAB_PODCATST_H

#include <iostream>
#include "Media.h"
using namespace std;

class Podcast : public Media {
private:
    string episodeTitle;
    string host;
    int episodeNumber;

public:
    Podcast(const string& t, const string& h, const int d, int epNum = 1)
        : Media(t, d), episodeTitle(t), host(h), episodeNumber(epNum) {}

    string toString() const override;
    void play() const override;
};

#endif //CIRCULAR_TEMPLATE_LIST_LAB_PODCATST_H
