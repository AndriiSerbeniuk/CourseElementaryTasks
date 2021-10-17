#include <iostream>
// TODO: remove when finished with testing
#include "LuckyFilter.hpp"
#include "LuckyPredicates.hpp"
#include "CitiesTable.hpp"
#include "TicketsRangeGen.hpp"

int main()
{
    // Testing code
    std::vector<Ticket> tickets {1500, 150015, 143341, 456654, 433658, 314413 };

    TicketCity city = CitiesTable::get_city("moscow");
    bool (*pred)(const Ticket&) = CitiesTable::get_predicate(city);
    LuckyFilter<std::vector<Ticket>::const_iterator> filter(tickets.cbegin(), tickets.cend(), pred);
    int counter = 0;

    for (auto t : filter)
    {
        ++counter;
    }
    std::cout << counter << "\n";

    LuckyFilter<std::vector<Ticket>::const_iterator> filter2(tickets.cbegin(), tickets.cend(), 
        CitiesTable::get_predicate(CitiesTable::get_city("piter")));
    counter = 0;
    
    for (auto t : filter2)
    {
        ++counter;
    }
    std::cout << counter << "\n";
    
    // Range processing testing
    TicketsRangeGen gen(
        Ticket(std::vector<char>(6, '0')), 
        Ticket(std::vector<char>(6, '9')));

    LuckyFilter<TicketsRangeGen::GenIterator> filter3(gen.begin(), gen.end(), 
        LuckyPredicates::MoscowLucky);
    counter = 0;
    
    for (auto t : filter3)
    {
        ++counter;
    }
    
    std::cout << counter << "\n";

    return 0;
}