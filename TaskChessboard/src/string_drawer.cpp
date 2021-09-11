#include "string_drawer.h"

const std::vector<std::map<ChessPieceType, char>> StringDrawer::pieces_chars {
  // Black pieces
	{ 
    { CHESS_NONE, '#' },
    { CHESS_PAWN, 'P' }
  },
  // White pieces
  {
    { CHESS_NONE, '_' },
    { CHESS_PAWN, 'p' }
  }
};

StringDrawer::StringDrawer(const ChessBoard* board, std::string& target_string) 
: ChessBoardDrawer(board), target_(target_string) {}

StringDrawer::~StringDrawer() {}

void StringDrawer::draw() {
  target_.clear();
  int w = board_->get_width(), h = board_->get_height();
  bool board_col = start_white_;
  const ChessPiece* cur_piece = nullptr;
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      cur_piece = &board_->get_piece(x, y);
      if (cur_piece->type == CHESS_NONE)
        target_ += pieces_chars.at(board_col).at(cur_piece->type);
      else
        target_ += pieces_chars.at(cur_piece->team).at(cur_piece->type);
      // To cycle between black and white
      board_col = !board_col;
    }
    target_ += '\n';
    if (w % 2 == 0)
      board_col = !board_col;
  }
}