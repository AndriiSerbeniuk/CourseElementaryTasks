#include "PiterFactory.hpp"

LuckyTicket* PiterFactory::GetTicket(int number)
{
    return new PiterTicket(number);
}
