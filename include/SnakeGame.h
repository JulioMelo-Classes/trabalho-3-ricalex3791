#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Player.h"


class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING, //<! quando o jogo está executando o estado é RUNNING
            RENDERING,
            GAME_OVER, //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
        };

    private:
        //<! atributos adicione outros se quiser
        int l,c; //<! usados no desenho do mapa
        int m[2],n[2];
        bool tempResult; //<! verifica se a cobra encontrou um caminho válido até a comida
        int x,y,dir; //<! usados para guardar a posição da cobra
        int mazeSizeX, mazeSizeY; //<! guarda o tamnho do mapa

        std::vector<std::string> maze; //<! vector contendo o labirinto atual, pode ser interpretado como uma matriz
        std::vector< std::vector <int> > visitado2; //<! vector contendo os caminhos que a cobra já passou

        int frameCount; //<! contador de frames, usado apenas como exemplo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo
        

        int score=0; //<! score atual
        int scoreToWin; //<! score necessário para fechar o mapa

        int foodL, foodC; //<! posições da comida no mapa

        Snake snake; //<! Cria a cobra
        Player player;

    public:
        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame(int argc, char *argv[]);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game(int argc, char *argv[]);

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief coloca a comida em uma posição aleatória válida no mapa
        **/
        void place_food();

        /**
        * @brief coloca o jogador em uma posição aleatória válida no mapa
        **/
        void place_snake();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h