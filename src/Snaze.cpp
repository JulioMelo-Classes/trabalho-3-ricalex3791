#include <iostream>
#include "SnakeGame.h"
#include "Snake.h"
#include "Player.h"

using namespace std;

int main(int argc, char *argv[]){
    SnakeGame game(argc, argv);
    
    game.loop(); //bloqueia aqui e só saí quando o jogo termina

    return 0;
}