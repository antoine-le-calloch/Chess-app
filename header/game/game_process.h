#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include "../types.h"

void gameProcess(SDL_Renderer *renderer, board_a board, SDL_Event event, action_s* lastAction);

#endif //GAME_PROCESS_H