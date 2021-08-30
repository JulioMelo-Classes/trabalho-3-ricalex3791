#include "Snake.h"
#include <iostream>

void Snake:: ReadCurrentPos(int l, int c){
    currPos.facingDirection = 1;
    currPos.l_pos = l;
    currPos.c_pos = c;
}

Direction Snake:: getCurrentPos(){
    return currPos;
}