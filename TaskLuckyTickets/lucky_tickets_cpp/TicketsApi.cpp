#include "TicketsApi.hpp"
#include "src/TicketsRangeGen.hpp"
#include "src/LuckyFilter.hpp"
#include "src/LuckyPredicates.hpp"
#include "src/CitiesTable.hpp"

bool(*GetCityLuckyPredicate(const char* city_name))(const Ticket&) 
{
    return CitiesTable::get_predicate(CitiesTable::get_city(city_name));
}

int CountLucky(const char* range_start, const char* range_end, 
    const char* city_name)
{
    int lucky_counter = 0;

    try
    {
        Ticket begin(range_start);
        Ticket end(range_end);
        TicketsRangeGen gen(begin, end);
        bool (*pred)(const Ticket&) = GetCityLuckyPredicate(city_name);
        
        if (pred)
        {
            LuckyFilter<TicketsRangeGen::GenIterator> filter(gen.begin(), gen.end(), pred);

            for (auto ticket : filter)
            {
                ++lucky_counter;
            }
        }
    }
    catch(const std::exception& e)
    {
        lucky_counter = -1;
    }

    return lucky_counter;
}

bool IsLucky(const char* ticket_num, const char* city_name)
{
    bool lucky = false;
    try
    {
        bool (*pred)(const Ticket&) = GetCityLuckyPredicate(city_name);
        Ticket ticket(ticket_num);
        lucky = pred(ticket);
    }
    catch(const std::exception& e)
    {}
    
    return lucky;
}

bool IsCityValid(const char* city_name)
{
    return UNKNOWN != CitiesTable::get_city(city_name);
}
