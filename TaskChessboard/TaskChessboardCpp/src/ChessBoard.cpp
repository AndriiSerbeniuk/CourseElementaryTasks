#include <stdexcept>
#include "ChessBoard.hpp"

ChessBoard::ChessBoard(int width, int height) 
{
    if (width <= 0 || height <= 0)
    {
        throw std::invalid_argument("Size of " + std::to_string(width) + "x" + 
            std::to_string(height) + " is invalid. Each dimention must be > 0.");
    }

    m_width = width;
    m_height = height; 
    m_pieces = new ChessPiece**[m_width];

    for (int i = 0; i < m_width; i++) 
    {
        m_pieces[i] = new ChessPiece*[m_height] { nullptr };
    }
}

ChessBoard::~ChessBoard() 
{
    for (int w = 0; w < m_width; w++) 
    {
        for (int h = 0; h < m_height; h++) 
        {
            if (m_pieces[w][h])
            {
                delete m_pieces[w][h];
            }
        }
        delete[] m_pieces[w];
    }
    delete[] m_pieces;
}

int ChessBoard::get_width() const {
    return m_width;
}

int ChessBoard::get_height() const {
    return m_height;
}

const ChessPiece& ChessBoard::get_piece(int x, int y) const 
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height) 
    {
        throw std::out_of_range("Unhandled exception: x = " + std::to_string(x) +
            "; y = " + std::to_string(y) + " is outside the chessboard bounds.");
    }

    if (m_pieces[x][y])
    {
        return *m_pieces[x][y];
    }

    return piece_blank;
}

void ChessBoard::set_piece(int x, int y, ChessPieceType piece, bool team)
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height) 
    {
        throw std::out_of_range("Unhandled exception: x = " + std::to_string(x) +
            "; y = " + std::to_string(y) + " is outside the chessboard bounds.");
    }

    if (m_pieces[x][y])
    {
        delete m_pieces[x][y];
    }

    m_pieces[x][y] = new ChessPiece {piece, team};
}
