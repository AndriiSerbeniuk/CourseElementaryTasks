#pragma once
#include "LuckyTicket.hpp"

class PiterTicket : public LuckyTicket
{
public:
    PiterTicket(int number);

protected:
    void CheckLucky() override;
};