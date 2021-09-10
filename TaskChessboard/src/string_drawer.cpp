#include "string_drawer.h"

const std::vector<std::map<ChessPiece, char>> StringDrawer::pieces_chars {
  // Black pieces
	{ 
    { NONE, '#' },
    { PAWN, 'P' }
  },
  // White pieces
  {
    { NONE, '_' },
    { PAWN, 'p' }
  }
};

StringDrawer::StringDrawer(const ChessBoard* board, std::string& target_string) 
: ChessBoardDrawer(board), target_(target_string) {}

StringDrawer::~StringDrawer() {}

void StringDrawer::draw() {
  target_.clear();
  int w = board_->get_width(), h = board_->get_height();
  bool white = start_white_;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      target_ += pieces_chars.at(white).at(board_->get_piece(x, y));
      // To cycle between black and white
      white = !white;
    }
    target_ += '\n';
    if (w % 2 == 0)
      white = !white;
  }
}