#include "../../header/game/game_utils.h"

int isPieceAndCurrentPlayer(board_a board, coord_s coord, int currentPlayer){
    if(isPiece(board, coord))
        return board[coord.line][coord.col].pieceColor == currentPlayer;
    return FALSE;
}

int isPiece(board_a board, coord_s coord){
    return board[coord.line][coord.col].piece != NO_PIECE;
}

int isSameColorPiece(board_a board, coord_s coord1, coord_s coord2){
    if(isPiece(board, coord1) && isPiece(board, coord2))
        return board[coord1.line][coord1.col].pieceColor == board[coord2.line][coord2.col].pieceColor;
    return FALSE;
}

int isDifferentColorPiece(board_a board, coord_s coord1, coord_s coord2){
    if(isPiece(board, coord1) && isPiece(board, coord2))
        return board[coord1.line][coord1.col].pieceColor != board[coord2.line][coord2.col].pieceColor;
    return FALSE;
}

int isPieceBetween(board_a board, coord_s coord1, coord_s coord2){
    /* Find the way on each axis, it can be 1, 0 or -1 */
    int wayLine = (coord2.line > coord1.line) - (coord2.line < coord1.line);
    int wayCol = (coord2.col > coord1.col) - (coord2.col < coord1.col);
    int line = coord1.line + wayLine;
    int col = coord1.col + wayCol;
    while (line != coord2.line || col != coord2.col){
        if(board[line][col].piece != NO_PIECE){
            return TRUE;
        }
        line += wayLine;
        col += wayCol;
    }
    return FALSE;
}