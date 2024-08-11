#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include "../types.h"

int isPieceCurrentPlayer(board_a board, coord_s coord, int currentPlayer);

int isPiece(board_a board, coord_s coord);

int isSameColorPiece(board_a board, coord_s coord1, coord_s coord2);

int isDifferentColorPiece(board_a board, coord_s coord1, coord_s coord2);

int isPieceBetween(board_a board, coord_s coord1, coord_s coord2);

#endif //GAME_UTILS_H