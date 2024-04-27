#include "../../header/game/game_setup.h"
#include "../../header/sdl/sdl_functions.h"

void setupPieces(board_a board){
    int pieces_line[BOARD_SIZE] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    for (int line = 0; line < BOARD_SIZE; ++line) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if(line == 0 || line == BOARD_SIZE-1) {
                board[line][col] = pieces_line[col];
            }else if(line == 1 || line == BOARD_SIZE-2) {
                board[line][col] = PAWN;
            }else {
                board[line][col] = NO_PIECE;
            }
        }
    }
}

void setPiecePath(char* path, char* name, char* color){
    snprintf(path, 50, "../images/pieces/%s_%s.bmp", name, color);
}

void setupBoard(SDL_Renderer* renderer, board_a board){
    SDL_SetRenderDrawColor(renderer, 255, 233, 127, 255); // Select white color
    SDL_RenderClear(renderer); // Draw all in white
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255); // Select black color
    char* piecesName[] = {
            "pawn",
            "bishop",
            "knight",
            "rook",
            "queen",
            "king"};
    char path[50];
    int piece = NO_PIECE;

    for (int line = 0; line < BOARD_SIZE; ++line) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if ((line + col) % 2 == 0) { // Color 1 black square each 2 squares
                SDL_Rect squareRect = {col * SQUARE_SIZE, line * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE};
                SDL_RenderFillRect(renderer, &squareRect);
            }

            if((piece = board[line][col]) > NO_PIECE){ // Add pieces image on the screen
                SDL_Rect square = {
                        (col * SQUARE_SIZE),(line * SQUARE_SIZE),
                        PIECE_SIZE, PIECE_SIZE};
                setPiecePath(path, piecesName[piece-1], (line < 2 ? "black": "white"));
                SDL_RenderCopy(renderer, getTextureFromBMP(renderer, path), NULL, &square);
            }
        }
    }
    SDL_RenderPresent(renderer); // Update the window
}

// Function to set up the board
void gameSetup(SDL_Renderer* renderer, board_a board){
    // Set up the pieces on the board
    setupPieces(board);

    // Create the visual board and visualize pieces
    setupBoard(renderer, board);
}