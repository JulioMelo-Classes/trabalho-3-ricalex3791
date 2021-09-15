#include "Player.h"

#include <iostream>
#include <fstream>
#include <string>

#include <ctime>

using namespace std;

bool Player:: find_solution(int x, int y, int dir, const std::vector<std::string> maze, std::vector< std::vector <int> > visitado){
    bool solved = false;
    Direction newMove;
    if(maze[y][x] == '*'){
        cout<<"Encontrou comida"<<endl;
        return true;
    }

    // Cobra está indo para o sul
    if(maze[y+1][x] != '#' && dir != 1 && visitado[y+1][x] != 1){
        visitado[y][x] = 1;
        dir = 3;

        newMove.l_pos = y;
        newMove.c_pos = x;
        newMove.facingDirection = 3;

        direcoes.push_back(newMove);
        
        solved = find_solution(x, y+1, dir, maze, visitado);
        visitado[y][x] = 0;

        if(solved){
            return true;
        }
    }

    // Cobra está indo para o norte
    if(maze[y-1][x] != '#' && dir != 3 && visitado[y-1][x] != 1){
        visitado[y][x] = 1;
        dir = 1;

        newMove.l_pos = y;
        newMove.c_pos = x;
        newMove.facingDirection = 1;

        direcoes.push_back(newMove);

        solved = find_solution(x, y-1, dir, maze, visitado);
        visitado[y][x] = 0;

        if(solved){
            return true;
        }

    }

    // Cobra está indo para o leste
    if(maze[y][x+1] != '#' && dir != 4 && visitado[y][x+1] != 1){
        visitado[y][x] = 1;
        dir = 2;

        newMove.l_pos = y;
        newMove.c_pos = x;
        newMove.facingDirection = 2;

        direcoes.push_back(newMove);

        solved = find_solution(x+1, y, dir, maze, visitado);
        visitado[y][x] = 0;

        if(solved){
            return true;
        }
    }
    
    // Cobra está indo para o oeste
    if(maze[y][x-1] != '#' && dir != 2 && visitado[y][x-1] != 1){
        visitado[y][x] = 1;
        dir = 4;
        
        newMove.l_pos = y;
        newMove.c_pos = x;
        newMove.facingDirection = 4;

        direcoes.push_back(newMove);

        solved = find_solution(x-1, y, dir, maze, visitado);
        visitado[y][x] = 0;

        if(solved){
            return true;
        }
    }

    if(direcoes.size() > 0){
        direcoes.pop_back();
    }   
    
    return false;
}

Direction Player:: next_move(Snake snake)
{
    Direction newDirection;
    if(direcoes.size() != 0){
        newDirection = direcoes.front();
        return newDirection;
    }

    newDirection.l_pos = snake.getCurrentPos().l_pos;
    newDirection.c_pos = snake.getCurrentPos().c_pos;
    newDirection.facingDirection = snake.getCurrentPos().facingDirection;
    
    return newDirection;
}