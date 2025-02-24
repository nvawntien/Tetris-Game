#ifndef CONFIG_H
#define CONFIG_H
#include <SDL2/SDL.h>
#include <iostream>

extern const int SCREEN_WIDH;
extern const int SCREEN_HEIGHT;
extern const char* WINDOW_TITLE;


struct Util {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    void logSDLError(const std :: string , bool);
    void initSDL();
    void quitSDL();
};

#endif