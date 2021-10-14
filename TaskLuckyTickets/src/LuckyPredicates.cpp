#include "LuckyPredicates.hpp"

unsigned int LuckyPredicates::s_lucky_length = 6;

bool LuckyPredicates::MoscowLucky(const Ticket& ticket)
{
    std::vector<char> number = ticket.get_number();
    bool is_lucky = false;

    if (number.size() == s_lucky_length)
    {
        int first_half_sum = 0;
        int second_half_sum = 0;
        int i = 0;
        int length = number.size();
        int half_of_length = length / 2;

        while (i < half_of_length)
        {
            first_half_sum += number[i];
            i++;
        }
        while (i < length)
        {
            second_half_sum += number[i];
            i++;
        }

        if (first_half_sum == second_half_sum)
        {
            is_lucky = true;
        }
    }
    
    return is_lucky;
}

bool LuckyPredicates::PiterLucky(const Ticket& ticket)
{
    std::vector<char> number = ticket.get_number();
    bool is_lucky = false;

    if (number.size() == s_lucky_length)
    {
        int even_sum = 0;
        int odd_sum = 0;

        for (char digit : number)
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
