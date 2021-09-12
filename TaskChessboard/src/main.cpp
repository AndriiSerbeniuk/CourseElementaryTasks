#include <iostream>
#include "string_drawer.h"

int main(int argc, char* argv[]) {
	if (argc != 3){
    std::cout << "Wrong number of arguments provided.\n"
      << "Pass two integers that correspond to board's width and height.\n";
    return 0;
  }
  int w, h;
  try {
      w = std::stoi(argv[1]);
    }
  catch (const std::exception& e) {
    std::cout << argv[1] << " is not an integer.\n";
  }
  try {
      h = std::stoi(argv[2]);
    }
  catch (const std::exception& e) {
    std::cout << argv[2] << " is not an integer.\n";
    return 0;
  }
  if (w <= 0 || h <= 0) {
    std::cout << w << "x" << h << " is not a valid size for a chess board."
    << "\nEach dimention must be > 0.\n";
    return 0;
  }
	ChessBoard board(w, h);		// Create a blank board
	std::string drawn_board;	// String the board will be drawn on
	StringDrawer drawer(&board, drawn_board);
	drawer.draw();
	std::cout << drawn_board << "\n\n";

	return 0;
}