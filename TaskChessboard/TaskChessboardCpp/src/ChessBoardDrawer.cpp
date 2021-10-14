#include "ChessBoardDrawer.hpp"

ChessBoardDrawer::ChessBoardDrawer()
    : m_board(nullptr), m_start_white(false)
{}

ChessBoardDrawer::ChessBoardDrawer(const ChessBoard* board) 
    : m_board(board), m_start_white(false)
{}

ChessBoardDrawer::~ChessBoardDrawer()
{}

bool ChessBoardDrawer::StartsWhite() const 
{
    return m_start_white;
}

void ChessBoardDrawer::StartWhite(bool white)
{
    m_start_white = white;
}