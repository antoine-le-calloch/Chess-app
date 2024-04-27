#ifndef SDL_SETUP_H
#define SDL_SETUP_H

#include "../types.h"

int setupSDL(sdl_s* sdlPtr);

int isQuitEvent(SDL_Event event);

void quitSDL(sdl_s* sdlPtr);

#endif //SDL_SETUP_H