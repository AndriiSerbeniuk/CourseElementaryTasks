#include "TicketsCounter.hpp"

int TicketsCounter::Count(const std::vector<int>& tickets_nums, TicketCity city)
{
    int lucky_count = 0;
    TicketsFactory factory;
    std::vector<std::unique_ptr<LuckyTicket>> tickets(factory.GetTickets(tickets_nums, city));
    auto ticket = tickets.cbegin();
    auto tickets_end = tickets.cend();

    while (ticket != tickets_end)
    {
        if ((*ticket)->IsLucky())
        {
            lucky_count++;
        }
        ticket++;
    }

    return lucky_count;
}
