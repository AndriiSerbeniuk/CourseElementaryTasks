#pragma once
#include "Ticket.hpp"

// Abstract base class for lucky tickets
class LuckyTicket : public Ticket
{
public:
    LuckyTicket(unsigned int number);
    virtual ~LuckyTicket() = default;

    // Returns true if the ticket is lucky
    virtual bool IsLucky() const = 0;
};