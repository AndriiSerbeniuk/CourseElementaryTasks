#pragma once
#include <vector>
#include "TicketsFactory.hpp"

class TicketsCounter
{
public:
    int Count(const std::vector<int>& tickets_nums, const std::string& city);
};