#include "TicketsRangeGenerator.hpp"

typedef TicketsRangeGenerator::GenIterator gen_iter;

const char gen_iter::s_top_digit = '9';
const char gen_iter::s_bottom_digit = '0';

gen_iter::GenIterator(const Ticket& begin, const Ticket& end)
    : m_begin(begin), m_end(end)
{}

gen_iter::reference gen_iter::operator*() const
{
    return m_begin;
}

gen_iter::pointer gen_iter::operator->() const
{
    return &m_begin;
}

Ticket gen_iter::next()
{
    auto ticket_num = m_begin.get_number();
    auto cur_digit = ticket_num.rbegin();
    auto end = ticket_num.rend();

    while (cur_digit != end)
    {
        if (*cur_digit != s_top_digit)
        {
            ++(*cur_digit);
            cur_digit = end;
        }
        else
        {
            if (cur_digit + 1 != end)
            {
                *cur_digit = s_bottom_digit;
                ++cur_digit;
            }
            else
            {
                cur_digit = end;
                m_begin = m_end;    // Not sure about this
            }
        }
    }

    return Ticket(ticket_num);
}

gen_iter& gen_iter::operator++()
{
    m_begin = next();
    return *this;
}

gen_iter gen_iter::operator++(int)
{
    gen_iter temp = *this;
    ++(*this);

    return temp;
}

bool operator==(const gen_iter& lhs, const gen_iter& rhs)
{
    return lhs.m_begin.get_number() == rhs.m_begin.get_number();
}

bool operator!=(const gen_iter& lhs, const gen_iter& rhs)
{
    return lhs.m_begin.get_number() != rhs.m_begin.get_number();
}
