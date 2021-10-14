#include "CitiesTable.hpp"
#include "LuckyPredicates.hpp"

const std::map<const std::string, TicketCity> CitiesTable::s_strings_cities
{
    { "moscow", MOSCOW },
    { "piter", PITER }
};

const std::map<TicketCity, bool (*)(const Ticket&)> CitiesTable::s_cities_predicates
{
    { UNKNOWN, nullptr },
    { MOSCOW, LuckyPredicates::MoscowLucky },
    { PITER, LuckyPredicates::PiterLucky }
};

TicketCity CitiesTable::get_city(const std::string& city_name)
{
    TicketCity city;
    try
    {
        city = s_strings_cities.at(city_name);
    }
    catch(const std::exception& e)
    {
        city = UNKNOWN;
    }
    
    return city;
}

bool (*CitiesTable::get_predicate(TicketCity city)) (const Ticket&)
{
    bool (*predicate)(const Ticket&);
    try
    {
        predicate = s_cities_predicates.at(city);
    }
    catch(const std::exception& e)
    {
        predicate = nullptr;
    }
    
    return predicate;
}
