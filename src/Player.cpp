#include "Player.h"

#include <iostream>
#include <fstream>
#include <string>

#include <random>       // std::default_random_engine
#include <time.h>



Direction Player:: next_move(Snake snake, const std::vector<std::string> maze)
{
    Direction newDirection = snake.getCurrentPos();
    srand (time(NULL));
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

    // for(int i=0;i<3;i++){
    //     std::cout<<randomOrder[i];
    // }
    // std::cout<<std::endl;
    
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
        }
    }

    // newDirection.l_pos = 5;
    // newDirection.c_pos = 5;
    // newDirection.facingDirection = 2;
    std::cout<<directionChosen<<std::endl;
    return newDirection;
}