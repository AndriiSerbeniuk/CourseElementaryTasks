#pragma once

// Chess pieces that can be places on the ChessBoard
enum ChessPiece { NONE, PAWN };

// Contains data about contained chess pieces on a width*height board
class ChessBoard {
private:
  int height_;
  int width_;
  ChessPiece** pieces_;

public:
  ChessBoard(int width, int height);
  virtual ~ChessBoard();

  int get_width() const;
  int get_height() const;
  ChessPiece get_piece(int x, int y) const;
  void set_piece(int x, int y, ChessPiece piece);
};