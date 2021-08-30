#ifndef Level_h
#define Level_h
#include <iostream>
#include <vector>

class Level {
    std::vector<std::string> levelMaze;
    
    
    public:
        Level(int argc, char *argv[]);
    private:
        void readMaze();
};

#endif 