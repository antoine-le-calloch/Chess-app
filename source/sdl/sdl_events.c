#include "../../header/sdl/sdl_events.h"

// Function to detect the SDL quit event
int isQuitEvent(SDL_Event* event) {
    while (SDL_PollEvent(event)) {
        if (event->type == SDL_QUIT) {
            return TRUE;
        }
    }
    return FALSE;
}

/*
// Function to detect the click event and return the coordinates of the click
coord_s isClickEvent(SDL_Event* event, SDL_Renderer* renderer){
    coord_s coord = {0, 0};
    while (1) {
        SDL_WaitEvent(event);
        if (event->type == SDL_QUIT) {
            return coord;
        }
        if (event->type == SDL_MOUSEBUTTONDOWN) {
            coord.col = event->button.x / SQUARE_SIZE;
            coord.line = event->button.y / SQUARE_SIZE;
            return coord;
        }
    }
}*/
