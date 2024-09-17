#include "../../header/sdl/sdl_functions.h"
#include "../../header/game/game_movement.h"
#include "../../header/game/game_rules.h"
#include "../../header/game/game_action.h"
#include "../../header/game/game_utils.h"

int isMovePossible(board_a board, coord_s lastC, coord_s newC){
    if(isSameColorPiece(board, lastC, newC)) {
        return FALSE;
    }
    switch (board[lastC.line][lastC.col].piece) {
        case PAWN:
            return canPawnMove(board, lastC, newC);
        case BISHOP:
            return canBishopMove(board, lastC, newC);
        case KNIGHT:
            return canKnightMove(board, lastC, newC);
        case ROOK:
            return canRookMove(board, lastC, newC);
        case QUEEN:
            return canQueenMove(board, lastC, newC);
        case KING:
            return canKingMove(board, lastC, newC);
        default:
            return FALSE;
    }
}

void updateBoard(board_a board, coord_s lastC, coord_s newC){
    board[newC.line][newC.col].piece = board[lastC.line][lastC.col].piece;
    board[newC.line][newC.col].pieceColor = board[lastC.line][lastC.col].pieceColor;
    board[lastC.line][lastC.col].piece = NO_PIECE;
}

void rollbackBoard(board_a board, coord_s baseC, coord_s updateC){
    board[baseC.line][baseC.col].piece = board[updateC.line][updateC.col].piece;
    board[baseC.line][baseC.col].pieceColor = board[updateC.line][updateC.col].pieceColor;
    board[updateC.line][updateC.col].piece = NO_PIECE;
}

void updateDisplay(SDL_Renderer* renderer, board_a board, coord_s lastCoord, coord_s newCoord){
    // update the last position square
    unselectOnePiece(renderer, board, lastCoord);

    square_s newSquare = board[newCoord.line][newCoord.col];
    // Remove the piece from new position if there is one
    if(newSquare.piece != NO_PIECE)
        colorOneSquare(renderer, SQUARE(newCoord.col, newCoord.line), newSquare.color);

    // Add the piece to the new position
    SDL_Rect square = SQUARE(newCoord.col, newCoord.line);
    addASurface(renderer, piecesSurfaces[newSquare.pieceColor][newSquare.piece], square);
}

int moveOnePiece(SDL_Renderer* renderer, board_a board, coord_s lastCoord, coord_s newCoord){
    if(isMovePossible(board, lastCoord, newCoord)){
        updateBoard(board, lastCoord, newCoord);
        if(isCheck(board, board[lastCoord.line][lastCoord.col].pieceColor)){
            rollbackBoard(board, lastCoord, newCoord);
        }else{
            updateDisplay(renderer, board, lastCoord, newCoord);
            return TRUE;
        }
    }
    unselectOnePiece(renderer, board, lastCoord);
    return FALSE;
}
