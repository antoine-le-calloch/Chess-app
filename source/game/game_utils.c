#include "../../header/game/game_utils.h"

int isPiece(board_a board, coord_s coord){
    return board[coord.line][coord.col].piece != NO_PIECE;
}