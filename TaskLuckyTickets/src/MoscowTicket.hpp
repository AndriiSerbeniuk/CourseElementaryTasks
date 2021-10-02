#pragma once
#include "LuckyTicket.hpp"

class MoscowTicket : public LuckyTicket
{
public:
    MoscowTicket(unsigned int number);

    bool IsLucky() const override;

private:
    static const int s_lucky_length;
};
