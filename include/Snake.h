#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include "Direction.h"

class Snake {
    int size = 1;
    int lives = 5;
    Direction currPos;

    public:
        void ReadCurrentPos(int l, int c, int d, int s);
        Direction getCurrentPos();
};

#endif 