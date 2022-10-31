#ifndef LEVEL2_H
#define LEVEL2_H

#include "draw.h"

class Level2: public Draw //tämä on level 2 luokka joka perii Draw luokan
{
    int enemy2X;
    int enemy2Y;
    public:
    Level2();
    void draw();
    void setEnemy2Y();
    void setEnemy2X();
    void checkTouch();

};

#endif