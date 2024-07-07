#ifndef GAME_RULES_H
#define GAME_RULES_H

#include "../types.h"

int canPawnMove(board_a board, coord_s lastC, coord_s newC);
int canBishopMove(board_a board, coord_s lastC, coord_s newC);
int canKnightMove(board_a board, coord_s lastC, coord_s newC);
int canRookMove(board_a board, coord_s lastC, coord_s newC);
int canQueenMove(board_a board, coord_s lastC, coord_s newC);
int canKingMove(board_a board, coord_s lastC, coord_s newC);


#endif //GAME_RULES_H