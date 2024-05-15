#include "../../header/sdl/sdl_setup.h"

// Function to set up a SDL window and renderer
int sdlSetup(sdl_s* sdlPtr){
    // Init SDL
    SDL_Init(SDL_INIT_VIDEO);
    sdlPtr->window = SDL_CreateWindow("Chessboard", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    sdlPtr->renderer = SDL_CreateRenderer(sdlPtr->window, -1, SDL_RENDERER_ACCELERATED);

    if (sdlPtr->window == NULL || sdlPtr->renderer == NULL) {
        if (sdlPtr->window == NULL) {
            SDL_Log("Failed to create window: %s", SDL_GetError());
            SDL_DestroyWindow(sdlPtr->window);
        }else if (sdlPtr->renderer == NULL) {
            SDL_Log("Failed to create renderer: %s", SDL_GetError());
            SDL_DestroyRenderer(sdlPtr->renderer);
        }
        SDL_Quit();
        return 0;
    }
    return 1;
}

// Function to quit properly the SDL window and destroy renderer
void sdlQuit(sdl_s* sdlPtr) {
    // Free resources and quit SDL
    SDL_DestroyRenderer(sdlPtr->renderer);
    SDL_DestroyWindow(sdlPtr->window);
    SDL_Quit();
}