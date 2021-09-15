#include "Snake.h"
#include <iostream>

void Snake:: ReadCurrentPos(int l, int c, int d){
    currPos.facingDirection = d;
    currPos.l_pos = l;
    currPos.c_pos = c;
}

Direction Snake:: getCurrentPos(){
    return currPos;
}

void Snake:: setLives(int i){
    lives -= i;
}

int Snake:: getLives(){
    return lives;
}