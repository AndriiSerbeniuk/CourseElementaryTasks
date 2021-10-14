#include <iostream>
// TODO: remove when finished with testing
#include "LuckyFilter.hpp"
#include "LuckyPredicates.hpp"
#include "CitiesTable.hpp"

int main()
{
    // TODO: make a proper user interface
    std::vector<Ticket> tickets {1500, 150015, 143341, 456654, 433658, 314413 };

    TicketCity city = CitiesTable::get_city("moscow");
    bool (*pred)(const Ticket&) = CitiesTable::get_predicate(city);
    LuckyFilter filter(tickets, pred);

    int counter = 0;

    for (auto t : filter)
    {
        ++counter;
    }
    std::cout << counter << "\n";

    LuckyFilter filter2(tickets, CitiesTable::get_predicate(CitiesTable::get_city("piter")));

    counter = 0;
    
    for (auto t : filter2)
    {
        ++counter;
    }
    std::cout << counter << "\n";
    
    return 0;
}