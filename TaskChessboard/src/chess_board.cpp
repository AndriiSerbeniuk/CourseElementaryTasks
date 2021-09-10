#include "chess_board.h"
#include <stdexcept>

ChessBoard::ChessBoard(int width, int height) {
  if (width <= 0 || height <= 0)
    throw std::invalid_argument("Size of " + std::to_string(width) + "*" + 
      std::to_string(height) + " is invalid. Each dimention must be > 0.");
  width_ = width;
  height_ = height; 
  pieces_ = new ChessPiece*[width_];
  for (int i = 0; i < width_; i++) {
      pieces_[i] = new ChessPiece[height_] { NONE };
  }
}

ChessBoard::~ChessBoard() {
  for (int i = 0; i < width_; i++) {
    delete[] pieces_[i];
  }
  delete[] pieces_;
}

int ChessBoard::get_width() const {
  return width_;
}

int ChessBoard::get_height() const {
  return height_;
}

ChessPiece ChessBoard::get_piece(int x, int y) const {
  if (x < 0 || x >= width_ || y < 0 || y >= height_) {
    throw std::out_of_range("Unhandled exception: x = " + std::to_string(x) +
      "; y = " + std::to_string(y) + " is outside the chessboard bounds.");
  }
  return pieces_[x][y];
}

void ChessBoard::set_piece(int x, int y, ChessPiece piece)
{
  if (x < 0 || x >= width_ || y < 0 || y >= height_) {
    throw std::out_of_range("Unhandled exception: x = " + std::to_string(x) +
      "; y = " + std::to_string(y) + " is outside the chessboard bounds.");
  }
  pieces_[x][y] = piece;
}