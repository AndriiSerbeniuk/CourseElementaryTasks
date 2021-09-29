#include "LuckyTicket.hpp"

const int LuckyTicket::s_lucky_length = 6;

LuckyTicket::LuckyTicket(int number) : m_number(number), m_is_lucky(false)
{}

bool LuckyTicket::IsLucky() const
{
    return m_is_lucky;
}

std::vector<int> LuckyTicket::DivideToDigits(int number) const
{
    std::vector<int> digits;
    char cur_digit;
    int left_digits = number;

    do
    {
        cur_digit = left_digits % 10;
        left_digits /= 10;
        if (cur_digit)
        {
            digits.push_back(cur_digit);
        }
    } while (left_digits);   

    return digits;
}