#include "TicketsFactory.hpp"

const std::map<TicketCity, ITicketFactory* (*)()> TicketsFactory::s_cities_factories
{
    { MOSCOW, GetMoscowFactory },
    { PITER, GetPiterFactory }
};

std::vector<std::unique_ptr<LuckyTicket>> TicketsFactory::GetTickets(
    const std::vector<int>& numbers, TicketCity city)
{
    std::unique_ptr<ITicketFactory> factory(s_cities_factories.at(city)());
    std::vector<std::unique_ptr<LuckyTicket>> tickets;

    for (int number : numbers)
    {
        tickets.push_back(std::unique_ptr<LuckyTicket>(factory->GetTicket(number)));
    }

    return tickets;
}

ITicketFactory* TicketsFactory::GetMoscowFactory()
{
    return new MoscowFactory();
}

ITicketFactory* TicketsFactory::GetPiterFactory()
{
    return new PiterFactory();
}
