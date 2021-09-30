#include "MoscowTicket.hpp"

MoscowTicket::MoscowTicket(int number) : LuckyTicket(number) 
{
    CheckLucky();
}

void MoscowTicket::CheckLucky()
{
    m_is_lucky = false;
    std::vector<int> digits = DivideToDigits(m_number);

    if (digits.size() != s_lucky_length)
    {
        return;
    }

    int first_half_sum = 0,
        second_half_sum = 0,
        i = 0, 
        length = digits.size(), 
        half_of_length = length / 2;

    while (i < half_of_length)
    {
        first_half_sum += digits[i];
        i++;
    }
    while (i < length)
    {
        second_half_sum += digits[i];
        i++;
    }

    if (first_half_sum == second_half_sum)
    {
        m_is_lucky = true;
    }
}
