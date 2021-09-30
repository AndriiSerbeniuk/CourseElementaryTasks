#pragma once
#include <vector>
#include <memory>
#include "TicketsFactory.hpp"

class TicketsCounter
{
public:
    int Count(const std::vector<int>& tickets_nums, TicketCity city);
};