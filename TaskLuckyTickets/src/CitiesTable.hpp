#pragma once
#include <map>
#include "TicketCity.hpp"
#include "Ticket.hpp"

class CitiesTable
{
public:
    // Returns city code based on its name
    // Is case sensitive
    static TicketCity get_city(const std::string& city_name);
    // Returns predicate for luckiness for a city
    static bool (*get_predicate(TicketCity city)) (const Ticket&);

private:
    // Map of city codes based on their names // TODO: not sure if using text as keys is a right way
    static const std::map<const std::string, TicketCity> s_strings_cities;
    // Map of luckiness predicates for cities
    static const std::map<TicketCity, bool (*)(const Ticket&)> s_cities_predicates;
};
