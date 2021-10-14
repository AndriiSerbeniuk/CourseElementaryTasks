#pragma once
#include "ChessPieceType.hpp"

struct ChessPiece 
{
    ChessPieceType type;
    bool team;  // False for black, true for white
} const piece_blank {CHESS_NONE, false};
