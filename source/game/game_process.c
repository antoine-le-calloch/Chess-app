#include "../../header/sdl/sdl_events.h"
#include "../../header/game/game_process.h"
#include "../../header/game/game_movement.h"
#include "../../header/game/game_action.h"
#include "../../header/game/game_utils.h"

void processSelectPiece(SDL_Renderer *renderer, board_a board, coord_s coord) {
    selectOnePiece(renderer, board, coord);
}

void processMovePiece(SDL_Renderer *renderer, board_a board, action_s* lastAction, coord_s coord) {
    moveOnePiece(renderer, board, lastAction->coord, coord);
}

void gameProcess(SDL_Renderer *renderer, board_a board, SDL_Event event, action_s* lastAction) {
    coord_s coord = {0, 0};
    if (isClickEvent(&event, &coord)) {
        if(lastAction->type == SELECT_PIECE) {
            processMovePiece(renderer, board, lastAction, coord);
            lastAction->type = MOVE_PIECE;
            lastAction->coord = coord;
        } else if(isPiece(board, coord)) {
            processSelectPiece(renderer, board, coord);
            lastAction->type = SELECT_PIECE;
            lastAction->coord = coord;
        }
    }
}