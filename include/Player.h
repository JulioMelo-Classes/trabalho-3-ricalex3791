#ifndef Player_h
#define Player_h
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Direction.h"

class Player {
    bool find_solution();
    public:
        Direction next_move(Snake snake, const std::vector<std::string> maze);
};

#endif 