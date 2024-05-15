#include "../../header/game/game_process.h"
#include "../../header/game/game_movement.h"

void gameProcess(SDL_Renderer *renderer, board_a board){
    coord_s lastCoord = {1, 3};
    coord_s newCoord = {2, 3};
    moveOnePiece(renderer, board, lastCoord, newCoord);
    lastCoord = newCoord;
    newCoord = (coord_s){3, 3};
    moveOnePiece(renderer, board, lastCoord, newCoord);
    lastCoord = newCoord;
    newCoord = (coord_s){4, 3};
    moveOnePiece(renderer, board, lastCoord, newCoord);
}