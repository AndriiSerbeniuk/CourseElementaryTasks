#include <iostream>
// TODO: remove when finished with testing
#include "LuckyFilter.hpp"
#include "LuckyPredicates.hpp"
#include "CitiesTable.hpp"
#include "TicketsRangeGenerator.hpp"

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
    
    TicketsRangeGenerator gen(
        Ticket(std::vector<char>(6, '0')), 
        Ticket(std::vector<char>(6, '9')));

    // for (auto gen_ticket : gen)
    // {
    //     for (auto dig : gen_ticket.get_number())
    //     {
    //         std::cout << dig;
    //     }
    //     std::cout << "\n";
    // }

    LuckyFilter<TicketsRangeGenerator::GenIterator> filter3(gen.begin(), gen.end(), 
        CitiesTable::get_predicate(CitiesTable::get_city("moscow")));
    counter = 0;
    
    for (auto t : filter3)
    {
        ++counter;
    }
    std::cout << counter << "\n";

    return 0;
}