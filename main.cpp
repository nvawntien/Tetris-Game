#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Tetris";
const int GRID_WIDTH = 300;
const int GRID_HEIGHT = 600;
const int GRID_X = (SCREEN_WIDTH - GRID_WIDTH) / 2;
const int GRID_Y = (SCREEN_HEIGHT - GRID_HEIGHT) / 2;
const int CELL_SIZE = 30;
const int ROWS = GRID_HEIGHT / CELL_SIZE;
const int COLS = GRID_WIDTH / CELL_SIZE;

void renderGrid(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i <= ROWS; i++) {
        SDL_RenderDrawLine(renderer, GRID_X, GRID_Y + i * CELL_SIZE, GRID_X + GRID_WIDTH, GRID_Y + i * CELL_SIZE);
    }
    for (int j = 0; j <= COLS; j++) {
        SDL_RenderDrawLine(renderer, GRID_X + j * CELL_SIZE, GRID_Y, GRID_X + j * CELL_SIZE, GRID_Y + GRID_HEIGHT);
    }
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cerr << "SDL could not initialize, SDL Error: " << SDL_GetError();
        return -1;
    }
    
    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                                        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 225);
        SDL_RenderClear(renderer);
        
        // draw grid cells
        renderGrid(renderer);
        
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    

    return 0;
}