#include "Snake.h"
#include <iostream>

void Snake:: ReadCurrentPos(int l, int c, int d){
    currPos.facingDirection = d;
    currPos.l_pos = l;
    currPos.c_pos = c;
}

void Snake:: ReadLastPos(Direction lastMove){
    pastPos.push_back(lastMove);
}

Direction Snake:: getCurrentPos(){
    return currPos;
}

std::vector<Direction> Snake:: getLastPos(){
    return pastPos;
}