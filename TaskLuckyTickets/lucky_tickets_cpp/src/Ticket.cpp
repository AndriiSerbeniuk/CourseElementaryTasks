#include <string.h>
#include "Ticket.hpp"

Ticket::Ticket(unsigned int number)
{
    m_number = DivideToDigits(number);
}

Ticket::Ticket(const std::vector<char>& number) : m_number(number)
{}

Ticket::Ticket(const char* number)
{
    int len = strlen(number);
    for (int i = 0; i < len; i++)
    {
        m_number.push_back(number[i]);
    }
}

std::vector<char> Ticket::get_number() const
{
    return m_number;
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
        if (left_digits || cur_digit)
        {
            digits.push_back(cur_digit + '0');
        }
    } while (left_digits);   

    return digits;
}
