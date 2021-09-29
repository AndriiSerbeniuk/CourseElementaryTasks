#pragma once
#include "LuckyTicket.hpp"

class ITicketFactory
{
public:
    virtual ~ITicketFactory() = default;

    virtual LuckyTicket* GetTicket(int number) = 0;
};