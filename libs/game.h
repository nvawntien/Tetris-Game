#ifndef GAME_H
#define GAME_H
#include "config.h"

class Tetris {
    private:
        bool running = true;
    public:
        bool isRunning() { return running;}
        void Event();
};

#endif