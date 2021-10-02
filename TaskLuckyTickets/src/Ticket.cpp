#include "Ticket.hpp"

Ticket::Ticket(unsigned int number)
{
    set_number(number);
}

void Ticket::set_number(unsigned int number)
{
    m_number = DivideToDigits(number);
}

std::vector<char> Ticket::DivideToDigits(unsigned int number) const
{
    std::vector<char> digits;
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
