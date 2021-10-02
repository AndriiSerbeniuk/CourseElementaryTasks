#include "PiterTicket.hpp"

const int PiterTicket::s_lucky_length = 6;

PiterTicket::PiterTicket(unsigned int number) : LuckyTicket(number)
{}

bool PiterTicket::IsLucky() const
{
    bool is_lucky = false;
    if (m_number.size() == s_lucky_length)
    {
        int even_sum = 0;
        int odd_sum = 0;

        for (char digit : m_number)
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
            is_lucky = true;
        }
    }
    
    return is_lucky;
}
