#pragma once
#include "MoscowFactory.hpp"
#include "PiterFactory.hpp"

class TicketsFactory
{
public:
    std::vector<LuckyTicket*> GetTickets(std::vector<int> numbers);
};