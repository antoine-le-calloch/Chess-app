#include "../../header/sdl/sdl_events.h"

// Function to detect the SDL quit event
int isQuitEvent(SDL_Event* event) {
    return event->type == SDL_QUIT;
}

// Function to detect the SDL click event and the coord of the click
int isClickEvent(SDL_Event* event, coord_s* coord){
    if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT) {
        int test = SQUARE_SIZE;
        coord->col = event->button.x / SQUARE_SIZE;
        coord->line = event->button.y / SQUARE_SIZE;
        return coord->col >= 0 && coord->line >= 0 &&
            coord->col < BOARD_SIZE && coord->line < BOARD_SIZE;
    }
    return FALSE;
}