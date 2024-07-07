#include "../../header/game/game_rules.h"

int canPawnMove(board_a board, coord_s lastC, coord_s newC){
    int way = board[lastC.line][lastC.col].pieceColor == WHITE ? -1 : 1;

    return newC.line == lastC.line + way && newC.col == lastC.col;
}

int canBishopMove(board_a board, coord_s lastC, coord_s newC){
    return abs(newC.line - lastC.line) == abs(newC.col - lastC.col);
}