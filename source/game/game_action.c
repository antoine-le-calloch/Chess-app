#include "../../header/sdl/sdl_functions.h"
#include "../../header/game/game_action.h"
#include "../../header/game/game_utils.h"

void selectOnePiece(SDL_Renderer* renderer, board_a board, coord_s coord) {
    // add the selected square color
    SDL_Rect rect = SQUARE(coord.col, coord.line);
    SDL_SetRenderDrawColor(renderer, 189, 246, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    // add the selected piece
    square_s boardSquare = board[coord.line][coord.col];
    addASurface(renderer, piecesSurfaces[boardSquare.pieceColor][boardSquare.piece], rect);
}

void unselectOnePiece(SDL_Renderer* renderer, board_a board, coord_s coord) {
    // revert to the original square color
    SDL_Rect rect = SQUARE(coord.col, coord.line);
    colorOneSquare(renderer, rect, board[coord.line][coord.col].color);

    // add the piece
    if (isPiece(board, coord)) {
        square_s boardSquare = board[coord.line][coord.col];
        addASurface(renderer, piecesSurfaces[boardSquare.pieceColor][boardSquare.piece], rect);
    }
}