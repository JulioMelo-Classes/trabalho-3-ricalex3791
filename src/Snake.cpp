#include "Snake.h"
#include <iostream>

void Snake:: ReadCurrentPos(int l, int c, int d, int s){
    currPos.facingDirection = d;
    currPos.l_pos = l;
    currPos.c_pos = c;
    currPos.stuck = s;
}

Direction Snake:: getCurrentPos(){
    return currPos;
}