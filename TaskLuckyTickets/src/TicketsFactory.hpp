#pragma once
#include <string>
#include <map>
#include <memory>
#include "MoscowFactory.hpp"
#include "PiterFactory.hpp"

enum TicketCity
{
    MOSCOW, PITER
};

class TicketsFactory
{
public:
    std::vector<std::unique_ptr<LuckyTicket>> GetTickets(
        const std::vector<int>& numbers, TicketCity city);

private:
    static ITicketFactory* GetMoscowFactory();
    static ITicketFactory* GetPiterFactory();

    static const std::map<TicketCity, ITicketFactory* (*)()> s_cities_factories;
};