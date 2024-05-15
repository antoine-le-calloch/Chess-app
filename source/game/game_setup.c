#include "../../header/game/game_setup.h"
#include "../../header/sdl/sdl_functions.h"

void setupBoard(board_a board){
    int piece;
    int pieces_line[BOARD_SIZE] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK};
    for (int line = 0; line < BOARD_SIZE; ++line) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            piece = NO_PIECE;
            if(line == 0 || line == BOARD_SIZE-1) {
                piece = pieces_line[col];
            }else if(line == 1 || line == BOARD_SIZE-2) {
                piece = PAWN;
            }
            square_s square = {
                    .color = (line+col) % 2 ? BLACK:WHITE,
                    .piece = piece,
                    .pieceColor = line<3 ? BLACK:WHITE
            };
            board[line][col] = square;
        }
    }
}

void setupPiecePath(char* path, char* name, char* color){
    snprintf(path, 50, "../images/pieces/%s_%s.bmp", name, color);
}

void createPiecesSurfaces(){
    char path[50];
    char* piecesName[] = {
            "empty",
            "pawn",
            "bishop",
            "knight",
            "rook",
            "queen",
            "king"};
    // Add the white pieces to the piecesTextures tab
    for (int i = 1; i < NB_PIECES; ++i) {
        setupPiecePath(path, piecesName[i], "white");
        piecesSurfaces[WHITE][i] = getSurfaceFromBMP(path);
    }

    for (int i = 1; i < NB_PIECES; ++i) {
        setupPiecePath(path, piecesName[i], "black");
        piecesSurfaces[BLACK][i] = getSurfaceFromBMP(path);
    }
}

void displayBoard(SDL_Renderer* renderer, board_a board){
    createPiecesSurfaces();
    square_s boardSquare;
    for (int line = 0; line < BOARD_SIZE; ++line) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            boardSquare = board[line][col];

            SDL_Rect squareRect = SQUARE(col, line);
            colorOneSquare(renderer, squareRect, boardSquare.color);

            if(boardSquare.piece > NO_PIECE){ // Add pieces image on the screen
                SDL_Rect square = SQUARE(col, line);
                addASurface(renderer, piecesSurfaces[boardSquare.pieceColor][boardSquare.piece], square);
            }
        }
    }
    SDL_RenderPresent(renderer); // Update the window
}

// Function to set up the board
void gameSetup(SDL_Renderer* renderer, board_a board){
    setupBoard(board);
    displayBoard(renderer, board);
}