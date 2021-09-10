#pragma once
#include "chess_board_drawer.h"
#include <vector>
#include <map>
#include <string>

// Draws a ChessBoard into a std::string
class StringDrawer : public ChessBoardDrawer {
private:
  // Target string
  std::string& target_;
  // Instructions on how to draw each ChessPiece
  static const std::vector<std::map<ChessPiece, char>> pieces_chars;

public:
  // Provide target board to draw and a reference to a target string to draw on. 
  // The string WILL be modified.
  StringDrawer(const ChessBoard* board, std::string& target_string);
  ~StringDrawer();
  // Draws the board onto the target string. The string will be modified
  void draw();
};