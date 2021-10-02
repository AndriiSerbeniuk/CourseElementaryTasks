#pragma once
#include "LuckyTicket.hpp"

class PiterTicket : public LuckyTicket
{
public:
    PiterTicket(unsigned int number);

    bool IsLucky() const override;

private:
    static const int s_lucky_length;
};