#include "../../header/sdl/sdl_functions.h"
#include "../../header/game/game_movement.h"
#include "../../header/game/game_rules.h"
#include "../../header/game/game_action.h"

int isMovePossible(board_a board, coord_s lastC, coord_s newC){
    if(board[lastC.line][lastC.col].piece == NO_PIECE)
        return FALSE;

    return canPawnMove(board, lastC, newC);
}

void updateBoard(board_a board, coord_s lastC, coord_s newC){
    board[newC.line][newC.col].piece = board[lastC.line][lastC.col].piece;
    board[newC.line][newC.col].pieceColor = board[lastC.line][lastC.col].pieceColor;
    board[lastC.line][lastC.col].piece = NO_PIECE;
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
        updateDisplay(renderer, board, lastCoord, newCoord);
        return TRUE;
    }
    unselectOnePiece(renderer, board, lastCoord);
    return FALSE;
}
