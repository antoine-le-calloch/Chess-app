#ifndef GAME_MOVEMENT_H
#define GAME_MOVEMENT_H

#include "../types.h"

int moveOnePiece(SDL_Renderer* renderer, board_a board, coord_s lastCoord, coord_s newCoord);
int isMovePossible(board_a board, coord_s lastC, coord_s newC);

#endif //GAME_MOVEMENT_H