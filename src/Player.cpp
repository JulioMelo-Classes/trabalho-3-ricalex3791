#include "Player.h"

#include <iostream>
#include <fstream>
#include <string>

#include <ctime>

using namespace std;

bool Player:: find_solution(Snake snake, const std::vector<std::string> maze){
    bool solved = false;
    Direction newDirection = snake.getCurrentPos();

    if(maze[newDirection.l_pos][newDirection.c_pos] == '*'){
        cout<<"Encontrou comida"<<endl;
        return true;
    }

    // Cobra está indo para o norte
    if(newDirection.facingDirection == 1){
        if(maze[newDirection.l_pos-1][newDirection.c_pos] != '#'){
            newDirection.l_pos-=1;
            //cout<<"porfavormeajuda"<<endl;
            newDirection.facingDirection=1;
            cout<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }

        if(maze[newDirection.l_pos][newDirection.c_pos+1] != '#'){
            newDirection.c_pos+=1;
            newDirection.facingDirection=2;
            cout<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }

        if(maze[newDirection.l_pos][newDirection.c_pos-1] != '#'){
            newDirection.c_pos-=1;
            newDirection.facingDirection=4;
            cout<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }

        return false;
    }

    // Cobra está indo para o Leste
    if(newDirection.facingDirection == 2){
        if(maze[newDirection.l_pos][newDirection.c_pos+1] != '#'){
            newDirection.c_pos+=1;
            //cout<<"porfavormeajuda"<<endl;
            newDirection.facingDirection=2;
            cout<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }

        if(maze[newDirection.l_pos+1][newDirection.c_pos] != '#'){
            newDirection.l_pos+=1;
            newDirection.facingDirection=3;
            cout<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }

        if(maze[newDirection.l_pos-1][newDirection.c_pos] != '#'){
            newDirection.l_pos-=1;
            newDirection.facingDirection=1;
            cout<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }

        return false;
    }

    // Cobra está indo para o Sul
    if(newDirection.facingDirection == 3){
        if(maze[newDirection.l_pos+1][newDirection.c_pos] != '#'){
            newDirection.l_pos+=1;
            //cout<<"porfavormeajuda"<<endl;
            newDirection.facingDirection=3;
            cout<<newDirection.facingDirection<<" Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }else if(maze[newDirection.l_pos][newDirection.c_pos-1] != '#'){
            newDirection.c_pos-=1;
            newDirection.facingDirection=4;
            cout<<newDirection.facingDirection<<" Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }else if(maze[newDirection.l_pos][newDirection.c_pos+1] != '#'){
            newDirection.c_pos+=1;
            newDirection.facingDirection=2;
            cout<<newDirection.facingDirection<<" Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }else if(newDirection.l_pos == 6 && newDirection.c_pos == 6){
            cout<<"END"<<endl;
            return false;
        }

        
    }

    // Cobra está indo para o Oeste
    if(newDirection.facingDirection == 4){
        if(maze[newDirection.l_pos][newDirection.c_pos-1] != '#'){
            newDirection.c_pos-=1;
            //cout<<"porfavormeajuda"<<endl;
            newDirection.facingDirection=4;
            cout<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }

        if(maze[newDirection.l_pos-1][newDirection.c_pos] != '#'){
            newDirection.l_pos-=1;
            newDirection.facingDirection=1;
            cout<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }

        if(maze[newDirection.l_pos+1][newDirection.c_pos] != '#'){
            newDirection.l_pos+=1;
            newDirection.facingDirection=3;
            cout<<"Posicao["<<newDirection.l_pos<<"]"<<"["<<newDirection.c_pos<<"]"<<endl;
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos, newDirection.facingDirection);
            direcoes.push_back(newDirection);
            solved = find_solution(snake, maze);

            if(solved){
                return true;
            }
        }
        return false;
    }

    

    return false;
}

Direction Player:: next_move(Snake snake, const std::vector<std::string> maze)
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

    // newDirection.l_pos = 5;
    // newDirection.c_pos = 5;
    // newDirection.facingDirection = 2;
    std::cout<<directionChosen<<std::endl;
    return newDirection;
}