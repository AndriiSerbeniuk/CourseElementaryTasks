#include <iostream>
#include "TicketsCounter.hpp"

int main()
{
    // TODO: make a proper user interface
    TicketsCounter counter;
    std::vector<int> tickets {143341, 456654, 433658 };
    std::string city("moscow");
    int lucky_moscow = counter.Count(tickets, city);
    city = "piter";
    int lucky_piter = counter.Count(tickets, city);
    std::cout << lucky_moscow << " " << lucky_piter << "\n";
    city = "sochi";
    int lucky_sochi = counter.Count(tickets, city);
    
    return 0;
}