#ifndef Player_h
#define Player_h
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Direction.h"

class Player {
    public:
        std::vector<Direction> direcoes; //<! Vetor com as direções a serem tomadas até a comida

        /*! Procura um caminho válido até a comida
				@param x, posição x da cobra
                @param y, posição y da cobra
                @param dir, direção da cobra
                @param maze, vector contendo o mapa
                @param visitado, vector contendo os locais que a cobra ja passou
				@return true se encontrou um caminho válido, false se não
		*/
        bool find_solution(int x, int y, int dir, const std::vector<std::string> maze, std::vector< std::vector <int> > visitado);
        /*! Procura um caminho válido até a comida
				@param snake cobra
				@return uma direção para a cobra com base na sequência de direções formada
		*/
        Direction next_move(Snake snake);

        /*! Procura um caminho válido até a comida
				@param snake cobra
                @param snake vector contendo o mapa
				@return uma direção para a cobra com base na sequência de direções formada
		*/
        Direction random_move(Snake snake, const std::vector<std::string> maze);
};

#endif 