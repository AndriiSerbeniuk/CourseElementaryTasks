#pragma once
#include "ChessBoard.hpp"

// Abstract class for drawing a ChessBoard.
class ChessBoardDrawer 
{
public:
    ChessBoardDrawer();
    ChessBoardDrawer(const ChessBoard* board);
    virtual ~ChessBoardDrawer();

    // The idea is to switch between
    // drawing black and white squares depending on its index.
    virtual void Draw() = 0;
    // Returns true if the first drawn square wil be white, false if black.
    bool StartsWhite() const;
    // Set to true if the first drawn square is supposed to be white, false if black.
    void StartWhite(bool white);

protected:
    // Target board
    const ChessBoard* m_board;
    // Determines whether drawing starts with a white or a black cell
    // true - white, false - black
    bool m_start_white;
};