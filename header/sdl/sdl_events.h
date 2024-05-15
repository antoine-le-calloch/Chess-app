#ifndef SDL_EVENTS_H
#define SDL_EVENTS_H

#include "../types.h"

int isQuitEvent(SDL_Event* event);

int isClickEvent(SDL_Event* event, coord_s* coord);

#endif //SDL_EVENTS_H