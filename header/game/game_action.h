#ifndef GAME_ACTION_H
#define GAME_ACTION_H

#include "../types.h"

void selectOnePiece(SDL_Renderer* renderer, board_a board, coord_s coord);

void unselectOnePiece(SDL_Renderer* renderer, board_a board, coord_s coord);

#endif //GAME_ACTION_H