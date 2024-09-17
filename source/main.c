//Types
#include "../header/types.h"
//SDL
#include "../header/sdl/sdl_setup.h"
#include "../header/sdl/sdl_events.h"
//Game
#include "../header/game/game_setup.h"
#include "../header/game/game_process.h"

int main(int argc, char *argv[]) {
    sdl_s sdl = {NULL, NULL};
    board_a board;
    SDL_Event event;
    action_s lastAction = {WHITE, NO_ACTION, {0, 0}};

    if(!sdlSetup(&sdl))
        return 1;
    gameSetup(sdl.renderer, board);

    while (1) {
        SDL_PollEvent(&event);
        if(isQuitEvent(&event) || lastAction.type == CHECKMATE)
            break;

        gameProcess(sdl.renderer, board, event, &lastAction);
        SDL_RenderPresent(sdl.renderer); // display update
    }
    sdlQuit(&sdl); // Quit the game
    return 0;
}