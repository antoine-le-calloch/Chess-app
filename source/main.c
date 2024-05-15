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

    // Set up the game
    if(!sdlSetup(&sdl))
        return 1;
    gameSetup(sdl.renderer, board);

    // Process the game
    while (!isQuitEvent(&event)) {
        gameProcess(sdl.renderer, board);
    }

    // Quit the game
    sdlQuit(&sdl);
    return 0;
}