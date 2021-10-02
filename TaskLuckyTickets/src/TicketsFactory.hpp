#pragma once
#include <string>
#include <map>
#include <memory>
#include "MoscowFactory.hpp"
#include "PiterFactory.hpp"
#include "TicketCity.hpp"

class TicketsFactory
{
public:
    std::vector<std::unique_ptr<LuckyTicket>> GetTickets(
        const std::vector<int>& numbers, TicketCity city);

    TicketCity GetCity(std::string city);

private:
    static ITicketFactory* GetMoscowFactory();
    static ITicketFactory* GetPiterFactory();

    static const std::vector<const char*> s_cities_indexes;
    static const std::map<TicketCity, ITicketFactory* (*)()> s_cities_factories;
};