#pragma once
#include <vector>

class TicketsCounter
{
public:
    TicketsCounter();
    TicketsCounter(const std::vector<int>& tickets);
    virtual ~TicketsCounter() = default;

    int get_lucky_count() const;
    std::vector<int> get_tickets() const;
    void set_tickets(const std::vector<int> tickets);

    std::vector<int> m_tickets;
    int m_lucky_count;

protected:
    virtual bool IsLucky(const std::vector<char>& number_digits) const = 0;

private:
    std::vector<char> DivideToDigits(int number);

    void Count();
};