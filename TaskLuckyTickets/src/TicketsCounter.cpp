#include "TicketsCounter.hpp"

int TicketsCounter::Count(const std::vector<int>& tickets_nums, const std::string& city)
{
    int lucky_count = 0;
    TicketsFactory factory;
    TicketCity city_index = factory.GetCity(city);
    if (city_index == -1)
    {
        throw std::invalid_argument("TicketsCounter::Count: The city is invalid");
    }


    std::vector<std::unique_ptr<LuckyTicket>> tickets(factory.GetTickets(tickets_nums, city_index));
    auto ticket = tickets.cbegin();
    auto tickets_end = tickets.cend();

    while (ticket != tickets_end)
    {
        if ((*ticket)->IsLucky())
        {
            ++lucky_count;
        }
        ++ticket;
    }

    return lucky_count;
}
