#include "../../header/game/game_rules.h"

int canPawnMove(board_a board, coord_s lastC, coord_s newC){
    int way = board[lastC.line][lastC.col].pieceColor == WHITE ? -1 : 1;
    int isFirstMove = way == 1 ? lastC.line == 1 : lastC.line == 6;
    if(newC.col == lastC.col)
        return newC.line == lastC.line + way || (isFirstMove && newC.line == lastC.line + 2 * way);
    return FALSE;
}

int canBishopMove(board_a board, coord_s lastC, coord_s newC){
    return abs(newC.line - lastC.line) == abs(newC.col - lastC.col);
}

int canRookMove(board_a board, coord_s lastC, coord_s newC){
    return newC.line == lastC.line || newC.col == lastC.col;
}