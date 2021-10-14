#include <string.h>
#include <memory>
#include "AccessApi.hpp"
#include "src/StringDrawer.hpp"
#include "src/ChessBoard.hpp"

AccessApi::AccessApi() : m_board(nullptr), m_allocated(false)
{}

AccessApi::~AccessApi()
{
    ClearBoard();
}

char* AccessApi::get_chessboard(int width, int height)
{
    std::unique_ptr<ChessBoard> board;
    std::string drawn_board;

    try
    {
        board.reset(new ChessBoard(width, height));
        StringDrawer drawer(&*board, drawn_board);
        drawer.Draw();
    }
    catch(const std::exception& e)
    {
        drawn_board = e.what();
    }
    
    ClearBoard();
    m_board = new char[drawn_board.length() + 1];
    m_allocated = true;
    strcpy(m_board, drawn_board.c_str());

    return m_board;
}

void AccessApi::ClearBoard()
{
    if (m_allocated)
    {
        delete[] m_board;
        m_allocated = false;
    }
}
