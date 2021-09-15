#ifndef Snake_h
#define Snake_h
#include <iostream>
#include <vector>
#include "Direction.h"

class Snake {
    int size = 1; //<! Tamanho atual da cobra
    int lives = 5; //<! vidas restantes
    Direction currPos; //<! posição atual

    public:
        /*! lê a posição atual da cobra
				@param l linha da matriz
                @param c coluna da matriz
                @param d direção da cobra
		*/
        void ReadCurrentPos(int l, int c, int d); 

        /*!
				@return a posição atual da cobra
		*/
        Direction getCurrentPos();

        void setLives(int i);
		int getLives();
};

#endif 