#include "../../header/game/game_utils.h"

int isPiece(board_a board, coord_s coord){
    return board[coord.line][coord.col].piece != NO_PIECE;
}

int isSameColorPiece(board_a board, coord_s coord1, coord_s coord2){
    if(isPiece(board, coord1) && isPiece(board, coord2))
        return board[coord1.line][coord1.col].pieceColor == board[coord2.line][coord2.col].pieceColor;
    return FALSE;
}