#include "MoscowTicket.hpp"

const int MoscowTicket::s_lucky_length = 6;

MoscowTicket::MoscowTicket(unsigned int number) : LuckyTicket(number) 
{}

bool MoscowTicket::IsLucky() const
{
    bool is_lucky = false;
    if (m_number.size() == s_lucky_length)
    {
        int first_half_sum = 0;
        int second_half_sum = 0;
        int i = 0;
        int length = m_number.size();
        int half_of_length = length / 2;

        while (i < half_of_length)
        {
            first_half_sum += m_number[i];
            i++;
        }
        while (i < length)
        {
            second_half_sum += m_number[i];
            i++;
        }

        if (first_half_sum == second_half_sum)
        {
            is_lucky = true;
        }
    }
    
    return is_lucky;
}
