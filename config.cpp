#include "libs/config.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Tetris";

void Util :: logSDLError(const std::string msg, bool check) {
    std :: cerr << msg << " Error: " << SDL_GetError() << std::endl;
    if (check) {
        SDL_Quit();
        exit(1);
    }
}

void Util :: initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        logSDLError("Init", true);
    }

    window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError("Create Window", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) logSDLError("Create Renderer", true);
}

void Util :: quitSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}