#include <algorithm>
#include <stdexcept>
#include <string.h>
#include <cwctype>
#include "TicketsFactory.hpp"

const std::vector<const char*> TicketsFactory::s_cities_indexes
{
    "moscow", 
    "piter"
};

const std::map<TicketCity, ITicketFactory* (*)()> TicketsFactory::s_cities_factories
{
    { MOSCOW, GetMoscowFactory },
    { PITER, GetPiterFactory }
};

TicketCity TicketsFactory::GetCity(std::string city)
{
    std::for_each(city.begin(), city.end(), [](char& c) 
            {
                c = tolower(c);
            });

    auto start = s_cities_indexes.cbegin();
    auto end = s_cities_indexes.cend();
    auto found = std::find(start, end, city);
    
    return (TicketCity)((found == end) ? -1 : found - start);
}

std::vector<std::unique_ptr<LuckyTicket>> TicketsFactory::GetTickets(
    const std::vector<int>& numbers, TicketCity city)
{
    if (!s_cities_factories.count(city))
    {
        throw("TicketsFactory::GetTickets: city is invalid");
    }
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
