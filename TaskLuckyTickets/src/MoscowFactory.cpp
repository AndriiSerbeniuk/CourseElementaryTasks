#include "MoscowFactory.hpp"

LuckyTicket* MoscowFactory::GetTicket(int number)
{
    return new MoscowTicket(number);
}
