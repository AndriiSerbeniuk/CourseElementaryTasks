#include "TicketsRangeGen.hpp"

const TicketsRangeGen::GenIterator TicketsRangeGen::s_end(
    TicketsRangeGen::GenIterator::s_end, 
    TicketsRangeGen::GenIterator::s_end);

TicketsRangeGen::TicketsRangeGen(const Ticket& begin, 
    const Ticket& end)
    : m_begin(begin), m_end(end)
{}

TicketsRangeGen::GenIterator TicketsRangeGen::begin()
{
    return GenIterator(m_begin, m_end);
}

TicketsRangeGen::GenIterator TicketsRangeGen::end()
{
    return s_end;
}
