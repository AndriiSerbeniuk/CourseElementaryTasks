#include <iostream>
#include "string_drawer.h"

int main() {
	ChessBoard board(8, 8);		// Create a blank board
	std::string drawn_board;	// String the board will be drawn on
	
	board.set_piece(1,1, PAWN);
	StringDrawer drawer(&board, drawn_board);
	drawer.draw();
	std::cout << drawn_board << "\n\n";

	drawer.start_white(true);
	drawer.draw();
	std::cout << drawn_board;

	return 0;
}