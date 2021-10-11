#include <iostream>
#include "AccessFuncs.hpp"
#include "src/string_drawer.h"
#include "src/chess_board.h"

void DrawChessboard(int width, int height)
{
    ChessBoard board(width, height);
    std::string drawn_board;
    StringDrawer drawer(&board, drawn_board);
    drawer.draw();
    std::cout << drawn_board << "\n";
}