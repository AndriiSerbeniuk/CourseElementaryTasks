#include <iostream>
#include "TicketsCounter.hpp"

int main()
{
    // TODO: make a proper user interface
    TicketsCounter counter;
    std::vector<int> tickets {143341, 456654, 433658 };
    int lucky_moscow = counter.Count(tickets, MOSCOW);
    int lucky_piter = counter.Count(tickets, PITER);
    std::cout << lucky_moscow << " " << lucky_piter << "\n";

    return 0;
}