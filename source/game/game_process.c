#include "../../header/sdl/sdl_events.h"
#include "../../header/game/game_process.h"
#include "../../header/game/game_movement.h"

void processSelectPiece(SDL_Renderer *renderer, coord_s coord) {
    SDL_Rect rect = {coord.col * SQUARE_SIZE, coord.line * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE};
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void processMovePiece(SDL_Renderer *renderer, board_a board, action_s* lastAction, coord_s coord) {
    moveOnePiece(renderer, board, lastAction->coord, coord);
}

void gameProcess(SDL_Renderer *renderer, board_a board, SDL_Event event, action_s* lastAction) {
    coord_s coord = {0, 0};
    if (isClickEvent(&event, &coord)) {
        if(lastAction->type != SELECT_PIECE) {
            processSelectPiece(renderer, coord);
            lastAction->type = SELECT_PIECE;
            lastAction->coord = coord;
        } else {
            processMovePiece(renderer, board, lastAction, coord);
            lastAction->type = MOVE_PIECE;
            lastAction->coord = coord;
        }
    }
}