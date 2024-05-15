#include "../../header/sdl/sdl_functions.h"

// Function to create a SDL_Surface from a BMP file
SDL_Surface* getSurfaceFromBMP(char* path){
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (surface == NULL) {
        SDL_Log("Error SDL_LoadBMP : %s",
                SDL_GetError());
        return NULL;
    }
    return surface;
}

// Function to create a SDL_Texture from a BMP file
SDL_Texture* getTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface){
    SDL_Texture *textureWithBMP = SDL_CreateTextureFromSurface(renderer, surface);
    // TODO: verify this line
    //SDL_FreeSurface(surface);
    if (textureWithBMP == NULL) {
        SDL_Log("Error SDL_CreateTextureFromSurface : %s",
                SDL_GetError());
        return NULL;
    }
    return textureWithBMP;
}

// Function to add a surface in a square on the renderer
void addASurface(SDL_Renderer* renderer, SDL_Surface* surface, SDL_Rect square){
    SDL_Texture* texture = getTextureFromSurface(renderer, surface);
    SDL_RenderCopy(renderer, texture, NULL, &square);
}

// Function to color a square on the renderer
void colorOneSquare(SDL_Renderer* renderer, SDL_Rect square, int color){
    if(color == WHITE) {
        SDL_SetRenderDrawColor(renderer, 255, 233, 127, 255); // Select white color
    }else {
        SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255); // Select black color
    }
    SDL_RenderFillRect(renderer, &square);
}