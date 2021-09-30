#include "PiterTicket.hpp"

PiterTicket::PiterTicket(int number) : LuckyTicket(number)
{
    CheckLucky();
}

void PiterTicket::CheckLucky()
{
    m_is_lucky = false;
    std::vector<int> digits = DivideToDigits(m_number);

    if (digits.size() != s_lucky_length)
    {
        return;
    }

    int even_sum = 0,
        odd_sum = 0;
    
    for (char digit : digits)
    {
        if (digit % 2)
        {
            odd_sum += digit;
        }
        else
        {
            even_sum += digit;
        }
    }
    if (even_sum == odd_sum)
    {
        m_is_lucky = true;
    }
}
