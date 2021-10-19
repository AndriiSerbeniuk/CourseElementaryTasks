#include "StringDrawer.hpp"

const std::vector<std::map<ChessPieceType, char>> StringDrawer::s_pieces_chars 
{
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
    : ChessBoardDrawer(board), m_target(target_string) 
{}

void StringDrawer::Draw() 
{
    m_target.clear();
    int w = m_board->get_width(), h = m_board->get_height();
    bool board_col = m_start_white;
    const ChessPiece* cur_piece = nullptr;

    for (int y = 0; y < h; y++) 
    {
        for (int x = 0; x < w; x++) 
        {
            cur_piece = &m_board->get_piece(x, y);
            if (cur_piece->type == CHESS_NONE)
            {
                m_target += s_pieces_chars.at(board_col).at(cur_piece->type);
            }
            else
            {
                m_target += s_pieces_chars.at(cur_piece->team).at(cur_piece->type);
            }
            // To cycle between black and white
            board_col = !board_col;
        }

        m_target += '\n';
        if (w % 2 == 0)
        {
            board_col = !board_col;
        }
    }
}
