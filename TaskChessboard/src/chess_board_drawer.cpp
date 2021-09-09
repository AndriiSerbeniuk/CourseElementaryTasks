#include "chess_board_drawer.h"

ChessBoardDrawer::ChessBoardDrawer()
  : board_(nullptr), start_white_(false) {}

ChessBoardDrawer::ChessBoardDrawer(const ChessBoard* board) 
  : board_(board), start_white_(false) {}

ChessBoardDrawer::~ChessBoardDrawer() {}

void ChessBoardDrawer::draw() {}

bool ChessBoardDrawer::starts_white() const {
  return start_white_;
}
void ChessBoardDrawer::start_white(bool white) {
  start_white_ = white;
}