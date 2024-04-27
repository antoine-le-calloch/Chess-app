//Types
#include "../header/types.h"
//SDL
#include "../header/sdl/sdl_setup.h"
//Game
#include "../header/game/game_setup.h"
#include "../header/game/game_process.h"

int main(int argc, char *args[]) {
    sdl_s sdl = {NULL, NULL};
    board_a board;
    SDL_Event event;

    if(!setupSDL(&sdl))
    {
        return 1;
    }

    gameSetup(sdl.renderer, board);

    //Start to play
    while (TRUE) {
        if (isQuitEvent(event)) {
            break;
        }
        gameProcess(sdl.renderer, board);
    }
    quitSDL(&sdl);
    return 0;
}