#include "SnakeGame.h"
#include "Snake.h"
#include "Player.h"

#include <iostream>
#include <fstream>
#include <string>
#include<sstream>


#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep
#include <ctime>

using namespace std;

SnakeGame::SnakeGame(int argc, char *argv[]){
    choice = "";
    frameCount = 0;
    initialize_game(argc, argv);
}

void SnakeGame::initialize_game(int argc, char *argv[]){
    mazeSizeX = 0;
    mazeSizeY = 0;
    //carrega o nivel ou os níveis
    ifstream levelFile;
    levelFile.open(argv[1], ios::in);
    int lineCount = 0;
    string line;

    int counter;
    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
            //Lê informações do mapa
            istringstream iss(line);
            if(lineCount==0){
                istringstream ss(line);
                string del;
                counter=0;
                    while(getline(ss, del, ' ')) {
                    string fs(del);

                    if(counter == 0 ){
                        mazeSizeX = stoi(del);
                    }
                    if(counter == 1){
                        mazeSizeY = stoi(del);
                    }
                    if(counter == 2){
                        scoreToWin = stoi(del);
                    }
                    counter++;
                }
            }

            if(lineCount > 0){ //ignora a primeira linha já que ela contem informações que não são uteis para esse exemplo
                maze.push_back(line);
                
            }
            lineCount++;
        }
    }
    place_snake();

    // Define posição inicial da cobra
    for(unsigned int i = 0; i < maze.size(); i++){
        for(unsigned int j = 0; j < maze[i].size(); j++){
            if(maze[i][j]=='v'){
                maze[i][j]=' ';
                snake.ReadCurrentPos(i, j, 1);
            }
        }
    }

    // Define posição da primeira comida
    place_food();

    cout<<"O tamanho do mapa eh ["<<mazeSizeX<<"]["<<mazeSizeY<<"]"<<endl;

    cout<<"mudando state"<<endl;

    state = RUNNING;
}

void SnakeGame::place_food(){
    srand ( (unsigned int)time(NULL));
    bool foodPlaced=false;
    int randX;
    int randY;
    while(foodPlaced == false){
        randX = rand() % mazeSizeX;
        randY = rand() % mazeSizeY;
        if(maze[randX][randY] == ' '){
            maze[randX][randY] = '*';
            foodL = randX;
            foodC = randY;
            foodPlaced = true;
        }
    }
}

void SnakeGame::place_snake(){
    srand ( (unsigned int)time(NULL));
    bool snakePlaced=false;
    int randX;
    int randY;
    while(snakePlaced == false){
        randX = rand() % mazeSizeX;
        randY = rand() % mazeSizeY;
        if(maze[randX][randY] == ' ' && maze[randX][randY-1] != '#'){
            maze[randX][randY] = 'v';
            snakePlaced = true;
        }
    }
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
            if(score >= scoreToWin){
                state = GAME_OVER;
                game_over();
            }

            x = snake.getCurrentPos().c_pos;
            y = snake.getCurrentPos().l_pos;
            dir = snake.getCurrentPos().facingDirection;

            //Inicializa matriz de locais visitados
            for(int i=0; i<mazeSizeX; i++)
            {
                std::vector <int> visitadoCol;
                for(int j=0; j<mazeSizeY; j++)
                {
                    visitadoCol.push_back( 0 );
                }
                visitado2.push_back(visitadoCol);
            }

            tempResult = player.find_solution(x, y, dir, maze, visitado2);
            if(tempResult){
                cout<<"ENCONTROU SOLUCAO"<<endl;
                state = RENDERING;
            }else{
                cout<<"Nao foram encontradas solucoes"<<endl;
                state = GAME_OVER;
                game_over();
            }


            // if(frameCount>0 && frameCount%1 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
            //     state = WAITING_USER;
            break;
        case RENDERING:
            Direction newDirection;
            newDirection = player.next_move(snake);
            snake.ReadCurrentPos(newDirection.l_pos, newDirection.c_pos,newDirection.facingDirection);

            if(player.direcoes.size()!=0){
                player.direcoes.erase(player.direcoes.begin());
            }else{
                score++;
                maze[foodL][foodC] = ' ';
                snake.ReadCurrentPos(foodL, foodC,newDirection.facingDirection);
                place_food();
                
                state = RUNNING;
            }

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
    system("cls");
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
            cout<< "Calculando Movimentos"<<endl;
            break;
        case RENDERING:
            cout << "----------------------------------------" << endl;
            cout << "Sua pontuaçao eh: " << score << endl;
            cout << "Restam movimentos: "<< player.direcoes.size() << endl;
            cout << "Pontos para vencer: "<< (scoreToWin-score) << endl;
            cout << "----------------------------------------" << endl;
            //desenha todas as linhas do labirinto
            l = snake.getCurrentPos().l_pos;
            c = snake.getCurrentPos().c_pos;

            

            char snakeHead;
            if(snake.getCurrentPos().facingDirection == 1){
                snakeHead = 'v';
            }else if(snake.getCurrentPos().facingDirection == 2){
                snakeHead = '<';
            }else if(snake.getCurrentPos().facingDirection == 3){
                snakeHead = '^';
            }else if(snake.getCurrentPos().facingDirection == 4){
                snakeHead = '>';
            }

            for(unsigned int i = 0; i < maze.size(); i++){
                for(unsigned int j = 0; j < maze[i].size(); j++){
                    if(i==l && j==c){
                       cout<<snakeHead;
                    }else{
                       cout<<maze[i][j];
                    }
                    
                }
                cout<<endl;
            }
            break;
        case WAITING_USER:
            cout<<"Sua pontuação eh: " << score << ". Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            for(unsigned int i = 0; i < maze.size(); i++){
                for(unsigned int j = 0; j < maze[i].size(); j++){
                    if(i==l && j==c){
                       cout<<'x';
                    }else{
                       cout<<maze[i][j];
                    }
                    
                }
                cout<<endl;
            }
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
    cout<<"Desculpe, voce perdeu!"<<endl;
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(100);// espera 1 segundo entre cada frame
    }
}
