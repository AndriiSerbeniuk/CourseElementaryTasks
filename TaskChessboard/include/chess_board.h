#pragma once

// Chess pieces that can be places on the ChessBoard
enum ChessPieceType { CHESS_NONE, CHESS_PAWN };

struct ChessPiece {
  ChessPieceType type;
  bool team;  // False for black, true for white
} const piece_blank {CHESS_NONE, false};

// Contains data about contained chess pieces on a width*height board
class ChessBoard {
private:
  int height_;
  int width_;
  // Double array of pointers to the pieces. Empty spaces on the board are nullptr
  ChessPiece*** pieces_;

public:
  ChessBoard(int width, int height);
  virtual ~ChessBoard();

  int get_width() const;
  int get_height() const;
  const ChessPiece& get_piece(int x, int y) const;
  // Creates a new piece on the board
  void set_piece(int x, int y, ChessPieceType piece, bool team);
};