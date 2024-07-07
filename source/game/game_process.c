#include "../../header/sdl/sdl_events.h"
#include "../../header/game/game_process.h"
#include "../../header/game/game_movement.h"
#include "../../header/game/game_action.h"
#include "../../header/game/game_utils.h"

void gameProcess(SDL_Renderer *renderer, board_a board, SDL_Event event, action_s* lastAction) {
    coord_s coord = {0, 0};
    if (isClickEvent(&event, &coord)) {
        if(lastAction->type == SELECT_PIECE) {
            moveOnePiece(renderer, board, lastAction->coord, coord);
            lastAction->type = MOVE_PIECE;
            lastAction->coord = coord;
        } else if(isPiece(board, coord)) {
            selectOnePiece(renderer, board, coord);
            lastAction->type = SELECT_PIECE;
            lastAction->coord = coord;
        }
    }
}