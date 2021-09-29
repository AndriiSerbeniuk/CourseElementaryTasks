#pragma once
#include "ITicketFactory.hpp"
#include "PiterTicket.hpp"

class PiterFactory : public ITicketFactory
{
public:
    LuckyTicket* GetTicket(int number) override;
};
