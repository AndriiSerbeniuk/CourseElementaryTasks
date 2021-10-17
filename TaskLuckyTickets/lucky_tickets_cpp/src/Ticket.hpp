#pragma once
#include <vector>

// Ticket with a number, repserented as a vector of char digits
class Ticket
{
public:
    Ticket(unsigned int number);
    Ticket(const std::vector<char>& number);
    Ticket(const char* number);

    std::vector<char> get_number() const;

protected:
    std::vector<char> m_number;

private:
    std::vector<char> DivideToDigits(unsigned int number) const;
};
