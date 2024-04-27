#include "../../header/sdl/sdl_functions.h"

// Function to create a SDL_Texture from a BMP file
SDL_Texture* getTextureFromBMP(SDL_Renderer* renderer, char* path){
    SDL_Surface *tmp = SDL_LoadBMP(path);
    if (tmp == NULL) {
        SDL_Log("Error SDL_LoadBMP : %s",
                SDL_GetError());
        return NULL;
    }

    SDL_Texture *textureWithBMP = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if (textureWithBMP == NULL) {
        SDL_Log("Error SDL_CreateTextureFromSurface : %s",
                SDL_GetError());
        return NULL;
    }
    return textureWithBMP;
}