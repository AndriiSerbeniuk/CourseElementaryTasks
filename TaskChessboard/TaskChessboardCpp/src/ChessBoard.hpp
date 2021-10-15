#pragma once
#include "ChessPiece.hpp"

// Contains data about contained chess pieces on a width*height board
class ChessBoard 
{
public:
    ChessBoard(int width, int height);
    ~ChessBoard();

    int get_width() const;
    int get_height() const;
    const ChessPiece& get_piece(int x, int y) const;
    // Creates a new piece on the board
    void set_piece(int x, int y, ChessPieceType piece, bool team);

private:
    int m_height;
    int m_width;
    // Double array of pointers to the pieces. Empty spaces on the board are nullptr
    ChessPiece*** m_pieces;
};
