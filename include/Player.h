#ifndef Player_h
#define Player_h
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Direction.h"

class Player {
    public:
        std::vector<Direction> direcoes; //<! Vetor com as direções a serem tomadas até a comida
        bool find_solution(int x, int y, int dir, const std::vector<std::string> maze, std::vector< std::vector <int> > visitado2);
        Direction next_move();
};

#endif 