#pragma once
#include "chess_board.h"

// Abstract class for drawing a ChessBoard.
class ChessBoardDrawer {
protected:
  // Target board
  const ChessBoard* board_;
  // Determines whether drawing starts with a white or a black cell
  // true - white, false - black
  bool start_white_;

public:
  ChessBoardDrawer();
  ChessBoardDrawer(const ChessBoard* board);
  virtual ~ChessBoardDrawer();
  // The idea is to switch between
  // drawing black and white squares depending on its index.
  virtual void draw() = 0;
  // Returns true if the first drawn square wil be white, false if black.
  bool starts_white() const;
  // Set to true if the first drawn square is supposed to be white, false if black.
  void start_white(bool white);
};