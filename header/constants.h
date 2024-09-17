#ifndef CONSTANTS_H
#define CONSTANTS_H

// Board
#define BOARD_SIZE 8
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640
#define SQUARE_SIZE (SCREEN_WIDTH / BOARD_SIZE)

// Bool
#define FALSE 0
#define TRUE 1

// Pieces
#define NO_PIECE 0
#define PAWN 1
#define BISHOP 2
#define KNIGHT 3
#define ROOK 4
#define QUEEN 5
#define KING 6
#define NB_PIECES 7

// Colors
#define BLACK 0
#define WHITE 1

// Actions
#define NO_ACTION 0
#define SELECT_PIECE 1
#define MOVE_PIECE 2
#define CHECKMATE 3

// tab with all the SDL_texture of the pieces
SDL_Surface *piecesSurfaces[2][NB_PIECES];

#define SQUARE(col, line) (SDL_Rect){(col) * SQUARE_SIZE, (line) * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE}

#endif //CONSTANTS_H