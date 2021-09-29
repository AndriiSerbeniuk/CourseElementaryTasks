#include "TicketsCounter.hpp"

TicketsCounter::TicketsCounter() : m_tickets(), m_lucky_count(0) {}

TicketsCounter::TicketsCounter(const std::vector<int>& tickets) : m_tickets(tickets)
{
    Count();
}


int TicketsCounter::get_lucky_count() const
{
    return m_lucky_count;
}

std::vector<int> TicketsCounter::get_tickets() const
{
    return m_tickets;
}

void TicketsCounter::set_tickets(const std::vector<int> tickets)
{
    m_tickets = tickets;
    Count();
}




void TicketsCounter::Count()
{
    
}
