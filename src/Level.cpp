#include "Level.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Level::Level(int argc, char *argv[]){
    ifstream levelFile;
    levelFile.open(argv[1], ios::in);

    int lineCount = 0;

    string line;
    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
            if(lineCount > 0){ //ignora a primeira linha já que ela contem informações que não são uteis para esse exemplo
                levelMaze.push_back(line);
            }
            lineCount++;
        }
    }
}