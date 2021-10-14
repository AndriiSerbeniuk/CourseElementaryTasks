#pragma once
#include "Ticket.hpp"

// Container for functions that check if a ticket is lucky
class LuckyPredicates
{
public:
    static bool MoscowLucky(const Ticket& ticket);
    static bool PiterLucky(const Ticket& ticket);

private:
    static unsigned int s_lucky_length;
};
