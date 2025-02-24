#include "libs/game.h"

int main(int argc, char* argv[]) {
    Util*  util = new Util;
    Tetris* player = new Tetris;

    util -> initSDL();
    while (player -> isRunning()) {
        player -> Event();
    }
    
    delete player;
    util -> quitSDL();
    delete util;
    return 0;
}