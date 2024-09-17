#include "../../header/game/game_utils.h"
#include "../../header/game/game_movement.h"

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

coord_s findKing(board_a board, int kingColor){
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].piece == KING && board[i][j].pieceColor == kingColor){
                coord_s kingCoord = {i, j};
                return kingCoord;
            }
        }
    }
}

int isKingInCheck(board_a board, int kingColorToCheck) {
    coord_s kingCoord = findKing(board, kingColorToCheck);
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            coord_s pieceCoord = {i,j};
            if(board[pieceCoord.line][pieceCoord.col].pieceColor != kingColorToCheck &&
                isMovePossible(board, pieceCoord, kingCoord)){
                return TRUE;
            }
        }
    }
    return FALSE;
}