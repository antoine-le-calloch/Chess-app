#include "../../header/game/game_movement.h"
#include "../../header/sdl/sdl_functions.h"

int isMovePossible(board_a board, coord_s lastC, coord_s newC){
    if(board[lastC.line][lastC.col].piece == NO_PIECE){
        return FALSE;
    }
    return TRUE;
}

void updateBoard(board_a board, coord_s lastC, coord_s newC){
    board[newC.line][newC.col].piece = board[lastC.line][lastC.col].piece;
    board[newC.line][newC.col].pieceColor = board[lastC.line][lastC.col].pieceColor;
    board[lastC.line][lastC.col].piece = NO_PIECE;
}

void updateDisplay(SDL_Renderer* renderer, board_a board, coord_s lastCoord, coord_s newCoord){
    // Remove the piece from the last position
    square_s lastSquare = board[lastCoord.line][lastCoord.col];
    SDL_Rect squareRect = SQUARE(lastCoord.col, lastCoord.line);
    colorOneSquare(renderer, squareRect, lastSquare.color);

    square_s newSquare = board[newCoord.line][newCoord.col];

    // Remove the piece from new position if there is one
    if(newSquare.piece != NO_PIECE)
        colorOneSquare(renderer, SQUARE(newCoord.col, newCoord.line), newSquare.color);

    // Add the piece to the new position
    SDL_Rect square = SQUARE(newCoord.col, newCoord.line);
    addASurface(renderer, piecesSurfaces[newSquare.pieceColor][newSquare.piece], square);

    // Update the window
    SDL_RenderPresent(renderer);
}

int moveOnePiece(SDL_Renderer* renderer, board_a board, coord_s lastCoord, coord_s newCoord){
    if(!isMovePossible(board, lastCoord, newCoord)){
        return FALSE;
    }
    updateBoard(board, lastCoord, newCoord);
    updateDisplay(renderer, board, lastCoord, newCoord);
    return TRUE;
}
