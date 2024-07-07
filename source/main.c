//Types
#include "../header/types.h"
//SDL
#include "../header/sdl/sdl_setup.h"
#include "../header/sdl/sdl_events.h"
//Game
#include "../header/game/game_setup.h"
#include "../header/game/game_process.h"

int main(int argc, char *args[]) {
    sdl_s sdl = {NULL, NULL};
    board_a board;
    SDL_Event event;
    action_s lastAction = {NO_ACTION, {0, 0}};

    // Set up the game
    if(!sdlSetup(&sdl))
        return 1;
    gameSetup(sdl.renderer, board);

    // Process the game
    while (1) {
        SDL_PollEvent(&event);
        if(isQuitEvent(&event))
            break;

        gameProcess(sdl.renderer, board, event, &lastAction);
        // display update
        SDL_RenderPresent(sdl.renderer);
    }

    // Quit the game
    sdlQuit(&sdl);
    return 0;
}