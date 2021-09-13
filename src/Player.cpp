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
    direcoes.pop_back();
    return false;
}

Direction Player:: next_move(Snake snake, const std::vector<std::string> maze)
{
    Direction newDirection = snake.getCurrentPos();
    // srand ((unsigned int)time(NULL));
    // int directionChosen;

    // //<! Embaralhar array
    // int randomOrder[3];
    // bool check=false;

    // for(int i=0;i<3;i++){
    //     int num_toAdd=rand() % 3;
    //     for(int j=0; j<3;j++){
    //         if(num_toAdd == randomOrder[j]){
    //         check=true;
    //         break;
    //         }else{
    //         check=false;
    //         }
    //     }
    //     if(check==true){
    //         i--;
    //     }else{
    //         randomOrder[i]=num_toAdd;
    //     }
    // }
    // int movesTried=0;
    // bool hasMoved=false;

    // // for(int i=0;i<3;i++){
    // //     std::cout<<randomOrder[i];
    // // }
    // // std::cout<<std::endl;
    
    // if(newDirection.facingDirection == 1 && hasMoved == false){ //Se estiver indo pro norte
    //     while(movesTried<3){
    //         if(randomOrder[movesTried] == 0){ //Continuar em linha reta
    //             if(maze[newDirection.l_pos-1][newDirection.c_pos] != '#'){
    //                 newDirection.l_pos-=1;
    //                 directionChosen=0;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         if(randomOrder[movesTried]==1){ //Ir para direita
    //             if(maze[newDirection.l_pos][newDirection.c_pos+1] != '#'){
    //                 newDirection.c_pos+=1;
    //                 newDirection.facingDirection=2;
    //                 directionChosen=1;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         if(randomOrder[movesTried]==2){ //Ir para esquerda
    //             if(maze[newDirection.l_pos][newDirection.c_pos-1] != '#'){
    //                 newDirection.c_pos-=1;
    //                 newDirection.facingDirection=4;
    //                 directionChosen=2;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         movesTried++;
    //         if(movesTried==3 && hasMoved==false){
    //             newDirection.facingDirection=-1;
    //             return newDirection;
    //         }
    //     }
    // }

    // if(newDirection.facingDirection == 2 && hasMoved == false){ //Se estiver indo pro Leste
    //     while(movesTried<3){
    //         if(randomOrder[movesTried] == 0){ //Continuar em linha reta
    //             if(maze[newDirection.l_pos][newDirection.c_pos+1] != '#'){
    //                 newDirection.c_pos+=1;
    //                 directionChosen=0;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         if(randomOrder[movesTried]==1){ //Ir para direita
    //             if(maze[newDirection.l_pos+1][newDirection.c_pos] != '#'){
    //                 newDirection.l_pos+=1;
    //                 newDirection.facingDirection=3;
    //                 directionChosen=1;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         if(randomOrder[movesTried]==2){ //Ir para esquerda
    //             if(maze[newDirection.l_pos-1][newDirection.c_pos] != '#'){
    //                 newDirection.l_pos-=1;
    //                 newDirection.facingDirection=1;
    //                 directionChosen=2;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         movesTried++;
    //         if(movesTried==3 && hasMoved==false){
    //             newDirection.facingDirection=-1;
    //             return newDirection;
    //         }
    //     }
    // }

    // if(newDirection.facingDirection == 3 && hasMoved == false){ //Se estiver indo pro Sul
    //     while(movesTried<3){
    //         if(randomOrder[movesTried] == 0){ //Continuar em linha reta
    //             if(maze[newDirection.l_pos+1][newDirection.c_pos] != '#'){
    //                 newDirection.l_pos+=1;
    //                 directionChosen=0;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         if(randomOrder[movesTried]==1){ //Ir para direita
    //             if(maze[newDirection.l_pos][newDirection.c_pos+1] != '#'){
    //                 newDirection.c_pos+=1;
    //                 newDirection.facingDirection=2;
    //                 directionChosen=1;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         if(randomOrder[movesTried]==2){ //Ir para esquerda
    //             if(maze[newDirection.l_pos][newDirection.c_pos-1] != '#'){
    //                 newDirection.c_pos-=1;
    //                 newDirection.facingDirection=4;
    //                 directionChosen=2;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         movesTried++;
    //         if(movesTried==3 && hasMoved==false){
    //             newDirection.facingDirection=-1;
    //             return newDirection;
    //         }
    //     }
    // }

    // if(newDirection.facingDirection == 4 && hasMoved == false){ //Se estiver indo pro Oeste
    //     while(movesTried<3){
    //         if(randomOrder[movesTried] == 0){ //Continuar em linha reta
    //             if(maze[newDirection.l_pos][newDirection.c_pos-1] != '#'){
    //                 newDirection.c_pos-=1;
    //                 directionChosen=0;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         if(randomOrder[movesTried]==1){ //Ir para direita
    //             if(maze[newDirection.l_pos-1][newDirection.c_pos] != '#'){
    //                 newDirection.l_pos-=1;
    //                 newDirection.facingDirection=1;
    //                 directionChosen=1;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         if(randomOrder[movesTried]==2){ //Ir para esquerda
    //             if(maze[newDirection.l_pos+1][newDirection.c_pos] != '#'){
    //                 newDirection.l_pos+=1;
    //                 newDirection.facingDirection=3;
    //                 directionChosen=2;
    //                 hasMoved=true;
    //                 break;
    //             }
    //         }
    //         movesTried++;
    //         if(movesTried==3 && hasMoved==false){
    //             newDirection.facingDirection=-1;
    //             return newDirection;
    //         }
    //     }
    // }

    // // newDirection.l_pos = 5;
    // // newDirection.c_pos = 5;
    // // newDirection.facingDirection = 2;
    // std::cout<<directionChosen<<std::endl;
    return newDirection;
}