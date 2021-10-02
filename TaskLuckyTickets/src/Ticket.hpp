#pragma once
#include <vector>

class Ticket
{
public:
    Ticket(unsigned int number);
    virtual ~Ticket() = default;

    void set_number(unsigned int number);

protected:
    std::vector<char> m_number;

private:
    std::vector<char> DivideToDigits(unsigned int number) const;
};