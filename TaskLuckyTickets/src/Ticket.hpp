#pragma once
#include <vector>

class Ticket
{
public:
    Ticket(unsigned int number);

    std::vector<char> get_number() const;

protected:
    std::vector<char> m_number;

private:
    std::vector<char> DivideToDigits(unsigned int number) const;
};
