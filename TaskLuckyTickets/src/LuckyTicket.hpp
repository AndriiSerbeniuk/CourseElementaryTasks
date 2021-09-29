#pragma once
#include <vector>

// Abstract base class for lucky tickets
class LuckyTicket
{
public:
    LuckyTicket(int number);
    virtual ~LuckyTicket() = default;

    // Returns true if the ticket is lucky
    bool IsLucky() const;

protected:
    // Should implement a check and assign it to m_is_lucky
    virtual void CheckLucky() = 0;
    // Divides a number into digits.
    std::vector<int> DivideToDigits(int number) const;

    // A fixed length a luckt ticket should have
    static const int s_lucky_length;

    int m_number;
    bool m_is_lucky;
};