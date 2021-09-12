#ifndef Player_h
#define Player_h
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Direction.h"

class Player {
    

    
    public:
        std::vector<Direction> direcoes; //<! Vetor com as direções a serem tomadas até a comida
        bool find_solution(Snake snake, const std::vector<std::string> maze);
        Direction next_move(Snake snake, const std::vector<std::string> maze);
};

#endif 