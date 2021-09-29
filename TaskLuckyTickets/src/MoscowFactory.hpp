#pragma once
#include "ITicketFactory.hpp"
#include "MoscowTicket.hpp"

class MoscowFactory : public ITicketFactory
{
public:
    LuckyTicket* GetTicket(int number) override;
};
