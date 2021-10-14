#pragma once
#include <vector>
#include <map>
#include <string>
#include "ChessBoardDrawer.hpp"

// Draws a ChessBoard onto a std::string
class StringDrawer : public ChessBoardDrawer
{
public:
    // Provide target board to draw and a reference to a target string to draw on. 
    // The string WILL be modified.
    StringDrawer(const ChessBoard* board, std::string& target_string);
    // Draws the board onto the target string. The string will be modified
    void Draw() override;

private:
    // Target string
    std::string& m_target;
    // Instructions on how to draw each ChessPiece
    static const std::vector<std::map<ChessPieceType, char>> s_pieces_chars;
};
