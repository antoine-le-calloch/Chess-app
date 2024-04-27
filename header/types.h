#ifndef TYPES_H
#define TYPES_H

// include libraries
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

// include constants
#include "constants.h"

typedef struct Coord {
    int line;
    int col;
} coord_s;

typedef struct sdl {
    SDL_Window *window;
    SDL_Renderer *renderer;
} sdl_s;

typedef int board_a[BOARD_SIZE][BOARD_SIZE];

#endif //TYPES_H