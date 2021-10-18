#pragma once

// Class that provides interface for outside use.
// Handles internal allocations on its own.
class AccessApi
{
public:
    AccessApi();
    ~AccessApi();

    // Returns string with a chessboard or error information
    char* get_chessboard(int width, int height);

private:
    char* m_board;
    bool m_allocated;

    void ClearBoard();
};
