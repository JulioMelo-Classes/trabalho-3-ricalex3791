#include "SnakeGame.h"
#include "Level.h"
#include "Snake.h"

#include <iostream>
#include <fstream>
#include <string>


#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;

SnakeGame::SnakeGame(int argc, char *argv[]){
    choice = "";
    frameCount = 0;
    initialize_game(argc, argv);
}

void SnakeGame::initialize_game(int argc, char *argv[]){
    //carrega o nivel ou os níveis
    //ifstream levelFile("data/maze1.txt"); //só dá certo se o jogo for executado dentro da raíz do diretório (vc vai resolver esse problema pegando o arquivo da linha de comando)

    ifstream levelFile;
    levelFile.open(argv[1], ios::in);

    int lineCount = 0;

    //Level firstLevel(argc, argv);
    //Snake snake;
    //snake.lives = 5;

    string line;
    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
            if(lineCount > 0){ //ignora a primeira linha já que ela contem informações que não são uteis para esse exemplo
                maze.push_back(line);
            }
            lineCount++;
        }
    }

    for(int i = 0; i < maze.size(); i++){
        for(int j = 0; j < maze[i].size(); j++){
            if(maze[i][j]=='*'){
                cout<<"chamando funcao de classe com posicoes "<<i<<j<<endl;
                snake.ReadCurrentPos(i, j);
            }
            
        }
    }

    cout<<"a posicao l eh "<<snake.getCurrentPos().l_pos<<endl;

    state = RUNNING;
}



void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case RUNNING:
            if(frameCount>0 && frameCount%10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
                state = WAITING_USER;
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    //system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:
            //desenha todas as linhas do labirinto
            // for(auto line : maze){
            //     cout<<line<<endl;
            // }
            l = snake.getCurrentPos().l_pos;
            c = snake.getCurrentPos().c_pos;

            for(int i = 0; i < maze.size(); i++){
                for(int j = 0; j < maze[i].size(); j++){
                    if(i==l && j==c){
                       cout<<"v";
                    }else{
                       cout<<maze[i][j];
                    }
                    //cout<<maze[i][j];
                    
                }
                cout<<endl;
            }
            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(500);// espera 0.5 segundo entre cada frame
    }
}
