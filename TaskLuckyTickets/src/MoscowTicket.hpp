#pragma once
#include "LuckyTicket.hpp"

class MoscowTicket : public LuckyTicket
{
public:
    MoscowTicket(int number);

protected:
    void CheckLucky() override;
};
