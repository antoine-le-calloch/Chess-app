#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H

#include "../types.h"

SDL_Surface * getSurfaceFromBMP(char* path);

SDL_Texture * getTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);

void addASurface(SDL_Renderer* renderer, SDL_Surface* surface, SDL_Rect square);

void colorOneSquare(SDL_Renderer* renderer, SDL_Rect square, int color);

#endif //SDL_FUNCTIONS_H