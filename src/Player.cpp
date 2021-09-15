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

Direction Player:: random_move(Snake snake, const std::vector<std::string> maze)
{
    Direction newDirection = snake.getCurrentPos();
    srand ((unsigned int)time(NULL));
    int directionChosen;

    //<! Embaralhar array
    int randomOrder[3];
    bool check=false;

    for(int i=0;i<3;i++){
        int num_toAdd=rand() % 3;
        for(int j=0; j<3;j++){
            if(num_toAdd == randomOrder[j]){
            check=true;
            break;
            }else{
            check=false;
            }
        }
        if(check==true){
            i--;
        }else{
            randomOrder[i]=num_toAdd;
        }
    }
    int movesTried=0;
    bool hasMoved=false;
    
    if(newDirection.facingDirection == 1 && hasMoved == false){ //Se estiver indo pro norte
        while(movesTried<3){
            if(randomOrder[movesTried] == 0){ //Continuar em linha reta
                if(maze[newDirection.l_pos-1][newDirection.c_pos] != '#'){
                    newDirection.l_pos-=1;
                    directionChosen=0;
                    hasMoved=true;
                    break;
                }
            }
            if(randomOrder[movesTried]==1){ //Ir para direita
                if(maze[newDirection.l_pos][newDirection.c_pos+1] != '#'){
                    newDirection.c_pos+=1;
                    newDirection.facingDirection=2;
                    directionChosen=1;
                    hasMoved=true;
                    break;
                }
            }
            if(randomOrder[movesTried]==2){ //Ir para esquerda
                if(maze[newDirection.l_pos][newDirection.c_pos-1] != '#'){
                    newDirection.c_pos-=1;
                    newDirection.facingDirection=4;
                    directionChosen=2;
                    hasMoved=true;
                    break;
                }
            }
            movesTried++;
            if(movesTried==3 && hasMoved==false){
                newDirection.facingDirection=-1;
                return newDirection;
            }
        }
    }

    if(newDirection.facingDirection == 2 && hasMoved == false){ //Se estiver indo pro Leste
        while(movesTried<3){
            if(randomOrder[movesTried] == 0){ //Continuar em linha reta
                if(maze[newDirection.l_pos][newDirection.c_pos+1] != '#'){
                    newDirection.c_pos+=1;
                    directionChosen=0;
                    hasMoved=true;
                    break;
                }
            }
            if(randomOrder[movesTried]==1){ //Ir para direita
                if(maze[newDirection.l_pos+1][newDirection.c_pos] != '#'){
                    newDirection.l_pos+=1;
                    newDirection.facingDirection=3;
                    directionChosen=1;
                    hasMoved=true;
                    break;
                }
            }
            if(randomOrder[movesTried]==2){ //Ir para esquerda
                if(maze[newDirection.l_pos-1][newDirection.c_pos] != '#'){
                    newDirection.l_pos-=1;
                    newDirection.facingDirection=1;
                    directionChosen=2;
                    hasMoved=true;
                    break;
                }
            }
            movesTried++;
            if(movesTried==3 && hasMoved==false){
                newDirection.facingDirection=-1;
                return newDirection;
            }
        }
    }

    if(newDirection.facingDirection == 3 && hasMoved == false){ //Se estiver indo pro Sul
        while(movesTried<3){
            if(randomOrder[movesTried] == 0){ //Continuar em linha reta
                if(maze[newDirection.l_pos+1][newDirection.c_pos] != '#'){
                    newDirection.l_pos+=1;
                    directionChosen=0;
                    hasMoved=true;
                    break;
                }
            }
            if(randomOrder[movesTried]==1){ //Ir para direita
                if(maze[newDirection.l_pos][newDirection.c_pos+1] != '#'){
                    newDirection.c_pos+=1;
                    newDirection.facingDirection=2;
                    directionChosen=1;
                    hasMoved=true;
                    break;
                }
            }
            if(randomOrder[movesTried]==2){ //Ir para esquerda
                if(maze[newDirection.l_pos][newDirection.c_pos-1] != '#'){
                    newDirection.c_pos-=1;
                    newDirection.facingDirection=4;
                    directionChosen=2;
                    hasMoved=true;
                    break;
                }
            }
            movesTried++;
            if(movesTried==3 && hasMoved==false){
                newDirection.facingDirection=-1;
                return newDirection;
            }
        }
    }

    if(newDirection.facingDirection == 4 && hasMoved == false){ //Se estiver indo pro Oeste
        while(movesTried<3){
            if(randomOrder[movesTried] == 0){ //Continuar em linha reta
                if(maze[newDirection.l_pos][newDirection.c_pos-1] != '#'){
                    newDirection.c_pos-=1;
                    directionChosen=0;
                    hasMoved=true;
                    break;
                }
            }
            if(randomOrder[movesTried]==1){ //Ir para direita
                if(maze[newDirection.l_pos-1][newDirection.c_pos] != '#'){
                    newDirection.l_pos-=1;
                    newDirection.facingDirection=1;
                    directionChosen=1;
                    hasMoved=true;
                    break;
                }
            }
            if(randomOrder[movesTried]==2){ //Ir para esquerda
                if(maze[newDirection.l_pos+1][newDirection.c_pos] != '#'){
                    newDirection.l_pos+=1;
                    newDirection.facingDirection=3;
                    directionChosen=2;
                    hasMoved=true;
                    break;
                }
            }
            movesTried++;
            if(movesTried==3 && hasMoved==false){
                newDirection.facingDirection=-1;
                return newDirection;
            }
        }
    }
    
    return newDirection;
}