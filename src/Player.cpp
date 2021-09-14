#include "Player.h"

#include <iostream>
#include <fstream>
#include <string>

#include <ctime>

using namespace std;

bool Player:: find_solution(int x, int y, int dir, const std::vector<std::string> maze, std::vector< std::vector <int> > visitado2){
    bool solved = false;
    int dirTried = 0;
    //cout<<"posicao l teste"<<snake.getCurrentPos().l_pos<<endl;
    Direction newMove;
    //snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
    if(maze[y][x] == '*'){
        cout<<"Encontrou comida"<<endl;
        return true;
    }

    //Ao invés de mexer com a posição da cobra, apenas passar um valor

    if(maze[y+1][x] != '#' && dir != 1 && visitado2[y+1][x] != 1){
        //newDirection.l_pos+=1;
        visitado2[y][x] = 1;
        dir = 3;
        newMove.l_pos = y;
        newMove.c_pos = x;
        newMove.facingDirection = 3;
        direcoes.push_back(newMove);
        cout<<dir<<"Posicao["<<y<<"]"<<"["<<x<<"]"<<endl;
        
        solved = find_solution(x, y+1, dir, maze, visitado2);
        visitado2[y][x] = 0;

        //cout<<"Antes de checar o retorno temos "<<snake.getCurrentPos().facingDirection<<" Posicao["<<snake.getCurrentPos().l_pos<<"]"<<"["<<snake.getCurrentPos().c_pos<<"]"<<endl;
        if(solved){
            return true;
        }
        // else{
            
        //     cout<<"No retorno temos "<<snake.getCurrentPos().facingDirection<<"Posicao["<<snake.getCurrentPos().l_pos<<"]"<<"["<<snake.getCurrentPos().c_pos<<"]"<<endl;
        // }
    }

    // Cobra está indo para o norte
    if(maze[y-1][x] != '#' && dir != 3 && visitado2[y-1][x] != 1){
        //newDirection.l_pos-=1;
        visitado2[y][x] = 1;
        dir = 1;
        newMove.l_pos = y;
        newMove.c_pos = x;
        newMove.facingDirection = 1;
        direcoes.push_back(newMove);
        cout<<dir<<"Posicao["<<y<<"]"<<"["<<x<<"]"<<endl;
        //cout<<snake.getCurrentPos().facingDirection<<"Posicao["<<snake.getCurrentPos().l_pos<<"]"<<"["<<snake.getCurrentPos().c_pos<<"]"<<endl;
        //direcoes.push_back(snake.getCurrentPos());
        cout<<"Hehe "<<direcoes.size()<<endl;
        solved = find_solution(x, y-1, dir, maze, visitado2);
        visitado2[y][x] = 0;

        if(solved){
            return true;
        }
        // else{
        //     cout<<newDirection.facingDirection<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
        //     snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
        //     return false;
        // }
    }

    if(maze[y][x+1] != '#' && dir != 4 && visitado2[y][x+1] != 1){
        visitado2[y][x] = 1;
        dir = 2;
        newMove.l_pos = y;
        newMove.c_pos = x;
        newMove.facingDirection = 2;
        direcoes.push_back(newMove);
        //cout<<snake.getCurrentPos().facingDirection<<"Posicao["<<snake.getCurrentPos().l_pos<<"]"<<"["<<snake.getCurrentPos().c_pos<<"]"<<endl;
        //direcoes.push_back(snake.getCurrentPos());
        cout<<dir<<"Posicao["<<y<<"]"<<"["<<x<<"]"<<endl;
        solved = find_solution(x+1, y, dir, maze, visitado2);
        visitado2[y][x] = 0;

        if(solved){
            return true;
        }
    }
    
    if(maze[y][x-1] != '#' && dir != 2 && visitado2[y][x-1] != 1){
        visitado2[y][x] = 1;
        dir = 4;
        //cout<<snake.getCurrentPos().facingDirection<<"Posicao["<<snake.getCurrentPos().l_pos<<"]"<<"["<<snake.getCurrentPos().c_pos<<"]"<<endl;
        //direcoes.push_back(snake.getCurrentPos());
        newMove.l_pos = y;
        newMove.c_pos = x;
        newMove.facingDirection = 4;
        direcoes.push_back(newMove);
        cout<<dir<<"Posicao["<<y<<"]"<<"["<<x<<"]"<<endl;
        solved = find_solution(x-1, y, dir, maze, visitado2);
        visitado2[y][x] = 0;

        if(solved){
            return true;
        }
    }

    //cout<<"END "<<snake.getCurrentPos().facingDirection<<" Posicao["<<snake.getCurrentPos().l_pos<<"]"<<"["<<snake.getCurrentPos().c_pos<<"]"<<endl;
    cout<<"END "<<dir<<" Posicao["<<y<<"]"<<"["<<x<<"]"<<endl;
    if(direcoes.size() > 0){
        direcoes.pop_back();
    }   
    
    return false;
}

Direction Player:: next_move()
{
    Direction newDirection;
    if(direcoes.size() != 0){
        newDirection = direcoes.front();
        return newDirection;
    }

    newDirection.l_pos = 2;
    newDirection.c_pos = 2;
    newDirection.facingDirection = 1;
    
    return newDirection;
}