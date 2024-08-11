#include "../../header/game/game_rules.h"
#include "../../header/game/game_utils.h"

int canPawnMove(board_a board, coord_s lastC, coord_s newC){
    int way = board[lastC.line][lastC.col].pieceColor == WHITE ? -1 : 1;

    if(isDifferentColorPiece(board, lastC, newC)){
        return newC.line == lastC.line + way && (newC.col == lastC.col + 1 || newC.col == lastC.col - 1);
    }else if (newC.col == lastC.col){
        int isFirstMove = way == 1 ? lastC.line == 1 : lastC.line == 6;
        return newC.line == lastC.line + way || (isFirstMove && newC.line == lastC.line + 2 * way);
    }
    return FALSE;
}

int canBishopMove(board_a board, coord_s lastC, coord_s newC){
    if(abs(newC.line - lastC.line) == abs(newC.col - lastC.col)){
        return !isPieceBetween(board, lastC, newC);
    }
    return FALSE;
}

int canKnightMove(board_a board, coord_s lastC, coord_s newC){
    int dLine = abs(newC.line - lastC.line);
    int dCol = abs(newC.col - lastC.col);
    return (dLine == 2 && dCol == 1) || (dLine == 1 && dCol == 2);
}

int canRookMove(board_a board, coord_s lastC, coord_s newC){
    if(newC.line == lastC.line || newC.col == lastC.col){
        return !isPieceBetween(board, lastC, newC);
    }
    return FALSE;
}

int canQueenMove(board_a board, coord_s lastC, coord_s newC){
    return canBishopMove(board, lastC, newC) || canRookMove(board, lastC, newC);
}

int canKingMove(board_a board, coord_s lastC, coord_s newC){
    int dLine = abs(newC.line - lastC.line);
    int dCol = abs(newC.col - lastC.col);
    return dLine <= 1 && dCol <= 1;
}